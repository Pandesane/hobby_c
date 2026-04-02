#include <stdio.h>
#include "./regex_number.h"
#include "./string.h"
#include "convert.h"

void write_file(char *filename, char *data)
{
  FILE *fptr;

  // 1. Open file in "w" (write) mode
  fptr = fopen(filename, "a");

  // 2. Check if the file opened successfully
  if (fptr == NULL)
  {
    printf("Error opening file!\n");
    return;
  }

  // 3. Write data to the file
  // fprintf(fptr, "Hello, this is a test.\n");
  // fputs("This is another line using fputs.\n", fptr);
  fputs(data, fptr);

  // 4. Close the file
  fclose(fptr);
}



void read_file(char *filename)
{
  FILE *fptr;
  char buffer[100];

  // 1. Open file in read ("r") mode
  fptr = fopen(filename, "r");

  // 2. Error handling: Check if file exists
  if (fptr == NULL)
  {
    perror("Error opening file");
  }

  // 3. Read content line-by-line
  while (fgets(buffer, 100, fptr))
  {
    char **split_line = (char **)malloc(2 * sizeof(char *));
    ;

    if (match_string("=", buffer))
    {
      split_string(split_line, buffer, "=");
      char *c_code = convert_line_to_c_code(split_line[0], split_line[1]);
      write_file("test/compiled_c/string.c", c_code);
    }
  }

  // 4. Close the file
  fclose(fptr);
}


