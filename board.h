#ifndef BOARD_H
#define BOARD_H

extern int board_size;
//extern int moves;

typedef struct Point
{
    int x;
    int y;
    int canMoveThere;
} Point;

char** init_basic_board(int size);
char** init_board();
void printBoard(char **board);
int isWithinBoard(char **board, int nX, int nY);

int moveRook(char **board, char piece, int nX, int nY);
int moveKing(char **board, int nX, int nY);
int movePiece(char **board, char piece, int nX, int nY);

Point* checkmate(char **board, int qX, int qY, int size);
void freeBoard(char **board);

int moveQueen(char **board);

#endif