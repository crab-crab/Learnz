// These functions return a visibility count when looking down/up/right/left accross a column/row
// can be compared against constraints to confirm suitability -> generate boolean

int vis_down(int **grid, int col, int size)
{
    int i = 0;
    int count = 0;
    int max = 0;

    while(i < size)
    {
        if(grid[i][col] > max)
        {
            max = grid[i][col];
            count++;
        }
        i++;
    }
    return (count);
}

int vis_up(int **grid, int col, int size)
{
    int count = 0;
    int max = 0;

    while(size > 0)
    {
        if(grid[size-1][col] > max)
        {
            max = grid[size-1][col];
            count++;
        }
        size--;
    }
    return (count);
}

int vis_right(int **grid, int row, int size)
{
    int i = 0;
    int count = 0;
    int max = 0;

    while(i < size)
    {
        if(grid[row][i] > max)
        {
            max = grid[row][i];
            count++;
        }
        i++;
    }
    return (count);
}

int vis_left(int **grid, int row, int size)
{
    int count = 0;
    int max = 0;

    while(size > 0)
    {
        if(grid[row][size-1] > max)
        {
            max = grid[row][size-1];
            count++;
        }
        size--;
    }
    return (count);
}
