%{
#include <stdio.h>
#include <string.h>

struct Symbol {
    char name[50];
    char type[20];
    int count;
} symtab[200];

int n = 0;                     // number of symbols
char current_type[20] = "";    // remembers last declared type

void insert_or_update(char *id) {
    for(int i = 0; i < n; i++) {
        if(strcmp(symtab[i].name, id) == 0) {
            symtab[i].count++;
            // If we have a type and this entry has no type yet
            if(current_type[0] != '\0' && strcmp(symtab[i].type, "unknown") == 0)
                strcpy(symtab[i].type, current_type);
            return;
        }
    }
    // New identifier
    strcpy(symtab[n].name, id);
    strcpy(symtab[n].type, current_type[0] != '\0' ? current_type : "unknown");
    symtab[n].count = 1;
    n++;
}

void print_symbol_table() {
    printf("\n\n=================================================\n");
    printf("                  SYMBOL TABLE\n");
    printf("=================================================\n");
    printf("%-15s %-12s %-10s\n", "Identifier", "Type", "Count");
    printf("-------------------------------------------------\n");
    for(int i = 0; i < n; i++) {
        printf("%-15s %-12s %-10d\n", 
               symtab[i].name, symtab[i].type, symtab[i].count);
    }
    printf("=================================================\n");
}
%}

ID      [a-zA-Z_][a-zA-Z0-9_]*

%%

int|float|char|double|boolean|real   { 
    strcpy(current_type, yytext); 
    printf("TYPE: %s\n", yytext); 
}

{ID}    { 
    insert_or_update(yytext);
    printf("IDENTIFIER: %s\n", yytext);
}

";"     { strcpy(current_type, ""); }   // reset type after semicolon

[ \t\n]+   { /* ignore whitespace */ }

.       { /* ignore other characters */ }

%%

int main() {
    printf("=== Symbol Table Generator Started ===\n");
    printf("Paste your code and press Ctrl+D when finished\n");
    printf("--------------------------------------------\n\n");

    yylex();           // start scanning
    print_symbol_table();   // print final table

    return 0;
}

int yywrap() {
    return 1;
}