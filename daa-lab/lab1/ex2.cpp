#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pair {
    int mn;
    int mx;
};

Pair dividenconquer(vector<int>& arr, int low, int high) {
    Pair left, right, result;
    if (low == high) {
        result.mn = result.mx = arr[low];
        return result;
    }


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

    result.mn = min(left.mn, right.mn);
    result.mx = max(left.mx, right.mx);

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Pair p = dividenconquer(arr, 0, n - 1);

    cout << "Minimum = " << p.mn << endl;
    cout << "Maximum = " << p.mx << endl;

    return 0;
}
