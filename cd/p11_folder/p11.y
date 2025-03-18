%{
    #include<stdio.h>
    #include<stdlib.h>
    int flag = 0;
    int yylex();
    void yyerror(const char *);
%}
 
%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
 
%%
 
ArithmeticExpression:
    E { printf("\nResult = %d\n", $$); return 0; }
;
 
E:
    E '+' E { $$ = $1 + $3; }
  | E '-' E { $$ = $1 - $3; }
  | E '*' E { $$ = $1 * $3; }
  | E '/' E { 
        if ($3 == 0) { 
            yyerror("Division by zero");
            $$ = 0;
        } else {
            $$ = $1 / $3; 
        }
    }
  | E '%' E { 
        if ($3 == 0) { 
            yyerror("Modulo by zero");
            $$ = 0;
        } else {
            $$ = $1 % $3; 
        }
    }
  | '(' E ')' { $$ = $2; }
  | NUMBER { $$ = $1; }
;
 
%%
 
int main() {
    printf("\nEnter an arithmetic expression:\n");
    yyparse();
    if (flag == 0)
        printf("\nEntered arithmetic expression is Valid\n\n");
    return 0;
}
 
void yyerror(const char *msg) {
    printf("\nError: %s\n", msg);
    flag = 1;
}