#include <stdio.h>
#include <stdlib.h>

int matrixPath(int** m, int** memo, int**memoEx, int r, int c, int i, int j){
    if(i == 0 && j == 0)
        return m[i][j];
    if(memoEx[i][j] == 0){
        memoEx[i][j] = 1;
        if(i == 0)
            return memo[i][j] = m[i][j] + matrixPath(m, memo, memoEx, r, c, i, j-1);
        else if(j == 0)
            return memo[i][j] = m[i][j] + matrixPath(m, memo, memoEx, r, c, i-1, j);
        else{
            int a, b;
            a = matrixPath(m, memo, memoEx, r, c, i-1, j);
            b = matrixPath(m, memo, memoEx, r, c, i, j-1);
            return memo[i][j] = m[i][j] + ((a < b) ? a : b);
        }
    }
    
    return memo[i][j];
}

int main(void){
    int **m;
    int **memo;
    int **memoEx;
    int i, j, row, col;

    row = 4;
    col = 4;

    m = (int**)malloc(sizeof(int*) * row);
    memo = (int**)malloc(sizeof(int*) * row);
    memoEx = (int**)malloc(sizeof(int*) * row);

    for (i = 0; i < row; i++){
        m[i] = (int*)malloc(sizeof(int) * col);
        memo[i] = (int*)malloc(sizeof(int) * col);
        memoEx[i] = (int*)malloc(sizeof(int) * col);
    }

    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++){
            scanf("%d", &m[i][j]);
            memo[i][j] = 0;
            memoEx[i][j] = 0;
        }
    
    printf("%d\n", matrixPath(m, memo, memoEx, row, col, row-1, col-1));

    for (i = 0; i < row; i++){
        free(m[i]);
        free(memo[i]);
        free(memoEx[i]);
    }
    free(m);
    free(memo);
    free(memoEx);

    return 0;
}