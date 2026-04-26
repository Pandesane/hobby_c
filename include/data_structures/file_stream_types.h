
#ifndef FILESTREAM_TYPES
#define FILESTREAM_TYPES
#include <stdio.h>
#include "./dynamic_array.h"
#include "./line.h"


typedef struct
{
  char *file_path;
  char *open_mode;
  FILE *file;
} H_FILE;

typedef struct
{
  H_FILE *h_file;
  // int line_buffer_size;
  // int maxLines;
  DYNAMIC_ARRAY  *cached_file_lines;
  int numberOfLines;
  int currentLine;
} FILESTREAM;

#endif