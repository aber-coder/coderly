#include <stdio.h>
#include <string.h>

int main() {
  char op[3];
  printf("Enter operator: ");
  scanf("%2s", op);

  if ((strchr("&|", op[0]) && op[0] == op[1]) || (op[0] == '!'))
    puts("Logical operator");
  else if ((strchr("<>", op[0]) && op[0] == op[1]) || strchr("&^|", op[0]))
    puts("Bitwise operator");
  else if (op[0] == '?' && op[1] == ':')
    puts("Ternary operator");
  else if ((strchr("+-", op[0]) && (op[1] == op[0])) || (op[0] == '=') ||
           strchr("+-*/%", op[0]) && op[1] == '=')
    puts("Assignment operator");
  else if (strchr("+-*/%", op[0]))
    puts("Arithmetic operator");
  else if (strchr("<>!=", op[0]) && op[1] == '=')
    puts("Relational operator");

  return 0;
}
