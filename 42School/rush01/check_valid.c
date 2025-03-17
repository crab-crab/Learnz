

int check_sudoku(int **grid, int x, int y, int size)
{
    int checknum = grid[y][x];

    int i = 0;
    while(i < size)
    {
        if(checknum == grid[i][x])
            return (0);
        i++;
    }
    i = 0;
    while(i < size)
    {
        if(checknum == grid[y][i])
            return (0);
        i++;
    }
    return(1);
}

int min_offset(int vis_value, int num, int size)
{
    int offset = size - vis_value;
    int closest = num - offset;
    if(closest > 0)
    {
        return(closest - 1);
    }
    else
        return(0);
}




int check_valid(int **grid, int **constraints, int x, int y, int size)
{

}