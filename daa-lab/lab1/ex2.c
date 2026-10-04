#include <stdio.h>

struct Pair {
    int mn;
    int mx;
};

struct Pair dividenconquer(int arr[], int low, int high) {
    struct Pair left, right, result;

    // One element
    if (low == high) {
        result.mn = arr[low];
        result.mx = arr[low];
        return result;
    }

    // Two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.mn = arr[low];
            result.mx = arr[high];
        } else {
            result.mn = arr[high];
            result.mx = arr[low];
        }
        return result;
    }

    int mid = (low + high) / 2;

    left = dividenconquer(arr, low, mid);
    right = dividenconquer(arr, mid + 1, high);

    result.mn = (left.mn < right.mn) ? left.mn : right.mn;
    result.mx = (left.mx > right.mx) ? left.mx : right.mx;

    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];   // Valid in C (VLA)
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Pair p = dividenconquer(arr, 0, n - 1);

    printf("Minimum = %d\n", p.mn);
    printf("Maximum = %d\n", p.mx);

    return 0;
}
