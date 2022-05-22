#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int printArr(int arr[], int n){
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int partition(int a[], int p, int r){
    int i, j, temp;
    for (i = p, j = p; i < r; i++) {
        if(a[i] < a[r]){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            j++;
        }
    }
    temp = a[r];
    a[r] = a[j];
    a[j] = temp;
    
    return j;
}

int selectionSmall(int a[], int p, int r, int search){
    int i;
    int q;

    q = partition(a, p, r);
    if (q != search) {
        if(q > search)
            return selectionSmall(a, p, q - 1, search);
        else
            return selectionSmall(a, q + 1, r, search);
    }
    
    return a[q];
}

int main(void){
    int n, i, search;
    int *A;
    
    srand(time(NULL));

    printf("Enter the number of numbers: ");
    scanf("%d", &n);
    A = (int*)malloc(sizeof(int)*n);

    printf("Nth small number?: ");
    scanf("%d", &search);

    for (i = 0; i < n; i++)
        A[i] = rand()%100;
    
    printArr(A, n);
    printf("%dth small number is %d\n", search, selectionSmall(A, 0, n-1, search-1));
    free(A);
    return 0;
}