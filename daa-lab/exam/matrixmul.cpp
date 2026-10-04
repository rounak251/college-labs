#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter size of matrix (n): ";
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));
    vector<vector<int>> C(n, vector<int>(n, 0));

    cout << "Enter elements of matrix A:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter elements of matrix B:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> B[i][j];

    // Matrix multiplication (O(n^3))
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nResult matrix C:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}
