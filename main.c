#include <stdio.h>
#include <regex.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "h_file.h"
#include "data_structures/dynamic_array.h"
#include "data_structures/file_stream.h";
#include "data_structures/line_trimmer.h"
#include "string/libstring.h"

#define PCRE2_CODE_UNIT_WIDTH 8
#include <stdio.h>
#include <string.h>
#include <pcre2.h>

int main()
{
  // read_file("test/vars/number.txt");
  // read_file("test/vars/string.txt");
  // read_file("test/vars/functions.txt");

  // split_line("    Pande Stephen Testing new library     ");
  FILESTREAM *file_stream = open_file("test/vars/functions.txt");
  load_file_contents(file_stream);
  remove_empty_lines(file_stream);
  remove_comment_lines(file_stream);
  print_file_contents(file_stream);
  printf(" 1 Dynamic array size: %d length: %d \n", file_stream->cached_file_lines->buffer_size, file_stream->cached_file_lines->length);

  DYNAMIC_ARRAY *sub_arr = get_sub_arr_DA(file_stream->cached_file_lines, 0, 10);
  for_each_DA(sub_arr, file_stream_printer);
  printf(" New Dynamic array size: %d length: %d \n", sub_arr->buffer_size, sub_arr->length);

  fit_array_size_to_length(sub_arr);
  for_each_DA(sub_arr, file_stream_printer);

  printf(" Static Dynamic array size: %d length: %d \n", sub_arr->buffer_size, sub_arr->length);

  return 0;
}
