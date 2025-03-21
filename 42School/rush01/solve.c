#include "rush.h"

// iterative backtracking algorithm
// returns true if a valid completed grid is found
// returns false any time an incorrect configuration is found
// iterates through all possible values for a given square until validity satisfied
// moves to next spot if validity satisfied
// backtracks a square any time false is returned
// will return false if no correct configurations are possible

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

