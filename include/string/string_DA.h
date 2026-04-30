
#include "../data_structures/dynamic_array.h"

#ifndef STRING_DA_H
#define STRING_DA_H

typedef struct
{
  int length;
  // Given a maximum of 20 dynamic arrays of the same type as an arg
  DYNAMIC_ARRAY *arrays[20];
} SPLIT_DA;

DYNAMIC_ARRAY *create_char_DA(char *string);
void trim_char_DA(DYNAMIC_ARRAY * arr);
SPLIT_DA split(DYNAMIC_ARRAY *arr, char delimeter);
DYNAMIC_ARRAY *merge(DYNAMIC_ARRAY *first, DYNAMIC_ARRAY *second, char delimeter);


#endif