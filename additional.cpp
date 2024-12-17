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