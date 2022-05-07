#include <stdio.h>
#include <stdlib.h>

void pick(int item[], int n, int *bucket, int m, int toPick){
    int i, lastIndex;

    if (toPick == 0) {
        for (i = 0; i < m; i++) {
            printf("%d", bucket[i]);
        }
        printf("\n");
        return;
    }
    
    lastIndex = m - toPick - 1;
    for (i = 0; i < n; i++) {
        bucket[lastIndex+1] = i;
        pick(item, n, bucket, m, toPick-1); 
    }
}

int main(void){
    int item[] = {0,1,2,3};
    int *bucket;
    int n;

    scanf("%d", &n);
    bucket = (int*) malloc(sizeof(int)*n);
    
    pick(item, 4, bucket, n, n);

    free(bucket);
    system("pause");
}