#include <stdio.h>

void eraseN(int *a, int *answer, int cardSize, int allSize){
    char flag;
    int i, j;
    int index = 0;

    scanf("%c", &flag);

    if(flag == 'Y')
        for (i = 0; i < allSize; i++){
            if(i != a[index])
                answer[i] = 0;
            else
                index++;
        }   
    else if(flag == 'N')
        for (i = 0; i < cardSize; i++)
            answer[a[i]] = 0;
            
    getchar();
}

int main(void){
    int card1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int card2[] = {1, 2, 3, 4, 9, 10, 11, 12};
    int card3[] = {1, 2, 5, 6, 9, 10, 11, 12};
    int card4[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int answer[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int i, j;

    /*
    char card[15][5] = {
        "YYYY", //1
        "YYYN", //2
        "YYNY", //3
        "YYNN", //4
        "YNYY", //5
        "YNYN", //6
        "YNNY", //7
        "YNNN", //8
        "NYYY", //9
        "NYYN", //10
        "NYNY", //11
        "NYNN", //12
        "NNYY", //13
        "NNYN", //14
        "NNNY" //15
    };
    */

    int cardSize = 8;
    int allSize = 16;

    eraseN(card1, answer, cardSize, allSize);
    eraseN(card2, answer, cardSize, allSize);
    eraseN(card3, answer, cardSize, allSize);
    eraseN(card4, answer, cardSize, allSize);
        
    
    for(i = 0; i < sizeof(answer)/sizeof(int); i++)
        if(answer[i] != 0)
            printf("%d\n", answer[i]);

    return 0;
}