#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int *A, int n){
    int i, j , temp;

    for(i = 0; i < n-1; i++)
        for (j = 0; j < n-i-j; j++)
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
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

    bubbleSort(A, n);

    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    free(A);

    system("pause");

    return 0;
}