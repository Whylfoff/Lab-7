//1.hpp
#ifndef MATRIX_HPP
#define MATRIX_HPP

namespace MatrixOperations {
    void readMatrix(int** matrix, int n);
    void processMatrix(int** matrix, int n);
    void writeMatrix(int** matrix, int n);
}

#endif // MATRIX_HPP
//2.cpp
#include "matrix.hpp"
#include <iostream>

using namespace std;

namespace MatrixOperations {
    void readMatrix(int** matrix, int n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> matrix[i][j];
            }
        }
    }
    void processMatrix(int** matrix, int n) {
        bool diagonalElementsAreMax = true;
        for (int i = 0; i < n; ++i) {
            int maxInRow = matrix[i][0];
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] > maxInRow) {
                    maxInRow = matrix[i][j];
                }
            }
            if (maxInRow != matrix[i][i]) {
                diagonalElementsAreMax = false;
                break;
            }
        }

        if (diagonalElementsAreMax) {
		int diagonalProduct = 1;
            for (int i = 0; i < n; ++i) {
                diagonalProduct *= matrix[i][i];
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (matrix[i][j] == 0) {
                        matrix[i][j] = diagonalProduct;
                    }
                }
            }
        }
    }

    void writeMatrix(int** matrix, int n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
}
//3.cpp
#include <iostream>
#include "matrix.hpp"

using namespace std;

int main() {
    int n;
    cout << "Введите размер матрицы (n): ";
    cin >> n;
    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
    }

    cout << "Введите элементы матрицы:\n";
    MatrixOperations::readMatrix(matrix, n);

    MatrixOperations::processMatrix(matrix, n);

    cout << "Обработанная матрица:\n";
    MatrixOperations::writeMatrix(matrix, n);

    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}