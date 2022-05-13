#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student {
    int id;
    int english;
    int math;
    int korean;
};

int partition(struct Student *s, int p, int q, int r){
    int i, j;
    struct  Student temp;

    for (i = p, j = p; j < r; j++) {
        if (s[j].korean > s[r].korean) {
            temp = s[i];
            s[i]= s[j];
            s[j] = temp;
            i++;
        }
    }
    temp = s[i];
    s[i]= s[j];
    s[j] = temp;
    
    return i;
}
void quickSort(struct Student *s, int p, int r) {
    if (p<r){
        int q = partition(s, p, q, r);
        quickSort(s, p, q - 1);
        quickSort(s, q + 1, r);
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
    int i, n;

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
    quickSort(students, 0, n-1);
    printArray(students, n);

    free(students);
    return 0;
}