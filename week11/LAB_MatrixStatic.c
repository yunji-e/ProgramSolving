#include <stdio.h>

void readMatrix(int a[][3]){
    int i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);
}

void matrixAdd(int a[][3], int b[][3], int c[][3]){
    int i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            c[i][j] = a[i][j]+b[i][j];
}

void printMatrix(int a[][3]){
    int i, j;

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++)
            printf("%4d", a[i][j]);
        printf("\n");
    }
}

int main(void){
    int a[3][3];
    int b[3][3];
    int c[3][3];

    printf("(3x3)Matrix A: \n");
    readMatrix(a);
    printf("(3x3)Matrix B: \n");
    readMatrix(b);
    matrixAdd(a, b, c);
    printf("MatrixAdd: \n");
    printMatrix(c);

    return 0;
}