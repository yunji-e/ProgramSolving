#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void display(char b[][3]) {
	int i, j;

	printf("    0 1 2\n");
	printf("   ------\n");
	for (i = 0; i < 3; i++){
		printf("%d |", i);
		for (j = 0; j < 3; j++)
			printf(" %c", b[i][j]);
		printf("\n");
	}
}

int isWin(char b[][3], int r, int c) {
	int i;
	int count = 1;
	char player = b[r][c];
	int ri, ci;

	ri = r - 1;
	while (ri >= 0 && player == b[ri][c]) {
		ri--;
		count++;
	}
	ri = r + 1;
	while (ri < 3 && player == b[ri][c]) {
		ri++;
		count++;
	}
	if (count == 3)
		return 1;
	count = 1;

	ci = c - 1;
	while (ci >= 0 && player == b[r][ci]) {
		ci--;
		count--;
	}
	ci = c + 1;
	while (ci < 3 && player == b[r][ci]) {
		ci++;
		count++;
	}
	if (count == 3)
		return 1;
	count = 1;

	ci = c - 1;
	ri = r - 1;
	while (ci >= 0 && ri >= 0 && player == b[ri][ci]) {
		ci--;
		ri--;
		count++;
	}
	ci = c + 1;
	ri = r + 1;
	while (ci < 3 && ri < 3 && player == b[ri][ci]) {
		ci++;
		ri++;
		count++;
	}
	if (count == 3)
		return 1;
	count = 1;

	ci = c + 1;
	ri = r - 1;
	while (ci < 3 && ri >= 0 && player == b[ri][ci]) {
		ci++;
		ri--;
		count++;
	}
	ci = c - 1;
	ri = r + 1;
	while (ci >= 0 && ri < 3 && player == b[ri][ci]) {
		ci--;
		ri++;
		count++;
	}
	if (count == 3)
		return 1;

	return 0;
}

int main(void) {
	char board[3][3];
	char player;
	int count = 0;
	int r, c;
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			board[i][j] = ' ';

	do {
		player = count % 2 == 0 ? 'X' : 'O';
		display(board);
		printf("Player %c(За ї­): ", player);
		scanf("%d %d", &r, &c);
		if (board[r][c] != ' ')
			continue;
		board[r][c] = player;
		if (isWin(board, r, c))
			break;
		count++;
	} while (count < 9);

	display(board);
	if (count == 9)
		printf("Nobody wins!\n");
	else
		printf("Player %c wins!\n", player);
}