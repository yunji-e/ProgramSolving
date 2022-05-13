#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int A[], int p, int r){
    int i, j, temp;
    for (i = p, j = p; j < r ; j++)
        if (A[j] < A[r]){
            temp = A[j];
            A[j] = A[i];
            A[i] = temp;
            i++;
        }
        temp = A[i];
        A[i] = A[r];
        A[r] = temp;
    return i;
}

void quickSort(int A[], int p, int r){
    int q;
    if(p < r){
        q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
    return;
}

void printList(int A[], int s, int e){
    int i;
    for (i = s; i <= e; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main(void){
    int *list;
    int i, n;

    srand(time(NULL));

    scanf("%d", &n);
    list = (int*)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++)
        list[i] = rand()%100;
    printList(list, 0, n-1);
    quickSort(list, 0, n-1);
    printList(list, 0, n-1);

    free(list);
    return 0;
}