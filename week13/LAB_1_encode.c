#include <stdio.h>
#include <string.h>

void makeCode(char code[], int dist){
    int i;
    for (i = 0; i < 26; i++){
        code[i] += dist;
        if(code[i] > 'Z')
            code[i] -= 'Z'-'A'+1;
    }
}

void printCode(char code[]){
    int i;
    for (i = 0; i < 26; i++)
        printf("%c ", code[i]);
    printf("\n");
}

void encode(char code[], char s[], char e[]){
    int i;
    for (i = 0; i < strlen(s); i++){
        if(s[i] >= 'A' && s[i] <= 'Z')
            e[i] = code[s[i]-'A'];
        else
            e[i] = s[i];
    }
}

int main(void){
    char sentence[80];
    char code[26];
    char encodedSentence[80];
    int dist;
    int n, i;

    for (i = 0; i < 26; i++)
        code[i] = 'A' + i;

    printf("Enter a distance for encoding: ");
    scanf("%d", &dist);

    printf("--------------------------------\n");
    printf("alphabet:\t");
    printCode(code);

    makeCode(code, dist);
    printf("encoded:\t");
    printCode(code);
    printf("--------------------------------\n");

    fflush(stdin);
    printf("Enter a sentence to encode: ");
    fgets(sentence, sizeof(sentence), stdin);
    encode(code, sentence, encodedSentence);
    printf("original sentence:\t");
    printf("%s", sentence);
    printf("encoded sentence:\t");
    printf("%s", encodedSentence);

    return 0;
}