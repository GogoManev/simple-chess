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
typedef struct Piece
{
    char piece;
    int x;
    int y;
} Piece;


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
            board[i][j] = '*';
        }
    }

    board[xSOP1][ySOP1] = 'R';
    board[xSOP2][ySOP2] = 'R';
    board[xking][yking] = 'K';
    board[xking2][yking2] = 'Q';
}

void printBoard()
{
    printf("  a b c d e f g h\n");
    for(int i = 0; i < 8; i++){
        printf("%d", i+1);
        for(int j = 0; j < 8; j++){
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
}

void movePiece(Piece piece, int nX, int nY)
{
    
}
 

int main()
{
    int isMenu = 1;
    int choice;

    //while(isMenu){
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
        int gameover = 0;
            init_board();
            printBoard();
            printf("Which figure do you want to move: ");
            char piece;
            scanf(" %c", &piece);
            printf("Where do you want to move it: ");
            int x, y;
            scanf("%d %d", &x, &y);
            //movePiece(piece, x, y);

        if(gameover){
            break;
        }
            
        case 2:
            //b
            break;

        case 3:
            //c
            break;
        
        case 4:
            return 0;
        
        default:
            printf("bru really, u cant chose one of da 4 options?? u so stupidz foreal\n");
            break;
        }

    //}
}