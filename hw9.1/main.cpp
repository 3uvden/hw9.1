#include <iostream>
#include <Windows.h>
#include <cstdlib>


const int length = 10;


int findMax(int a, int b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

int findMax(int a, int b, int c) {
    return findMax(findMax(a, b), c);
}

int findMax(const int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int findMax(const int arr[][10], int rows, int cols) {
    int maxVal = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] > maxVal) {
                maxVal = arr[i][j];
            }
        }
    }
    return maxVal;
}

int findMax(int arr[][10][10], int depth, int rows, int cols) {
    int maxVal = 0;
    for (int i = 0; i < depth; ++i) {
        for (int j = 0; j < rows; ++j) {
            for (int k = 0; k < cols; ++k) {
                if (arr[i][j][k] > maxVal) {
                    maxVal = arr[i][j][k];
                }
            }
        }
    }
    return maxVal;
}

int main() {
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    int a = 5, b = 12, c = 9;
    std::cout << "Максимальное значение 2-х чисел (" << a << ", " << b << "): " << findMax(a, b) << '\n';
    std::cout << "Максимальное значение 3-х чисел (" << a << ", " << b << ", " << c << "): " << findMax(a, b, c) << '\n';


    const int rows = 3, cols = 10;
    int arr2D[rows][cols];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr2D[i][j] = rand() % 100;
        }
    }

    std::cout << "Максимальное значение в двумерном массиве: " << findMax(arr2D, rows, cols) << '\n';

    const int rows1 = 10, cols1 = 10;
    const int depth = 2;
    int arr3D[depth][rows1][cols1];
    for (int i = 0; i < depth; ++i) {
        for (int j = 0; j < rows; ++j) {
            for (int k = 0; k < cols; ++k) {
                arr3D[i][j][k] = rand() % 100 + 1;
            }
        }
    }

    std::cout << "Максимальное значение в трехмерном массиве: " << findMax(arr3D, depth, rows, cols) << '\n';

    return 0;
}