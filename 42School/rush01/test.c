#include "rush.h"
int add_values(int **grid, char *values, int size)
{
	int in_size = count_inputs(values);
	int *in_parsed = parse_input(values, in_size);
	int x = 0;
	int y = 0;
	while(size > 0)
	{
		if(x == size)
		{
			x = 0;
			y++;
		}
		grid[y][x] = *values;
		values++;
		x++;
	}
	return(in_size);
}


int finish_grid(int **grid, int x, int y, int size)
{
	int num = size;
	
	if (x == size)
		return (finish_grid(grid, 0, y + 1, size));
	if (y == size)
		return (1);
	while (num > 0)
	{
		edit_grid(grid, x, y, num);
		
		if(check_sudoku(grid, x, y, size) == 1)
		{	
			if (finish_grid(grid, x + 1, y, size) == 1)
				return(1);
			edit_grid(grid, x, y, 0);
		}
		num--;
	}
	edit_grid(grid, x, y, 0);
	return(0);
}

int *get_grid_vis(int **grid, int size)
{
	int i = 0;
	
	int *constraints = (int *)malloc(4 * size * sizeof(int));
	while(i < size)
	{
		constraints[i] = vis_down(grid, i, size);
		constraints[i + size] = vis_up(grid, i, size);
		constraints[i + 2*size] = vis_right(grid, i, size);
		constraints[i + 3*size] = vis_left(grid, i, size);
		i++;
	}
	return (constraints);
}