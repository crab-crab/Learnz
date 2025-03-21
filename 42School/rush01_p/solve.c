#include "rush.h"

int solve(int **grid,int *constraints, int x, int y,int size)
{
	int num = size;
	
	if (x == size)
	{
		if(check_row(grid, constraints, y, size) == 1)
			return (solve(grid, constraints, 0, y + 1, size));
		else
			return (0);
	}
	if (y == size)
		return (check_grid_vis(grid, constraints, size));
	
	while (num > 0)
	{
		edit_grid(grid, x, y, num);
		if(check_valid(grid, constraints, x, y, size) == 1)
		{	
			if (solve(grid, constraints, x+1, y, size) == 1)
				return(1);
			edit_grid(grid, x, y, 0);
		}
		num--;
	}
	edit_grid(grid, x, y, 0);
	return(0);
}

