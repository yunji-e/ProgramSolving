#include <stdio.h>
#include <stdlib.h>

long long H(int n, long long* memo){
    int i;

    if(n == 1)
        return 1;
    if(memo[n] == 0)
        for (i = 1; i < n; i++)
            memo[n] += (n-i) * H(i, memo);
    return memo[n];
}

int main(void){
    int n, i;
    long long* memo;

    scanf("%d", &n);
    memo = (long long*)malloc(sizeof(long long)*(n+1));
    for (i = 0; i <= n; i++)
        memo[i] = 0;

    printf("%lld\n", H(n, memo));

    free(memo);
    return 0;
}