

int check_grid(int **grid, int *constraints, int size)
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