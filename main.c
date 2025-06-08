#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "board.h"
#include "replay.h"

int main()
{
    int isMenu = 1;
    int gameover = 0;
    //char **board = init_board();
    char** board = NULL;

    int choice;

    while (isMenu)
    {
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
            board = init_board();

            while (!gameover)
            {
                printBoard(board);
                printf("Which figure do you want to move: ");
                char piece;
                scanf(" %c", &piece);
                printf("Where do you want to move it: ");
                int x, y;
                scanf("%d %d", &x, &y);
                movePiece(board, piece, x - 1, y - 1);
                if (!moveQueen(board, board_size))
                {
                    gameover = 1;
                    printBoard(board);
                }
                
            }
            isMenu = 1;
            break;

        case 2:
            int newSize = 1;
            while (newSize < 3)
            {
                printf("Current board size is %dx%d \n", board_size, board_size);
                printf("Enter new size for the board: ");
                scanf("%d", &newSize);
            }
            board_size = newSize;
            freeBoard(board);
            
            
            printf("Board size changed to %dx%d \n", board_size, board_size);

            isMenu = 1;
            break;

        case 3:
            char** replay_board = load_replay("idk.txt");
            freeBoard(replay_board);
            break;

        case 4:
            printf("goodbye!\n");
            freeBoard(board);
            return 0;

        default:
            printf("Invalid option. Please try again.\n");
            break;
        }
    }

    return 0;
}