#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*e5 이윤지 20210804 컴퓨터학과 1학년*/

int main(void) {
	char str[100];
	char key;
	int i;
	int count = 0;

	printf("Enter a String: ");
	scanf("%s", str);

	getchar();

	printf("Enter a character: ");
	scanf("%c", &key);

	for (i = 0; str[i] != '\0'; i++)
		if (str[i] == key)
			count++;

	printf("\'%c\' is appeared %d times", key, count);
}
