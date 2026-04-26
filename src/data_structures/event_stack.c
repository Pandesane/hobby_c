
#include "data_structures/event_stack.h"
#include "data_structures/line.h"

EVENT_STACK *create_event_stack(int element_size, EVENT_STACK_CALLBACK event_handler, GET getter, SET setter)
{
  EVENT_STACK *stack = (EVENT_STACK *)malloc(sizeof(EVENT_STACK));

  stack->arr = create_array_DA(element_size, getter, setter);
  stack->in_parenthesis = 0;
  stack->event_handler = event_handler;
  return stack;
}

void add_EVENT_STACK(EVENT_STACK *event_stack, void *element)
{
  int addToArray = event_stack->event_handler(event_stack->arr, element, &event_stack->in_parenthesis);
  if (addToArray)
  {
    add_DA(event_stack->arr, element);
  }
}
void *pop_EVENT_STACK(EVENT_STACK *event_stack)
{
  pop_DA(event_stack->arr);
}

