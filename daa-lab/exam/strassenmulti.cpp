#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;

// Add two matrices
Matrix add(Matrix A, Matrix B, int n) {
    Matrix C(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Subtract two matrices
Matrix subtract(Matrix A, Matrix B, int n) {
    Matrix C(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Strassen multiplication
Matrix strassen(Matrix A, Matrix B, int n) {
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int newSize = n / 2;

    Matrix A11(newSize, vector<int>(newSize));
    Matrix A12(newSize, vector<int>(newSize));
    Matrix A21(newSize, vector<int>(newSize));
    Matrix A22(newSize, vector<int>(newSize));
    Matrix B11(newSize, vector<int>(newSize));
    Matrix B12(newSize, vector<int>(newSize));
    Matrix B21(newSize, vector<int>(newSize));
    Matrix B22(newSize, vector<int>(newSize));

    // Divide matrices
    for(int i = 0; i < newSize; i++) {
        for(int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Compute M1 to M7
    Matrix M1 = strassen(add(A11,A22,newSize), add(B11,B22,newSize), newSize);
    Matrix M2 = strassen(add(A21,A22,newSize), B11, newSize);
    Matrix M3 = strassen(A11, subtract(B12,B22,newSize), newSize);
    Matrix M4 = strassen(A22, subtract(B21,B11,newSize), newSize);
    Matrix M5 = strassen(add(A11,A12,newSize), B22, newSize);
    Matrix M6 = strassen(subtract(A21,A11,newSize), add(B11,B12,newSize), newSize);
    Matrix M7 = strassen(subtract(A12,A22,newSize), add(B21,B22,newSize), newSize);

    // Compute C blocks
    Matrix C11 = add(subtract(add(M1,M4,newSize),M5,newSize),M7,newSize);
    Matrix C12 = add(M3,M5,newSize);
    Matrix C21 = add(M2,M4,newSize);
    Matrix C22 = add(subtract(add(M1,M3,newSize),M2,newSize),M6,newSize);

    // Combine result
    Matrix C(n, vector<int>(n));
    for(int i = 0; i < newSize; i++) {
        for(int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    return C;
}

// Driver
int main() {
    int n = 2;
    Matrix A = {{1, 2}, {3, 4}};
    Matrix B = {{5, 6}, {7, 8}};

    Matrix C = strassen(A, B, n);

    cout << "Result matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}
//o(2.81)