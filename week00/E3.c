#include <stdio.h>

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

		printf("1���� %d������ ���� %d\n", n, total(n));
	}
}