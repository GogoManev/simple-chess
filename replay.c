#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "replay.h"
#include "board.h"

void save_move(char piece, int x, int y, char name[])
{
    FILE *file = fopen(name, "a");
    fprintf(file, "%c%d|%d\n", piece, x, y);
    fclose(file);
}

char **load_replay(char name[])
{
    FILE *file = fopen(name, "r");
    char string[256];
    fgets(string, 256, file);
    // printf("%s", string);
    int size = 0;

    Point R, r, K, Q;
    R.x = 0;
    R.y = 0;
    r.x = 1;
    r.y = 1;
    K.x = 2;
    K.y = 2;
    Q.x = 3;
    Q.y = 3;

    int size_flag = 0;

    int len = strlen(string);

    for (int i = 0; i < len; i++)
    {
        if (string[i] == '\0' || string[i] == '\n')
            break;
        if (size_flag == 0)
        {
            if (string[i] == '/')
            {
                size_flag = i + 1;
                break;
            }
            if (isdigit((unsigned char)string[i]))
                size = size * 10 + (string[i] - '0');
        }
    }
    printf("%d\n", size);

    char **board = init_basic_board(size);

    board[R.x][R.y] = 'R';
    board[r.x][r.y] = 'r';
    board[K.x][K.y] = 'K';
    board[Q.x][Q.y] = 'Q';
    return board;
}

void stats(char name[])
{
    FILE *file = fopen(name, "r");
    char string[256];
    while (fgets(string, 256, file) != NULL)
    {
        if (string[0] <= '9' && string[0] <= '0')
            continue;
        /*общ брой ходове, брой ходове за всяка фигура, брой пъти когато компютъра е поставен в “шах”, други по преценка на ученика*/
    }
    fclose(file);
    file = fopen(name, "a");
    fprintf(file, "EOR\n"); // end of replay
    fprintf(file, "moves - ");
    fprintf(file, "checks - ");
    fprintf(file, "r - ");
    fprintf(file, "R - ");
    fprintf(file, "K - ");
    fprintf(file, "life events - ");
    fprintf(file, "rooks lost - ");
    fprintf(file, "rooks gained - ");
}

void play_replay(char name[])
{
    FILE *file = fopen(name, "r");
    char string[256];
    fgets(string, 256, file);
    int size = 0;

    Point R, r, K, Q;
    R.x = -1;
    r.x = -1;
    K.x = -1;
    Q.x = -1;

    int size_flag = 0;

    int len = strlen(string);

    for (int i = 0; i < len; i++)
    {
        if (string[i] == '/')
        {
            size_flag = i + 1;
            break;
        }
        if (isdigit((unsigned char)string[i]))
            size = size * 10 + (string[i] - '0');
    }
    int x = 0, y = 0;
    for (int j = 0; j < 4; j++)
    {
        for (int i = size_flag; i < len; i++)
        {
            if (string[i] == '|')
            {
                size_flag = i + 1;
                break;
            }
            if (isdigit((unsigned char)string[i]))
                x = x * 10 + (string[i] - '0');
        }
        for (int i = size_flag; i < len; i++)
        {
            if (string[i] == ',')
            {
                size_flag = i + 1;
                break;
            }
            if (isdigit((unsigned char)string[i]))
                y = y * 10 + (string[i] - '0');
        }
        if (R.x == -1)
        {
            R.x = x;
            R.y = y;
        }
        else if (r.x == -1)
        {
            r.x = x;
            r.y = y;
        }
        else if (K.x == -1)
        {
            K.x = x;
            K.y = y;
        }
        else
        {
            Q.x = x;
            Q.y = y;
        }

        x = 0;
        y = 0;
    }

    char **board = init_basic_board(size);

    board[R.x][R.y] = 'R';
    board[r.x][r.y] = 'r';
    board[K.x][K.y] = 'K';
    board[Q.x][Q.y] = 'Q';

    printBoard(board);

    int tickster = 0;
    char c;
    while (fgets(string, 256, file))
    {
        if(strcmp(string, "EOR") == 0) {
            break;
        }
        printf("%s\n", string);
        for (int i = tickster; i < len; i++)
        {
            if (string[i] == '|')
            {
                tickster = i + 1;
                break;
            }
            if (isdigit((unsigned char)string[i]))
                x = x * 10 + (string[i] - '0');
        }
        for (int i = tickster; i < len; i++)
        {
            if (string[i] == '\n')
                break;
            if (isdigit((unsigned char)string[i]))
                y = y * 10 + (string[i] - '0');
        }
        switch (string[0])
        {
        case 'K':
            board[K.x][K.y] = '*';
            K.x = x;
            K.y = y;
            board[K.x][K.y] = 'K';
            break;

        case 'Q':
            board[Q.x][Q.y] = '*';
            Q.x = x;
            Q.y = y;
            board[Q.x][Q.y] = 'Q';
            break;
        case 'R':
            board[R.x][R.y] = '*';
            R.x = x;
            R.y = y;
            board[R.x][R.y] = 'R';
        case 'r':
            board[r.x][r.y] = '*';
            r.x = x;
            r.y = y;
            board[r.x][r.y] = 'r';
        }
        scanf("%c", &c);
        printBoard(board);
    }
    printf("dsadas");
    freeBoard(board);
}