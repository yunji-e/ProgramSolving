#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/*e8 이윤지 20210804 컴퓨터학과 1학년*/

void input(char arr[]) {
	scanf("%s", arr);
}

void reverse(char arr[]) {
	int i;
	int length =  strlen(arr);

	printf("Reverse: ");
	for (i = 0; i < length; i++)
		printf("%c", arr[length - i - 1]);
}


int main(void) {
	char name[20];

	printf("Enter your name: ");
	input(name);
	reverse(name);
}