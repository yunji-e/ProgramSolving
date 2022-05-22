#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress2(char s[], char comp[]){
    int i;
    int size = strlen(s);
    int index = 0;
    int count = 1;
    char temp1[3], temp2[3];
    for (i = 2; i < size; i+=2, count++) {
        strncpy(temp1, &s[i-2], 2);
        strncpy(temp2, &s[i], 2);
        if(strncmp(temp1, temp2, 2)!=0){
            if(count != 1){
                if(count < 10){
                    comp[index++] = count + '0';
                }
                else if(count < 100){
                    comp[index++] = count / 10 + '0';
                    comp[index++] = count % 10 + '0';
                }
                else if(count < 1000){
                    comp[index++] = count / 100 + '0';
                    comp[index++] = count / 10 % 10 + '0';
                    comp[index++] = count % 10 + '0';
                }
            }
                
            strncpy(&comp[index], temp1, 2);
            index+=2;
            count = 0;
        }
    }
    if(i == size){
        if(count < 10){
            comp[index++] = count + '0';
        }
        else if(count < 100){
            comp[index++] = count / 10 + '0';
            comp[index++] = count % 10 + '0';
        }
        else if(count < 1000){
            comp[index++] = count / 100 + '0';
            comp[index++] = count / 10 % 10 + '0';
            comp[index++] = count % 10 + '0';
        }
        strncpy(&comp[index], temp1, 2);
        index+=2;
    }
    else
        comp[index++] = s[size-1];
    comp[index] = '\0';
}

int main(void){
    char s[1000];
    char comp[1000] = {'\0'};
    
    scanf("%s", &s);
    compress2(s, comp);
    printf("%s\n", comp);
    printf("%d\n", strlen(comp));
    return 0;
}