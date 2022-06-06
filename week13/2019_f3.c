#include <stdio.h>
#include <stdlib.h>

int solution(int n, int* memo){
    if(n == 1)
        return 0;
    /*
    for(int i = 2; i <= n; i++){
        memo[i] = memo[i-1]+1;
        if(i%2 == 0)
            memo[i] = (memo[i]<(memo[i/2]+1)?memo[i]:memo[i/2]+1);
        if(i%3 == 0)
            memo[i] = (memo[i]<(memo[i/3]+1)?memo[i]:memo[i/3]+1);
    }
    */
    if(memo[n] != 0)
        return memo[n];
    
    memo[n] = solution(n-1, memo)+1;
    if(n%2 == 0)
        memo[n] = memo[n] < solution(n/2, memo)+1 ? memo[n] : memo[n/2]+1;
    if(n%3 == 0)
        memo[n] = memo[n] < solution(n/3, memo)+1 ? memo[n] : memo[n/3]+1;

    return memo[n];
}

int main(void){
    int n, i;
    int* memo;

    scanf("%d", &n);
    memo = (int*)malloc(sizeof(int)*(n+1));
    for(i = 0; i <= n; i++)
        memo[i] = 0;

    printf("%d\n", solution(n, memo));
    
    free(memo);
    return 0;
}