#include <stdio.h>
#include <string.h>

void makeCode(char code[], int dist){
    int i;
    
    for (i = 0; i < 26; i++){
        code[i] = 'A' + dist + i;
        if(code[i] > 'Z')
            code[i] -= 'Z'-'A'+1;
    }
}

void printCode(char code[]){
    int i;
    printf("--------------------------------\n");
    printf("alphabet:\t");
    for (i = 0; i < 26; i++)
        printf("%c ", 'A'+i);
    printf("\n");

    printf("encoded:\t");
    for (i = 0; i < 26; i++)
        printf("%c ", code[i]);
    printf("\n");
    printf("--------------------------------\n");
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

void decode(char code[], char e[], char d[]){
    int i;
    for (i = 0; i < strlen(e); i++){
        d[i] = e[i]-(code[0]-'A');
        if(d[i] < 'A')
            code[i] += 'Z'-'A'+1;
    }
}

int main(void){
    char sentence[80];
    char code[26];
    char encodedSentence[80];
    char decodedSentence[80];
    int dist;

    printf("Enter a distance for encoding: ");
    scanf("%d", &dist);
    makeCode(code, dist);
    printCode(code);

    fflush(stdin);
    printf("Enter a sentence to encode: ");
    fgets(sentence, sizeof(sentence), stdin);

    printf("original sentence:\t");
    printf("%s", sentence);

    encode(code, sentence, encodedSentence);
    printf("encoded sentence:\t");
    printf("%s", encodedSentence);

    decode(code, encodedSentence, decodedSentence);
    printf("decoded sentence:\t");
    puts(decodedSentence);

    return 0;
}