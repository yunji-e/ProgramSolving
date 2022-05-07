#include <stdio.h>

int pow(int n, int r) {
	if (r == 1)
		return n;
	else if (r % 2 == 0) {
		int midleV = pow(n, r / 2);
		return midleV * midleV;
	}
	else {
		int midleV = pow(n, r / 2);
		return n * midleV * midleV;
	}
}

int main(void) {
	int r;
	printf("Enter a number: ");
	scanf("%d", &r);
	printf("%d", pow(2, r));
}