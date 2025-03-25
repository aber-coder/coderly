%{
#include "exp12a.tab.h" 
%}

%%

"="        { printf("\nOperator is EQUAL\n"); }
"+"        { printf("\nOperator is PLUS\n"); }
"-"        { printf("\nOperator is MINUS\n"); }
"/"        { printf("\nOperator is DIVISION\n"); }
"*"        { printf("\nOperator is MULTIPLICATION\n"); }
[a-zA-Z][a-zA-Z0-9]* { 
    printf("\nIdentifier is %s\n", yytext);
    return ID; 
}
[ \t\n\r]+   { /* skip whitespace */ }
.           { return yytext[0]; }

%%

int yywrap() {
    return 1;
}
