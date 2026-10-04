//Write a program to search for an element
 //in array using the binary search algorithm
#include <iostream>
using namespace std;

int binarysearch(int arr[], int low, int high, int x) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == x)
        return mid;
    else if (arr[mid] > x)
        return binarysearch(arr, low, mid - 1, x);
    else
        return binarysearch(arr, mid + 1, high, x);
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements (sorted): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cout << "Enter the desired number: ";
    cin >> x;

    int result = binarysearch(arr, 0, n - 1, x);

    if (result != -1)
        cout << "Element found at index: " << result;
    else
        cout << "Element not found";

    return 0;
}

    