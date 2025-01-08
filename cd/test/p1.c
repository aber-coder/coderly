#include "tokens.c"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char *string;
bool isDelimiter(const char ch) { return strchr(delimiters, ch) != NULL; }
bool isOperator(const char ch) { return strchr(operators, ch) != NULL; }
bool isAllDigits(const char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (!isdigit(str[i])) {
      return false;
    }
  }
  return true;
}
bool isReal(const char *str) {
  if (!isAllDigits(str)) {
    return false;
  }
  int dot_count = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == '.') {
      dot_count++;
      if (dot_count > 1) {
        return false;
      }
    }
  }
  return true;
}
bool isKeyword(const char *str) {
  size_t len = sizeof(keywords) / sizeof(keywords[0]);
  for (int i = 0; i < len; i++) {
    if (strcmp(keywords[i], str) == 0) {
      return true;
    }
  }
  return false;
}
bool isValidIdentifer(const char *str) {
  if (isDelimiter(str[0]) || isdigit(str[0])) {
    return false;
  }
  for (int i = 0; str[i] != '\0'; i++) {
    if (!isalpha(str[i]) && !strcmp(&str[i], "_")) {
      return false;
    }
  }
  return true;
}
char *substr(const char *str, const char *start, const char *end) {
  int len = end - start;
  char *substring = (char *)malloc(len + 1);
  strncpy(substring, str, len);
  substring[len] = '\0';
  return substring;
}
void parse(const char *input) {
  const char *str = input;
  const char *start = NULL;

  while (*str) {
    if (isDelimiter(*str)) {
      if (isOperator(*str)) {
        printf("%c is an operator\n", *str);
      } else {
        printf("%c is a delimiter\n", *str);
      }
      str++;
    } else {
      start = str;
      while (*str && !isDelimiter(*str)) {
        str++;
      }
      char *substring = substr(input, start, str);
      if (isKeyword(substring)) {
        printf("%s is a keyword\n", substring);
      } else if (isAllDigits(substring)) {
        printf("%s is an integer\n", substring);
      } else if (isReal(substring)) {
        printf("%s is a real number\n", substring);
      } else if (isValidIdentifer(substring)) {
        printf("%s is an identifer\n", substring);
      } else {
        printf("%s is not an identifer\n", substring);
      }
      free(substring);
    }
  }
}

int main() {

  const char *input = "int a = b + 1.23 +2c; ";
  parse(input);
  return 0;
}
