
#include "data_structures/file_stream.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



FILESTREAM *open_file(char *fileName)
{

  printf("%s \n", fileName);
  FILE *f = fopen(fileName, "r");
  H_FILE *h_file = (H_FILE *)malloc(sizeof(H_FILE));
  h_file->open_mode = "r";
  h_file->file_path = fileName;
  h_file->file = f;

  FILESTREAM *file_stream = (FILESTREAM *)malloc(sizeof(FILESTREAM));
  file_stream->h_file = h_file;
  file_stream->currentLine = 0;
  // file_stream->line_buffer_size = MAX_BUFFER_SIZE;
  // file_stream->maxLines = 300;

  // TODO: Create a line data structure array that makes it easy to put and get lines of a file
  DYNAMIC_ARRAY *arr = create_array_DA(sizeof(LINE), line_arr_getter, line_arr_setter);
  file_stream->cached_file_lines = arr;
  return file_stream;
}

void print_file_contents(FILESTREAM *file_stream)
{
  // for (size_t i = 0; i < file_stream->numberOfLines; i++)
  // {
  //   /* code */
  //   char *line = (char *)&file_stream->cached_file_lines[i * MAX_BUFFER_SIZE];
  //   printf("LINE: %ld >%s \n", i, line);
  // }

  for_each_DA(file_stream->cached_file_lines, line_arr_printer);
}

void load_file_contents(FILESTREAM *file_stream)
{
  char buffer[300];

  if (file_stream->h_file->file == NULL)
  {
    printf("Error: Could not open file.\n");
  }

  int line_index = 0;
  while (fgets(buffer, sizeof(buffer), file_stream->h_file->file))
  {
    // printf("LINE: %s", buffer); // Prints each line
    push_DA(file_stream->cached_file_lines, buffer);
    line_index++;
  }

  file_stream->numberOfLines = line_index + 1;
  fclose(file_stream->h_file->file);
}

LINE get_current_line(FILESTREAM *file_stream)
{
  if (file_stream->currentLine > file_stream->numberOfLines - 2)
  {
    return "";
  }
  printf("Current Line: %d \n", file_stream->currentLine);
  LINE curr_line = get_at_index_DA(file_stream->cached_file_lines, file_stream->currentLine);
  printf("First line %d: %s \n", file_stream->currentLine, curr_line);
  return curr_line;
}

LINE get_next_line(FILESTREAM *file_stream)
{
  if (file_stream->currentLine < file_stream->numberOfLines)
  {
    file_stream->currentLine += 1;
  }
  LINE curr_line = get_at_index_DA(file_stream->cached_file_lines, file_stream->currentLine);

  return curr_line;
}

LINE get_previous_line(FILESTREAM *file_stream)
{
  if (file_stream->currentLine > 0)
  {
    file_stream->currentLine -= 1;
  }
  LINE curr_line = get_at_index_DA(file_stream->cached_file_lines, file_stream->currentLine);
  return curr_line;
}

Boolean has_next_line(FILESTREAM *fileStream)
{
  if (fileStream->currentLine == fileStream->numberOfLines)
  {
    return 0;
  }

  return 1;
}