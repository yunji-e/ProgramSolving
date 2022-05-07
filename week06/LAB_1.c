#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    free(A);
    system("pause");
    return 0;
}