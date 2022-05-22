#include <stdio.h>
#include <stdlib.h>

int compress1(char s[]){
    int i;
    int size = 0;
    int index = 0;
    int count = 1;
    for (i = 1; s[i] != '\0'; i++, count++) {
        if(s[i] != s[i-1]){
            if(count != 1){
                s[index++] = count+'0';
                size++;
            }
            s[index++] = s[i-1];
            count = 0;
            size++;
        }
    }
    if(count != 1){
        s[index++] = count+'0';
        size++;
    }
    s[index++] = s[i-1];
    s[index] = '\0';
    size++;
    return size;
}

int main(void){
    char s[1000];

    scanf("%s", &s);
    int size = compress1(s);
    printf("%s\n", s);
    printf("%d\n", size);
    return 0;
}