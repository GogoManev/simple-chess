#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include"board.h"


/*
void init_board(char **board, int bX, int bY)
{

    for(int i = 0; i < bX; i++){
        for(int j = 0; j < bY; j++){
            board[i][j] = '*';
        }
    }

    int xSOP1, ySOP1, xSOP2, ySOP2;
    int xking, yking, xking2, yking2;
    // generate pos for top 1 and top 2
    xSOP1 = rand() % bX;
    ySOP1 = rand() % bY;
    xSOP2 = rand() % bX;
    ySOP2 = rand() % bY;
    while (xSOP1 == xSOP2 && ySOP1 == ySOP2) {
        xSOP2 = rand() % bX;
        ySOP2 = rand() % bY;
    }

    // generate pos for kings
    xking = rand() % bX;
    yking = rand() % bY;
    xking2 = rand() % bX;
    yking2 = rand() % bY;
    while ((xking == xking2 && yking == yking2) || (xking == xSOP1 && yking == ySOP1) ||
            (xking == xSOP2 && yking == ySOP2) || (xking2 == xSOP1 && yking2 == ySOP1) ||
            (xking2 == xSOP2 && yking2 == ySOP2)) {
        xking = rand() % bX;
        yking = rand() % bY;
        xking2 = rand() % bX;
        yking2 = rand() % bY;
    }

    FILE* file = fopen("idk.txt", "w");
    fprintf(file, "%d--%d|%d,%d|%d,%d|%d,%d|%d", xSOP1, ySOP1, xSOP2, ySOP2, xking, yking, xking2, yking2);
    /*
    0. board size
    1. top 1 - x,y
    2. top 2 - x,y
    3. king (player) - x,y
    4. king (bot) - x,y
    */
   /*
    fclose(file);

    board[xSOP1][ySOP1] = 'R';
    board[xSOP2][ySOP2] = 'r';
    board[xking][yking] = 'K';
    board[xking2][yking2] = 'Q'; 
}

void printBoard(char **board, int bX, int bY)
{
    printf("  a b c d e f g h\n");
    for(int i = 0; i < bX; i++){
        printf("%d", i+1);
        for(int j = 0; j < bY; j++){
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
}

int isWithinBoard(char **board, int bX, int bY, int nX, int nY){
    if (nX < 0 || nX >= bX || nY < 0 || nY >= bY) {
        printf("Invalid move. Try again.\n");
        return 1;
    } else{
        return 0;
    }
}

void moveRook(char **board, int bX, int bY, int nX, int nY)
{
    if (isWithinBoard(board, bX, bY, nX, nY)) {
        return;
    }

    if (board[nX][nY] == '*') {
        for (int i = 0; i < bX; i++) {
            for (int j = 0; j < bY; j++) {
                if (board[i][j] == 'R') {

                    if(i != nX && j != nY) {
                        printf("Invalid move. Try again.\n");
                        return;
                    }

                    board[i][j] = '*';
                    board[nX][nY] = 'R';
                    return;
                }

                if(board[i][j] == 'r') {

                    if(i != nX && j != nY) {
                        printf("Invalid move. Try again.\n");
                        return;
                    }

                    board[i][j] = '*';
                    board[nX][nY] = 'r';
                    return;
                }
            }
        }
    } else {
        printf("Invalid move. Try again.\n");
    }
}

void moveKing(char **board, int bX, int bY, int nX, int nY)
{
    if (isWithinBoard(board, bX, bY, nX, nY)) {
        return;
    }

    if (board[nX][nY] == '*') {
        for (int i = 0; i < bX; i++) {
            for (int j = 0; j < bY; j++) {
                if (board[i][j] == 'K') {
                    board[i][j] = '*';
                    board[nX][nY] = 'K';
                    return;
                     
                }
            }
        }
    } else {
        printf("Invalid move. Try again.\n");
    }
}

void movePiece(char **board, int bX, int bY, char piece, int nX, int nY)
{
    if (piece == 'R' || piece == 'r'){
        moveRook(board, bX, bY, nX, nY);
    }else if (piece == 'K'){
        moveKing(board, bX, bY, nX, nY);
    }else{
        printf("Invalid piece. Try again.\n");
    }
}

int checkmate(char **board, int bX, int bY)
{
    return 1;
}

void freeBoard(char **board, int bX)
{
    for (int i = 0; i < bX; i++) {
                free(board[i]);
        }

    free(board);
}*/

int main()
{
    //board_size2 = 7;
    int isMenu = 1;
    int gameover = 0;
    int bX = 8, bY = 8;
    /*char **board = malloc(bX * sizeof(char *));
    for (int i = 0; i < bX; i++) {
        board[i] = malloc(bY * sizeof(char));
    }*/
   //char** board = init_board(board_size2, board_size2, board_size2);


    int choice;

    while(isMenu){
        printf("What do you want to do?\n");
        printf("1. Start a new game\n");
        printf("2. Change board size\n");
        printf("3. Replay from a file\n");
        printf("4. Exit\n");
        printf("\nChoose an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        !isMenu;
        srand(time(NULL));
        char** board = init_board(board_size2);

        while (!gameover) {
            printBoard(board, bX, bY);
            printf("Which figure do you want to move: ");
            char piece;
            scanf(" %c", &piece);
            printf("Where do you want to move it: ");
            int x, y;
            scanf("%d %d", &x, &y);
            movePiece(board, bX, bY, piece, x - 1, y - 1);
        }
            isMenu = 1;
            break;
            
        case 2:

            printf("Current board size is %dx%d \n", bX, bY);
            printf("Enter new size for the board: ");
            scanf("%d %d", &bX, &bY);

            freeBoard(board, bX);

            board = malloc(bX * sizeof(char *));
            for (int i = 0; i < bX; i++) {
                board[i] = malloc(bY * sizeof(char));
            }
            
            isMenu = 1;
            break;

        case 3:
            //c
            break;
        
        case 4:
            printf("goodbye!\n");
            freeBoard(board, board_size2);
            return 0;
        
        default:
            printf("bru really, u cant chose one of da 4 options?? u so stupidz foreal\n");
            break;
        }

    }

    return 0;
}