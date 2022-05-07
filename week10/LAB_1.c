#include <stdio.h>

void readMatrix(int a[][3], int n){
    int i, j;

    for (i = 0; i < n; i++)
        for(j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);
}

void matrixAdd(int a[][3], int b[][3], int x[][3], int n){
    int i, j;
    for (i = 0; i < n; i++) {
        for(j = 0; j < 3; j++)
           x[i][j] = a[i][j] + b[i][j];
    }
}

void printMatrix(int a[][3], int n){
    int i, j;
    for (i = 0; i < n; i++) {
        for(j = 0; j < 3; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

int main(void){
    int A[3][3];
    int B[3][3];
    int X[3][3];

    readMatrix(A, 3);
    readMatrix(B, 3);
    matrixAdd(A, B, X, 3);
    printMatrix(X, 3);

    return 0;
}