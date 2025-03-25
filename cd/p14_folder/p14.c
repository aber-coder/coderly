#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char op[2], arg1[5], arg2[5], result[5];
    FILE *fp1 = fopen("./input.txt", "r"), *fp2 = fopen("output.txt", "w");
    if (!fp1 || !fp2) return printf("Error opening file.\n"), 1;
    
    while (fscanf(fp1, "%s %s %s %s", op, arg1, arg2, result) == 4) {
        char *inst = strcmp(op, "+") == 0 ? "ADD" : strcmp(op, "-") == 0 ? "SUB" :
                    strcmp(op, "*") == 0 ? "MUL" : strcmp(op, "/") == 0 ? "DIV" : NULL;
        
        if (inst)
            fprintf(fp2, "\nMOV R0, %s\n%s R0, %s\nMOV %s, R0", arg1, inst, arg2, result);
        else if (strcmp(op, "=") == 0)
            fprintf(fp2, "\nMOV R0, %s\nMOV %s, R0", arg1, result);
        else
            fprintf(fp2, "\nInvalid operation: %s", op);
    }
    
    fclose(fp1); fclose(fp2);
    return printf("Assembly code generated in output.txt\n"), 0;
}