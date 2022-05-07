#include <stdio.h>
#include <stdlib.h>

int isSequence(int a[], int size){
    int i;
    int k = a[1] - a[0];

    for (i = 2; i < size; i++)
        if (k != a[i] - a[i-1])
            return 0;

    return 1;
}

int pick(int A[], int item[], int n, int picked[], int m, int toPick){
    int i;
    int ret = 0;
    int lastIndex;
    int *result;
    result = (int*)malloc(sizeof(int)*m);
    int minCul = m;
    int count;

    if (toPick == 0) {
        for (i = 0; i < m; i++)
            result[i] = picked[i] + A[i];
        
        if(isSequence(result, m)){
            for (i = 0; i < m; i++) {
                count = 0;
                if (picked[i] == 0)
                    count++;
            }
            
            return count;
        }
            
        return -1;
    }
    
    lastIndex = m - toPick - 1;

    for (i = 0; i < n; i++) {
        picked[lastIndex + 1] = item[i];
        int tmp = pick(A, item, n, picked, m, toPick-1);
        if (minCul > temp)
            minCul = temp;
    }
    free(result);
    return ret;

    if (ret == 0)
        return -1;
    return minCul;
}

int main(void){
    int i, n;
    int item[3] = {-1, 0, 1};
    int *A;
    int *picked;

    scanf("%d", &n);
    A = (int*)malloc(sizeof(int) * n);
    picked = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    printf("%d", pick(A, item, 3, picked, n, n));

    free(A);
    free(picked);
    return 0;
}