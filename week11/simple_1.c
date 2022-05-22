#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n, i, max;
    int *numbers;
    int smallIdx;
    int total = 1;
    
    scanf("%d", &n);
    numbers = (int*)malloc(sizeof(int)*n);
    
    for (i = 0; i < n; i++)
        scanf("%d", &numbers[i]);
    
    smallIdx = 0;
    for (i = 1; i < n; i++){
        if(numbers[i] < numbers[smallIdx])
            smallIdx = i;
    }
    
    numbers[smallIdx] += 1;

    for (i = 0; i < n; i++)
        total *= numbers[i];
    
    printf("%d", total);
    return 0;
}