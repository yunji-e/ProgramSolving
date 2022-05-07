#include <stdio.h>

#define WIDTH 10
#define HEIGHT 10

int screen[WIDTH][HEIGHT] = {
0, 0, 0,-1,-1,-1,-1,-1,-1,-1,
-1,-1, 0,-1,-1,-1,-1,-1,-1,-1,
-1, 0, 0, 0, 0, 0, 0,-1,-1,-1,
-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
-1,-1, 0, 0, 0,-1, 0, 0, 0,-1,
-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
-1,-1,-1,-1, 0,-1, 0,-1, 0,-1,
-1,-1,-1,-1, 0,-1,-1,-1, 0,-1,
-1,-1,-1,-1, 0, 0, 0, 0, 0, 0
};

void flood_fill(int x, int y)
{
	int num = 9;
	if (screen[x][y] == 0 && x>=0 && x<WIDTH && y >= 0 && y<HEIGHT) {
		screen[x][y] = num;
		flood_fill(x, y + 1);
		flood_fill(x, y - 1);
		flood_fill(x + 1, y);
		flood_fill(x - 1, y);
	}
}

void printTable(int s[][HEIGHT]) {
	int i, j;
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++)
			printf("%2d", s[i][j]);
		printf("\n");
	}
	printf("\n");
}

int main(void) {
	printTable(screen);
	flood_fill(5, 3);
	printTable(screen);
}