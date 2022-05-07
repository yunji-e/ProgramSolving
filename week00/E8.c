#include <stdio.h>
#include <string.h>

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