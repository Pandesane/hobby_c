#include "data_structures/dynamic_array.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

DYNAMIC_ARRAY *create_array_DA(int element_size, GET arr_getter_fun, SET arr_setter_fun)
{
  int initial_buffer_size = 5;
  // printf("Created buffer size by malloc: %d", element_size * initial_buffer_size);
  void *buffer = malloc(element_size * initial_buffer_size);

  DYNAMIC_ARRAY *arr = (DYNAMIC_ARRAY *)malloc(sizeof(DYNAMIC_ARRAY));
  arr->buffer = buffer;
  arr->buffer_size = initial_buffer_size;
  arr->element_size = element_size;
  arr->_current_insert_index = 0;
  arr->arr_setter_function = arr_setter_fun;
  arr->arr_getter_function = arr_getter_fun;
  return arr;
}

DYNAMIC_ARRAY *create_static_array_DA(int element_size, int length, GET arr_getter_fun, SET arr_setter_fun)
{
  int initial_buffer_size = length;
  // printf("Created buffer size by malloc: %d", element_size * initial_buffer_size);
  void *buffer = malloc(element_size * initial_buffer_size);

  DYNAMIC_ARRAY *arr = (DYNAMIC_ARRAY *)malloc(sizeof(DYNAMIC_ARRAY));
  arr->buffer = buffer;
  arr->is_static_arr = 1;
  arr->buffer_size = initial_buffer_size;
  arr->element_size = element_size;
  arr->_current_insert_index = 0;
  arr->arr_setter_function = arr_setter_fun;
  arr->arr_getter_function = arr_getter_fun;
  return arr;
}

// Stack functions
void push_DA(DYNAMIC_ARRAY *arr, void *data)
{
  add_DA(arr, data);
}
void pop_DA(DYNAMIC_ARRAY *arr)
{
  remove_at_index_DA(arr, arr->length - 1);
}

// Queue like properties
void enqueue_DA(DYNAMIC_ARRAY *arr, void *data)
{
  add_DA(arr, data);
}
void dequeue_DA(DYNAMIC_ARRAY *arr)
{
  remove_at_index_DA(arr, 0);
}

// List Function properties
void add_DA(DYNAMIC_ARRAY *arr, void *data)
{
  arr->arr_setter_function(arr->buffer, arr->_current_insert_index, data);
  arr->length = arr->_current_insert_index + 1;
  arr->_current_insert_index++;
  _grow_buffer_DA(arr);
}

void for_each_DA(DYNAMIC_ARRAY *arr, VoidFunction fn)
{
  for (int i = 0; i < arr->length; i++)
  {
    void *data = arr->arr_getter_function(arr->buffer, i);
    fn(data);
  }
}

void *get_at_index_DA(DYNAMIC_ARRAY *arr, int index)
{
  if (arr->length > index && index >= 0)
  {
    return arr->arr_getter_function(arr->buffer, index);
  }
  else
  {
    // printf("Returning nil of 0 index: %d and length: %d \n", index, arr->length);
    return 0;
  }
}

void insert_at_index_DA(DYNAMIC_ARRAY *arr, int index, void *new_data)
{
  if (arr->length > index && index >= 0)
  {
    // First shift copy the elements to a higher index
    for (int i = arr->length; i > index; i--)
    {
      // int put_at = i + 1;
      int get_prev_index_data = i - 1;
      void *data = arr->arr_getter_function(arr->buffer, get_prev_index_data);
      arr->arr_setter_function(arr->buffer, i, data);
    }
    // Then replace the element at that given index
    arr->arr_setter_function(arr->buffer, index, new_data);
    // Do clean up
    arr->length++;
    arr->_current_insert_index = arr->length - 1;
    _grow_buffer_DA(arr);
  }
}

void remove_at_index_DA(DYNAMIC_ARRAY *arr, int index)
{
  if (arr->length > index && index >= 0)
  {
    // shift all elements in the arr to that index and
    for (int i = index; i < arr->length - 1; i++)
    {
      int start_at = i + 1;
      void *data = arr->arr_getter_function(arr->buffer, start_at);
      arr->arr_setter_function(arr->buffer, i, data);
    }
    arr->length--;
    arr->_current_insert_index = arr->length - 1;
    _shrink_buffer_DA(arr);
  }
}
int has_next_element(DYNAMIC_ARRAY *arr, int index)
{
  if (arr->length > index && index >= 0)
  {
    return 1;
  }
  return 0;
}
void _grow_buffer_DA(DYNAMIC_ARRAY *arr)

{
  if (arr->is_static_arr == 1)
  {
    printf("Gotten a static array \n");
    return;
  }
  // Grow buffer when the length items are more than a half of the buffer size

  if (arr->length > arr->buffer_size / 2)
  {
    printf("Growing buffer \n");
    int new_buffer_size = arr->buffer_size * 2;
    void *new_buffer = malloc(arr->element_size * new_buffer_size);
    for (int i = 0; i < arr->length; i++)
    {
      void *data = arr->arr_getter_function(arr->buffer, i);
      arr->arr_setter_function(new_buffer, i, data);
    }
    free(arr->buffer);
    arr->buffer = new_buffer;
    arr->buffer_size = new_buffer_size;
  }
}

void _shrink_buffer_DA(DYNAMIC_ARRAY *arr)
{
  if (arr->is_static_arr == 1)
  {
    return;
  }

  // Shrink buffer when the length items are less than a third of the buffer size
  if (arr->length < arr->buffer_size / 3)
  {
    printf("Shrinking buffer \n");
    int new_buffer_size = arr->buffer_size / 2;
    void *new_buffer = malloc(arr->element_size * new_buffer_size);
    for (int i = 0; i < arr->length; i++)
    {
      void *data = arr->arr_getter_function(arr->buffer, i);
      arr->arr_setter_function(new_buffer, i, data);
    }

    free(arr->buffer);
    arr->buffer = new_buffer;
    arr->buffer_size = new_buffer_size;
  }
}

DYNAMIC_ARRAY *get_sub_arr_DA(DYNAMIC_ARRAY *arr, int start_index, int end_index)
{
  // Create a new array pointer
  // copy the getter and setters
  DYNAMIC_ARRAY *new_arr = create_array_DA(arr->element_size, arr->arr_getter_function, arr->arr_setter_function);

  // Iterate from the main array and get the element at the index and copy its value to a newindex in the new arraey
  int index = start_index;
  while (has_next_element(arr, index) && index <= end_index)
  {
    void *element = get_at_index_DA(arr, index);
    add_DA(new_arr, element);

    index++;
  }

  return new_arr;
}

void free_arr_element_memory(void *data)
{
  free(data);
}

void release_array_memory_DA(DYNAMIC_ARRAY *arr)
{
  for_each_DA(arr, free_arr_element_memory);
  free(arr);
  arr = 0;
}

void fit_array_size_to_length(DYNAMIC_ARRAY *arr)
{
  DYNAMIC_ARRAY *new_arr = create_static_array_DA(arr->element_size, arr->length, arr->arr_getter_function, arr->arr_setter_function);

  // Iterate from the main array and get the element at the index and copy its value to a newindex in the new arraey
  int index = 0;
  while (has_next_element(arr, index))
  {
    void *element = get_at_index_DA(arr, index);
    add_DA(new_arr, element);

    index++;
  }
  release_array_memory_DA(arr);
  *arr = *new_arr;
}