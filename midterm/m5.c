#include <stdio.h>
#include <stdlib.h>

int isSequence(int a[], int size){
    int i;
    int k = a[1] - a[0];

    //if(size<=2)
    //  return 1;
    for (i = 2; i < size; i++)
        if (k != a[i] - a[i-1])
            return 0;

    return 1;
}


int main(void){
    int i, n;
    int *a;

    scanf("%d", &n);
    a = (int*)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
        
    printf("%d", isSequence(a, n));

    free(a);
    return 0;
}