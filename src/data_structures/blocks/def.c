
#include "data_structures/blocks/def.h"

#include "string/string_DA.h"

char *convert_def_arg_to_c_arg(DYNAMIC_ARRAY *arr)
{
  SPLIT_DA func_arg_split_new = split(arr, ':');

  // printf("Split Func args array length for ':': %d\n", func_arg_split_new.length);
  // TODO: do some preprocessing on the function type  func_arg_split_new.arrays[1]
  DYNAMIC_ARRAY *c_arr_args = merge(func_arg_split_new.arrays[1], func_arg_split_new.arrays[0], ' ');
  char *c_args = convert_to_cstr(c_arr_args);
  return c_args;
}
// IN -- def greet(name: string, age: number) do
// OUT -- ANY_T greet(string name, Number age)
void process_def_block_header(char *def_header)
{
  // Already knows its at def block so processing is easy
  DYNAMIC_ARRAY *parse_string = create_char_DA(def_header);
  // Remove the do
  pop_DA(parse_string);
  pop_DA(parse_string);
  // Remove the def
  dequeue_DA(parse_string);
  dequeue_DA(parse_string);
  dequeue_DA(parse_string);
  // Trim off trailing spaces
  trim_char_DA(parse_string);
  // TODO: Instead of removing the ) split it and get te funcs return type
  SPLIT_DA func_split_data = split(parse_string, ')');
  parse_string = func_split_data.arrays[0];
  trim_char_DA(func_split_data.arrays[1]);
  char *return_type = convert_to_cstr(func_split_data.arrays[1]);
  // return_type = string_tocstr(string_trim(string_new(return_type)));
  printf("The return type is: %s : %d\n", return_type, strlen(return_type));
  if (strlen(return_type) == 0)
  {
    return_type = "void";
  }

  // Remove the last )
  // pop_DA(parse_string);

  SPLIT_DA split_string = split(parse_string, '(');

  char *func_name = convert_to_cstr(split_string.arrays[0]);

  // for_each_DA(split_string.arrays[0], char_arr_printer);
  printf("Function name is:  %s\n", func_name);
  printf("Split array length: %d\n", split_string.length);

  DYNAMIC_ARRAY *func_arg_arr = split_string.arrays[1];
  SPLIT_DA func_arg_split = split(func_arg_arr, ',');
  printf("Split Func args array length: %d\n", func_arg_split.length);

  char *func_args[func_arg_split.length];

  for (size_t i = 0; i < func_arg_split.length; i++)
  {
    char *c_args = convert_def_arg_to_c_arg(func_arg_split.arrays[i]);
    func_args[i] = c_args;
  }

  DYNAMIC_ARRAY *output = create_char_DA(" ");
  for (size_t i = 0; i < func_arg_split.length; i++)
  {
    if (i == 0)
    {
      output = merge(output, create_char_DA(func_args[i]), ' ');
    }
    else
    {
      output = merge(output, create_char_DA(func_args[i]), ',');
    }
  }
  // printf("The formatted c equivalent 1: %s \n", func_args[0]);
  // printf("The formatted c equivalent 2: %s \n", func_args[1]);
  // printf("The formatted c equivalent 3: %s \n", func_args[2]);
  // trim_char_DA(output);
  // push_DA(output, (void *)')');
  char c = ')';
  push_DA(output, &c);
  c = ';';
  push_DA(output, &c);
  c = '(';
  insert_at_index_DA(output, 0, &c);
  output = merge(create_char_DA(func_name), output, ' ');
  // TODO: Check if return type is empty , then we put void
  output = merge(create_char_DA(return_type), output, ' ');

  // for_each_DA(output, char_arr_printer);
  char *c_func_header = convert_to_cstr(output);
  printf("The generated c function header: %s \n", c_func_header);
}

void def_preprocessor(DYNAMIC_ARRAY *line_arr, DO_STACK *me_do_stack, int current_index)
{
  printf("Running preprocessor def \n");
  me_do_stack->line_end_index = current_index;
  me_do_stack->line_expressions = get_sub_arr_DA(line_arr, me_do_stack->line_start_index + 1, current_index - 1);
  me_do_stack->name = (char *)get_block_name((char *)get_at_index_DA(line_arr, me_do_stack->line_start_index));
  for_each_DA(me_do_stack->line_expressions, line_arr_printer);
}

DO_STACK *create_def_do_stack_block(int line_start_index)
{
  DO_STACK *defmodule_block = (DO_STACK *)malloc(sizeof(DO_STACK));
  defmodule_block->line_start_index = line_start_index;
  defmodule_block->type = "def";
  defmodule_block->preprocess = def_preprocessor;

  return defmodule_block;
}
