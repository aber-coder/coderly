#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *string;

const string keywords[] = {
    "int", "float", "if", "else", "while", "return", "void", "for",
    "char", "double", "long", "short", "signed", "struct",
     "goto", "continue", "break", "switch", "case",
    "default", "sizeof", "typedef", "const"};
const string delimiters = " ;,(){}[]\n\t+-*/=<>!&|";
const string operators = "+-*/=<>!&|";

bool isDelimiterOrOperator(const char ch)
{
  return strchr(delimiters, ch) != NULL;
}

bool isOperator(const char ch)
{
  return strchr(operators, ch) != NULL;
}

bool isAllDigits(const string str)
{
  for (int i = 0; str[i] != '\0'; i++)
  {
    if (!isdigit(str[i]))
    {
      return false;
    }
  }
  return true;
}

bool isReal(const string str)
{
  int dot_count = 0;
  for (int i = 0; str[i] != '\0'; i++)
  {
    if (str[i] == '.')
    {
      dot_count++;
      if (dot_count > 1)
      {
        return false;
      }
    }
    else if (!isdigit(str[i]))
    {
      return false;
    }
  }
  return dot_count == 1;
}

bool isKeyword(const string str)
{
  size_t len = sizeof(keywords) / sizeof(keywords[0]);
  for (size_t i = 0; i < len; i++)
  {
    if (strcmp(keywords[i], str) == 0)
    {
      return true;
    }
  }
  return false;
}

bool isValidIdentifer(const string str)
{
  if (isDelimiterOrOperator(str[0]) || isdigit(str[0]))
  {
    return false;
  }
  for (int i = 0; str[i] != '\0'; i++)
  {
    if (!isalpha(str[i]) && str[i] != '_' && !isdigit(str[i]))
    {
      return false;
    }
  }
  return true;
}

char *substr(const string start, const string end)
{
  int len = end - start;
  char *substring = (char *)malloc(len + 1);
  strncpy(substring, start, len);
  substring[len] = '\0';
  return substring;
}

void parse(const string input)
{
  string str = input;
  string start = NULL;

  while (*str)
  {
    if (isDelimiterOrOperator(*str))
    {
      if (isOperator(*str))
      {
        printf("%c is an operator\n", *str);
      }
      else
      {
        printf("'%c' is a delimiter\n", *str);
      }
      str++;
    }
    else
    {
      start = str;
      while (*str && !isDelimiterOrOperator(*str))
      {
        str++;
      }
      string substring = substr(start, str);
      if (isKeyword(substring))
      {
        printf("%s is a keyword\n", substring);
      }
      else if (isAllDigits(substring))
      {
        printf("%s is an integer\n", substring);
      }
      else if (isReal(substring))
      {
        printf("%s is a real number\n", substring);
      }
      else if (isValidIdentifer(substring))
      {
        printf("%s is an identifier\n", substring);
      }
      else
      {
        printf("%s is not a valid identifier\n", substring);
      }
      free(substring);
    }
  }
}

int main()
{
  const string input = "int a = b + 1.23 +2c;";
  parse(input);
  return 0;
}