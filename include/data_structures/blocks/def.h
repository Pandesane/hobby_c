
#include "../do_stack.h"
#include <stdlib.h>
#include <stdio.h>
#include "data_structures/line.h"
#include "data_structures/line_trimmer.h"

#ifndef DEF_H
#define DEF_H

// typedef struct block
// {
//   char *type;
//   char *name;
//   int start_index;
//   int end_index;
//   DYNAMIC_ARRAY *line_expressions;
//   struct block *inside_blocks;

// } DO_STACK;


char *convert_def_arg_to_c_arg  (  DYNAMIC_ARRAY *arr);
// IN -- def greet(name: string, age: number) do
// OUT -- ANY_T greet(string name, Number age)
void process_def_block_header(char *def_header);
void def_preprocessor(DYNAMIC_ARRAY *line_arr, DO_STACK *me_do_stack, int current_index);
DO_STACK *create_def_do_stack_block(int line_start_index);

#endif
