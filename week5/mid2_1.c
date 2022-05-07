#include <stdio.h>
#include <string.h>

int main(void){
    char num[50];
    int i;

    scanf("%s", num);

    //i = strlen(num);
    for (i = 0; num[i] != '\0'; i++);

    if (num[i-1] % 2 == 0)
        printf("1");
    else
        printf("0");
}