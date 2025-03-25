%{
#include <stdio.h>
#include <stdlib.h>
extern int yylex();
extern int yylval;
void yyerror(const char *s);
%}

%token ID

%%

statement:
      ID '=' expression   { printf("\nValid arithmetic expression\n"); }
    | expression           { printf("\nValid arithmetic expression\n"); }
    ;

expression:
      expression '+' ID    { printf("Addition: %s + %s\n", $1, $3); }
    | expression '-' ID    { printf("Subtraction: %s - %s\n", $1, $3); }
    | expression '*' ID    { printf("Multiplication: %s * %s\n", $1, $3); }
    | expression '/' ID    { printf("Division: %s / %s\n", $1, $3); }
    | ID                   { printf("Identifier: %s\n", $1); }
    ;

%%

int main() {
    printf("Enter an expression:\n");
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
