#include <stdio.h>

int right_max_sum(int A[], int left, int right){
    int sum = A[left];
    int max = sum;
    int i;
    for (i = left + 1; i <= right; i++) {
        sum += A[i];
        if(max < sum)
            max = sum;
    }
    return max;
}

int main(void){
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int max = right_max_sum(A, 3, 5);

    printf("max value = %d\n", max);
}