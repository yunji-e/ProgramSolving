#include <stdio.h>
#include <stdlib.h>

int right_max_sum(int A[], int left, int right) {
    int sum = A[left];
    int max = sum;
    int i;
    for (i = left + 1; i <= right; i++) {
        sum += A[i];
        if (max < sum)
            max = sum;
    }
    return max;
}

int left_max_sum(int A[], int left, int right) {
    int sum = A[right];
    int max = sum;
    int i;
    for (i = right - 1; i >= left; i--) {
        sum += A[i];
        if (max < sum)
            max = sum;
    }
    return max;
}

int max_subarray(int A[], int left, int right) {
    int q;
    int v1, v2, v3;
    if (left >= right)
        return A[left];
    q = (left + right) / 2;
    v1 = max_subarray(A, left, q - 1);
    v2 = max_subarray(A, q + 1, right);
    v3 = -A[q] + right_max_sum(A, q, right) + left_max_sum(A, left, q);

    if (v1 > v2)
        if (v1 > v3)
            return v1;
        else if(v2 > v3)
            return v2;
        else
            return v3;
    else if (v2 > v3)
        return v2;
    else
        return v3;
}

int main(void) {  
    int i, n;
    int* A;

    scanf("%d", &n);
    A = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    int lastIndex = n - 1;
    int max = max_subarray(A, 0, lastIndex);
    printf("%d", max);
    return 0;
}