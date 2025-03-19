#include "rush.h"

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        write(1, "expected 2 program arguments", 28);
        exit(EXIT_FAILURE);        
    }

	// start timer
	struct timeval start, end;
	gettimeofday(&start, NULL);

    // preparse input string to find number of characters
    int arg_size = count_inputs(argv[1]);

    // from math, squrt to get length of one side
    int size = (arg_size/4);

    // return one dimensional int array containing constraints
    int *constraints = parse_input(argv[1], arg_size);

	// initialise grid - 2d array of ints
	// fill with 0's
	int **grid = grid_innit(size);
	grid_fill(grid, size, 0);


	// call solve function on grid & constraints, print grid if solution
	if(solve(grid, constraints, 0, 0, size) == 1)
	{
		write(1, "grid solved:\n", 13);
		print_grid(grid, size);
	}
	else
		write(1, "no solution found :(\n", 20);

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
