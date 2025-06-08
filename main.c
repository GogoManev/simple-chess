#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "board.h"

int main()
{
    int isMenu = 1;
    int gameover = 0;
    int bX = 8, bY = 8;
    char **board = init_board(board_size2);

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
            char **board = init_board(board_size2);

            while (!gameover)
            {
                printBoard(board, bX, bY);
                printf("Which figure do you want to move: ");
                char piece;
                scanf(" %c", &piece);
                printf("Where do you want to move it: ");
                int x, y;
                scanf("%d %d", &x, &y);
                movePiece(board, bX, bY, piece, x - 1, y - 1);
                //moveQueen(); //slay 🙄💅
                //`(*>﹏<*)′
                //(✿◡‿◡)
                //☆: .｡. o(≧▽≦)o .｡.:☆
            }
            isMenu = 1;
            break;

        case 2:

            printf("Current board size is %dx%d \n", bX, bY);
            printf("Enter new size for the board: ");
            scanf("%d", &bX, &bY);

            freeBoard(board, bX);

            board = malloc(bX * sizeof(char *));
            for (int i = 0; i < bX; i++)
            {
                board[i] = malloc(bY * sizeof(char));
            }

            isMenu = 1;
            break;

        case 3:
            // c
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