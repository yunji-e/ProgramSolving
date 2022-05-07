#include <stdio.h>
#include <string.h>

int isMulN(char num[], int length, int n){
    int sum = 0;
    int i;

    switch (n) {
    case 2:
    case 5:
        if ((num[length - 1] - '0') % n == 0)
            return 1;
        break;
    case 3:    
        for (i = 0; i < length; i++)
            sum = sum + num[i] - '0';
        if (sum % 3 == 0)
            return 1;
        break;
    case 4:
        if(((num[length-2] - '0') * 10 + (num[length-1] - '0')) % 4 == 0)
            return 1;
        break;
    }
    return 0;
}

int main(void){
    char num[50];
    int i;
    int length;

    scanf("%s", num);

    //length = strlen(num)
    for (length = 0; num[length] != '\0'; length++);

    for (i = 2; i <= 5; i++)
        printf("%d", isMulN(num, length, i));
}