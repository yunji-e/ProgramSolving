#include <stdio.h>
#include <stdlib.h>
//int pick() (리턴값으로 count대체)
void pick(int *items, int n, int *picked, int m , int toPick, int sum, int *count){
    int i;
    int smallest;
    int lastIndex = m - toPick - 1;
    //int ret = 0;

    if(sum == 0){
        //picked[lastIndex+1] = -1;
        //for (i = 0; picked[i] != -1 ; i++)  
            //printf("%d ", items[picked[i]]);
        //printf("\n");
        (*count)++;
        return; //return 1;
    }
    if(toPick == 0 || sum < 0)
        return; //return 0;
    
    if(toPick == m)
        smallest = 0;
    else
        smallest = picked[lastIndex];
        
    for (i = smallest; i < n; i++) {
        picked[lastIndex+1] = i;
        pick(items, n, picked, m, toPick - 1, sum - items[i], count);
            //ret = ret + pick()
    }

    //return ret
}

int main(void){
    int coin[] = {10, 50, 100, 500};
    int *picked;
    int charge;
    int count = 0;

    scanf("%d", &charge);
    if (charge % 10 > 0 || charge == 0)
        printf("0");
    else{
        picked = (int*)malloc(sizeof(int)*charge/10);
        pick(coin, 4, picked, charge/10, charge/10, charge, &count);
        printf("%d", count);
        free(picked);
    }
}