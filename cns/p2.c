#include <stdio.h>

#define OP(str, op) { \
    for (int i = 0; str[i]; i++) \
        printf("%c", str[i] op 127); \
    printf("\n"); \
}

int main() {
    char *str = "HELLO WORLD";
    printf("AND\n"); OP(str, &);
    printf("OR\n");  OP(str, |);
    printf("XOR\n"); OP(str, ^);
    return 0;
}
