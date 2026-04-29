

#ifndef LINKED_LIST_H
#define LINKED_LIST_H



// List getter functions usage examples for an integer
// void *getter_for_int_linked_list(void *linked_list_buffer)
// {
//   printf("Running getter for linked_list \n");
//   LINKED_LIST *list_item = (LINKED_LIST *)linked_list_buffer;
//   return (int *)list_item->data;
// }
// void setter_for_int_linked_list(void *linked_list_buffer, void *data)
// {
//   LINKED_LIST *list_item = (LINKED_LIST *)linked_list_buffer;
//   int *int_data = malloc(sizeof(int));
//   *int_data = *(int *)data;
//   printf("Setting data of %d \n", *int_data);
//   list_item->data = int_data;
//   list_item->next_list_item = 0;
// }

typedef void *(*LIST_GET)(void *linked_list_buffer);
typedef void (*LIST_SET)(void *linked_list_buffer, void *data);

typedef struct list
{
  void *data;
  //  ADD GETTER AND SETTER

  struct list *prev_list_item;
  struct list *next_list_item;

  int isAtStart;
  int isAtEnd;
} LINKED_LIST;

typedef struct
{
  int element_size;
  int length;
  LIST_GET linked_list_item_getter;
  LIST_SET linked_list_item_setter;
  LINKED_LIST *start;
} LINKED_LIST_HEADER;

// A linked list is good for iteration in recursive functions
// CReate a linked list head
LINKED_LIST_HEADER *create_linked_list(int element_size, LIST_GET linked_list_item_getter,
                                       LIST_SET linked_list_item_setter);

void add_to_linked_list(LINKED_LIST_HEADER *list, void *element);
LINKED_LIST *get_previous_linked_list(LINKED_LIST *list);
LINKED_LIST *get_next_linked_list(LINKED_LIST *list);
// void *get_previous_linked_list_data(LINKED_LIST *list);
// void *get_next_linked_list_data(LINKED_LIST *list);
void push_list(LINKED_LIST_HEADER * list , void * data);
LINKED_LIST * pop_list(LINKED_LIST_HEADER * list);
void enqueue_list(LINKED_LIST_HEADER * list , void * data);
LINKED_LIST * deque_list(LINKED_LIST_HEADER * list);


// int isLastList(LINKED_LIST *list);
// int isFirstList(LINKED_LIST *list);
LINKED_LIST *last_linked_list(LINKED_LIST_HEADER *list);
LINKED_LIST *first_linked_list(LINKED_LIST_HEADER *list);

// get_prev_item next_list_item
// create linked list returns the list head

#endif
