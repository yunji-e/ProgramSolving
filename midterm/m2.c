#include <stdio.h>

void solution(int s[], int n, int k){
    if (n == 0)
        return;

    int i;
    for (i = 0; n!=0 ; i++)
    {
        s[i] = n % k;
        n /= k;
    }
    s[i] = -1;

    return;
}


int isPalindrome(int n, int k){
    int s[10];
    int i, size;

    solution(s, n, k);
    for (i = 0; s[i] != -1; i++);

    size = i;
    
    for (i = 0; i < size / 2; i++) {
        if(s[i] != s[size - i - 1])
            return 0;
    }
    
    return 1;
}

int main(void){
    int n, k;
    int i;

    scanf("%d %d", &n, &k);

    printf("%d", isPalindrome(n, k));

    return 0;
}