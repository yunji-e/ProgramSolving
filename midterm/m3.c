#include <stdio.h>
#include <string.h>

void reverse(char src_s[], char s[]){
    int i;
    int length = strlen(src_s);
    for (i = 0; i < length; i++)
        s[i] = src_s[length - i - 1];
    s[i] = '\0';
}

int countMinusCarry(char n1[], char n2[]){
    int minusCarry = 0;
    int carryFlag = 0;
    int i, num1, num2;

    char r_n1[10];
    char r_n2[10];
    reverse(n1, r_n1);
    reverse(n2, r_n2);
    
    int len1 = strlen(n1);
    int len2 = strlen(n2);

    for (i = 0; i < len1 || i < len2; i++) {
        num1 = (i < len1) ? r_n1[i] - '0' : 0;
        num2 = (i < len2) ? r_n2[i] - '0' : 0;

        if (num1 - num2 - carryFlag < 0){
            carryFlag = 1;
            minusCarry++;
        }
        else
            carryFlag = 0;
    }
    
    return minusCarry;
}

int main(void){
    char n1[10];
    char n2[10];

    scanf("%s %s", n1, n2);
    printf("%d", countMinusCarry(n1, n2));

    return 0;
}