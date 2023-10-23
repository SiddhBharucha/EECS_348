/* The code `#include <iostream>` and `#include <fstream>` are preprocessor directives in C++. They
include the necessary header files for input/output operations (`iostream`) and file input/output
operations (`fstream`). */
#include <iostream>
#include <fstream>

const int MATRIX_SIZE = 100;

/* These are function declarations in C++. */
void readMatrixFromFile(int matrix[][MATRIX_SIZE], int& size, const char* filename);
void printMatrix(int matrix[][MATRIX_SIZE], int size);
void addMatrices(int matrixA[][MATRIX_SIZE], int matrixB[][MATRIX_SIZE], int resultMatrix[][MATRIX_SIZE], int size);
void multiplyMatrices(int matrixA[][MATRIX_SIZE], int matrixB[][MATRIX_SIZE], int resultMatrix[][MATRIX_SIZE], int size);
void subtractMatrices(int matrixA[][MATRIX_SIZE], int matrixB[][MATRIX_SIZE], int resultMatrix[][MATRIX_SIZE], int size);

/**
 * The main function reads two matrices from a file, prints them, performs addition, multiplication,
 * and subtraction operations on them, and then returns 0.
 * 
 * @return The main function is returning an integer value of 0.
 */
int main() {
    int matrixA[MATRIX_SIZE][MATRIX_SIZE];
    int matrixB[MATRIX_SIZE][MATRIX_SIZE];
    int resultMatrix[MATRIX_SIZE][MATRIX_SIZE];
    int size;

    std::ifstream inputFile("matrix_input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error: Cannot open file matrix_input.txt" << std::endl;
        return 1;
    }

    inputFile >> size;

    // Read Matrix A
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            inputFile >> matrixA[i][j];
        }
    }

    // Read Matrix B
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            inputFile >> matrixB[i][j];
        }
    }

    inputFile.close();

    std::cout << "Your name" << std::endl;
    std::cout << "Lab #6: Matrix manipulation" << std::endl;

    std::cout << "Matrix A:" << std::endl;
    printMatrix(matrixA, size);

    std::cout << "Matrix B:" << std::endl;
    printMatrix(matrixB, size);

    addMatrices(matrixA, matrixB, resultMatrix, size);
    multiplyMatrices(matrixA, matrixB, resultMatrix, size);
    subtractMatrices(matrixA, matrixB, resultMatrix, size);

    return 0;
}

/**
 * The function "printMatrix" prints a square matrix of integers.
 * 
 * @param matrix The parameter `matrix` is a 2-dimensional array of integers. It represents a matrix
 * with `MATRIX_SIZE` number of rows and columns.
 * @param size The parameter "size" represents the size of the square matrix. It indicates the number
 * of rows and columns in the matrix.
 */
void printMatrix(int matrix[][MATRIX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

/**
 * The function `addMatrices` takes two matrices `matrixA` and `matrixB`, adds their corresponding
 * elements, and stores the result in `resultMatrix`, then prints the sum matrix.
 * 
 * @param matrixA A 2D array representing the first matrix.
 * @param matrixB The parameter `matrixB` is a 2D array representing the second matrix in the addition
 * operation. It is of type `int` and has dimensions `MATRIX_SIZE x MATRIX_SIZE`.
 * @param resultMatrix The `resultMatrix` parameter is a 2D array that will store the sum of `matrixA`
 * and `matrixB`. It is passed as a reference to the function, so any changes made to `resultMatrix`
 * inside the function will be reflected outside the function as well.
 * @param size The parameter "size" represents the size of the matrices. It indicates the number of
 * rows and columns in the matrices.
 */
void addMatrices(int matrixA[][MATRIX_SIZE], int matrixB[][MATRIX_SIZE], int resultMatrix[][MATRIX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            resultMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    std::cout << "Matrix Sum (A + B):" << std::endl;
    printMatrix(resultMatrix, size);
}

/**
 * The function `multiplyMatrices` multiplies two matrices `matrixA` and `matrixB` of size `size` and
 * stores the result in `resultMatrix`, and then prints the resulting matrix.
 * 
 * @param matrixA A 2D array representing the first matrix.
 * @param matrixB The parameter `matrixB` is a 2D array representing the second matrix in the
 * multiplication operation. It is of type `int` and has dimensions `MATRIX_SIZE` x `MATRIX_SIZE`.
 * @param resultMatrix The `resultMatrix` parameter is a 2D array that will store the product of
 * `matrixA` and `matrixB`. It should have the same size as the input matrices, which is specified by
 * the `size` parameter.
 * @param size The parameter "size" represents the size of the square matrices. It indicates the number
 * of rows and columns in the matrices.
 */
void multiplyMatrices(int matrixA[][MATRIX_SIZE], int matrixB[][MATRIX_SIZE], int resultMatrix[][MATRIX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < size; k++) {
                resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    std::cout << "Matrix Product (A * B):" << std::endl;
    printMatrix(resultMatrix, size);
}

/**
 * The function subtracts two matrices element-wise and stores the result in a third matrix, then
 * prints the resulting matrix.
 * 
 * @param matrixA A 2D array representing the first matrix.
 * @param matrixB The parameter `matrixB` is a 2D array representing the second matrix in the
 * subtraction operation. It is of type `int` and has dimensions `MATRIX_SIZE x MATRIX_SIZE`.
 * @param resultMatrix The resultMatrix parameter is a 2D array that will store the difference of the
 * two input matrices (matrixA and matrixB). It should have the same size as the input matrices, which
 * is specified by the size parameter.
 * @param size The parameter "size" represents the size of the matrices. It indicates the number of
 * rows and columns in the matrices.
 */
void subtractMatrices(int matrixA[][MATRIX_SIZE], int matrixB[][MATRIX_SIZE], int resultMatrix[][MATRIX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            resultMatrix[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }

    std::cout << "Matrix Difference (A - B):" << std::endl;
    printMatrix(resultMatrix, size);
}
