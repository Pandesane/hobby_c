#include <stdio.h>

#ifndef FILESTREAM_TYPES
#define FILESTREAM_TYPES

typedef char *LINE;
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

#endif