#include <stdio.h>
#include <string.h>
#include "data_structures/do_stack.h"


#ifndef KEYWORDS_H
#define KEYWORDS_H

// typedef struct
// {
//   char *value;
//   int TYPE;

// } KEYWORD_T;

// char *keywords[] = {"def", "defp", "defmodule", "defstruct", "do", "end", "if", "case", "cond"};

typedef enum
{
  unknown_keyword,
  defmodule,
  def,
  defp,
  end
} Block_Keywords;

Block_Keywords switch_char_words(char *word);
void switch_block_keywords(char *word, int index, DYNAMIC_ARRAY * arr, DYNAMIC_ARRAY *do_stack_arr);

void create_do_blocks(DYNAMIC_ARRAY *arr);
#endif