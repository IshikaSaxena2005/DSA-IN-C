//•	Write a program to find the addition of two matrices.
// Write separate functions for reading the matrix, displaying the matrix and to find the multiplication of the matrices.

#include <stdio.h>

void readMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


void addMatrices(int rows, int cols, int matrix1[rows][cols], int matrix2[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

int main() {
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int matrix1[rows][cols];
    int matrix2[rows][cols];
    int result[rows][cols];
    int c[rows][cols];

    printf("For Matrix 1:\n");
    readMatrix(rows, cols, matrix1);

    printf("For Matrix 2:\n");
    readMatrix(rows, cols, matrix2);

    printf("Matrix 1:\n");
    displayMatrix(rows, cols, matrix1);

    printf("Matrix 2:\n");
    displayMatrix(rows, cols, matrix2);

    addMatrices(rows, cols, matrix1, matrix2, result);

    printf("Sum of Matrices:\n");
    displayMatrix(rows, cols, result);



    return 0;
}

