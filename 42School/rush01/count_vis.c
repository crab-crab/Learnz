// These functions return a visibility count when looking down/up/right/left accross a column/row
// can be compared against constraints to confirm suitability -> generate boolean

// looking downwards
// if column incomplete - assume incomplete values add to count
int vis_down(int **grid, int col, int size)
{
    int i = 0;
    int count = 0;
    int max = 0;

    while(i < size)
    {
        if(grid[i][col] == 0)
		{
			count += (size - max);
			return(count);
		}	
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
// if column incomplete & max value < size:
// return number of incomplete spaces
int vis_up(int **grid, int col, int size)
{
    int i = size - 1;
	int count = 0;
    int max = 0;
	int zeros = 0;

    while(i >= 0)
    {
        if(grid[i][col] == 0)
		{
			zeros++;
			count++;
		}
		if(grid[i][col] > max)
        {
            max = grid[i][col];
            count++;
        }
        i--;
    }
	if(max < size)
		count = zeros;
    return (count);
}

// looking -> right
// if row incomplete - assume incomplete values add to count
int vis_right(int **grid, int row, int size)
{
    int i = 0;
    int count = 0;
    int max = 0;

    while(i < size)
    {
        if(grid[row][i] == 0)
		{
			count += (size - max);
			return(count);
		}
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
// if row incomplete & max value < size:
// return number of incomplete spaces
int vis_left(int **grid, int row, int size)
{
    int i = size - 1;
	int count = 0;
    int max = 0;
	int zeros = 0;

    while(i >= 0)
    {
        if(grid[row][i] == 0)
		{
			zeros++;
			count++;
		}
		if(grid[row][i] > max)
        {
            max = grid[row][i];
            count++;
        }
        i--;
    }
	if(max < size)
		count = zeros;
    return (count);
}

// check a row according to the constraints on either side
int check_row(int **grid, int *constraints, int row, int size)
{
	if(vis_right(grid, row, size) != constraints[row + 2*size] 
	|| vis_left(grid, row, size) != constraints[row + 3*size])
		return(0);
	else
    	return (1);
}

// check a col according to the constraints on either side
int check_col(int **grid, int *constraints, int col, int size)
{
	if(vis_up(grid, col, size) != constraints[col + size] 
	|| vis_down(grid, col, size) != constraints[col])
		return(0);
	else
    	return (1);
}

// check an entire grid against constraints
int check_grid_vis(int **grid, int *constraints, int size)
{
    int i = 0;
    while (i < size)
    {
        if(vis_down(grid, i, size) != constraints[i] 
        || vis_up(grid, i, size) != constraints[i + size]
		|| vis_right(grid, i, size) != constraints[i + 2*size] 
        || vis_left(grid, i, size) != constraints[i + 3*size])
            return(0);
        i++;
    }
    return (1);
}