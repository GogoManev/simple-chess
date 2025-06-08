#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "board.h"

int main()
{
    int isMenu = 1;
    int gameover = 0;
    char **board = init_board(board_size);

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
            board = init_board(board_size);

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
                if(moveQueen(board, board_size)) {
                    gameover = 1;
                    printBoard(board);
                }
                //moveQueen(); //slay 🙄💅
                //`(*>﹏<*)′
                //(✿◡‿◡)
                //☆: .｡. o(≧▽≦)o .｡.:☆
            }
            isMenu = 1;
            break;

        case 2:
            int newSize;
            printf("Current board size is %dx%d \n", board_size, board_size);
            printf("Enter new size for the board: ");
            scanf("%d", &newSize);

            freeBoard(board);

            board_size = newSize;
            board = init_board(board_size);
            printf("Board size changed to %dx%d \n", board_size, board_size);

            isMenu = 1;
            break;

        case 3:
            FILE *file;
            printf("Enter the name of the file to replay from (Make sure it's in the same folder): ");
            char filename[100];
            scanf(" %s", filename);
            file = fopen(filename, "r");

            if(file == NULL) {
                printf("Error opening file.\n");
                break;
            }
            
            int size, xRook1, yRook1, xRook2, yRook2, xking, yking, xqueen, yqueen; 

            fscanf(file, "%d--%d|%d,%d|%d,%d|%d,%d|%d", &size, &xRook1, &yRook1, &xRook2, &yRook2, &xking, &yking, &xqueen, &yqueen);
            fclose(file);
            break;

        case 4:
            printf("goodbye!\n");
            freeBoard(board);
            return 0;

        default:
            printf("bru really, u cant chose one of da 4 options?? u so stupidz foreal\n");
            break;
        }
    }

    return 0;
}