#ifndef BOARD_H
#define BOARD_H

extern int board_size;

char** init_board(int size);
void printBoard(char **board);
int isWithinBoard(char **board, int nX, int nY);
void moveRook(char **board, char piece, int nX, int nY);
int moveKing(char **board, int nX, int nY);
void movePiece(char **board, char piece, int nX, int nY);
int checkmate(char **board);
void freeBoard(char **board);

void moveQueen();

#endif