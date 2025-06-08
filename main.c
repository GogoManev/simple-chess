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
    int iliketomoveitmoveit=0;
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
            //!isMenu;
            srand(time(NULL));
            board = init_board();
            gameover = 0;

            while (!gameover)
            {
                char piece;
                int x, y;

                printBoard(board);
                printf("Which figure do you want to move: ");
                scanf(" %c", &piece);

                printf("Where do you want to move it: ");
                scanf("%d %d", &x, &y);
                
                if(movePiece(board, piece, x - 1, y - 1)) {
                    iliketomoveitmoveit++;
                }
                if (moveQueen(board))
                {
                    gameover = 1;
                    printBoard(board);
                }
                
            }
            
            stats("idk.txt");
            printf("%d", iliketomoveitmoveit);
            isMenu = 1;
            break;

        case 2:
            board_size = 1;
            while (board_size < 3)
            {
                printf("Current board size is %dx%d \n", board_size, board_size);
                printf("Enter new size for the board: ");
                scanf("%d", &board_size);
            }
            //board_size = newSize;
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