// These functions return a visibility count when looking down/up/right/left accross a column/row
// can be compared against constraints to confirm suitability -> generate boolean

// looking downwards
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

// looking upwards
int vis_up(int **grid, int col, int size)
{
    int count = 0;
    int max = 0;

    while(size >= 0)
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

// looking -> right
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

// looking -> left
int vis_left(int **grid, int row, int size)
{
    int count = 0;
    int max = 0;

    while(size >= 0)
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

int check_row(int **grid, int *constraints, int row, int size)
{
	if(vis_right(grid, row, size) != constraints[row + 2*size] 
	|| vis_left(grid, row, size) != constraints[row + 3*size])
		return(0);
	else
    	return (1);
}

int check_grid_vis(int **grid, int *constraints, int size)
{
    int i = 0;
    while (i < size)
    {
        if(vis_down(grid, i, size) != constraints[i] 
        || vis_up(grid, i, size) != constraints[i + size])
            return(0);
        if(vis_right(grid, i, size) != constraints[i + 2*size] 
        || vis_left(grid, i, size) != constraints[i + 3*size])
            return(0);
        i++;
    }
    return (1);
}