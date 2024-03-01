#ifndef MAZE_H_
#define MAZE_H_

void print_maze(int** maze, int map_row, int map_col);

int** create_maze(int map_row, int map_col, int worlddata_amount, int** worlddata);

void free_maze(int** maze, int map_row);

#endif /* MAZE_H_ */
