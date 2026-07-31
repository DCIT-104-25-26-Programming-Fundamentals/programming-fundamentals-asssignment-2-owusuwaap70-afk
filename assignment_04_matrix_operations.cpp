#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void readMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
}

void printMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << setw(4) << matrix[i][j];
        cout << endl;
    }
}

void transpose(int matrix[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[j][i] = matrix[i][j];
}

void addMatrices(int a[10][10], int b[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = a[i][j] + b[i][j];
}

void multiplyMatrices(int a[10][10], int b[10][10], int result[10][10], int m, int n, int p) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++)
                result[i][j] += a[i][k] * b[k][j];
        }
}

int main() {
    int matrix[10][10], result[10][10];
    int rows, cols;

    // Part A - Transpose
    cout << "=== PART A: Transpose ===" << endl;
    cout << "Enter number of rows: "; cin >> rows;
    cout << "Enter number of columns: "; cin >> cols;
    readMatrix(matrix, rows, cols);
    cout << "\nOriginal Matrix:" << endl;
    printMatrix(matrix, rows, cols);
    transpose(matrix, result, rows, cols);
    cout << "\nTransposed Matrix:" << endl;
    printMatrix(result, cols, rows);

    // Part B - Add
    int a[10][10], b[10][10], sum[10][10];
    cout << "\n=== PART B: Matrix Addition ===" << endl;
    cout << "Enter number of rows: "; cin >> rows;
    cout << "Enter number of columns: "; cin >> cols;
    cout << "Matrix A:" << endl;
    readMatrix(a, rows, cols);
    cout << "Matrix B:" << endl;
    readMatrix(b, rows, cols);
    addMatrices(a, b, sum, rows, cols);
    cout << "\nResult:" << endl;
    printMatrix(sum, rows, cols);

    // Part C - Multiply
    int c[10][10], d[10][10], product[10][10];
    int m, n, p;
    cout << "\n=== PART C: Matrix Multiplication ===" << endl;
    cout << "Matrix A rows: "; cin >> m;
    cout << "Matrix A cols (= Matrix B rows): "; cin >> n;
    cout << "Matrix B cols: "; cin >> p;
    cout << "Matrix A:" << endl;
    readMatrix(c, m, n);
    cout << "Matrix B:" << endl;
    readMatrix(d, n, p);
    multiplyMatrices(c, d, product, m, n, p);
    cout << "\nResult:" << endl;
    printMatrix(product, m, p);

    return 0;
}