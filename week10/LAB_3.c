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

int selection(int *A, int p, int r, int n){
    int q;
    int ranking;

    if(p < r){
        q = partition(A, p, r);
        ranking = q - p + 1;

        if(n == ranking)
            return A[q];
        else if(n > ranking)
            return selection(A, q + 1, r, n - ranking);
        else
            return selection(A, p, q - 1, n);
    } 
}

int main(void){
    int *A;
    int n, i, r;

    scanf("%d", &n);
    scanf("%d", &r);
    A = (int*)malloc(sizeof(int)*n);

    srand(time(NULL));
    for(i = 0; i < n; i++)
        A[i] = rand() % 1000;

    for(i = 0; i < n; i++)
        printf("%d ", A[i]);
        printf("\n");

        printf("%d ", selection(A, 0, n-1, r));

        free(A);
}