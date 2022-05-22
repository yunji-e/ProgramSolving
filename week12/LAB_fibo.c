#include <stdio.h>
#include <stdlib.h>

int fib(int n, int *F){
    if(n == 1 || n == 2)
        return 1;

    if(F[n] == 0)
        F[n] = fib(n-1, F) + fib(n-2, F);

    return F[n];
}

int main(void){
    int n, i;
    int *F;

    printf("Nth fib: ");
    scanf("%d", &n);

    F = (int*)malloc(sizeof(int)*(n+1));
    for (i = 0; i <= n; i++)
        F[i] = 0;

    for (i = 1; i <= n; i++)
        printf("%d ", fib(i, F));
    printf("\n");

    free(F);

    return 0;
}