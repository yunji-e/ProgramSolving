#include <stdio.h>

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

int main(void){
    int n, i;
    int a[100];
    int start;

    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &start);

    selectionSortNew(a, start, n);
    testPrint(a, n);

    return 0;
}