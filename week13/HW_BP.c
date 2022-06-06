#include <stdio.h>
#include <stdlib.h>

#define ST 1
#define LE 2
#define UP 3

int matrixPath(int** m, int** memo, int**memoEx, int **BP, int r, int c, int i, int j){
    if(i == 0 && j == 0){
        BP[i][j] = ST;
        return m[i][j];
    }
        
    if(memoEx[i][j] == 0){
        memoEx[i][j] = 1;
        if(i == 0){
            BP[i][j] = LE;
            memo[i][j] = m[i][j] + matrixPath(m, memo, memoEx, BP, r, c, i, j-1);
        }
        else if(j == 0){
            BP[i][j] = UP;
            memo[i][j] = m[i][j] + matrixPath(m, memo, memoEx, BP, r, c, i-1, j);
        }
        else{
            int a, b;
            a = matrixPath(m, memo, memoEx, BP, r, c, i-1, j);
            b = matrixPath(m, memo, memoEx, BP, r, c, i, j-1);
            BP[i][j] = (memo[i][j-1]) < memo[i-1][j] ? LE : UP;
            memo[i][j] = m[i][j] + ((a < b) ? a : b);
        }
    }
    
    return memo[i][j];
}

void print_path(int i, int j, int **BP){
    if(BP[i][j] == LE)
        print_path(i, j-1, BP);
    if(BP[i][j] == UP)
        print_path(i-1, j, BP);
    printf("<%d, %d>", i, j);
}

int main(void){
    int **m;
    int **memo;
    int **memoEx;
    int **BP;
    int i, j, row, col;

    row = 4;
    col = 4;

    m = (int**)malloc(sizeof(int*) * row);
    memo = (int**)malloc(sizeof(int*) * row);
    memoEx = (int**)malloc(sizeof(int*) * row);
    BP = (int**)malloc(sizeof(int*) * row);

    for (i = 0; i < row; i++){
        m[i] = (int*)malloc(sizeof(int) * col);
        memo[i] = (int*)malloc(sizeof(int) * col);
        memoEx[i] = (int*)malloc(sizeof(int) * col);
        BP[i] = (int*)malloc(sizeof(int) * col);
    }

    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++){
            scanf("%d", &m[i][j]);
            memo[i][j] = 0;
            memoEx[i][j] = 0;
        }
    
    matrixPath(m, memo, memoEx, BP, row, col, row-1, col-1);

    print_path(3, 3, BP);

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