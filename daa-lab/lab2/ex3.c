#include <stdio.h>

// Iterative Binary Search
int binarySearchIterative(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

// Recursive Binary Search
int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
        return mid;
    else if (key < arr[mid])
        return binarySearchRecursive(arr, low, mid - 1, key);
    else
        return binarySearchRecursive(arr, mid + 1, high, key);
}

int main() {
    int n, key;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter sorted array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    // Iterative result
    int res1 = binarySearchIterative(arr, n, key);
    if (res1 != -1)
        printf("Iterative: Element found at index %d\n", res1);
    else
        printf("Iterative: Element not found\n");

    // Recursive result
    int res2 = binarySearchRecursive(arr, 0, n - 1, key);
    if (res2 != -1)
        printf("Recursive: Element found at index %d\n", res2);
    else
        printf("Recursive: Element not found\n");

    return 0;
}
