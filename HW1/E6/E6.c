#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*e6 이윤지 20210804 컴퓨터학과 1학년*/

int main(void) {
	int i;
	char con = 'y';

	srand(time(NULL));

	while (con == 'y') {
		printf("***로또 번호 생성기***\n");
		printf("생성 번호: ");
		for (i = 0; i < 6; i++)
			printf("%d ", rand() % 45 + 1);

		printf("\n");
		printf("다시 생성하시겠습니까? (y/n):");
		scanf("%c", &con);
		getchar();
		printf("\n");
	}
}