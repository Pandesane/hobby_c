

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef void *(*GET)(void *buffer, int index);
typedef void (*SET)(void *dynamic_arr, int index, void *data);

typedef struct list
{
  void *data;
  //  ADD GETTER AND SETTER
  int element_size;
  int length;
  struct list *prev_list_item;
  struct list *next_list_item;
  GET linked_list_item_getter;
  SET linked_list_item_setter;
} LINKED_LIST;

// CReate a linked list head
// get_prev_item next_list_item
// create linked list returns the list head


#endif
