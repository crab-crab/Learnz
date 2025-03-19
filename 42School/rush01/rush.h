// if rush.h is not included to any file
// Include guard
#ifndef RUSH_H

#define RUSH_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

// argv.c
int count_inputs(char *);
int *parse_input(char *, int);

// count_vis.c
int vis_down(int **, int, int);
int vis_up(int **, int, int);
int vis_right(int **, int, int);
int vis_left(int **, int, int);
int check_row(int **, int *, int, int);
int check_col(int **, int *, int, int);
int check_grid_vis(int **, int *, int);

// grid.c
int **grid_innit(int);
void grid_fill(int **, int, int);
void print_grid(int **, int);
void edit_grid(int **, int, int, int);
void free_grid(int **, int);

// check_valid.c
int check_sudoku(int **, int, int, int);
int min_offset(int, int, int);
int check_offset(int **, int *, int, int, int);
int check_valid(int **, int *, int, int, int);

// math.c
int squrt(int);

// solve.c
int solve(int **, int *, int, int, int);

#endif
