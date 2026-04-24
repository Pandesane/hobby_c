// #include <string.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include "./regex_number.h"
// #include "./string.h"

// char *convert_line_to_c_code(char *var_name, char *var_value)
// {
//   // printf("int %s = %s;", var_name, var_value);

//   // 1. Calculate required size: name + value + " = " + ";" + null terminator
//   int size = strlen(var_name) + strlen(var_value) + 5;

//   // 2. Allocate writable memory on the heap
//   char *string = (char *)malloc(size * sizeof(char));

//   if (string == NULL)
//     return NULL; // Always check if malloc failed

//   // 3. Safe to write now
//   trim(var_value);
//   if (is_integer(var_value))
//   {
//     sprintf(string, "int %s = %s;", var_name, var_value);
//   }
//   else if (is_float(var_value))
//   {
//     sprintf(string, "float %s = %s;", var_name, var_value);
//   }
//   else if (is_string(var_value))
//   {
//     sprintf(string, "char * %s = %s;", var_name, var_value);
//   }
//   else
//   {
//     return "";
//   }

//   return string;
// }