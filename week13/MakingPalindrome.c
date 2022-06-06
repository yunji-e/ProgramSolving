#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char *s, int start, int end){
    int i;
    
    for (i = start; i < (start+end) / 2; i++){
        if(s[i] != s[end - i + start])
            return 0;
    }
        
    return 1;
}

void MakingPalindrome(char *s){
    int i;
    int memo;
    int size;

    for(size = 0; s[size] != '\0'; size++);
    memo = size - 1;
    
    if(size == 2){
        s[size++] = s[0];
        s[size] = '\0';
        return;
    }
    
    for(i = 3; i <= size; i += 2)
        if(isPalindrome(s, size-i, size-1))
            memo = size-i;
    
    for (i = memo-1; i >= 0; i--)
        s[size++] = s[i];
    s[size] = '\0';
}

int main(void){
    char s[100];

    scanf("%s", s);
    MakingPalindrome(s);
    printf("%s", s);

    return 0;
}