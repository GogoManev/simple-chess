#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "board.h"
#include "replay.h"

int board_size = 8;
int moveCount = 0;

char **init_board()
{
    char **board = malloc(board_size * sizeof(char *));
    for (int i = 0; i < board_size; i++)
        board[i] = malloc(board_size * sizeof(char));

    for (int i = 0; i < board_size; i++)
        for (int j = 0; j < board_size; j++)
            board[i][j] = '*';

    int xRook1, yRook1, xRook2, yRook2;
    int xking, yking, xqueen, yqueen;
    // generate pos for top 1 and top 2
    xRook1 = rand() % board_size;
    yRook1 = rand() % board_size;
    xRook2 = rand() % board_size;
    yRook2 = rand() % board_size;
    while (xRook1 == xRook2 && yRook1 == yRook2)
    {
        xRook2 = rand() % board_size;
        yRook2 = rand() % board_size;
    }

    // generate pos for kings
    xking = rand() % board_size;
    yking = rand() % board_size;
    xqueen = rand() % board_size;
    yqueen = rand() % board_size;
    while ((xking == xqueen && yking == yqueen) || (xking == xRook1 && yking == yRook1) ||
           (xking == xRook2 && yking == yRook2) || (xqueen == xRook1 && yqueen == yRook1) ||
           (xqueen == xRook2 && yqueen == yRook2))
    {
        xking = rand() % board_size;
        yking = rand() % board_size;
        xqueen = rand() % board_size;
        yqueen = rand() % board_size;
    }

    FILE *file = fopen("idk.txt", "w");
    fprintf(file, "%d/%d|%d,%d|%d,%d|%d,%d|%d\n", board_size, xRook1, yRook1, xRook2, yRook2, xking, yking, xqueen, yqueen);
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

void printBoard(char **board)
{
    printf(" ");
    for (int i = 0; i < board_size; i++)
        printf(" %d", i + 1);
    printf("\n");

    for (int i = 0; i < board_size; i++)
    {
        printf("%d", i + 1);
        for (int j = 0; j < board_size; j++)
            printf(" %c", board[i][j]);
        printf("\n");
    }
}

int isWithinBoard(char **board, int nX, int nY)
{
    if (nX < 0 || nX >= board_size || nY < 0 || nY >= board_size)
    {
        printf("Invalid move. Try again.\n");
        return 1;
    }
    else
        return 0;
}

void moveRook(char **board, char piece, int nX, int nY)
{
    if (isWithinBoard(board, nX, nY))
        return;

    if (board[nX][nY] == '*')
    {
        for (int i = 0; i < board_size; i++)
        {
            for (int j = 0; j < board_size; j++)
            {
                if (board[i][j] == 'R' && piece == 'R')
                {

                    if (i != nX && j != nY)
                    {
                        printf("Invalid move. Try again.\n");
                        return;
                    }

                    board[i][j] = '*';
                    board[nX][nY] = 'R';
                    moveCount++;
                    save_move(piece, nX, nY, "idk.txt");
                    return;
                }

                if (board[i][j] == 'r' && piece == 'r')
                {

                    if (i != nX && j != nY)
                    {
                        printf("Invalid move. Try again.\n");
                        return;
                    }

                    board[i][j] = '*';
                    board[nX][nY] = 'r';
                    moveCount++;
                    save_move(piece, nX, nY, "idk.txt");
                    return;
                }
            }
        }
    }
    else
        printf("Invalid move. Try again.\n");
}

int moveKing(char **board, int nX, int nY)
{
    if (isWithinBoard(board, nX, nY))
        return 0;

    if (board[nX][nY] == '*')
    {
        for (int i = 0; i < board_size; i++)
        {
            for (int j = 0; j < board_size; j++)
            {
                if (board[i][j] == 'K')
                {
                    if (abs(i - nX) <= 1 && abs(j - nY) <= 1)
                    {
                        board[i][j] = '*';
                        board[nX][nY] = 'K';
                        moveCount++;
                        save_move('K', nX, nY, "idk.txt");
                    }
                    return 1;
                }
            }
        }
    }
    else
        printf("Invalid move. Try again.\n");
}

void movePiece(char **board, char piece, int nX, int nY)
{
    if (piece == 'R' || piece == 'r')
        moveRook(board, piece, nX, nY);
    else if (piece == 'K')
        moveKing(board, nX, nY);
    else
        printf("Invalid piece. Try again.\n");
}

void freeBoard(char **board)
{
    if (board)
    {
        for (int i = 0; i < board_size; i++)
            free(board[i]);

        free(board);
    }
}

Point *checkmate(char **board, int qX, int qY, int size)
{
    Point *points = malloc(8 * sizeof(Point));
    int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

    for (int i = 0; i < 8; i++)
    {
        points[i].x = qX + dx[i];
        points[i].y = qY + dy[i];
        if ((points[i].x > -1 && points[i].x < size) && (points[i].y > -1 && points[i].y < size))
            points[i].canMoveThere = 1;
    }

    for (int i = 0; i < 8; i++)
        if (points[i].canMoveThere = 1)
        {
            for (int j = 0; j < size - 1; j++)
            {
                if (board[j][points[i].x] == 'R' || board[j][points[i].x] == 'r')
                    points[i].canMoveThere = 0;
            }
            for (int j = 0; j < size - 1; j++)
            {
                if (board[points[i].y][j] == 'R' || board[points[i].y][j] == 'r')
                    points[i].canMoveThere = 0;
            }
        }

    return points;
}

int moveQueen(char **board)
{
    
    int x, y;
    for (int i = 0; i < board_size; i++)
        for (int j = 0; j < board_size; j++)
            if (board[i][j] == 'Q')
            {
                x = i;
                y = j;
                //board[i][j] = '*';
            }

    int flag = 0;
    Point *points = checkmate(board, x, y, board_size);
    Point *RealPoints = NULL;
    int tick = 0;

    for (int i = 0; i < 8; i++)
        if (points[i].canMoveThere = 1)
        {
            if (!RealPoints)
                RealPoints = malloc(1 * sizeof(Point));
            else
                RealPoints = realloc(RealPoints, (1 + tick) * sizeof(Point));
            RealPoints[tick] = points[i];
            flag++;
        }
    
    if (flag)
    {
        int point = rand() % (tick + 1);
        board[x][y] = '*';
        board[RealPoints[point].x][RealPoints[point].y] = 'Q';
        printf("%d.%d -- %d.%d\n", x, y, RealPoints[point].x, RealPoints[point].y);
        save_move('Q', RealPoints[point].x, RealPoints[point].y, "idk.txt");
        free(RealPoints);
        free(points);
        return 1;
    }
    else
    {
        free(RealPoints);
        free(points);
        return 0;
    }
}