#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*e3 이윤지 20210804 컴퓨터학과 1학년*/

int total(int n) {
	if (n == 1)
		return 1;

	return n + total(n - 1);
}

int main(void) {
	int n;
	
	while (1) {
		printf("Input a number(-1 for exit): ");
		scanf("%d", &n);

		if (n == -1)
			break;

		printf("1부터 %d까지의 합은 %d\n", n, total(n));
	}
}