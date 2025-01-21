#include <stdio.h>
#include <string.h>

int main()
{
    char str[3];
    printf("Enter value to be identified: ");
    scanf("%2s", str);

    if ((str[0] == '&' || str[0] == '|') && str[0] == str[1] || (str[0] == '!' && str[1] == '\0'))
        printf("\nIt is Logical operator");
    else if ((str[0] == '<' || str[0] == '>') && str[1] == str[0] || strchr("&^|", str[0]) && str[1] == '\0')
        printf("\nIt is Bitwise Operator");
    else if (str[0] == '?' && str[1] == ':')
        printf("\nIt is Ternary operator");
    else if ((str[0] == '+' || str[0] == '-') && (str[0] == str[1] || str[1] == '\0'))
        printf("\nIt is Unary operator");
    else if ((str[0] == '=' && str[1] == ' ') || strchr("+-*/%", str[0]) && str[1] == '=')
        printf("\nIt is Assignment operator");
    else if (strchr("+-*/%", str[0]) && str[1] == '\0')
        printf("\nIt is Arithmetic operator");
    else if ((str[0] == '<' || str[0] == '>' || str[0] == '!' || str[0] == '=') && (str[1] == '=' || str[1] == '\0'))
        printf("\nIt is Relational Operator");

    return 0;
}
