#include <stdio.h>
#include <stdlib.h>

void selectionSort(int A[], int n, int start){
    int i, j;
    int temp;

    for (i = start; i < n; i++) {
        int minIndex = i;
        for (j = i; j < n; j++){
            if (A[minIndex] > A[j])
                minIndex = j;
        }
        temp = A[i];
        A[i] = A[minIndex];
        A[minIndex] = temp;
    }
}

int main(void){
    int *A;
    int i, n, start;

    scanf("%d", &n);

    A = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    scanf("%d", &start);

    selectionSort(A, n, start);
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);

    free(A);
    return 0;
}