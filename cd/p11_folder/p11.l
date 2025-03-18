%{
    #include<stdio.h>
    #include<stdlib.h>
    #include "p11.tab.h"
 
    extern int yylval;
%}
 
%%
 
[0-9]+      { yylval = atoi(yytext); return NUMBER; }
[\t ]+      ;  /* Ignore spaces and tabs */
\n          { return 0; }  /* End of input */
.           { return yytext[0]; }  /* Return other characters as they are */
 
%%
 
int yywrap() {
    return 1;
}