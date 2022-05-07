#include <stdio.h>
#include <stdlib.h>

void pick(int* items, int n, int* picked, int m, int toPick) {
    int i, j;
    int lastIndex;
    int smallest;
    int sum = 0;

    lastIndex = m - toPick - 1;

    

    //0~lastIndex까지의 합 구해서 입력값보다 크면 출력후 리턴 

    //0으로 모든 조합 뽑은 후 조건에 맞는 조합만 출력
    /*
    if (toPick == 0) {
        for (i = 0; i < m; i++){
            if(picked[i]==1)
                sum+=1000;
            else if(picked[i]==2)
                sum+=5000;
            else if(picked[i]==3)
                sum+=10000;
        }
        if(sum == m*1000){
            for (i = 0; i < m; i++) {
                if(picked[i]==0) continue;
                printf("%d ", items[picked[i]]);
            }
            printf("\n");
        }
        return;
    }
    */

    if(m==toPick)
        smallest = 0;
    else
        smallest = picked[lastIndex];
    
    for (i = smallest; i < n; i++) {
        picked[lastIndex + 1] = i;
        pick(items, n, picked, m, toPick - 1);
    }
}

int main(void) {
    int items[] = { 0, 1000, 5000, 10000 };
    //0원 넣는 방법/money가 되면 break하는 방법
    int* picked;
    int money;

    scanf("%d", &money);
    picked = (int*)malloc(sizeof(int) * money/1000);
    pick(items, 4, picked, money / 1000, money / 1000); 
}