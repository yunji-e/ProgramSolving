#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int *A, int n){
    int i, j, temp;
    for(i = 0; i < n-1; i++){
        int maxIdx = 0;

        for(j = 0; j < n-i; j++)
            if(A[maxIdx] < A[j])
                maxIdx = j;

        temp =  A[maxIdx];
        A[maxIdx] = A[n-i-1];
        A[n-i-1] = temp;
    }
}

int main(void){
    int n, i;
    int *A;

    scanf("%d", &n);

    A = (int*) malloc(sizeof(int)*n);

    srand( time(NULL) );

    for (i = 0; i < n; i++)
        A[i] = rand()%1000;

    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    selectionSort(A, n);
    
    printf("정렬된 후:\n");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    free(A);

    system("pause");

    return 0;
}