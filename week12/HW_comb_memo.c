#include <stdio.h>
#include <stdlib.h>

int comb(int n, int r, int** memo){
    if(memo[n][r] != -1)
        return memo[n][r];
    if(r == 0 || r == n)
        return memo[n][r] = 1 ;
    return memo[n][r] = comb(n-1, r-1, memo) + comb(n-1, r, memo);
}

int main(void){
    int C;
    int **memo;
    int n, r, i, j;

    n = 4;
    r = 2;

    memo = (int**)malloc(sizeof(int*) * (n+1));
    for (i = 0; i < n+1; i++)
        memo[i] = (int*)malloc(sizeof(int) * (r+1));

    for (i = 0; i < n+1; i++)
        for(j = 0; j < r+1; j++)
            memo[i][j] = -1;

    C = comb(n, r, memo);
    printf("comb(%d, %d) = ", n, r);
    printf("%d", C);

    for (i = 0; i < n+1; i++)
        free(memo[i]);
    free(memo);

    return 0;
}