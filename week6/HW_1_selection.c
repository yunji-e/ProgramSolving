#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student {
    int id;
    int english;
    int math;
    int korean;
};


int selectiongSort(struct Student *std, int n){
    int i, j;
    int minIndex;
    struct Student temp;
    
    for (i = 0; i < n; i++) {
        minIndex = 0;
        for (j = 1; j < n - i; j++) {
            if (std[minIndex].korean > std[j].korean)
            minIndex = j;
        }
        
        temp = std[minIndex];
        std[minIndex] = std[n - i - 1];
        std[n - i - 1] = temp;
    }
}

int main(void){
    int i, n;
    struct Student *students;

    srand(time(NULL));

    scanf("%d", &n);
    students = (struct Student*)malloc(sizeof(struct Student)*n);

    for (i = 0; i < n; i++) {
        students[i].id = i+1;
        students[i].korean = rand()%101;
        students[i].english = rand()%101;
        students[i].math = rand()%101;
    }

    for (i = 0; i < n; i++)
        printf("id: %d\t eng: %d\t math: %d\t ko: %d\n", students[i].id, students[i].english, students[i].math, students[i].korean);
    
    selectiongSort(students, n);

    printf("[Selection Sort]\n");
    for (i = 0; i < n; i++)
        printf("id: %d\t eng: %d\t math: %d\t ko: %d\n", students[i].id, students[i].english, students[i].math, students[i].korean);

    free(students);
    system("pause");
    return 0;
}