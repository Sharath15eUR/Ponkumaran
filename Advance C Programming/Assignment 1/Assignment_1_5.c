#include <stdio.h>
#include <stdlib.h>

void MatrixMultiplication(int **matrixA, int rA, int cA, int **matrixB, int rB, int cB, int **matrixC) {
    int i, j, k;

    for (i = 0; i < rA; ++i) {
        for (j = 0; j < cB; ++j) {
            matrixC[i][j] = 0;
            for (k = 0; k < cA; ++k) {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main() {
    int i, j;
    int rA, cA, rB, cB;

    // Enter Matrix A
    printf("Enter Number of Rows in MatrixA: ");
    scanf("%d", &rA);
    printf("Enter Number of columns in MatrixA: ");
    scanf("%d", &cA);

    int **matrixA = (int **)malloc(rA * sizeof(int *));
    for (i = 0; i < rA; ++i) {
        matrixA[i] = (int *)malloc(cA * sizeof(int));
    }

    printf("Enter MatrixA: \n");
    for (i = 0; i < rA; ++i) {
        for (j = 0; j < cA; ++j) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    // Enter Matrix B
    printf("Enter Number of Rows in MatrixB: ");
    scanf("%d", &rB);
    printf("Enter Number of columns in MatrixB: ");
    scanf("%d", &cB);

    int **matrixB = (int **)malloc(rB * sizeof(int *));
    for (i = 0; i < rB; ++i) {
        matrixB[i] = (int *)malloc(cB * sizeof(int));
    }

    printf("Enter MatrixB: \n");
    for (i = 0; i < rB; ++i) {
        for (j = 0; j < cB; ++j) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    // Allocate memory for MatrixC
    int **matrixC = (int **)malloc(rA * sizeof(int *));
    for (i = 0; i < rA; ++i) {
        matrixC[i] = (int *)malloc(cB * sizeof(int));
    }

    // Perform Matrix Multiplication
    MatrixMultiplication(matrixA, rA, cA, matrixB, rB, cB, matrixC);

    // Printing MatrixC
    printf("\nThe Matrix Multiplication of MatrixA and MatrixB: \n");
    for (i = 0; i < rA; ++i) {
        for (j = 0; j < cB; ++j) {
            printf("%d ", matrixC[i][j]);
        }
        printf("\n");
    }

    // Free dynamically allocated memory
    for (i = 0; i < rA; ++i) {
        free(matrixA[i]);
    }
    free(matrixA);

    for (i = 0; i < rB; ++i) {
        free(matrixB[i]);
    }
    free(matrixB);

    for (i = 0; i < rA; ++i) {
        free(matrixC[i]);
    }
    free(matrixC);

    return 0;
}
