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
    int size = squrt(arg_size);

    // return one dimensional int array containing constraints
    int *constraints = parse_input(argv[1], arg_size);

	// initialise grid - 2d array of ints
	// fill with 0's
	int **grid = grid_innit(size);
	grid_fill(grid, size, 0);


	// call solve function on grid & constraints, print grid
	if(solve(grid, constraints, 0, 0, size) == 1)
	{
		printf("grid solved:\n");
		print_grid(grid, size);
	}
	else
		printf("no solution found :(\n");

	free(grid);

	// stop timer and calculate difference
	gettimeofday(&end, NULL);
	long int time_taken = (end.tv_sec * 1000000 + end.tv_usec) 
						- (start.tv_sec * 1000000 + start.tv_usec);


	printf("Time taken is : %ld milli seconds\n", time_taken/1000);
	return(0);
}
