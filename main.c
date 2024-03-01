#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include "move.h"
int main(int argc, char *argv[]) {
    int i;
    int worlddata_amount, map_row, map_col;
    int** worlddata;
    int** maze;

    /* read metadata from map.txt */
    FILE* fp;
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Unable to open file\n");
        return 1;
    }
    fscanf(fp, "%d %d %d", &worlddata_amount, &map_row, &map_col);
    worlddata = (int**) malloc(worlddata_amount * sizeof(int*));
    for (i = 0; i < worlddata_amount; i++) {
        worlddata[i] = (int*) malloc(3 * sizeof(int));
        fscanf(fp, "%d %d %d", &worlddata[i][0], &worlddata[i][1], &worlddata[i][2]);
    }
    fclose(fp);

    /* create and print maze */
    maze = create_maze(map_row, map_col, worlddata_amount, worlddata);
    print_maze(maze, map_row, map_col);
     movement(maze, map_row, map_col);

    /* free memory */
    free_maze(maze, map_row);
    for (i = 0; i < worlddata_amount; i++) {
        free(worlddata[i]);
    }
    free(worlddata);
    return 0;
}
