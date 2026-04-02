#include <stdio.h>
#include <regex.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "./include/file.h"

#define PCRE2_CODE_UNIT_WIDTH 8
#include <stdio.h>
#include <string.h>
#include <pcre2.h>

int main()
{
  read_file("test/vars/number.txt");
  read_file("test/vars/string.txt");

  return 0;
}