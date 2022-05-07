#include <stdio.h>

int isPrime(int n) {
	int i;
	for (i = 2; i < n; i++)
		if (n % i == 0)
			break;
	if (i == n)
		return 1;
	else
		return 0;
}

int main(void) {
	int i;
	for (i = 1; i <= 30; i++)
		if (isPrime(i))
			printf("%d ", i);
}