#include <stdio.h>

int calculateReverse(int n){
    int reverse = 0;
    while(n>0){
        reverse = reverse*10 + n%10;
        n/=10;
    }
    return reverse;
}

int main(void) {
    int n, reverse;
    int count = 0;

    scanf("%d", &n);
    reverse = calculateReverse(n);

    while(n!= reverse){
        n = n + reverse;
        reverse = calculateReverse(n);
        count++;
    }

    printf("%d %d", count, n);

    return 0;
}