#include <stdio.h>
#include <stdlib.h>

void pick(int* item, int n, int* picked, int m, int toPick, float *min, float mid){
    if(toPick == 0){
        int total = 0;
        float d;
        int i;

        for (i = 0; i < m; i++){
            total += item[picked[i]];
            //printf("%d ", item[picked[i]]);
        }
        //printf("total: %d \n", total);
        d = mid - total;
        //절댓값 함수 abs(value);
        if(d < 0)
            d = -d;
        *min = (*min < d ? *min : d);
        return;
    }

    int lastIndex = m - toPick - 1;
    int smallest, i;

    if (toPick == m)
        smallest = 0;
    else
        smallest = picked[lastIndex] + 1;
    
    for (i = smallest; i < n; i++) {
        picked[lastIndex + 1] = i;
        pick(item, n, picked, m, toPick-1, min, mid);
    }
}

int main(void){
    int n, i;
    int *students;
    int *picked;
    float min;
    float mid = 0;

    scanf("%d", &n);
    students = (int*)malloc(sizeof(int)*n);
    picked = (int*)malloc(sizeof(int)*n);

    for (i = 0; i < n; i++){
        scanf("%d", &students[i]);
        mid += students[i];
    }
    mid /= 2;
    min = mid;
    picked[0] = 0;
    pick(students, n, picked, n/2, n/2-1, &min, mid);
    printf("%d", (int)(min * 2));

    free(students);
    free(picked);
    return 0;
}