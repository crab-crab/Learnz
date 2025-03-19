
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "rush.h"

void ft_putnbr(int nbr)//!checked!
{
    if(nbr == -2147483648)
    {
        write(1, "-2147483648", 11);
        return;
    }
    if(nbr < 0)
    {
        write(1, "-", 1);
        nbr = nbr * -1;
    }
    if( nbr >= 0 && nbr <= 9)
    {
        char c = '0' + nbr;
        write(1, &c, 1);
        return;
    }
    ft_putnbr(nbr / 10);
    ft_putnbr(nbr % 10);
}

// initialise grid of size n, return pointer to 2d int array of grid
int **grid_innit(int n)//!checked!
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
void grid_fill(int **grid, int n, int fill)//!checked!
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
void print_grid(int **grid, int n)//!checked!
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
void edit_grid(int **grid, int x, int y, int value)//!checked!
{
    grid[y][x] = value;
}

// free the malloc'd memory of all members of grid, of grid
// check for NULL before freeing, set to NULL after
void free_grid(int **grid, int n)//!checked!
{
    int i;
	i = 0;

    while (i < n)
    {
        if (grid[i] != NULL)
		{
			free(grid[i]);
			grid[i] = NULL;
			//write(1, "row free\n", 9);
		}
		i++;
    }
	if (grid != NULL)
		{
			free(grid);
			grid = NULL;
			//write(1, "grid free\n", 10);
		}
}

// int main(void)
// {
//     int size = 5;
//     int **grid = grid_innit(size);
//     grid_fill(grid, size, 0);
//     print_grid(grid, size);
// 	write(1, "______________\n\n", 16);

//     edit_grid(grid, 0, 0, 1);
//     edit_grid(grid, 0, 1, 2);
//     edit_grid(grid, 0, 2, 3);
//     edit_grid(grid, 0, 3, 4);
//     edit_grid(grid, 1, 0, 2);
//     edit_grid(grid, 1, 1, 3);
//     edit_grid(grid, 1, 2, 4);
//     edit_grid(grid, 1, 3, 1);
//     edit_grid(grid, 2, 0, 3);
//     edit_grid(grid, 2, 1, 4);
//     edit_grid(grid, 2, 2, 1);
//     edit_grid(grid, 2, 3, 2);
//     edit_grid(grid, 3, 0, 4);
//     edit_grid(grid, 3, 1, 1);
//     edit_grid(grid, 3, 2, 2);
//     edit_grid(grid, 3, 3, 3);


//     print_grid(grid, size);

// 	printf("checksudoku: %d\n", check_sudoku(grid, 0, 0, size));

// 	free_grid(grid, size);


// }