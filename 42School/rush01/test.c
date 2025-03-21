#include "rush.h"

// takes a string of initial grid values, parses and inserts into grid
int add_values(int **grid, char *values, int size)
{
	int in_size = count_inputs(values);
	int result = in_size;
	printf("counted %d values\n", in_size);
	int *in_parsed = parse_input(values, in_size);
	int x = 0;
	int y = 0;
	while(in_size > 0)
	{
		if(x == size)
		{
			x = 0;
			y++;
		}
		grid[y][x] = *in_parsed;
		in_parsed++;
		x++;
		in_size--;
	}
	return(result);
}

// finishes a half-started grid using sudoku rules
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

// generate a set of constraints from a finished grid
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

// Test Generation //
// argv[1] == "t" | argv[2] = size of square | argv[3] = <initial values string>
// example: ./a.out "t" "4" "1 2 3 4 2 3 4 1 3 4 1 2 4 1 2 3"
// if in test mode, program will generate a sudoku legal grid from initial values
// then calculate vis values and return a corresponding *constraints

int *test(char c_test_size, char *test_values, int *constraints)
{

	int size = c_test_size - '0';
	printf("generating test of size: %d\n", size);

	// initialise and fill grid with 0's
	int **grid = grid_innit(size);
	grid_fill(grid, size, 0);
	int added = add_values(grid, test_values, size);

	// finish grid and generate set of constraints
	finish_grid(grid, (added % size), (added / size), size);
	constraints = get_grid_vis(grid, size);

	//print test grid
	printf("grid with initial %d values finished:\n", added);
	print_grid(grid, size);

	// print test constraints
	printf("generated constraints:\n");
	pt_parsed_input(constraints, size);

	// free grid used to generate test values
	free(grid);

	return (constraints);
}