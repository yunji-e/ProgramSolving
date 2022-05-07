#include <stdio.h>

void echo(int arr[], int n) {
	int i;

	printf("Enter 5 numbers: ");
	for (i = 0; i < 5; i++)
		scanf("%d", &arr[i]);

	printf("echo: ");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
}

void reverse(int arr[], int n) {
	int i;
	printf("reverse: ");
	for (i = 0; i < n; i++)
		printf("%d ", arr[n - 1 - i]);
}

int main(void) {
	int arr[5];
	int i;

	echo(arr, 5);
	printf("\n");
	reverse(arr, 5);
	printf("\n");
}