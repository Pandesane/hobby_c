#include "data_structures/linked_list.h"
#include <stdlib.h>
#include <stdio.h>

LINKED_LIST_HEADER *create_linked_list(int element_size, LIST_GET linked_list_item_getter, LIST_SET linked_list_item_setter)
{
  LINKED_LIST_HEADER *linked_list_header = (LINKED_LIST_HEADER *)malloc(sizeof(LINKED_LIST_HEADER));
  linked_list_header->element_size = element_size;
  linked_list_header->length = 0;
  linked_list_header->linked_list_item_getter = linked_list_item_getter;
  linked_list_header->linked_list_item_setter = linked_list_item_setter;
  // Point the start to null
  linked_list_header->start = 0;
  return linked_list_header;
}

LINKED_LIST *last_linked_list(LINKED_LIST_HEADER *list)
{
  LINKED_LIST *start_list_item = list->start;
  if (start_list_item->isAtEnd)
  {
    return start_list_item;
  }

  int index = 0;
  LINKED_LIST *last_list = start_list_item;
  while (index <= list->length - 1)
  {
    printf("While current list data: %d\n", *(int *)last_list->data);
    if (last_list->isAtEnd == 1)
    {
      // return last_list.prev_list_item->next_list_item;
      return last_list;
    }
    else if (last_list->next_list_item == 0)
    {
      return last_list;
    }
    printf("Trying to get the next list item: \n");
    last_list = (last_list->next_list_item);
    index++;
  }

  return last_list;
}
LINKED_LIST *first_linked_list(LINKED_LIST_HEADER *list)
{
  if (list->length > 0)
  {
    return list->start;
  }

  return 0;
}

LINKED_LIST *get_previous_linked_list(LINKED_LIST *list_item)
{
  if (list_item->isAtStart)
  {
    return list_item;
  }
  return list_item->prev_list_item;
}
LINKED_LIST *get_next_linked_list(LINKED_LIST *list_item)
{
  if (list_item->isAtEnd)
  {
    return list_item;
  }

  return list_item->next_list_item;
}

void add_to_linked_list(LINKED_LIST_HEADER *list, void *element)
{
  LINKED_LIST *new_item = (LINKED_LIST *)malloc(sizeof(LINKED_LIST));
  // void * element_buffer = malloc(list->element_size);

  if (list->length == 0)
  {
    // Passes in the LINKED_LIST void *
    list->linked_list_item_setter(new_item, element);
    new_item->isAtStart = 1;
    new_item->isAtEnd = 1;
    new_item->prev_list_item = 0;
    new_item->next_list_item = 0;
    list->start = new_item;
  }
  else
  {
    list->linked_list_item_setter(new_item, element);
    LINKED_LIST *last_list_item = last_linked_list(list);
    if (last_linked_list == 0)
    {
      printf("Error: Last list is 0 \n");
      return;
    }
    last_list_item->next_list_item = new_item;
    last_list_item->isAtEnd = 0;
    new_item->prev_list_item = last_list_item;

    new_item->isAtEnd = 1;
  }

  list->length++;

  // element_buffer = element;
}

// Stack functions
void push_list(LINKED_LIST_HEADER *list, void *data)
{
  add_to_linked_list(list, data);
}
LINKED_LIST *pop_list(LINKED_LIST_HEADER *list)
{
  if ((list->length) == 0)
  {
    return 0;
  }
  LINKED_LIST *last_list_item = (LINKED_LIST *)last_linked_list(list);

  if (last_list_item->isAtStart)
  {

    list->start = 0;
    list->length = 0;

    return last_list_item;
  }
  LINKED_LIST *prev_list_item = last_list_item->prev_list_item;
  // int *null = 0;
  prev_list_item->next_list_item = 0;
  ;
  prev_list_item->isAtEnd = 1;
  // printf("Prev item data : %d\n", *(int *)prev_list_item->data);

  last_list_item->prev_list_item = (LINKED_LIST *)NULL;
  last_list_item->next_list_item = (LINKED_LIST *)NULL;
  list->length--;

  return last_list_item;
}

// Queue functions
void enqueue_list(LINKED_LIST_HEADER *list, void *data)
{
  add_to_linked_list(list, data);
}
LINKED_LIST *deque_list(LINKED_LIST_HEADER *list)
{
  if ((list->length) == 0)
  {
    return 0;
  }
  LINKED_LIST *start_list_item = list->start;

  if (list->length == 1)
  {

    list->start = 0;
    list->length = 0;

    return start_list_item;
  }
  LINKED_LIST *next_list_item = start_list_item->next_list_item;
  next_list_item->prev_list_item = 0;
  next_list_item->isAtStart = 1;
  start_list_item->next_list_item = 0;
  start_list_item->prev_list_item = 0;
  printf("Start item data : %d\n", *(int *)next_list_item->data);

  list->length--;
  return start_list_item;
}
