#include <stdio.h>
#include <stdlib.h>

void testPrint(int* a, int size){
    int i;
    for(i = 0; i < size; i++)
        printf("%d ", a[i]);
        printf("\n");
}

void selectionSortNew(int A[], int left, int n){
    int i, j;
    int maxIndex;
    int temp;
    
    for (i = left; i < n; i++) {
        maxIndex = left;
        for (j = left + 1; j < n + left - i; j++) {
            if (A[maxIndex] < A[j])
            maxIndex = j;
        }
        
        temp = A[maxIndex];
        A[maxIndex] = A[n + left - i - 1];
        A[n + left - i - 1] = temp;
    }
}

void solution(int a[], int n){
    int i, pivot, temp;
    int index;

    for (i = n-1; i > 0; i--) {
        if(a[i-1] < a[i])
            break;
    }
    
    pivot = i - 1;
    if(pivot == -1){
        printf("-1");
        return;
    }

    index = pivot+1;
    for (; i < n; i++) {
        if(a[index] > a[i] && a[pivot] < a[i])
            index = i;
    }
    temp = a[index];
    a[index] = a[pivot];
    a[pivot] = temp;
    selectionSortNew(a, pivot + 1, n);
    testPrint(a, n);
}

int main(void){
    int n, i;
    int *A;
    int count = 0;

    scanf("%d", &n);
    A = (int*)malloc(sizeof(int)*n);

    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    solution(A, n);

    return 0;
}