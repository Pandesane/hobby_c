// #include <stdio.h>
// #include <regex.h>
// #include <string.h>
// #include <stdbool.h>
// #include <stdlib.h>
// #define PCRE2_CODE_UNIT_WIDTH 8
// #include <pcre2.h>

// #ifndef REGEX_NUMBER
// #define REGEX_NUMBER 0

// #define INT_REGEX "^([+-]?(0[xX][0-9a-fA-F]+|[1-9][0-9]*|0))$"
// #define FLOAT_REGEX "^([+-]?(([0-9]*\.[0-9]+|[0-9]+\.)([eE][+-]?[0-9]+)?|[0-9]+[eE][+-]?[0-9]+)[fFlL]?)$"
// // #define STRING_REGEX "^\"([^"\\\n]|\\.)*"$"
// #define STRING_REGEX "^\"[a-zA-Z0-9]*\"$"
// bool match_string(char *match, char *string_to_match)
// {

//   pcre2_code *re;
//   PCRE2_SPTR pattern = (PCRE2_SPTR)match; // Your Perl-style regex
//   PCRE2_SPTR subject = (PCRE2_SPTR)string_to_match;
//   int errornumber;
//   PCRE2_SIZE erroroffset;

//   printf("Match %s: Value %s \n", match, string_to_match);

//   bool match_found = false;

//   // 1. Compile pattern (e.g., matching "Hello")
//   re = pcre2_compile(pattern, PCRE2_ZERO_TERMINATED, 0, &errornumber, &erroroffset, NULL);

//   if (re == NULL)
//   {
//     printf("Regex compilation failed\n");
//     match_found = false;
//   }

//   // 2. Perform the match
//   pcre2_match_data *match_data = pcre2_match_data_create_from_pattern(re, NULL);
//   int rc = pcre2_match(re, subject, strlen((char *)subject), 0, 0, match_data, NULL);

//   if (rc < 0)
//   {
//     printf("No match found.\n");
//     match_found = false;
//   }
//   else
//   {
//     printf("Match found!\n");
//     match_found = true;
//   }

//   // 3. Cleanup
//   pcre2_match_data_free(match_data);
//   pcre2_code_free(re);
//   return match_found;
// }

// bool is_integer(char *value)
// {
//   return match_string(INT_REGEX, value);
// }

// bool is_float(char *value)
// {
//   return match_string(FLOAT_REGEX, value);
// }

// bool is_string(char *value)
// {
//   return match_string(STRING_REGEX, value);
// }

// #endif