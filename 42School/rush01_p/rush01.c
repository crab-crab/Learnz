#include "rush.h"

int main(int argc, char **argv)
{
    if(argc != 2 && argv[1][0] != 't')
    {
        write(1, "expected 2 program arguments\n", 29);
        exit(EXIT_FAILURE);        
    }

	int **grid;
	int *constraints;
	int size;

	// Test Generation //
	// argv[1] == "t" | argv[2] = size of square | argv[3] = <initial values>
	// if in test mode, program will generate a sudoku legal grid from initial values
	// then calculate vis values and return a corresponding *constraints
	if(argv[1][0] == 't')
	{
		printf("generating test values\n");
		int test_size = argv[2][0] - '0';
		printf("test square size: %d\n", test_size);
		size = test_size;
		grid = grid_innit(size);
		grid_fill(grid, size, 0);
		int added = add_values(grid, argv[3], size);
		finish_grid(grid, (added % size), (added / size), size);
		constraints = get_grid_vis(grid, size);
		printf("grid with initial %d values finished:\n", added);
		print_grid(grid, size);
		printf("generated constraints:\n");
		pt_parsed_input(constraints, size);
		grid_fill(grid, size, 0);
	}

	// start timer
	struct timeval start, end;
	gettimeofday(&start, NULL);

   	if(argc == 2)
	{ 
		// preparse input string to find number of characters
		int arg_size = count_inputs(argv[1]);
		size = (arg_size/4);

		// return one dimensional int array containing constraints
		constraints = parse_input(argv[1], arg_size);

		// initialise grid - 2d array of ints
		// fill with 0's
		grid = grid_innit(size);
		grid_fill(grid, size, 0);
	}

	// call solve function on grid & constraints, print grid if solution
	if(solve(grid, constraints, 0, 0, size) == 1)
	{
		write(1, "grid solved:\n", 13);
		print_grid(grid, size);
	}
	else
	{
		write(1, "no solution found :(\n", 20);
		print_grid(grid, size);
	}
	// free all pointers in grid and set to NULL
	free(grid);

	// stop timer and calculate difference
	gettimeofday(&end, NULL);
	long int time_taken = (end.tv_sec * 1000000 + end.tv_usec) 
						- (start.tv_sec * 1000000 + start.tv_usec);

	// print time taken
	printf("Time taken: %ld micro seconds\n", time_taken);
	return(0);
}
