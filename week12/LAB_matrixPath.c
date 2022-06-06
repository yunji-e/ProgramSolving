#include <stdio.h>
#include <stdlib.h>

int matrixPath(int** m, int r, int c, int i, int j){
    if(i == 0 && j == 0)
        return m[i][j];
    else if(i == 0)
        return m[i][j] + matrixPath(m, r, c, i, j-1);
    else if(j == 0)
        return m[i][j] + matrixPath(m, r, c, i-1, j);
    else{
        int a, b;
        a = matrixPath(m, r, c, i-1, j);
        b = matrixPath(m, r, c, i, j-1);
        return m[i][j] + ((a < b) ? a : b);
    }
}

int main(void){
    int **m;
    int i, j, row, col;

    row = 4;
    col = 4;

    m = (int**)malloc(sizeof(int*) * row);

    for (i = 0; i < row; i++)
        m[i] = (int*)malloc(sizeof(int) * col);

    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            scanf("%d", &m[i][j]);
    
    printf("%d\n", matrixPath(m, row, col, row-1, col-1));

    for (i = 0; i < row; i++)
        free(m[i]);
    free(m);

    return 0;
}