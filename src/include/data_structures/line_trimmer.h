#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./file_stream_types.h"
#include "./file_stream.h"

// File operates on the line array by
/*
remove_empty_lines(FILESTREAM*, line_number)
*/

void remove_empty_lines(FILESTREAM *file_stream);

void remove_empty_lines(FILESTREAM *file_stream)
{
  // Trim the line
  // Remove the line if its empty
  // update the number of lines
  // Get all empty lines into an array and remove them by index we want
  // Make sure the number of lines is the same as the array length or index in the array

  while (has_next_line(file_stream))
  {
    LINE current_line = get_current_line(file_stream);
    // printf("First line %d: %s", file_stream->currentLine, current_line);
    int current_line_has_chars = 0;
    for (; *current_line != '\0'; current_line++)
    {
      char ch = *current_line;

      if (ch == ' ')
      {
        // printf("Got empty character: \n");
        if (current_line_has_chars == 1)
        {
          break;
        }
      }
      else if (ch == '\n')
      {
        printf("Got new line: \n");
        if (current_line_has_chars != 1)
        {
          printf("This is an empty line [%d]: \n", file_stream->currentLine);
        }
      }
      else
      {
        current_line_has_chars = 1;
        // printf("Got character: \n");
        // printf("Char: %c\n", *current_line);
      }
    }

    get_next_line(file_stream);
  }

  file_stream->currentLine = 0;
}