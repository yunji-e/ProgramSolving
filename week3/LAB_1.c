#include <stdio.h>

int main(void) {
    int a;
    int b;
    int count = 0;
    int carry = 0;

    scanf("%d %d", &a, &b);
    while(a > 0 || b > 0){
        if((a%10+b%10+carry)>=10) {
            count++;
            carry = 1;
        }
        else
            carry = 0;
        a /= 10;
        b /= 10;
    }

    printf("%d", count);
    return 0;
}