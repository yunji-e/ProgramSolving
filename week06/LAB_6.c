#include <stdio.h>

int left_max_sum(int A[], int left, int right) {
    int i;
    int sum = 0;
    int sum_max = A[right];

    for (i = right; i >= left; i--) {
        sum = sum + A[i];
        if(sum>sum_max)
            sum_max = sum;
    }
    return sum_max;
}

int main() {
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int max = left_max_sum(A, 4, 6); // A[6], A[5]+A[6], A[4]+A[5]+A[6], 중에서 최대값, 즉 3
    //int max = left_max_sum(A, 0, 4); // 최대값 3
    //int max = left_max_sum(A, 4, 7); // 최대값 -2
    printf("max value = %d\n", left_max_sum(A, 4, 6));
    printf("max value = %d\n", left_max_sum(A, 0, 4));
    printf("max value = %d\n", left_max_sum(A, 4, 7));
}