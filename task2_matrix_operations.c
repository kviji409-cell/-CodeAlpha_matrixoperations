#include <stdio.h>

#define MAX 10

void readMatrix(int matrix[MAX][MAX], int rows, int cols, const char *name) {
    int i, j;
    printf("Enter elements of %s (%d x %d):\n", name, rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%s[%d][%d]: ", name, i + 1, j + 1);
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid input.\n");
            }
        }
    }
}

void printMatrix(const int matrix[MAX][MAX], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(const int a[MAX][MAX], const int b[MAX][MAX],
                 int result[MAX][MAX], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            result[i][j] = a[i][j] + b[i][j];
}

void multiplyMatrices(const int a[MAX][MAX], const int b[MAX][MAX],
                      int result[MAX][MAX], int rowsA, int colsA, int colsB) {
    int i, j, k;
    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (k = 0; k < colsA; k++)
                result[i][j] += a[i][k] * b[k][j];
        }
    }
}

void transposeMatrix(const int source[MAX][MAX], int result[MAX][MAX],
                     int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            result[j][i] = source[i][j];
}

int main(void) {
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;
    int choice;

    printf("=== Matrix Operations ===\n");
    printf("1. Addition\n2. Multiplication\n3. Transpose of a matrix\n");
    printf("Choose operation: ");
    if (scanf("%d", &choice) != 1) return 1;

    if (choice == 1) {
        printf("Enter rows and columns (1-%d): ", MAX);
        if (scanf("%d %d", &rowsA, &colsA) != 2 ||
            rowsA < 1 || rowsA > MAX || colsA < 1 || colsA > MAX) {
            printf("Invalid dimensions.\n");
            return 1;
        }
        readMatrix(a, rowsA, colsA, "A");
        readMatrix(b, rowsA, colsA, "B");
        addMatrices(a, b, result, rowsA, colsA);
        printf("A + B =\n");
        printMatrix(result, rowsA, colsA);
    } else if (choice == 2) {
        printf("Enter rows and columns of matrix A: ");
        if (scanf("%d %d", &rowsA, &colsA) != 2 ||
            rowsA < 1 || rowsA > MAX || colsA < 1 || colsA > MAX) {
            printf("Invalid dimensions.\n");
            return 1;
        }
        printf("Enter rows and columns of matrix B: ");
        if (scanf("%d %d", &rowsB, &colsB) != 2 ||
            rowsB < 1 || rowsB > MAX || colsB < 1 || colsB > MAX ||
            colsA != rowsB) {
            printf("Invalid dimensions: columns of A must equal rows of B.\n");
            return 1;
        }
        readMatrix(a, rowsA, colsA, "A");
        readMatrix(b, rowsB, colsB, "B");
        multiplyMatrices(a, b, result, rowsA, colsA, colsB);
        printf("A x B =\n");
        printMatrix(result, rowsA, colsB);
    } else if (choice == 3) {
        printf("Enter rows and columns (1-%d): ", MAX);
        if (scanf("%d %d", &rowsA, &colsA) != 2 ||
            rowsA < 1 || rowsA > MAX || colsA < 1 || colsA > MAX) {
            printf("Invalid dimensions.\n");
            return 1;
        }
        readMatrix(a, rowsA, colsA, "A");
        transposeMatrix(a, result, rowsA, colsA);
        printf("Transpose of A =\n");
        printMatrix(result, colsA, rowsA);
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    return 0;
}
