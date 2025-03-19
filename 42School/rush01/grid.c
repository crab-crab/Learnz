
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "rush.h"

// These functions handle initialisation/malloc for grid
// as well as: editting values, printing, freeing


// initialise grid of size n, return pointer to 2d int array of grid
int **grid_innit(int n)
{
    int i = 0;
    int **grid = (int **)malloc(n * sizeof(int *));
    if(grid == NULL)
    {
        write(1, "grid innit error", 16);
        return (NULL);
    }

    while (i < n)
    {
        grid[i] = (int *)malloc(n * sizeof(int));
        if(grid[i] == NULL)
        {
            write(1, "grid row innit error", 20);
            return (NULL);
        }
        i++;
    }
    return (grid);
}

// fill grid with filler int "fill"
void grid_fill(int **grid, int n, int fill)
{
    int i = 0;
    int j = 0;

    while(i < n)
    {
        j = 0;
        while(j < n)
        {
            grid[i][j] = fill;
            j++;
        }
        i++;
    }
}

// print out grid on stdout
void print_grid(int **grid, int n)
{
    int i = 0;
    int j = 0;

    while(i < n)
    {
        j = 0;
        while(j < n)
        {
            ft_putnbr(grid[i][j]);
            write(1," ",1);
            j++;
        }
        write(1,"\n",1);
        i++;
    }
}

// change value at position x,y in grid
void edit_grid(int **grid, int x, int y, int value)
{
    grid[y][x] = value;
}

// free the malloc'd memory of all members of grid, of grid
// check for NULL before freeing, set to NULL after
void free_grid(int **grid, int n)
{
    int i;
	i = 0;

    while (i < n)
    {
        if (grid[i] != NULL)
		{
			free(grid[i]);
			grid[i] = NULL;
		}
		i++;
    }
	if (grid != NULL)
		{
			free(grid);
			grid = NULL;
		}
}
