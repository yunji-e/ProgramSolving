#include <stdio.h>

int left_max_sum(int A[], int left, int right){
    int sum = A[right];
    int max = sum;
    int i;
    for (i = right - 1; i >= left; i--) {
        sum += A[i];
        if(max < sum)
            max = sum;
    }
    return max;
}

int main(void){
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int max = left_max_sum(A, 4, 6);

    printf("max value = %d\n", max);
}