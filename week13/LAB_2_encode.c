#include <stdio.h>
#include <stdlib.h>
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

int main(void){
    char sentence[80];
    char code[26];
    char encodedSentence[80];
    int dist;
    FILE *fp1, *fp2;

    printf("Enter a distance for encoding: ");
    scanf("%d", &dist);
    makeCode(code, dist);
    printCode(code);

    if((fp1 = fopen("original.txt", "r")) == NULL){
        printf("file open error1");
        exit(1);
    }
    if((fp2 = fopen("encoded.txt", "w")) == NULL){
        printf("file open error2");
        exit(1);
    }

    while(fgets(sentence, sizeof(sentence), fp1) != NULL){
        encode(code, sentence, encodedSentence);
        fputs(encodedSentence, fp2);
        memset(sentence, '\0', 80);
        memset(encodedSentence, '\0', 80);
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}