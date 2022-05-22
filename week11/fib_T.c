#include <stdio.h>
#include <stdlib.h>

long fib(long F[], int n){
    if(n == 1 || n == 2)
        return 1;
    if(F[n-1]==0)
        F[n-1] = fib(F, n-1);
    if(F[n-2]==0)
        F[n-2] = fib(F, n-2);
    return F[n-1] + F[n-2];
}

/* 
long fib(int n, long* F){
    if(n == 1 || n == 2)
        return 1;
    if(F[n] == 0)
        F[n] = fib(n-1, F) + fib(n-2, F);
    
    return F[n];
}
*/

int main(void){
    int i, n;
    long *F;

    scanf("%d", &n);
    F = (long*)malloc(sizeof(int)*(n+1));

    for (i = 0; i < n + 1; i++)
        F[i] = 0;

    
    printf("%d\n", fib(F, n));
}