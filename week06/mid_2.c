#include <stdio.h>
#include <string.h>

/*
int reverse(int n){
    int ret = 0;

    while(n!=0){
        ret = ret * 10 + n % 10;
        n = n/10;
    }
    return ret;
}
*/

void solution(int n){
    if (n == 0)
        return;
    solution(n / 10);
    printf("%d ", n % 10);

    return;
}

int main(void){
    int n;
    scanf("%d", &n);
    solution(n*9);

    /*
    int n;
    int rev_n;

    scanf("%d", &n);

    n = n * 9;

    rev_n = reverse(n);

    while(rev_n != 0){
        printf("%d", )
    }
    */

    return 0;
}