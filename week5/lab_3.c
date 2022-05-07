#include <stdio.h>

void pick(char *items[], int n, int *picked, int m, int toPick){
    int i, lastIndex, smallest;

    if(toPick == 0){
        int picked_index;
        for(i = 0; i < m; i++){
            picked_index = picked[i];
            printf("%s\t", items[picked_index]);
        }
        printf("\n");
        return;
    }

    lastIndex = m - toPick - 1;
    for (i = 0; i < n; i++) {
        int j;
        int flag = 0;
        for(j = 0; j <= lastIndex; j++)
            if(picked[j] == i)
                flag = 1;
        if(flag == 1)
            continue;

        picked[lastIndex + 1] = i;
        pick(items, n, picked, m, toPick - 1);
    }
}

int main(void){
    char *actors[] = {"����", "�����", "���߱�", "����", "����"};
    int picked[3];
    int i, n;
    
    printf("���� ������?: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        printf("��%d\t", i + 1);
    printf("\n");
    pick(actors, 5, picked, n, n);
    system("pause");
}