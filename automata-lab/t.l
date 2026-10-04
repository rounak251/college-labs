%{
#include <stdio.h>
%}

DIGIT           [0-9]
LETTER          [a-zA-Z]
ID              ({LETTER}|_)({LETTER}|{DIGIT}|_)*

%%

"if"            { printf("KEYWORD: if\n"); }
"then"          { printf("KEYWORD: then\n"); }
"else"          { printf("KEYWORD: else\n"); }
"do"            { printf("KEYWORD: do\n"); }
"while"         { printf("KEYWORD: while\n"); }

"<"             { printf("RELOP: <\n"); }
"<="            { printf("RELOP: <=\n"); }
"="             { printf("RELOP: =\n"); }
">"             { printf("RELOP: >\n"); }
">="            { printf("RELOP: >=\n"); }
"<>"            { printf("RELOP: <>\n"); }

{DIGIT}+        { printf("INTEGER: %s\n", yytext); }

{ID}            { printf("IDENTIFIER: %s\n", yytext); }

[ \t\n]+        { /* ignore whitespace */ }

.               { printf("UNKNOWN: %s\n", yytext); }

%%

int main(void)
{
    printf("=== Pascal Token Recognizer Started ===\n");
    printf("Type your code (press Ctrl+D to finish)\n");
    printf("----------------------------------------\n");
    yylex();
    printf("\n=== End of Analysis ===\n");
    return 0;
}

int yywrap(void) { return 1; }