
// #define DATA_TYPE int

#ifndef H_DYNAMIC_ARRAY
#define H_DYNAMIC_ARRAY
#define Integer int
#define Float float

typedef void (*VoidFunction)(void *);
typedef void *(*GET)(void *buffer, int index);
typedef void (*SET)(void *dynamic_arr, int index, void *data);

// GETTER AND SETTER FUNC CALL DESIGNs
// void arr_setter(void *void_buffer, int index, void *data)
// {
//   float *buffer = (float *)void_buffer;
//   buffer[index] = chunk;
// }

// void *arr_getter(void *void_buffer, int index)
// {
//   float *buffer = (float *)void_buffer;
//   return buffer[index];
// }
typedef struct
{
  int length;
  void *buffer;
  int element_size;
  int buffer_size;
  int _current_insert_index;
  char *arr_data_type;
  GET arr_getter_function;
  SET arr_setter_function;
  int is_static_arr;

} DYNAMIC_ARRAY;

// Stack like properties
void push_DA(DYNAMIC_ARRAY *arr, void *data);
void* pop_DA(DYNAMIC_ARRAY *arr);
void* first_DA(DYNAMIC_ARRAY *arr);
void* last_DA(DYNAMIC_ARRAY *arr);

// Queue like properties
void enqueue_DA(DYNAMIC_ARRAY *arr, void *data);
void dequeue_DA(DYNAMIC_ARRAY *arr);

// List properties
DYNAMIC_ARRAY *create_array_DA(int element_size, GET arr_getter_fun, SET arr_setter_fun);
DYNAMIC_ARRAY *create_static_array_DA(int element_size,int length, GET arr_getter_fun, SET arr_setter_fun);
void insert_at_index_DA(DYNAMIC_ARRAY *arr, int index, void *data);
void replace_at_index_DA(DYNAMIC_ARRAY *arr, int index, void *data);
void remove_at_index_DA(DYNAMIC_ARRAY *arr, int index);
void *get_at_index_DA(DYNAMIC_ARRAY *arr, int index);
void add_DA(DYNAMIC_ARRAY *arr, void *data);

// For each function call back design
// void run(void *data)
// {
//   printf("Data in array is: %f \n", *(float *)data);
// }
void for_each_DA(DYNAMIC_ARRAY *arr, VoidFunction fn);
void _grow_buffer_DA(DYNAMIC_ARRAY *arr);
void _shrink_buffer_DA(DYNAMIC_ARRAY *arr);
int has_next_element(DYNAMIC_ARRAY *arr, int index);
// Releases a memory chunk all back to the OS
void release_array_memory_DA(DYNAMIC_ARRAY *arr);
// Helps save on memory consumed by the program
void fit_array_size_to_length(DYNAMIC_ARRAY *arr);
DYNAMIC_ARRAY * get_sub_arr_DA(DYNAMIC_ARRAY *, int start_index , int end_index);


#endif