

#include "./dynamic_array.h"

#ifndef EVENT_STACK_H
#define EVENT_STACK_H

typedef int (*EVENT_STACK_CALLBACK)(DYNAMIC_ARRAY *arr, void *element, int *in_parenthesis);

typedef struct
{

  EVENT_STACK_CALLBACK event_handler;
  DYNAMIC_ARRAY *arr;
  int in_parenthesis;
} EVENT_STACK;

EVENT_STACK *create_event_stack(int element_size, EVENT_STACK_CALLBACK event_handler, GET getter, SET setter);
void add_EVENT_STACK(EVENT_STACK *event_stack, void *element);
void *pop_EVENT_STACK(EVENT_STACK *event_stack);

#endif