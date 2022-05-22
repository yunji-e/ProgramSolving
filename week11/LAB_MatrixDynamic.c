#include <stdio.h>
#include <stdlib.h>

void readMatrix(int **A, int row, int col){
    int i, j;

    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            scanf("%d", &A[i][j]);
}

void matrixAdd(int **A, int **B, int **X, int row, int col){
    int i, j;

    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            X[i][j] = A[i][j] + B[i][j];
}

void printMatrix(int **a, int row, int col){
    int i, j;

    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++)
            printf("%4d", a[i][j]);
        printf("\n");
    }
}

int main(void){
    int **A, **B;
    int **X;
    int aRow, aCol;
    int i, j;

    printf("Enter row and column of matrix A: ");
    scanf("%d %d", &aRow, &aCol);

    A = (int**)malloc(sizeof(int)*aRow);
    B = (int**)malloc(sizeof(int)*aRow);
    X = (int**)malloc(sizeof(int)*aRow);
    for (i = 0; i < aRow; i++){
        A[i] = (int*)malloc(sizeof(int)*aCol);
        B[i] = (int*)malloc(sizeof(int)*aCol);
        X[i] = (int*)malloc(sizeof(int)*aCol);
    }

    printf("Enter matrix A:\n");
    readMatrix(A, aRow, aCol);
    printf("Enter matrix B:\n");
    readMatrix(B, aRow, aCol);
    
    matrixAdd(A, B, X, aRow, aCol);
    printMatrix(X, aRow, aCol);

    for (i = 0; i < aRow; i++) {
        free(A[i]);
        free(B[i]);
        free(X[i]);
    }
    free(A);
    free(B);
    free(X);
    
    return 0;
}