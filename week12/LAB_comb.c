#include <stdio.h>

int comb(int n, int r){
    //printf("comb(%d, %d)\n", n, r );
    if(r == 0 || r == n)
        return 1 ;
    return comb(n-1, r-1) + comb(n-1, r);
}

int main(void){
    int C;
    C = comb(4, 2);
    printf("%d", C);

    return 0;
}