#include <stdio.h>
#include <stdlib.h>

void readMatrix(int **a, int r, int c){
    int i, j;

    for (i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
}

void matrixAdd(int **a, int **b, int **x, int r, int c){
    int i, j;
    for (i = 0; i < r; i++) {
        for(j = 0; j < c; j++)
           x[i][j] = a[i][j] + b[i][j];
    }
}

void printMatrix(int **a, int r, int c){
    int i, j;
    for (i = 0; i < r; i++) {
        for(j = 0; j < c; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

int main(void){
    int **A, **B, **X;
    int i;
    int row, col;

    scanf("%d %d", &row, &col);
    A = (int**)malloc(sizeof(int*)*row);
    B = (int**)malloc(sizeof(int*)*row);
    X = (int**)malloc(sizeof(int*)*row);
    for (i = 0; i < row; i++) {
        A[i] = (int*)malloc(sizeof(int)*col);
        B[i] = (int*)malloc(sizeof(int)*col);
        X[i] = (int*)malloc(sizeof(int)*col);
    }
    
    readMatrix(A, row, col);
    readMatrix(B, row, col);
    matrixAdd(A, B, X, row, col);
    printMatrix(X, row, col);

    for(i = 0; i < row; i++){
        free(A[i]);
        free(B[i]);
        free(X[i]);
    }
    free(A);
    free(B);
    free(X);

    return 0;
}