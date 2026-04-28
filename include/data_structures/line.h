#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "data_structures/dynamic_array.h"

#ifndef LINE_H
#define LINE_H

typedef char *LINE;
void line_arr_printer(void *data);

void line_arr_setter(void *void_buffer, int index, void *data);

void *line_arr_getter(void *void_buffer, int index);



void char_arr_printer(void *data);

void char_arr_setter(void *void_buffer, int index, void *data);

void *char_arr_getter(void *void_buffer, int index);
char * convert_to_cstr(DYNAMIC_ARRAY *arr);
DYNAMIC_ARRAY *new_dynamic_arr();
#endif