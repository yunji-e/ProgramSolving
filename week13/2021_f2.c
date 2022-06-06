#include <stdio.h>
#include <stdlib.h>

/*
struct Memo{
    int N0;
    int N1;
}
*/

int fib(int n, int* F){
    if(n == 0 || n == 1)
        return 1;
    if(F[n-1]==0)
        F[n-1] = fib(n-1, F);
    if(F[n-2]==0)
        F[n-2] = fib(n-2, F);
    return F[n-1] + F[n-2];
}

int main(void){
    int n, i;
    int *F;

    scanf("%d", &n);
    F = (int*)malloc(sizeof(int)*n);
    for(i = 0; i < n; i++)
        F[i] = 0;

    fib(n, F);
    printf("\n%d %d", F[n-1], F[n-2]);

    free(F);

    return 0;
}