//matrix.hpp
#ifndef MATRIX_HPP
#define MATRIX_HPP

namespace MatrixOperations {
    void readMatrix(int** matrix, int n);
    void processMatrix(int** matrix, int n);
    void writeMatrix(int** matrix, int n);
}

#endif // MATRIX_HPP
//additional.cpp
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
//main.cpp
#include <iostream>
#include "matrix.hpp"

using namespace std;

int main() {
    int m;
    cout << "Введите размер матрицы: ";
    cin >> m;
    int** matrix = new int*[m];
    for (int i = 0; i < m; ++i) {
        matrix[i] = new int[m];
    }

    cout << "Введите элементы матрицы:\n";
    MatrixOperations::readMatrix(matrix, m);

    MatrixOperations::processMatrix(matrix, m);

    cout << "Обработанная матрица:\n";
    MatrixOperations::writeMatrix(matrix, m);

    for (int i = 0; i < m; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}