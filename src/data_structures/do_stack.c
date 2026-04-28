#include "data_structures/do_stack.h"

void do_stack_arr_printer(void *data)
{
  DO_STACK do_block = *(DO_STACK *)data;
  printf("Data in do_stack is: name: %s  type: %s \n",do_block.name, do_block.type);
}

void do_stack_arr_setter(void *void_buffer, int index, void *data)
{

  DO_STACK *buffer = (DO_STACK *)void_buffer;
  DO_STACK do_block = *(DO_STACK *)data;
  buffer[index] = do_block;
  // printf("Adding do block: %s \n", (&buffer[index])->type);
}

void *do_stack_arr_getter(void *void_buffer, int index)
{
  DO_STACK *buffer = (DO_STACK *)void_buffer;
  // printf("Getting do block: %s \n", (&buffer[index])->type);
  return &buffer[index];
}