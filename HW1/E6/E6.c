#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*e6 ������ 20210804 ��ǻ���а� 1�г�*/

int main(void) {
	int i;
	char con = 'y';

	srand(time(NULL));

	while (con == 'y') {
		printf("***�ζ� ��ȣ ������***\n");
		printf("���� ��ȣ: ");
		for (i = 0; i < 6; i++)
			printf("%d ", rand() % 45 + 1);

		printf("\n");
		printf("�ٽ� �����Ͻðڽ��ϱ�? (y/n):");
		scanf("%c", &con);
		getchar();
		printf("\n");
	}
}