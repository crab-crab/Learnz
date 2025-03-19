#include "rush.h"

int solve(int **grid,int *constraints, int x, int y,int size)
{
	int num = size;
	
	// print_grid(grid, size);
	// printf("\n");
	//printf("solve - x:%d, y:%d\n", x, y);
	if (x == size)
	{
		return (solve(grid, constraints, 0, y + 1, size));
		// if(check_row(grid, constraints, x, size) == 1)
		// 	return (solve(grid, constraints, 0, y + 1, size));
		// else
		// 	return (0);
	}
	if (y == size)
	{
		// print_grid(grid, size);
		// printf("\n");
		return (check_grid_vis(grid, constraints, size));
	}
	

	while (num > 0)
	{
		// printf("solve - x:%d, y:%d | num = %d\n", x, y, num);
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


// Test Values:
// 4x4:  "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"  (correct)
// Output: 1 2 3 4
//		   2 3 4 1
//         3 4 1 2
//         4 1 2 3
//
// 5x5:
// 6x6:
// 7x7:
// 8x8:
// 9x9: