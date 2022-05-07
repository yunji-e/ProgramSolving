#include <stdio.h>
#include <string.h>

void reverse(char src_s[], char s[]){
    int i;
    int length = strlen(src_s);
    for (i = 0; i < length; i++)
        s[i] = src_s[length - i - 1];
    s[i] = '\0';
}

int countCarry(char str1[], char str2[]){
    char s1[101];
    char s2[101];

    int i, n1, n2;
    int carryFlag = 0;
    int carry = 0;
    int length1 = strlen(str1);
    int length2 = strlen(str2);

    reverse(str1, s1);
    reverse(str2, s2);

    for (i = 0; i < length1 || i < length2; i++) {
        n1 = (i < length1) ? s1[i] - '0' : 0;
        n2 = (i < length2) ? s2[i] - '0' : 0;

        if (n1 + n2 + carryFlag >= 10){
            carryFlag = 1;
            carry++;
        }
        else
            carryFlag = 0;
    }

    return carry;
}

int main(void){
    char str1[101];
    char str2[101];

    scanf("%s", str1);
    scanf("%s", str2);

    printf("%d", countCarry(str1, str2));

    return 0;
    /*
    char n1[101] = {0, };
    char n2[101] = {0, };
    char rev_n1[101] = {0, };
    char rev_n2[101] = {0, };

    int i;
    int len_n1;
    int len_n2;
    int carry = 0;
    int carry_count = 0;

    scanf("%s", n1);
    scanf("%s", n2);

    len_n1 = strlen(n1);
    len_n2 = strlen(n2);

    for(i = 0; i < len_n1; i++)
        rev_n1[i] = n1[len_n1 - i - 1];

    for(i = 0; i < len_n2; i++)
        rev_n2[i] = n2[len_n2 - i - 1];

    max_len = (len_n1 > len_n2) ? len_n1 : len_n2;

    for(i = 0; i < max_len; i++){
        int t1 = (rev_n1[i] != NULL) ? 0 : rev_n1[i] - '0'; //혹은 0으로 초기화했으므로 NULL 대신 0도 괜찮음
        int t2 = (rev_n2[i] != NULL) ? 0 : rev_n2[i] - '0';
        int t3 = t1 + t2 + carry;
        if (t3 > 9){
            carry = 1;
            carry_count++;
        }
        else
            carry = 0;
    }

    printf("%d\n", carry_count);
    */
}