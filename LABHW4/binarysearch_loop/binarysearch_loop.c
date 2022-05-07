#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[] = { 1,3,5,6,7,8,11,20,30 };

int search_binary(int key, int low, int high) {
    int middle;

    while (low <= high) {
        middle = (low + high) / 2;
        if (key < arr[middle])
            high = middle - 1;
        else if (key > arr[middle])
            low = middle + 1;
        else
            return middle;
    }

    return -1;
}

int main(void) {
    int i;
    int key;

    printf("Sorted list: ");
    for (i = 0; i < 8; i++)
        printf("%d ", arr[i]);

    printf("\nEnter key:");
    scanf("%d", &key);

    printf("%d", search_binary(key, 0, 8));
    return 0;
}