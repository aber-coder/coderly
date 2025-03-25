#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_TAC(char *exp);

int addr = 100;

int main() {
    int ch;
    char exp[50], id1[10], op[5], id2[10];

    while (1) {
        printf("\n1. Assignment\n2. Arithmetic\n3. Relational\n4. Exit\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter expression with assignment operator: ");
                scanf("%s", exp);
                generate_TAC(exp);
                break;

            case 2:
                printf("Enter expression with arithmetic operator: ");
                scanf("%s", exp);
                printf("Three Address Code:\ntemp = %s\n", exp);
                break;

            case 3:
                printf("Enter relational expression (e.g., a < b): ");
                scanf("%s %s %s", id1, op, id2);

                if (strchr("<>!=", op[0])) {  
                    printf("\n%d\tif %s %s %s goto %d", addr, id1, op, id2, addr + 3);
                    printf("\n%d\tT := 0", ++addr);
                    printf("\n%d\tgoto %d", ++addr, addr + 2);
                    printf("\n%d\tT := 1\n", ++addr);
                    addr++;
                } else {
                    printf("Invalid relational operator.\n");
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}

void generate_TAC(char *exp) {
    char *eq = strchr(exp, '=');
    if (!eq) {
        printf("Invalid assignment expression.\n");
        return;
    }
    char lhs[20], rhs[20];
    strncpy(lhs, exp, eq - exp);
    lhs[eq - exp] = '\0';
    strcpy(rhs, eq + 1);
    printf("Three Address Code:\ntemp = %s\n%s = temp\n", rhs, lhs);
}

