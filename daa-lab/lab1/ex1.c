#include <stdio.h>

void lsminmax(int arr[], int n) {
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (min > arr[i])
            min = arr[i];
        if (max < arr[i])
            max = arr[i];
    }

    printf("minimum %d\n", min);
    printf("maximum %d\n", max);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    lsminmax(arr, n);
    return 0;
}
