#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student {
    int korean;
    int math;
    int english;
    int id;
};

int partition(struct Student *s, int select, int p, int q, int r){
    int i = p;
    int j = p;
    struct  Student temp;

    switch (select) {
        case 1:
            for (; j < r; j++)  
                if (s[j].korean > s[r].korean) {
                    temp = s[i];
                    s[i]= s[j];
                    s[j] = temp;
                    i++;
                }
            break;
        case 2:
            for (; j < r; j++)  
                if (s[j].math > s[r].math) {
                    temp = s[i];
                    s[i]= s[j];
                    s[j] = temp;
                    i++;
                }
            break;
        case 3:
            for (; j < r; j++)  
                if (s[j].english > s[r].english) {
                    temp = s[i];
                    s[i]= s[j];
                    s[j] = temp;
                    i++;
                }
            break;
        case 4:
            for (; j < r; j++)  
                if (s[j].id < s[r].id) {
                    temp = s[i];
                    s[i]= s[j];
                    s[j] = temp;
                    i++;
                }
            break;
    }
    temp = s[i];
    s[i]= s[j];
    s[j] = temp;
    
    return i;
}
void quickSort(struct Student *s, int select, int p, int r) {
    if (p<r){
        int q = partition(s, select, p, q, r);
        quickSort(s, select, p, q - 1);
        quickSort(s, select, q + 1, r);
    }
}

void printArray(struct Student *a, int n){
    int i;
    for (i = 0; i < n; i++) {
        printf("학번: %d 영어: %d 수학: %d 국어: %d\n", a[i].id, a[i].english, a[i].math, a[i].korean);
    }
    printf("\n");
}

int main(void){
    struct Student *students;
    int i, n, select;

    srand(time(NULL));
    printf("학생 수를 입력하세요: ");
    scanf("%d", &n);
    students = (struct Student*)malloc(sizeof(struct Student)*n);
    for (i = 0; i < n; i++) {
        students[i].id = i + 1;
        students[i].english = rand() % 101;
        students[i].math = rand() % 101;
        students[i].korean = rand() % 101;
    }
    printArray(students, n);

    while(1){
        printf("정렬 기준 선택(1: korean, 2: math, 3: english, 4:id, 0: exit):");
        scanf("%d", &select);
        if(select == 0)
            break;

        quickSort(students,select, 0, n-1);
        printArray(students, n);
    }
    

    free(students);
    return 0;
}