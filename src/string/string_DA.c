#include "string/string_DA.h"
#include "data_structures/line_trimmer.h"

DYNAMIC_ARRAY *create_char_DA(char *string)
{
  DYNAMIC_ARRAY *arr = create_array_DA(sizeof(char), char_arr_getter, char_arr_setter);

  while (*string != '\0')
  {
    char c = *string;
    push_DA(arr, &c);

    string++;
  }

  return arr;
}

void trim_char_DA(DYNAMIC_ARRAY *arr)
{
  int index = 0;
  int beforeChar = 0;

  while (has_next_element(arr, index) && !beforeChar)
  {

    char c = *(char *)get_at_index_DA(arr, index);
    if (c == ' ')
    {
      remove_at_index_DA(arr, index);
    }
    else
    {
      beforeChar = 1;
    }
    index++;
  }

  int afterChar = 0;
  index = arr->length - 1;

  while (has_next_element(arr, index) && !afterChar)
  {

    char c = *(char *)get_at_index_DA(arr, index);
    if (c == ' ')
    {
      remove_at_index_DA(arr, index);
    }
    else
    {
      afterChar = 1;
    }
    index--;
  }
}

SPLIT_DA split(DYNAMIC_ARRAY *arr, char delimeter)
{
  trim_char_DA(arr);

  // for_each_DA(arr, char_arr_printer);
    printf("In array length: [%d]\n", arr->length);


  SPLIT_DA splits;
  splits.length = 0;

  int index = 0;
  int split_index = 0;
  // char last_c = *(char *)last_DA(arr);

  while (has_next_element(arr, index))
  {

    char c = *(char *)get_at_index_DA(arr, index);
    if (c == delimeter)
    {
      printf("current [s=%d, i=%d]\n", split_index, index);
      DYNAMIC_ARRAY *sub_arr = get_sub_arr_DA(arr, split_index, index -1 );
      for_each_DA(sub_arr, char_arr_printer);
      split_index = index + 1;
      splits.arrays[splits.length] = sub_arr;
      splits.length++;
    }
    else
    {
    }
    index++;
  }

  // Get the last split array
  printf("current [s=%d, i=%d]\n", split_index, index);
  DYNAMIC_ARRAY *sub_arr = get_sub_arr_DA(arr, split_index, index-1);
  for_each_DA(sub_arr, char_arr_printer);
  // split_index = index + 1;
  splits.arrays[splits.length] = sub_arr;

  // insert_at_index_DA(sub_arr, index-1, &last_c);

  splits.length++;

  return splits;
}

DYNAMIC_ARRAY *merge(DYNAMIC_ARRAY *first, DYNAMIC_ARRAY *second, char delimeter)
{
  DYNAMIC_ARRAY *new_arr = create_array_DA(first->element_size, first->arr_getter_function, first->arr_setter_function);
  int first_index = 0;
  printf("First array length %d \n", first->length);
  printf("Second array length %d \n", second->length);
  printf("New  array length %d \n", new_arr->length);

  while (has_next_element(first, first_index))
  {

    char data = *(char *)get_at_index_DA(first, first_index);
    push_DA(new_arr, &data);
    first_index++;
  }

  // Push the delimeter
  push_DA(new_arr, &delimeter);

  int second_index = 0;
  while (has_next_element(second, second_index))
  {

    void *data = get_at_index_DA(second, second_index);
    push_DA(new_arr, data);
    second_index++;
  }

  return new_arr;
}
