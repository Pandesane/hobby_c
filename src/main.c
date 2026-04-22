#include <stdio.h>
#include <regex.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "./include/data_structures/file_stream.h";
#include "./include/file.h"
#include "./include/data_structures/line_trimmer.h"
#include "./include/data_structures/dynamic_array.h"

#define PCRE2_CODE_UNIT_WIDTH 8
#include <stdio.h>
#include <string.h>
#include <pcre2.h>

void run(void *data)
{

  printf("Data in array is: %f \n", *(float *)data);
}

void arr_setter(void *void_buffer, int index, void *data)
{
  float *buffer = (float *)void_buffer;
  *(buffer + index) = *(float *)data;
}

void *arr_getter(void *void_buffer, int index)
{
  float *buffer = (float *)void_buffer;
  return buffer + index;
}

int main()
{
  // read_file("test/vars/number.txt");
  // read_file("test/vars/string.txt");
  // read_file("test/vars/functions.txt");
  FILESTREAM *file_stream = open_file("test/vars/functions.txt");
  load_file_contents(file_stream);
  // print_file_contents(file_stream);

  remove_empty_lines(file_stream);
  // printf(get_current_line(file_stream));
  // printf(get_next_line(file_stream));
  // printf(get_next_line(file_stream));
  // printf(get_next_line(file_stream));
  // printf(get_next_line(file_stream));
  // printf(get_previous_line(file_stream));
  // printf(get_next_line(file_stream));
  printf("Number of lines cached %d \n", file_stream->numberOfLines);

  // Dynamic array testing

  DYNAMIC_ARRAY *arr = create_array_DA(sizeof(float), arr_getter, arr_setter);
  float number = 10.5;
  push_DA(arr, &number);
  push_DA(arr, &number);
  push_DA(arr, &number);

  float new_num = 3.173;
  add_DA(arr, &new_num);
  float *element = get_at_index_DA(arr, 3);
  printf("Got element at index %d: %f \n", 3, *element);
  for_each_DA(arr, run);
  printf(" 1 Dynamic array size: %d length: %d \n", arr->buffer_size, arr->length);
  insert_at_index_DA(arr, 3, &number);
  insert_at_index_DA(arr, 3, &number);

  for_each_DA(arr, run);

  printf("2 Dynamic array size: %d length: %d \n", arr->buffer_size, arr->length);

  remove_at_index_DA(arr, 4);
  remove_at_index_DA(arr, 4);
  pop_DA(arr);
  pop_DA(arr);
  pop_DA(arr);
  for_each_DA(arr, run);

  printf("3 Dynamic array size: %d length: %d \n", arr->buffer_size, arr->length);

  return 0;
}