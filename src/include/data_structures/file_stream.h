#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 300
typedef char *LINE;
typedef int Boolean;


typedef struct
{
  char *file_path;
  char *open_mode;
  FILE *file;
} H_FILE;

typedef struct
{
  H_FILE *h_file;
  int line_buffer_size;
  int maxLines;
  LINE *cached_file_lines;
  int numberOfLines;
  int currentLine;
} FILESTREAM;

// File stream
/*
openFIle
getNextLine
previousLine
nextLine
parseLines
hasNextLine
setFileBufferSize
getNumberOfLine
releaseStream

*/

FILESTREAM *open_file(char *fileName);
LINE get_current_line(FILESTREAM *fileStream);
LINE get_next_line(FILESTREAM *fileStream);
LINE get_previous_line(FILESTREAM *fileStream);
Boolean has_next_line(FILESTREAM *fileStream);
void load_file_contents(FILESTREAM *file_stream);
void print_file_contents(FILESTREAM *file_stream);
void set_file_buffer_size(FILESTREAM *fileStream);

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
  file_stream->line_buffer_size = MAX_BUFFER_SIZE;
  file_stream->currentLine = 0;
  file_stream->maxLines = 300;
  // TODO: Create a line data structure array that makes it easy to put and get lines of a file
  file_stream->cached_file_lines = (LINE *)malloc(file_stream->maxLines * file_stream->line_buffer_size * sizeof(char *));

  return file_stream;
}

void print_file_contents(FILESTREAM *file_stream)
{
  for (size_t i = 0; i < file_stream->numberOfLines; i++)
  {
    /* code */
    char *line = (char *)&file_stream->cached_file_lines[i * MAX_BUFFER_SIZE];
    printf("LINE: %ld >%s \n", i, line);
  }
}

void load_file_contents(FILESTREAM *file_stream)
{
  char buffer[MAX_BUFFER_SIZE];

  if (file_stream->h_file->file == NULL)
  {
    printf("Error: Could not open file.\n");
  }

  int line_index = 0;
  while (fgets(buffer, sizeof(buffer), file_stream->h_file->file))
  {
    // printf("%s", buffer); // Prints each line
    // file_stream->cached_file_lines[line_index * MAX_BUFFER_SIZE] = buffer;
    strcpy((char *)&file_stream->cached_file_lines[line_index * MAX_BUFFER_SIZE], buffer);
    line_index++;
  }

  file_stream->numberOfLines = line_index + 1;
  fclose(file_stream->h_file->file);
}

LINE get_current_line(FILESTREAM *file_stream)
{
  return (char *)&file_stream->cached_file_lines[file_stream->currentLine * MAX_BUFFER_SIZE];
}

LINE get_next_line(FILESTREAM *file_stream)
{
  if (file_stream->currentLine < file_stream->numberOfLines)
  {
    file_stream->currentLine += 1;
  }
  return (char *)&file_stream->cached_file_lines[file_stream->currentLine * MAX_BUFFER_SIZE];
}

LINE get_previous_line(FILESTREAM *file_stream)
{
  if (file_stream->currentLine > 0)
  {
    file_stream->currentLine -= 1;
  }
  return (char *)&file_stream->cached_file_lines[file_stream->currentLine * MAX_BUFFER_SIZE];
}
