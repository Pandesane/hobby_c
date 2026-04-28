

#include "data_structures/line_trimmer.h"





void remove_empty_lines(FILESTREAM *file_stream)
{
  // Trim the line
  // Remove the line if its empty
  // update the number of lines
  // Get all empty lines into an array and remove them by index we want
  // Make sure the number of lines is the same as the array length or index in the array
  int index = 0;
  int total_number_of_empty_lines = 0;
  while (has_next_element(file_stream->cached_file_lines, index))
  {
    LINE current_line = get_at_index_DA(file_stream->cached_file_lines, index);
    // printf("First line %d: %s \n", index, current_line);
    int current_line_has_chars = 0;
    for (; *current_line != '\0'; current_line++)
    {
      char ch = *current_line;

      if (ch == ' ')
      {
        if (current_line_has_chars == 1)
        {
          printf("This Line is not empty[%d]: %s ", index + 1, current_line);
          break;
        }
      }
      else if (ch == '\n')
      {
        // printf("Got new line: \n");
        if (current_line_has_chars != 1)
        {
          printf("This is an empty line [%d]: \n", index + 1);
          remove_at_index_DA(file_stream->cached_file_lines, index);
          // current_line_has_chars = 1;
          index--;
          total_number_of_empty_lines++;
          break;
        }
      }
      else
      {
        current_line_has_chars = 1;
        // printf("Got character: \n");
        // printf("Char: %c\n", *current_line);
      }
    }

    index++;
  }
  printf("Total number of empty lines: %d \n", total_number_of_empty_lines);
  // TODO: Always call fit array to size after removin all comments and new lines
  // void fit_array_size_to_length(DYNAMIC_ARRAY *arr);
}

void remove_comment_lines(FILESTREAM *file_stream)
{
  // Trim the line
  // Remove the line if its empty
  // update the number of lines
  // Get all empty lines into an array and remove them by index we want
  // Make sure the number of lines is the same as the array length or index in the array
  int index = 0;
  int total_number_of_comment_lines = 0;
  while (has_next_element(file_stream->cached_file_lines, index))
  {
    LINE current_line = get_at_index_DA(file_stream->cached_file_lines, index);
    int current_line_has_chars = 0;
    int is_comment_line = 0;
    for (; *current_line != '\0'; current_line++)
    {
      char ch = *current_line;

      if (ch == ' ')
      {
        if (current_line_has_chars == 1)
        {

          break;
        }
      }
      else if (ch == '#')
      {
        // printf("First line %d: %c \n", index, ch);
        if (current_line_has_chars != 1)
        {
          printf("Comment line found[%d]: \n", index + 1);
          total_number_of_comment_lines++;
          remove_at_index_DA(file_stream->cached_file_lines, index);
          index--;
          break;
        }
      }
      else
      {
        current_line_has_chars = 1;
        // printf("Got character: \n");
        // printf("Char: %c\n", *current_line);
      }
    }

    index++;
  }
  printf("Total number of comment lines: %d \n", total_number_of_comment_lines);
  // TODO: Always call fit array to size after removin all comments and new lines
  // void fit_array_size_to_length(DYNAMIC_ARRAY *arr);
}

int event_stack_callback(DYNAMIC_ARRAY *arr, void *element, int *in_parenthesis)
{
  // THis function removes inside trailing spaces in a line and makes it possible to split it further
  // for_each_DA(arr, char_arr_printer);

  char current_c = *(char *)element;
  if (arr->length == 0)
  {
    return 1;
  }

  char prev_c = *(char *)last_DA(arr);

  if (current_c == ' ' && prev_c == ' ')
  {
    return 0;
  }
  if ((*in_parenthesis) != 0 && current_c == ' ')
  {
    return 0;
  }

  if (current_c == '(')
  {
    char space = ' ';
    if (prev_c != ' ' && prev_c != '(' && prev_c != '&')
    {
      add_DA(arr, &space);
    }
    *in_parenthesis = (*in_parenthesis) + 1;
    return 1;
  }
  if (prev_c == ' ' && current_c == ',')
  {
    replace_at_index_DA(arr, arr->length - 1, element);
    return 0;
  }

  if (prev_c == ',' && current_c == ' ')
  {
    return 0;
  }

  if (current_c == ')')
  {
    *in_parenthesis = (*in_parenthesis) - 1;
    return 1;
  }

  return 1;
}

char *remove_inline_and_trailing_spaces(char *line)
{
  // TODO: first create release_array_memory_DA
  // Create a data structure that receives a char
  // Check if the char is not a space
  // Add the char to the stack
  // Get from stack if we have a length more than one and create a new memory
  // Creates a representation of that char as an array

  string_t *test_string = string_new(line);
  string_t *new_string = string_trim(test_string);
  // string_println(new_string);
  EVENT_STACK *stack = create_event_stack(sizeof(char), event_stack_callback, char_arr_getter, char_arr_setter);

  char *trimmed_string = string_tocstr(new_string);

  while (*trimmed_string != '\0')
  {
    char c = *trimmed_string;
    add_EVENT_STACK(stack, &c);

    trimmed_string++;
  }

  // TODO: Remove error in fit_array_size_to_length
  // fit_array_size_to_length(stack->arr);
  char *final_line_str = convert_to_cstr(stack->arr);

  return final_line_str;

  // printf("Event Stack  size: %d with length: %d \n", stack->arr->buffer_size, stack->arr->length);
}

char *get_block_name(char *line)
{
  // char *start_line = get_at_index_DA(arr, index);

  string_t *s_string = string_new(line);
  string_vector_t *sv_string = string_split(s_string, ' ');
  char *cstr = string_tocstr(string_vector_get(sv_string, 1));
  return cstr;
}

