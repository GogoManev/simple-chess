#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

enum PieceType {
    TOP1,
    TOP2,
    KING,
    BOTKING
};
//64
struct Piece
{
    int x;
    int y;
};


char board[8][8];
void init_board()
{
    int xSOP1, ySOP1, xSOP2, ySOP2;
    int xking, yking, xking2, yking2;
    // generate pos for top 1 and top 2
    xSOP1 = rand() % 8;
    ySOP1 = rand() % 8;
    xSOP2 = rand() % 8;
    ySOP2 = rand() % 8;
    while (xSOP1 == xSOP2 && ySOP1 == ySOP2) {
        xSOP2 = rand() % 8;
        ySOP2 = rand() % 8;
    }

    // generate pos for kings
    xking = rand() % 8;
    yking = rand() % 8;
    xking2 = rand() % 8;
    yking2 = rand() % 8;
    while ((xking == xking2 && yking == yking2) || (xking == xSOP1 && yking == ySOP1) ||
            (xking == xSOP2 && yking == ySOP2) || (xking2 == xSOP1 && yking2 == ySOP1) ||
            (xking2 == xSOP2 && yking2 == ySOP2)) {
        xking = rand() % 8;
        yking = rand() % 8;
        xking2 = rand() % 8;
        yking2 = rand() % 8;
    }

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            board[i][j] = ' ';
        }
    }

    board[xSOP1][ySOP1] = 'S';
    board[xSOP2][ySOP2] = 'S';
    board[xking][yking] = 'K';
    board[xking2][yking2] = 'K';
}

void printBoard()
{
    printf("  1 2 3 4 5 6 7 8\n");
    for(int i = 0; i < 8; i++){
        printf("%d", i+1);
        for(int j = 0; j < 8; j++){
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int choice;
    printBoard();

    /*while(1){
        printf("What do you want to do?\n");
        printf("1. Start a new game\n");
        printf("2. Change board size\n");
        printf("3. Replay from a file\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            //a
            break;

        case 2:
            //b
            break;

        case 3:
            //c
            break;
        
        case 4:
            return 0;
        
        default:
            printf("total nigger");
            break;
        }

    }*/
}