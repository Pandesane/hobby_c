// #include <stdio.h>
// #include <ctype.h>

// #ifndef CUSTOM_STRING

// #define CUSTOM_STRING 0

// void split_string(char **tokens, char *line, char *delimeter)
// {
//   char *token = strtok(line, delimeter);
//   int index = 0;

//   while (token != NULL)
//   {
//     printf("%s\n", token);
//     tokens[index] = token;
//     index++;
//     token = strtok(NULL, delimeter); // Subsequent calls
//   }
// }

// void trim(char *str)
// {
//   if (str == NULL)
//     return;

//   int len = strlen(str);
//   int start = 0;
//   int end = len - 1;

//   // 1. Find the first non-whitespace character
//   while (start < len && isspace((unsigned char)str[start]))
//   {
//     start++;
//   }

//   // 2. Find the last non-whitespace character
//   while (end >= start && isspace((unsigned char)str[end]))
//   {
//     end--;
//   }

//   // 3. Shift the string forward to the start of the array
//   int i;
//   for (i = start; i <= end; i++)
//   {
//     str[i - start] = str[i];
//   }

//   // 4. Add the new null terminator
//   str[i - start] = '\0';
// }

// #endif