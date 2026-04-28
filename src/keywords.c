#include "data_structures/do_stack.h"
#include "keywords.h"
#include "data_structures/blocks/defmodule.h"
#include "data_structures/blocks/def.h"
#include "data_structures/blocks/defp.h"
#include "string/libstring.h"

void create_do_blocks(DYNAMIC_ARRAY *arr)
{
  DYNAMIC_ARRAY *do_stack_arr = create_array_DA(sizeof(DO_STACK), do_stack_arr_getter, do_stack_arr_setter);
  // DO_STACK *defmodule_stack = create_defmodule_do_stack_block(0);
  // push_DA(do_stack_arr, defmodule_stack);
  int index = 0;

  while (has_next_element(arr, index))
  {

    char *start_line = get_at_index_DA(arr, index);

    string_t *s_string = string_new(start_line);
    string_vector_t *sv_string = string_split(s_string, ' ');
    char *cstr = string_tocstr(string_vector_get(sv_string, 0));

    switch_block_keywords(cstr, index, arr, do_stack_arr);

    index++;
  }
  for_each_DA(do_stack_arr, do_stack_arr_printer);
}

void switch_block_keywords(char *word, int index, DYNAMIC_ARRAY *line_arr, DYNAMIC_ARRAY *do_stack_arr)
{
  switch (switch_char_words(word))
  {
  case unknown_keyword:
    printf("Unknown keyword block: %s\n", word);
    break;
  case defmodule:
    // printf("Gotten a defmodule block here: \n");
    DO_STACK *defmodule_stack = create_defmodule_do_stack_block(index);
    // defmodule_stack->preprocess(arr, defmodule_stack, index);
    push_DA(do_stack_arr, defmodule_stack);

  case def:
    printf("Gotten a def block here: \n");
    DO_STACK *def_stack = create_def_do_stack_block(index);
    push_DA(do_stack_arr, def_stack);
    break;
  case defp:
    printf("Gotten a defp block here: \n");
    DO_STACK *defp_stack = create_defp_do_stack_block(index);
    push_DA(do_stack_arr, defp_stack);
    break;

  case end:
    printf("Gotten a  end block here: \n");
    // Here we pop from the stack give the do_block some preprocessing such as determining available var names etc depending on the do_block
    DO_STACK *do_stack = pop_DA(do_stack_arr);
    do_stack->preprocess(line_arr, do_stack, index);
    // After preprocessing the do_block is attached to a code_generation queue
    do_stack_arr_printer(do_stack);
    break;

  default:
    break;
  }
}

Block_Keywords switch_char_words(char *word)
{
  if (strcmp(word, "defmodule") == 0)
  {
    return defmodule;
  }
  else if (strcmp(word, "def") == 0)
  {
    return def;
  }
  else if (strcmp(word, "defp") == 0)
  {
    return defp;
  }
  else if (strcmp(word, "end") == 0)
  {
    return end;
  }
  // else if (word == "def")
  // {
  //   return def;
  // }
  // else if (word == "def")
  // {
  //   return def;
  // }

  return unknown_keyword;
}
