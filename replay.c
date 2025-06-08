#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "replay.h"

void save_move(char piece, int x, int y, char name[])
{
    FILE* file = fopen(name, "a");
    fprintf(file, "%c%d|%d\n", piece, x, y);
    fclose(file);
}

char **load_replay(char name[])
{
    int temp_val;

    FILE *file = fopen(name, "r");
    char string[256];
    fgets(string, 256, file);
    // printf("%s", string);
    int size = 0;
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
                size_flag = 1;
                break;
            }
            else
            {
                temp_val = (int)string[i] - 48;
                // printf("%d\n", temp_val);
                size = (size * 10) + temp_val;
            }
        }
    }
    printf("%d\n", size);

    char **board = malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++)
        board[i] = malloc(size * sizeof(char));
    // return board;
}

void stats(char name[]) {
    FILE* file = fopen(name, "r");
    char string[256];
    while(fgets(string, 256, file) != NULL) {
        if(string[0] <= '9' && string[0] <= '0')
            continue;
        /*общ брой ходове, брой ходове за всяка фигура, брой пъти когато компютъра е поставен в “шах”, други по преценка на ученика*/
    }
}

void play_replay(char name[])
{
}