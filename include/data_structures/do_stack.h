#include "./dynamic_array.h"
#include <stdio.h>

#ifndef DO_STACK_H
#define DO_STACK_H
// Run when the do_block is popped from the cache_stack before pushing it into the processing queue
typedef char **(*GENERATE_CODE)();

typedef struct do_block
{
  char *type;
  char *name;
  int line_start_index;
  int line_end_index;
  DYNAMIC_ARRAY *line_expressions;
  struct block *inside_blocks;
  // RUN preprocess;
  void (*preprocess)(DYNAMIC_ARRAY *arr, struct do_block *, int current_index);
  GENERATE_CODE generate_code;
} DO_STACK;
// typedef struct block DO_STACK;

void do_stack_arr_printer(void *data);

void do_stack_arr_setter(void *void_buffer, int index, void *data);

void *do_stack_arr_getter(void *void_buffer, int index);

#endif