#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*e4 ������ 20210804 ��ǻ���а� 1�г�*/

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
		printf("����.\n");
	else
		printf("%d��°�� �ִ�.\n", search + 1);
}

int searchKey(int arr[], int key) {
	int i;
	for (i = 0; i < 5; i++)
		if (arr[i]==key)
			return i;
	return 0;
}