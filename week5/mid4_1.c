#include <stdio.h>
#include <stdlib.h>

int flag = 0;

//int
void solution(char items[], int n, char bucket[], int N, int m, int toPick){
    int i;
    int lastIndex;

    if (toPick == 0) {
        int sum = 0;

        for (i = 0; i < m; i++) {
            if (bucket[i] == 0)
                sum += (i + 1);
            else
                sum -= (i - 1);
        }

        if (sum == N || sum == -N)
            flag = 1;
        return;
    }

    lastIndex = m - toPick - 1;
    for (i = 0; i < n; i++) {
        bucket[lastIndex+1] = i;
        solution(items, n, bucket, N, m, toPick - 1);
    }

    /*
    int i, lastIndex;
    int ret = 0;

    if(toPick == 0){
        int picked_index;
        int sum = 0;

        for(i = 0l i < m; i++){
            picked_index = picked[i];
            printf("%c%d", item[picked_index]==1?'+':'-', (i+1));
            sum += item[picked_index]*(i+1);
        }
        printf("=%d\n", sum);

        if(sum == target)
            return 1;

        return 0;
    }

    lastIndex = m - toPick - 1;

    for(i = 0; i < n; i++){
        picked[lastIndex+1] = i;
        ret += pick(item, n, picked, m, toPick - 1, target);
    }

    return ret;
    */
}

int main(void){
    int n, N;
    char items[] = { '+', '-' }; //int형 1, -1쓰는게 더 용이
    //int items[] = {1, -1};
    char *bucket;

    scanf("%d %d", &n, &N);
    bucket = (char*)malloc(sizeof(char)*n);

    if (N != 0)
        solution(items, 2, bucket, N, n, n);

    //printf("%d", solution(~));
    
    printf("%d", flag);
    free(bucket);
}