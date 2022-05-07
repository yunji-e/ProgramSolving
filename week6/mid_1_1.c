#include <stdio.h>
#include <string.h>

void reverse(char src_s[], char s[]){
    int i;
    int length = strlen(src_s);
    for (i = 0; i < length; i++)
        s[i] = src_s[length - i - 1];
    s[i] = '\0';
}

int main(void){
    char src_s[101];
    char s[101];

    scanf("%s", src_s);
    reverse(src_s, s);
    printf("%s\n", s);

    return 0;
}