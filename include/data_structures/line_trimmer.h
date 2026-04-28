#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./file_stream_types.h"
#include "./file_stream.h"
#include <ctype.h>
#include "string/libstring.h"
#include "event_stack.h"

// File operates on the line array by
/*
remove_empty_lines(FILESTREAM*, line_number)
*/

#ifndef LINE_TRIMMER_H
#define LINE_TRIMMER_H
void remove_empty_lines(FILESTREAM *file_stream);
void remove_comment_lines(FILESTREAM *file_stream);
int event_stack_callback(DYNAMIC_ARRAY *arr, void *element, int *in_parenthesis);
char *remove_inline_and_trailing_spaces(char *line);
char *get_block_name(char *line);

#endif