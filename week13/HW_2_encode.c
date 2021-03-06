#include <stdio.h>
#include <string.h>
#include <ctype.h>

void makeCode(char code[], int dist, char key[]){
    int i, j;
    int c = 'A';
    
    strcpy(&code[dist], key);
    for (i = dist + strlen(key); i < 26; i++) {
        while(strchr(key, c)!=NULL)
            c++;
        code[i] = c++;
    }
    for (i = 0; i < dist; i++){
        while(strchr(key, c)!=NULL)
            c++;
        code[i] = c++;
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
    for (i = 0; i <= strlen(s); i++){
        if(s[i] >= 'A' && s[i] <= 'Z')
            e[i] = code[s[i]-'A'];
        else
            e[i] = s[i];
    }
}

void remove_duplicated_char(char* word){
    int len = strlen(word);
    int i, j;

    for (i = 0; i < len; i++)
        for(j = 0; j < i; j++)
            if(word[i] == word[j]){
                strcpy(&word[i], &word[i+1]);
                len--;
                i--;
                break;
            }
    printf("removed: %s\n", word);
}

int main(void){
    char sentence[80];
    char code[26];
    char key[30];
    char encodedSentence[80];
    char decodedSentence[80];
    int dist;

    printf("Enter a word to use for encoding: ");
    scanf("%s", key);
    printf("Enter a distance for encoding: ");
    scanf("%d", &dist);

    remove_duplicated_char(key);
    makeCode(code, dist, key);
    printCode(code);

    fflush(stdin);
    printf("Enter a sentence to encode: ");
    fgets(sentence, sizeof(sentence), stdin);

    printf("original sentence:\t");
    printf("%s", sentence);

    encode(code, sentence, encodedSentence);
    printf("encoded sentence:\t");
    printf("%s", encodedSentence);

    return 0;
}