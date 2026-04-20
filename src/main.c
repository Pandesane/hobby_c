#include <stdio.h>
#include <regex.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "./include/data_structures/file_stream.h";
#include "./include/file.h"

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
  print_file_contents(file_stream);

  printf(get_current_line(file_stream));
  printf(get_next_line(file_stream));
  printf(get_next_line(file_stream));
  printf(get_next_line(file_stream));
  printf(get_next_line(file_stream));
  printf(get_previous_line(file_stream));
  printf(get_next_line(file_stream));
  printf("Number of lines cached %d \n", file_stream->numberOfLines);

  return 0;
}