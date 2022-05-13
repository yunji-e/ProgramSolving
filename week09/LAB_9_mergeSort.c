#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int A[], int p, int q, int r){
    int *B;
    int i, j, t;
    B = (int*)malloc(sizeof(int)*(r-p+1));
    i = p;
    j = q + 1;
    t = 0;
    
    while(i <= q && j <= r){
        if(A[i] < A[j]){
            B[t] = A[i];
            i++;
        }
        else{
            B[t] = A[j];
            j++;
        }
        t++;
    }

    if (i > q)
        for(;j<=r;j++, t++)
            B[t] = A[j];
    else
        for(;i<=q;i++, t++)
            B[t] = A[i];

    for (i = p, t = 0; i <= r; i++, t++)
        A[i] = B[t];

    free(B);
}

void mergeSort(int A[], int p, int r){
    if(p < r){
        int q = (p + r)/2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

void printList(int A[], int s, int e){
    int i;
    for (i = s; i < e; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main(void){
    int i, n;
    int *A;

    srand(time(NULL));

    scanf("%d", &n);
    A = (int*)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++)
        A[i] = rand()%100;
    printList(A, 0, n);
    mergeSort(A, 0, n-1);
    printList(A, 0, n);

    free(A);
    return 0;
}