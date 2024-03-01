#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

void print_maze(int** maze, int map_row, int map_col) {
    int i, j;
    char character;
    for (i = 0; i < map_row; i++) {
        for (j = 0; j < map_col; j++) {
            if (i == 0 || i == map_row - 1) {
                if (j == 0 || j == map_col - 1) {
                    printf(" #");       /*Map corners*/
                } else {
                    printf(" -");       /*Top and bottom borders*/
                }
            } else if (j == 0 || j == map_col - 1) {
                printf(" |");           /*Left and right borders*/
            } else {
                if (maze[i][j] == 0) {
                    character = '^';
                    printf(" %c", character);       /*Player*/
                } else if (maze[i][j] == 1) {
                    character = 'M';
                    printf(" %c", character);       /*Monster*/
                } else if (maze[i][j] == 2) {
                    character = 'X';
                    printf(" %c", character);       /*Goal*/
                } else if (maze[i][j] == 3) {
                    character = 'O';
                    printf(" %c", character);       /*Wall*/
                } else if (maze[i][j] == 4) {
                    character = 'K';
                    printf(" %c", character);       /*Key*/
                } else if (maze[i][j] == -1) {
                    character = ' ';
                    printf(" %c", character);       /*Empty space*/
                }
            }
        }
        printf("\n");
    }
}

int** create_maze(int map_row, int map_col, int worlddata_amount, int** worlddata) {
    int i, j, k, row, col, code;
    int** maze = (int**) malloc(map_row * sizeof(int*));
    for (i = 0; i < map_row; i++) {
        maze[i] = (int*) malloc(map_col * sizeof(int));
        for (j = 0; j < map_col; j++) {
            maze[i][j] = -1; /* initialize the whole maze as unassigned (empty space) */
        }
    }

    /* assign objects to maze */
    for (k = 0; k < worlddata_amount; k++) {
        row = worlddata[k][0];
        col = worlddata[k][1];
        code = worlddata[k][2];
        maze[row][col] = code;
    }

    return maze;
}

/*free memory from malloc*/
void free_maze(int** maze, int map_row) {
    int i;
    for (i = 0; i < map_row; i++) {
        free(maze[i]);
    }
    free(maze);
}
