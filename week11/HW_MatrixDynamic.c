#include <stdio.h>
#include <stdlib.h>

void readMatrix(int **a, int row, int col){
    int i, j;
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            scanf("%d", &a[i][j]);
}

void transposedMatrix(int **a, int **b, int row, int col){
    int i, j, temp;
    for (i = 0; i < col; i++)
        for (j = 0; j < row; j++)
            b[i][j] = a[j][i];
}

void mulMatrix(int **a, int **b, int **x, int row, int col, int n){
    int i, j, k, sum;
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++) {
            sum = 0;
            for (k = 0; k < n; k++)
                sum += a[i][k] * b[k][j];
            x[i][j] = sum;
        }
}

void printMatrix(int **a, int row, int col){
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++)
            printf("%5d", a[i][j]);
        printf("\n");
    }
}

int main(void){
    int **A, **B, **C;
    int **X;
    int i, aRow, aCol, cRow, cCol;

    printf("Enter row and col of matrix A: ");
    scanf("%d %d", &aRow, &aCol);
    printf("Enter row and col of matrix C(The row is %d): ", aCol);
    scanf("%d %d", &cRow, &cCol);

    A = (int**)malloc(sizeof(int)*aRow);
    for (i = 0; i < aRow; i++)
        A[i] = (int*)malloc(sizeof(int)*aCol);
    B = (int**)malloc(sizeof(int)*aCol);
    for (i = 0; i < aCol; i++)
        B[i] = (int*)malloc(sizeof(int)*aRow);
    C = (int**)malloc(sizeof(int)*cRow);
    for (i = 0; i < cRow; i++)
        C[i] = (int*)malloc(sizeof(int)*aCol);
    X = (int**)malloc(sizeof(int)*aRow);
    for (i = 0; i < aRow; i++)
        X[i] = (int*)malloc(sizeof(int)*cCol);
    
    printf("%dx%d matrix A: \n", aRow, aCol);
    readMatrix(A, aRow, aCol);
    printf("%dx%d matrix C: \n", cRow, cCol);
    readMatrix(C, cRow, cCol);
    mulMatrix(A, C, X, aRow, cCol, aCol);

    printf("matrix multiplication: \n");
    printMatrix(X, aRow, cCol);
    printf("transposed matrix: \n");
    transposedMatrix(A, B, aRow, aCol);
    printMatrix(B, aCol, aRow);
    
    for (i = 0; i < aRow; i++){
        free(A[i]);
        free(X[i]);
    }
    for (i = 0; i < aCol; i++)
        free(B[i]);
    for (i = 0; i < cRow; i++)
        free(C[i]);
    free(A);
    free(B);
    free(C);
    free(X);

    return 0;
}