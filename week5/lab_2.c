#include <stdio.h>

void pick(char *actors[], int n, int *picked, int m, int toPick){
    int i;
    int lastIndex;
    int smallest;
    
    if(toPick == 0){
        int picked_index;
        for(i = 0; i < m; i++){
            picked_index = picked[i];
            printf("%s\t", actors[picked_index]);
        }
        printf("\n");
        return;
    }

    lastIndex = m - toPick - 1;
    if(toPick == m)
        smallest = 0;
    else
        smallest = picked[lastIndex]+1;

    for (i = smallest; i < n; i++) {
        picked[lastIndex+1] = i;
        pick(actors, n, picked, m, toPick-1);
    }
}

int main(){
    char *actors[] = {"공유", "김수현", "송중기", "지성", "현빈"};
    int picked[3];
    int i, n;
    
    printf("인기상 몇 명?: ");
    scanf("%d", &n);
    pick(actors, 5, picked, n, n);
}