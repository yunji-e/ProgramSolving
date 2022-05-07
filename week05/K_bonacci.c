#include <stdio.h>

int four_bonacci(int n){
    if(n > 4)
        return four_bonacci(n-1) + four_bonacci(n-2) + four_bonacci(n-3) + four_bonacci(n-4);
    else
        return 1;
}

int k_bonacci(int k, int n){
    int i;
    int sum = 0;

    if(n > k){    
        for (i = 1; i <= k; i++)
            sum += k_bonacci(k, n - i);
        return sum;
    }
    else
        return 1;
}

int main(){
    int k, n;
    k = 4;
    scanf("%d", &n);
    printf("%d\n", four_bonacci(n));
    scanf("%d %d", &k, &n);
    printf("%d\n", k_bonacci(k, n));
}