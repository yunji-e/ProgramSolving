#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student{
    int id;
    int korean;
    int english;
    int math;
};

void bubbleSort(struct Student *students, int n, int select){
    struct Student temp;
    int i, j;

    if (select > 4 || select < 0){
        printf("????? ???????.\n");
        return;
    }
    
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            //if문 하나로 처리하는 방법
            //if((select == 1) && arr[j].korean < arr[j+1].korean) ||
                //(select == 2) &&
                // 3
                // 4
                //{ swap }
            switch (select) {
                case 1:
                    if(students[j].korean < students[j + 1].korean){
                        //중복되는 부분을 flag처리하고
                        //맨 마지막에서 flag == 1일때 처리하는 방법
                        temp = students[j];
                        students[j] = students[j + 1];
                        students[j + 1] = temp;
                    }
                    break;
                case 2:
                    if(students[j].math < students[j + 1].math){
                        temp = students[j];
                        students[j] = students[j + 1];
                        students[j + 1] = temp;
                    }
                    break;
                case 3:
                    if(students[j].english < students[j + 1].english){
                        temp = students[j];
                        students[j] = students[j + 1];
                        students[j + 1] = temp;
                    }
                    break;
                case 4:
                    if(students[j].id > students[j + 1].id){
                        temp = students[j];
                        students[j] = students[j + 1];
                        students[j + 1] = temp;
                    }
                    break;
            }
}

int main(){
    int i, n, select;
    struct Student *students;

    srand(time(NULL));
    printf("?л? ???? ????????: ");
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
        printf("\n");

    while(1) {
        printf("???? ???? ????(1: ????, 2: ????, 3: ????, 4: id(????????), 0:????): ");
        scanf("%d", &select);

        if (select == 0)
            break;

        bubbleSort(students, n, select);

        for (i = 0; i < n; i++)
        printf("id: %d\t eng: %d\t math: %d\t ko: %d\n", students[i].id, students[i].english, students[i].math, students[i].korean);
        printf("\n");
    }

    free(students);
    system("pause");
    return 0;
}