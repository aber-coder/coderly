#include <stdio.h>

char *ip;
char string[50];

int E(), Edash(), T(), Tdash(), F();
void action(char *rule) { printf("%s\t%s \n", ip, rule); }

int main() {
  printf("Enter the string\n");
  scanf("%s", string);
  ip = string;

  printf("\n\nInput\tAction\n--------------------------------\n");
  if (E() && *ip == '\0') {
    printf("\n--------------------------------\n");
    printf("\n String is successfully parsed\n");
  } else {
    printf("\n--------------------------------\n");
    printf("Error in parsing String\n");
  }
}

int E() {
  action("E->TE'");
  return T() && Edash();
}

int Edash() {
  if (*ip == '+') {
    action("E'->+TE'");
    ip++;
    return T() && Edash();
  }
  action("E'->^");
  return 1;
}

int T() {
  action("T->FT'");
  return F() && Tdash();
}

int Tdash() {
  if (*ip == '*') {
    action("T'->*FT'");
    ip++;
    return F() && Tdash();
  }
  action("T'->^");
  return 1;
}

int F() {
  if (*ip == '(') {
    action("F->(E)");
    ip++;
    return E() && (*ip == ')' ? (ip++, 1) : 0);
  } else if (*ip == 'i') {
    ip++;
    action("F->id");
    return 1;
  }
  return 0;
}
