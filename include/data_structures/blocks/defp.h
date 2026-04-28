
#include "../do_stack.h"
#include <stdlib.h>
#include <stdio.h>
#include "data_structures/line.h"
#include "data_structures/line_trimmer.h"

#ifndef DEFP_H
#define DEFP_H

// typedef struct block
// {
//   char *type;
//   char *name;
//   int start_index;
//   int end_index;
//   DYNAMIC_ARRAY *line_expressions;
//   struct block *inside_blocks;

// } DO_STACK;

void defp_preprocessor(DYNAMIC_ARRAY *line_arr, DO_STACK *me_do_stack, int current_index)
{
  printf("Running preprocessor defp \n");
  me_do_stack->line_end_index = current_index;
  me_do_stack->line_expressions = get_sub_arr_DA(line_arr, me_do_stack->line_start_index + 1, current_index - 1);
  me_do_stack->name = (char *)get_block_name((char *)get_at_index_DA(line_arr, me_do_stack->line_start_index));
  for_each_DA(me_do_stack->line_expressions, line_arr_printer);
}

DO_STACK *create_defp_do_stack_block(int line_start_index)
{
  DO_STACK *defmodule_block = (DO_STACK *)malloc(sizeof(DO_STACK));
  defmodule_block->line_start_index = line_start_index;
  defmodule_block->type = "defp";
  defmodule_block->preprocess = defp_preprocessor;

  return defmodule_block;
}

#endif
