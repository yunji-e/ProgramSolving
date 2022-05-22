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

/*
int calOperation(int *n1, int *n2, int k){
    
}
int pick(int *items, int n, int* bucket, int* num1, int* num2){
    int i, lastIndex, smallest, iteml
    int result;
    int opNum, min;
    min = 1000;
    opNum = 1000;
    if(k == 0){
        for(i = 0; i < bucketSize; i++)
            num2[i] = num1[i] + items[bucket[i]];

        if(isSequence(num2, bucketSize))
            opNum = calOperation(num1, num2, bucketSize);
    }


    smallest = 0;

    for(item = smallest; item < n; item++){
        bucket[lastIndex+1] = item;
        result = pick(itmes, n, bucket, bucketSize, k-1, num1, num2)
    }

    return min;
}
*/

int pick(int A[], int item[], int n, int picked[], int m, int toPick, int min){
    int i;
    int ret;
    int lastIndex;
    int *result;
    result = (int*)malloc(sizeof(int)*m);
    if (toPick == 0) {
        for (i = 0; i < m; i++)
            result[i] = picked[i] + A[i];
        
        if(isSequence(result, m)){
            int count = 0;
            for (i = 0; i < m; i++)
                if(picked[i]!=0)
                    count++;           
            
            return count;
        }
        return -1;
    }
    
    lastIndex = m - toPick - 1;

    for (i = 0; i < n; i++) {
        picked[lastIndex + 1] = item[i];
        ret = pick(A, item, n, picked, m, toPick-1, min);
        if (ret < min && ret != -1)
            min = ret;
    }
    free(result);
    return min;
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

    int min = pick(A, item, 3, picked, n, n, n + 1);
    if (min == n+1)
        min = -1;

    printf("%d\n", min);

    free(A);
    free(picked);
    return 0;
}