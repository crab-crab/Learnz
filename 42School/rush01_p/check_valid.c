#include "rush.h"

//These functions check if a number at a given position breaks any rules/constraints

//given a position in the square, does that number repeat itself in its colum/row?
int check_sudoku(int **grid, int x, int y, int size)
{
    int checknum = grid[y][x];

    int i = 0;
    while(i < size)
    {
		if(checknum == grid[i][x])
			if(i != y)
				return (0);
			
        i++;
    }
    i = 0;
    while(i < size)
    {
		if(checknum == grid[y][i])
			if(i != x)
				return (0);
        i++;
    }
    return(1);
}

// return minimum distance between num and edge, given a vis_value
int min_distance(int vis_value, int num, int size)
{
    int offset = size - vis_value;
    int closest = num - offset;
    if(closest > 0)
        return(closest - 1);
    else
        return(0);
}

// checks max possible views can satisfy constraints
int max_possible(int **grid, int *constraints, int x, int y, int size)
{
	if (vis_down(grid, x, size) < constraints[x]
		|| vis_up(grid, x, size) < constraints[x + size]
		|| vis_right(grid, y, size) < constraints[y + 2*size]
		|| vis_left(grid, y, size) < constraints[y + 3*size])
		return (0);
	return(1);
}

// check offset of a given number against expected offset
// do so in all directions - up/down/left/right
int check_min_distance(int **grid, int *constraints, int x, int y, int size)
{
	int num = grid[y][x];
	if(min_distance(constraints[x], num, size) > y
		|| min_distance(constraints[x + size], num, size) > size - y
		|| min_distance(constraints[y + 2*size], num, size) > x
		|| min_distance(constraints[y + 3*size], num, size) > size - x)
		return(0);
	return(1);
}

// check if value at position x,y conforms to Sudoku & Min Distance & Max Possible
// run right after placing a new number in the grid, allows recursion to progress if True
int check_valid(int **grid, int *constraints, int x, int y, int size)
{
    if (check_sudoku(grid, x, y , size) 
		&& check_min_distance(grid, constraints, x, y, size) 
		&& max_possible(grid, constraints, x, y, size))
    {
        return (1);
    }
    else
        return (0);
}
