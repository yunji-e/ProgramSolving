#include <stdio.h>
#include <stdlib.h>

void testPrint(int* a, int size){
    int i;
    for(i = 0; i < size; i++)
        printf("%d ", a[i]);
        printf("\n");
}

int solution(int a[], int n, int m){
    int i, j;
    int index = m;
    int min;

    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++)
            if(a[j] == n - i)
                break;
        if(j == m)
            a[index++] = n - i;
    }

    for (i = 0; i < m; i++){
        min = -1;
        for(j = 0; j < n - m; j++){
            if(a[m+j] > a[m-i-1] )
                if(min > a[m+j] || min == -1)
                    min = a[m+j];
        }
        if (min != -1)
            break;
    }

    int lastIdx = m - i - 1;
    if(lastIdx == -1)
        return -1;

    for (i = 0; i < m - lastIdx; i++)
        a[lastIdx+i] = min + i;

    if(a[m-1] > n)
        return -1;
    return 1;
}

int main(void){
    int n, m, i;
    int *A;

    scanf("%d %d", &n, &m);
    A = (int*)malloc(sizeof(int)*n);
    for (i = 0; i < m; i++)
        scanf("%d", &A[i]);

    if(solution(A, n, m)>0)
        testPrint(A, m);
    else
        printf("-1\n");

    free(A);
    return 0;
}