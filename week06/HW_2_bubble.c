#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student{
    int id;
    int korean;
    int english;
    int math;
};

void bubbleSortDescendingByKorean(struct Student *students, int n){
    struct Student temp;
    int i, j;

    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if(students[j].korean < students[j + 1].korean){
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
}

void bubbleSortAscendingById(struct Student *students, int n){
    struct  Student temp;
    int i, j;

    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if(students[j].id>students[j + 1].id){
                temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
}

int main(){
    int i, n;
    struct Student *students;

    srand(time(NULL));
    scanf("%d", &n);
    students = (struct Student*)malloc(sizeof(struct Student)*n);
    
    for (i = 0; i < n; i++) {
        students[i].id = i + 1;
        students[i].english = rand()%101;
        students[i].math = rand()%101;
        students[i].korean = rand()%101;
    }
    
    for (i = 0; i < n; i++)
        printf("id: %d\t eng: %d\t math: %d\t ko: %d\n", students[i].id, students[i].english, students[i].math, students[i].korean);
    
    bubbleSortDescendingByKorean(students, n);
    printf("Sort-Korean\n");
    for (i = 0; i < n; i++)
        printf("id: %d\t eng: %d\t math: %d\t ko: %d\n", students[i].id, students[i].english, students[i].math, students[i].korean);

    bubbleSortAscendingById(students, n);
    printf("Sort-id\n");
    for (i = 0; i < n; i++)
        printf("id: %d\t eng: %d\t math: %d\t ko: %d\n", students[i].id, students[i].english, students[i].math, students[i].korean);

    free(students);
    system("pause");
    return 0;
}