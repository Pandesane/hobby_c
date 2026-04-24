#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./file_stream_types.h"
#include "./file_stream.h"
#include <ctype.h>
#include "string/libstring.h"

// File operates on the line array by
/*
remove_empty_lines(FILESTREAM*, line_number)
*/

void remove_empty_lines(FILESTREAM *file_stream);
void remove_comment_lines(FILESTREAM *file_stream);
void split_line(char *line);
// char **split_line(char *line);

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

void split_line(char *line)
{
  // TODO: first create release_array_memory_DA
  // Create a data structure that receives a char
  // Check if the char is not a space
  // Add the char to the stack
  // Get from stack if we have a length more than one and create a new memory
  // Creates a representation of that char as an array

  string_t *test_string = string_new(line);
  // string_println(test_string);
  string_t *new_string = string_trim(test_string);
  string_vector_t *split_strings = string_split(new_string, ' ');

  if(string_vector_len(split_strings) > 2){
    
  }


  printf("String vector size: %d with length: %d \n", sizeof(string_vector_t), string_vector_len(split_strings));
}