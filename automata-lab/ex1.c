#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 10

char productions[MAX][MAX];
char first[MAX][MAX], follow[MAX][MAX];
int n;

// Function to add symbol to set
void addToSet(char set[], char c) {
    for (int i = 0; set[i]; i++)
        if (set[i] == c)
            return;
    int len = strlen(set);
    set[len] = c;
    set[len + 1] = '\0';
}

// FIRST function
void findFirst(char c, int index) {
    if (!isupper(c)) {
        addToSet(first[index], c);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (productions[i][0] == c) {
            if (productions[i][2] == '#') {
                addToSet(first[index], '#');
            } else {
                findFirst(productions[i][2], index);
            }
        }
    }
}

// FOLLOW function
void findFollow(char c, int index) {
    if (productions[0][0] == c)
        addToSet(follow[index], '$');

    for (int i = 0; i < n; i++) {
        for (int j = 2; productions[i][j]; j++) {
            if (productions[i][j] == c) {
                if (productions[i][j + 1] != '\0') {
                    if (!isupper(productions[i][j + 1])) {
                        addToSet(follow[index], productions[i][j + 1]);
                    } else {
                        int k;
                        for (k = 0; k < n; k++) {
                            if (productions[k][0] == productions[i][j + 1]) {
                                for (int l = 0; first[k][l]; l++) {
                                    if (first[k][l] != '#')
                                        addToSet(follow[index], first[k][l]);
                                }
                            }
                        }
                    }
                } else {
                    if (productions[i][0] != c)
                        findFollow(productions[i][0], index);
                }
            }
        }
    }
}

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (e.g. A=aB):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", productions[i]);
        first[i][0] = '\0';
        follow[i][0] = '\0';
    }

    // FIRST
    for (int i = 0; i < n; i++) {
        findFirst(productions[i][0], i);
    }

    // FOLLOW
    for (int i = 0; i < n; i++) {
        findFollow(productions[i][0], i);
    }

    // Output FIRST
    printf("\nFIRST sets:\n");
    for (int i = 0; i < n; i++) {
        printf("FIRST(%c) = { ", productions[i][0]);
        for (int j = 0; first[i][j]; j++)
            printf("%c ", first[i][j]);
        printf("}\n");
    }

    // Output FOLLOW
    printf("\nFOLLOW sets:\n");
    for (int i = 0; i < n; i++) {
        printf("FOLLOW(%c) = { ", productions[i][0]);
        for (int j = 0; follow[i][j]; j++)
            printf("%c ", follow[i][j]);
        printf("}\n");
    }

    return 0;
}