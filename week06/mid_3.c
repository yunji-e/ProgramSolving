#include <stdio.h> 

int main(void){
    int map[100][100];
    int i, j, height, width;
    int player;

    scanf("%d %d", &width, &height);
    scanf("%d", &player);

    for (i = 0; i < height; i++)
        //scanf("%s", map[i]);
        for (j = 0; j < width - 1; j++)
            scanf("%1d", &map[i][j]);

    for (i = 0; i < height; i++) {
        if (player < width && map[i][player] == 1)
            player++;
        else if(player - 1 >= 0 && map[i][player-1] == 1)
            player--;
    }

    printf("%d", player);
    
    return 0;
}