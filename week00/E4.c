#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*e4 이윤지 20210804 컴퓨터학과 1학년*/

int searchKey(int arr[], int key);

int main(void) {
	int arr[5];
	int i, key, search;

	printf("Enter 5 int: ");

	for (i = 0; i < 5; i++)
		scanf("%d", &arr[i]);

	printf("Enter a key: ");
	scanf("%d", &key);

	search = searchKey(arr, key);

	if (search == 0)
		printf("없다.\n");
	else
		printf("%d번째에 있다.\n", search + 1);
}

int searchKey(int arr[], int key) {
	int i;
	for (i = 0; i < 5; i++)
		if (arr[i]==key)
			return i;
	return 0;
}