#include <stdio.h>
#include <regex.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "h_file.h"
#include "data_structures/dynamic_array.h"
#include "data_structures/file_stream.h";
#include "data_structures/line_trimmer.h"

#define PCRE2_CODE_UNIT_WIDTH 8
#include <stdio.h>
#include <string.h>
#include <pcre2.h>



int main()
{
  // read_file("test/vars/number.txt");
  // read_file("test/vars/string.txt");
  // read_file("test/vars/functions.txt");
  FILESTREAM *file_stream = open_file("test/vars/functions.txt");
  load_file_contents(file_stream);
  printf(" 1 Dynamic array size: %d length: %d \n", file_stream->cached_file_lines->buffer_size, file_stream->cached_file_lines->length);
  remove_empty_lines(file_stream);
  remove_comment_lines(file_stream);
  print_file_contents(file_stream);
  printf(" 1 Dynamic array size: %d length: %d \n", file_stream->cached_file_lines->buffer_size, file_stream->cached_file_lines->length);

  return 0;
}