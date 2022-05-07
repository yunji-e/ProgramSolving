#include <stdio.h>

void input(int arr[], int n);
int isEqual(int* a1, int* a2, int n);

int main(void) {
	int arr1[5];
	int arr2[5];
	
	printf("Enter 1st arr: ");
	input(arr1, 5);
	printf("Enter 2nd arr: ");
	input(arr2, 5);

	if (isEqual(arr1, arr2, 5))
		printf("�� ���� �迭�� ����.\n");
	else
		printf("�� ���� �迭�� �ٸ���.\n");
}

void input(int arr[], int n) {
	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
}

int isEqual(int* a1, int* a2, int n) {
	int i;
	for (i = 0; i < n; i++, *a1++, *a2++)
		if (*a1 != *a2)
			return 0;
	
	return 1;
}