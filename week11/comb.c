#include <stdio.h>

int comb(int n, int r){
    if(n == r || r == 0)
        return 1;
    else
        return comb(n-1, r-1)+comb(n-1, r);
}

int main(void){
    int C;
    C = comb(4, 2);
    printf("%d\n", C);
    return 0;
}