
#include <stdlib.h>
#include <unistd.h>

void ft_putnbr(int nbr)
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
            write(1, "grid innit error", 16);
            return (NULL);
        }
        i++;
    }
    return (grid);
}

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

void edit_grid(int **grid, int x, int y, int value)
{
    grid[y][x] = value;
}

void free_grid(int **grid, int n)
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

int main(void)
{
    int size = 5;
    int **grid = grid_innit(size);
    grid_fill(grid, size, 0);
    print_grid(grid, size);

    edit_grid(grid, 0, 0, 1);
    edit_grid(grid, 1, 1, 1);
    edit_grid(grid, 2, 2, 1);
    edit_grid(grid, 3, 3, 1);
    edit_grid(grid, 4, 4, 1);

    print_grid(grid, size);
}