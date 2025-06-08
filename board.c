#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "board.h"

int board_size2 = 8;

char** init_board(int size)
{
    char** board = malloc(board_size2 *  sizeof(char *));
    for (int i = 0; i < board_size2; i++)
        board[i] = malloc(board_size2 * sizeof(char));
    
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            board[i][j] = '*';

    int xRook1, yRook1, xRook2, yRook2;
    int xking, yking, xqueen, yqueen;
    // generate pos for top 1 and top 2
    xRook1 = rand() % board_size2;
    yRook1 = rand() % board_size2;
    xRook2 = rand() % board_size2;
    yRook2 = rand() % board_size2;
    while (xRook1 == xRook2 && yRook1 == yRook2)
    {
        xRook2 = rand() % board_size2;
        yRook2 = rand() % board_size2;
    }

    // generate pos for kings
    xking = rand() % board_size2;
    yking = rand() % board_size2;
    xqueen = rand() % board_size2;
    yqueen = rand() % board_size2;
    while ((xking == xqueen && yking == yqueen) || (xking == xRook1 && yking == yRook1) ||
           (xking == xRook2 && yking == yRook2) || (xqueen == xRook1 && yqueen == yRook1) ||
           (xqueen == xRook2 && yqueen == yRook2))
    {
        xking = rand() % board_size2;
        yking = rand() % board_size2;
        xqueen = rand() % board_size2;
        yqueen = rand() % board_size2;
    }

    FILE *file = fopen("idk.txt", "w");
    fprintf(file, "%d--%d|%d,%d|%d,%d|%d,%d|%d", size, xRook1, yRook1, xRook2, yRook2, xking, yking, xqueen, yqueen);
    /*
    0. board size
    1. top 1 - x,y
    2. top 2 - x,y
    3. king (player) - x,y
    4. king (bot) - x,y
    */
    fclose(file);

    board[xRook1][yRook1] = 'R';
    board[xRook2][yRook2] = 'r';
    board[xking][yking] = 'K';
    board[xqueen][yqueen] = 'Q';

    return board;
}

void printBoard(char **board, int bX, int bY)
{
    printf("  a b c d e f g h\n");
    for (int i = 0; i < bX; i++)
    {
        printf("%d", i + 1);
        for (int j = 0; j < bY; j++)
        {
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
}

int isWithinBoard(char **board, int bX, int bY, int nX, int nY)
{
    if (nX < 0 || nX >= bX || nY < 0 || nY >= bY)
    {
        printf("Invalid move. Try again.\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

void moveRook(char **board, int bX, int bY, int nX, int nY)
{
    if (isWithinBoard(board, bX, bY, nX, nY))
    {
        return;
    }

    if (board[nX][nY] == '*')
    {
        for (int i = 0; i < bX; i++)
        {
            for (int j = 0; j < bY; j++)
            {
                if (board[i][j] == 'R')
                {

                    if (i != nX && j != nY)
                    {
                        printf("Invalid move. Try again.\n");
                        return;
                    }

                    board[i][j] = '*';
                    board[nX][nY] = 'R';
                    return;
                }

                if (board[i][j] == 'r')
                {

                    if (i != nX && j != nY)
                    {
                        printf("Invalid move. Try again.\n");
                        return;
                    }

                    board[i][j] = '*';
                    board[nX][nY] = 'r';
                    return;
                }
            }
        }
    }
    else
    {
        printf("Invalid move. Try again.\n");
    }
}

int moveKing(char **board, int bX, int bY, int nX, int nY)
{
    if (isWithinBoard(board, bX, bY, nX, nY))
    {
        return 0;
    }

    if (board[nX][nY] == '*')
    {
        for (int i = 0; i < bX; i++)
        {
            for (int j = 0; j < bY; j++)
            {
                if (board[i][j] == 'K')
                {
                    if (abs(i - nX) <= 1 && abs(j - nY) <= 1)
                    {
                        board[i][j] = '*';
                        board[nX][nY] = 'K';
                    }
                    return 1;
                }
            }
        }
    }
    else
    {
        printf("Invalid move. Try again.\n");
    }
}

void movePiece(char **board, int bX, int bY, char piece, int nX, int nY)
{
    if (piece == 'R' || piece == 'r')
    {
        moveRook(board, bX, bY, nX, nY);
    }
    else if (piece == 'K')
    {
        if(moveKing(board, bX, bY, nX, nY)) {
            FILE* file = fopen("idk.txt", "a");
            fprintf(file, "\nk%d|%d", nX, nY);
            fclose(file);
        }
    }
    else
    {
        printf("Invalid piece. Try again.\n");
    }
}

int checkmate(char **board, int bX, int bY)
{
    return 1;
}

void freeBoard(char **board, int bX)
{
    for (int i = 0; i < bX; i++)
    {
        free(board[i]);
    }

    free(board);
}