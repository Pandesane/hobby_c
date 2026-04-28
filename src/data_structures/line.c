

#include "data_structures/line.h"

void line_arr_printer(void *data)
{

  printf("Data in array is: %s \n", (LINE)data);
}

void line_arr_setter(void *void_buffer, int index, void *data)
{
  LINE chunk = (LINE)malloc(strlen((char *)data) + 1);
  // LINE chunk = malloc(sizeof(char *) * 300);

  strcpy(chunk, (char *)data);
  LINE *buffer = (LINE *)void_buffer;
  // printf("Data  added to array [%d] is: %s ", index, buffer[index]);
  buffer[index] = chunk;
}

void *line_arr_getter(void *void_buffer, int index)
{
  LINE *buffer = (LINE *)void_buffer;
  return buffer[index];
}

void char_arr_printer(void *data)
{
  char c = *(char *)data;
  printf("Data in array is: %c \n", c);
}

void char_arr_setter(void *void_buffer, int index, void *data)
{

  char *buffer = (char *)void_buffer;
  // printf("Data  added to array [%d] is: %s ", index, buffer[index]);
  buffer[index] = *(char *)data;
}

void *char_arr_getter(void *void_buffer, int index)
{
  char *buffer = (char *)void_buffer;
  return &buffer[index];
}

char *convert_to_cstr(DYNAMIC_ARRAY *arr)
{
  char *cstr = malloc(sizeof(char) * (arr->length + 1));

  int index = 0;
  while (has_next_element(arr, index))
  {
    char c = *(char *)get_at_index_DA(arr, index);
    cstr[index] = c;
    index++;
  }

  cstr[arr->length] = '\0';

  return cstr;
}

DYNAMIC_ARRAY *new_dynamic_arr()
{
  return create_array_DA(sizeof(LINE), line_arr_getter, line_arr_setter);
}