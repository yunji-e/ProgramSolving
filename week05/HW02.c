#include <stdio.h>
#include <stdlib.h>

void pick(char *items, int n, char *picked, int m, int toPick){
    int i;
    int lastIndex;
    int sum = 0;

    for (i = 0; i < m; i++){
        if (picked[i] == '+')
            sum += i+1;
        else
            sum -= i+1;
    }

    
    if(toPick == 0){
        if (sum == m + 1 || sum == - m - 1){
            for (i = 0; i < m; i++){
                printf("%c", picked[i]);
                printf("%d ", i+1);
            }
            printf("= %d", sum);
            printf("\n");
        }
        return;
    }

    lastIndex = m - toPick - 1;
    for (i = 0; i < n; i++) {
        picked[lastIndex+1] = items[i];
        pick(items, n, picked, m, toPick - 1);
    }
}

int main(void){
    char items[] = { '+', '-' };
    char *picked;
    int n;

    scanf("%d", &n);
    picked = (char*)malloc(sizeof(int)*n);
    pick(items, 2, picked, n, n);
}