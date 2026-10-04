#include <stdio.h>
#include <string.h>

int main() {
    char nonTerminal, alpha[10], beta[10];

    printf("Enter Non-Terminal (A): ");
    scanf(" %c", &nonTerminal);

    printf("Enter alpha (for A->Aα  ): ");
    scanf("%s", alpha);

    printf("Enter beta (for A->β): ");
    scanf("%s", beta);

    printf("\nGrammar after removing left recursion:\n");

    // A → βA'
    printf("%c -> %s%c'\n", nonTerminal, beta, nonTerminal);

    // A' → αA' | ε
    printf("%c' -> %s%c' | ε\n", nonTerminal, alpha, nonTerminal);

    return 0;
}