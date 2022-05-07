#include <stdio.h>

int count(int n){
    int count = 0;
    while(n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

int solution(int n){
    int i, j, number;
    int turn = 0;

    for (i = 1; turn < n; i++)
        turn += count(i*3); //n번째 숫자 근처 3의 배수 구하기
    number = (i-1)*3;

    if (turn > n) //n번째 숫자가 3의 배수 도중에 있는 경우(ex | 15의 1 등)
        for (i = 0; i < turn - n; i++) //넘친 만큼(turn==n이면 루프가 안돌아서 if문 필요없었을듯)
            number /= 10; //후진

    //맨 마지막 숫자 리턴
    return number % 10;
}

int main(void){
    int n;
    scanf("%d", &n);
    printf("%d", solution(n));    
    
    /*교수님의 답
    for(int i = 3; ; i += 3){
        m = count(i);
        if(n - m <= 0){
            break;
        }
        else
            n -= m;
    }

    int number = i;

    for(i = 0; i < m - n; i++)
        number /= 10;
    
    printf("%d\n", number % 10);
    */
}