#include <iostream>
#include <vector>

using namespace std;

// Function to add two matrices
vector<vector<int>> matrixAddition(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}

// Function to subtract two matrices
vector<vector<int>> matrixSubtraction(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}

// Function to multiply two matrices using Strassen's algorithm
vector<vector<int>> strassenMatrixMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();

    // Base case: If the matrix size is 1x1
    if (n == 1) {
        vector<vector<int>> C(1, vector<int>(1));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    // Splitting matrices into submatrices
    int mid = n / 2;
    vector<vector<int>> A11(mid, vector<int>(mid)), A12(mid, vector<int>(mid)), A21(mid, vector<int>(mid)), A22(mid, vector<int>(mid));
    vector<vector<int>> B11(mid, vector<int>(mid)), B12(mid, vector<int>(mid)), B21(mid, vector<int>(mid)), B22(mid, vector<int>(mid));

    // Initialize submatrices
    for (int i = 0; i < mid; ++i) {
        for (int j = 0; j < mid; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    // Calculating Strassen's algorithm matrices
    vector<vector<int>> M1 = strassenMatrixMultiply(matrixAddition(A11, A22), matrixAddition(B11, B22));
    vector<vector<int>> M2 = strassenMatrixMultiply(matrixAddition(A21, A22), B11);
    vector<vector<int>> M3 = strassenMatrixMultiply(A11, matrixSubtraction(B12, B22));
    vector<vector<int>> M4 = strassenMatrixMultiply(A22, matrixSubtraction(B21, B11));
    vector<vector<int>> M5 = strassenMatrixMultiply(matrixAddition(A11, A12), B22);
    vector<vector<int>> M6 = strassenMatrixMultiply(matrixSubtraction(A21, A11), matrixAddition(B11, B12));
    vector<vector<int>> M7 = strassenMatrixMultiply(matrixSubtraction(A12, A22), matrixAddition(B21, B22));

    // Calculating result submatrices
    vector<vector<int>> C11 = matrixAddition(matrixSubtraction(matrixAddition(M1, M4), M5), M7);
    vector<vector<int>> C12 = matrixAddition(M3, M5);
    vector<vector<int>> C21 = matrixAddition(M2, M4);
    vector<vector<int>> C22 = matrixAddition(matrixSubtraction(matrixAddition(M1, M3), M2), M6);

    // Combine result submatrices into result matrix
    vector<vector<int>> result(n, vector<int>(n));
    for (int i = 0; i < mid; ++i) {
        for (int j = 0; j < mid; ++j) {
            result[i][j] = C11[i][j];
            result[i][j + mid] = C12[i][j];
            result[i + mid][j] = C21[i][j];
            result[i + mid][j + mid] = C22[i][j];
        }
    }

    return result;
}

int main() {
    // Test case
    vector<vector<int>> A = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<vector<int>> B = {{17, 18, 19, 20}, {21, 22, 23, 24}, {25, 26, 27, 28}, {29, 30, 31, 32}};

    vector<vector<int>> result = strassenMatrixMultiply(A, B);

    // Displaying the result
    cout << "Result Matrix:" << endl;
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
