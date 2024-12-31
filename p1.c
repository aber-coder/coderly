#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "tokens.c"

bool isDelimiter(char ch)
{
    return strchr(delimiters, ch) != NULL;
}

bool isOperator(char ch)
{
    return strchr(operators, ch) != NULL;
}

bool validIdentifier(char *str)
{
    if (isdigit(str[0]) || isDelimiter(str[0]))
    {
        return false;
    }
    return true;
}

bool isKeyword(char *str)
{
    int n = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(keywords[i], str) == 0)
            return true;
    }
    return false;
}

bool isInteger(char *str)
{
    int i, len = strlen(str);
    if (len == 0)
        return false;
    for (i = 0; i < len; i++)
        if (!isdigit(str[i]))
            return false;

    return true;
}

bool isRealNumber(char *str)
{
    if (*str == '-')
        str++;
    bool hasDecimal = false;
    while (*str)
    {
        if (*str == '.')
        {
            if (hasDecimal)
                return false;
            hasDecimal = true;
        }
        else if (!isdigit(*str))
        {
            return false;
        }
        str++;
    }
    return hasDecimal;
}

char *subString(const char *str, const char *start, const char *end)
{
    int length = end - start;
    char *subStr = (char *)malloc(length + 1);
    strncpy(subStr, start, length);
    subStr[length] = '\0';
    return subStr;
}

void parse(const char *input)
{
    const char *str = input;
    const char *start;

    while (*str != '\0')
    {
        if (!isDelimiter(*str))
        {
            start = str;
            while (*str != '\0' && !isDelimiter(*str))
            {
                str++;
            }

            char *subStr = subString(input, start, str);

            if (isKeyword(subStr))
            {
                printf("'%s' IS A KEYWORD\n", subStr);
            }
            else if (isInteger(subStr))
            {
                printf("'%s' IS AN INTEGER\n", subStr);
            }
            else if (isRealNumber(subStr))
            {
                printf("'%s' IS A REAL NUMBER\n", subStr);
            }
            else if (validIdentifier(subStr))
            {
                printf("'%s' IS A VALID IDENTIFIER\n", subStr);
            }
            else
            {
                printf("'%s' IS NOT A VALID IDENTIFIER\n", subStr);
            }

            free(subStr);
        }
        else
        {
            if (isOperator(*str))
            {
                printf("'%c' IS AN OPERATOR\n", *str);
            }
            str++;
        }
    }
}

int main()
{

    const char *str = "int a = b + 1.23 +2c; ";
    parse(str);
    return 0;
}
