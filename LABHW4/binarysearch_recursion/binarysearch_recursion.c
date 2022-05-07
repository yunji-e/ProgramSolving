#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[] = { 1,3,5,6,7,8,11,20,30 };

int search_binary(int key, int low, int high) {
	int middle;
	if (low <= high) {
		middle = (low + high) / 2;
		if (key == arr[middle])
			return middle;
		else if (key < arr[middle])
			return search_binary(key, low, middle - 1);
		else
			return search_binary(key, middle + 1, high);
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