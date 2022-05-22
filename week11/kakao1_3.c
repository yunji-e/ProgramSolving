#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compress3(char s[], char comp[], int n){
    int i;
    int size = strlen(s);
    int index = 0;
    int count = 1;
    char *temp1, *temp2;
    temp1 = (char*)malloc(sizeof(char)*n);
    temp2 = (char*)malloc(sizeof(char)*n);

    for (i = 0; i < size; i++)
        comp[i] = '\0';

    for (i = n; i < size; i+=n, count++) {
        strncpy(temp1, &s[i-n], n);
        strncpy(temp2, &s[i], n);
        if(strncmp(temp1, temp2, n)!=0){
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
                
            strncpy(&comp[index], temp1, n);
            index+=n;
            count = 0;
        }
    }
    if(i == size){
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
        strncpy(&comp[index], temp1, n);
        index+=n;
        comp[index] = '\0';
    }
    else
        strcat(&comp[index++], &s[i-n]);

    free(temp1);
    free(temp2);

    return strlen(comp);
}

int main(void){
    char s[1000];
    char comp[1000];
    int smallest = INT_MAX;
    int i, temp, size;

    scanf("%s", &s);
    size = strlen(s);
    for (i = 1; i <= size/2; i++){
        temp = compress3(s, comp, i);
        if(temp < smallest)
            smallest = temp;
    }
    printf("%d\n", smallest );
    return 0;
}