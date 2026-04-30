#include <stdio.h>
#include <regex.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
// #include "h_file.h"
// #include "data_structures/dynamic_array.h"
// #include "data_structures/file_stream.h";
#include "data_structures/line_trimmer.h"
// #include "string/libstring.h"
#include "keywords.h"

#define PCRE2_CODE_UNIT_WIDTH 8
#include <stdio.h>
#include <string.h>
#include <pcre2.h>
#include "data_structures/linked_list.h"
#include "string/string_DA.h"
#include "data_structures/blocks/def.h"

// int main()
// {
//   // read_file("test/vars/number.txt");
//   // read_file("test/vars/string.txt");
//   // read_file("test/vars/functions.txt");

//   // split_line("  defmodule  HelloWorld  do   ");
//   // split_line("  def name do  ");
//   // split_line(" def greet ( name , age  ) do ");
//   // split_line(" def greet ( name , age  ) do \n");

//   FILESTREAM *file_stream = open_file("test/vars/module.txt");
//   load_file_contents(file_stream);
//   remove_empty_lines(file_stream);
//   remove_comment_lines(file_stream);
//   print_file_contents(file_stream);
//   printf(" 1 Dynamic array size: %d length: %d \n", file_stream->cached_file_lines->buffer_size, file_stream->cached_file_lines->length);

//   int index = 0;
//   DYNAMIC_ARRAY *arr = file_stream->cached_file_lines;
//   while (has_next_element(arr, index))
//   {

//     LINE line = get_at_index_DA(arr, index);
//     char *new_line = remove_inline_and_trailing_spaces(line);
//     replace_at_index_DA(arr, index, new_line);
//     // printf("Formatted line: -->%s\n", new_line);

//     // string_t *s_string = string_new(new_line);
//     // string_vector_t *sv_string = string_split(s_string, ' ');
//     // char *cstr = string_tocstr(string_vector_get(sv_string, 0));
//     // switch_block_keywords(cstr, index, arr);

//     index++;
//   }
//   // LINE start_line = get_at_index_DA(arr, 0);
//   // string_t *s_string = string_new(start_line);
//   // string_vector_t *sv_string = string_split(s_string, ' ');
//   // char *cstr = string_tocstr(string_vector_get(sv_string, 0));
//   // switch_block_keywords(cstr, index, arr);
//   create_do_blocks(arr);

//   // string_println(string_vector_get(sv_string, 0));

//   return 0;
// }

typedef enum
{
  INT,
  FLOAT
} Number_Code;
typedef struct
{
  Number_Code code;
  union
  {
    float float_var;
    int int_var;
  };
} Number;


int main()
{

  // char *def_header_block = "def greet(age: number) do";
  // char *def_header_block = "def greet(name: string, age: number) string do";
  char *def_header_block = "def greet(name: string, age: number, gender: string) do";
  process_def_block_header(def_header_block);
  return 0;
}
