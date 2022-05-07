#include <stdio.h>

void pick(int n, int picked[], int m, int toPick) {
    int i;
    int smallest;
    int lastIndex;

    //base case
    if (toPick == 0) {
        for (i = 0; i < m; i++)
            printf("%d", picked[i]);
        printf("\n");
        return;
    }

    //reculsive case
    lastIndex = m - toPick - 1;
    if (m == toPick) //array null, lastIndex == -1
        smallest = 0;
    else
        smallest = picked[lastIndex] + 1;

    for (i = smallest; i < n; i++) { //smallest~n(¼ö ¹üÀ§)
        picked[lastIndex + 1] = i;
        pick(n, picked, m, toPick - 1);
    }

}

int main(void) {
    int picked[3];

    pick(7, picked, 3, 3);
    //ÀüÃ¼ ¼ö, »ÌÀº ¹è¿­, ÃÑ »ÌÀ» °³¼ö, »Ì¾Æ¾ßÇÒ °³¼ö

    return 0;
}