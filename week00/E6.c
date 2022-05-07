#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
	int i;
	char con = 'y';

	srand(time(NULL));

	while (con == 'y') {
		printf("***?¥æ? ??? ??????***\n");
		printf("???? ???: ");
		for (i = 0; i < 6; i++)
			printf("%d ", rand() % 45 + 1);

		printf("\n");
		printf("??? ??????©£?????? (y/n):");
		scanf("%c", &con);
		getchar();
		printf("\n");
	}
}