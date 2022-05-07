#include <stdio.h>

int main(void) {
    int a;
    int c = 1;
    int count = 1;

    scanf("%d", &a);

    while(c%a != 0){
        c = c*10 + 1;
        count++;
    }
    printf("%d", count);
    return 0;
}