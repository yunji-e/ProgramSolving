#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[] = { 1,3,5,6,7,8,11,20,30 };

int sorted_seq_search(int key, int low, int high) {
	int i;
	for (i = low; i <= high; i++) {
		if (key < arr[i])
			break;
	}
	if (key == arr[i - 1])
		return i - 1;
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

	printf("%d", sorted_seq_search(key, 0, 8));
	return 0;
}