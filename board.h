#ifndef BOARD_H
#define BOARD_H

extern int board_size2;

char** init_board(int size);
void printBoard(char **board, int bX, int bY);
int isWithinBoard(char **board, int bX, int bY, int nX, int nY);
void moveRook(char **board, int bX, int bY, int nX, int nY);
int moveKing(char **board, int bX, int bY, int nX, int nY);
void movePiece(char **board, int bX, int bY, char piece, int nX, int nY);
int checkmate(char **board, int bX, int bY);
void freeBoard(char **board, int bX);

int moveQueen(char **board, int size);

#endif