#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int *arr, int n){
    int i, j, temp, count;
    
    for (i = 0; i < n; i++) {
        count = 0;
        for (j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                count++;
            }
        }

        if (count == 0)
            break;

        j = 0;
        printf("i = %d:", i);
        for (j = 0; j < n; j++)
            printf("%4d", arr[j]);
        printf("\n");
    }
}

int main(void){
    int i, n;
    int *arr;

    printf("Enter a number: ");
    scanf("%d", &n);
    arr = (int*)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
        arr[i] = rand() % 100;
    
    printf("초기 :");
    for (i = 0; i < n; i++)
        printf("%4d", arr[i]);
    printf("\n");

    bubbleSort(arr, n);

    printf("정렬 :");
    for (i = 0; i < n; i++)
        printf("%4d", arr[i]);
    printf("\n");

    free(arr);
    
    system("pause");
    return 0;
}