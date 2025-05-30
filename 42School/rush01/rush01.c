#include "rush.h"

int main(int argc, char **argv)
{
    if(argc != 2 && argv[1][0] != 't')
    {
        write(1, "expected 2 program arguments\n", 29);
        exit(EXIT_FAILURE);        
    }

	int **grid;
	char *s_constraints;
	int *constraints;
	int size;

	// Test Mode //
	// generate test constraints according to input
	// argv[1] == "t" | argv[2] = size of square | argv[3] = <initial values string>
	// example: ./a.out "t" "6" "1 3 4 2 6"
	if(argv[1][0] == 't')
	{
		size = argv[2][0] - '0';
		constraints = test(argv[2][0], argv[3], constraints);
	}

	// start timer
	struct timeval start, end;
	gettimeofday(&start, NULL);


	// only execute if not in test mode
	if (argc == 2)
	{		
		// if correct arguments received and not in test mode
		// preparse input string to find number of characters
		int arg_size = count_inputs(argv[1]);
		size = (arg_size/4);

		// return one dimensional int array containing constraints
		constraints = parse_input(argv[1], arg_size);
	}


	// initialise grid - 2d array of ints
	// fill with 0's
	grid = grid_innit(size);
	grid_fill(grid, size, 0);


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
	free_grid(grid, size);
	free_constraints(constraints, size);

	// stop timer and calculate difference
	gettimeofday(&end, NULL);
	long int time_taken = (end.tv_sec * 1000000 + end.tv_usec) 
						- (start.tv_sec * 1000000 + start.tv_usec);

	// print time taken
	printf("Time taken: %ld micro seconds\n", time_taken);
	return(0);
}
