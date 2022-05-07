#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int *A, int n){
    int i, j, k, temp;
    for(i = 1; i < n; i++){
        for (j = 0; j < i; j++)
            if(A[i]<A[j]) 
                break;

        temp = A[i];
        for ( k = i; k > j; k--)
            A[k] = A[k-1];
        A[j] = temp;
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

    insertionSort(A, n);
    
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    free(A);

    return 0;
}