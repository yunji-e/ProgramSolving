#include <stdio.h>

void solution(int n, int k){
    if (n == 0)
        return;

    solution(n / k, k);
    printf("%d ", n % k);

    return;
}

int main(void){
    int n, k;
    int i;

    scanf("%d %d", &n, &k);

    solution(n, k);

    return 0;
}