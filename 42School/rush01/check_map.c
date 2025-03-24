// add the max height block at the edge whenever viewer constraint == 1
int add_max_n(int ***map, int *constraints,int x, int y, int size,)
{
	int i = 0;

	while (i < n)
	{
		if (constraints[i] == 1)
			map_set_num(map[0][i], size, size);
		if (constraints[i + size] == 1)
			map_set_num(map[size-1][i], size, size);
		if (constraints[i + 2*size] == 1)
			map_set_num(map[i][0], size, size);
		if (constraints[i + 3*size] == 1)
			map_set_num(map[i][size-1], size, size);	
	}
}

int sdk_row_check(int ***map, int row, int num, int size)
{
	int i = 0;
	int last_index = 0;
	int count = 0;

	while (i < size)
	{
		if (map[row][i][num] > 0)
		{
			count++;
			last_index = i;
		}
		i++
	}
	if(count == 1)
		return (last_index);
	else
		return (-1);
}

int sdk_col_check(int ***map, int col, int num, int size)
{
	int i = 0;
	int last_index = 0;
	int count = 0;

	while (i < size)
	{
		if (map[i][col][num] > 0)
		{
			count++;
			last_index = i;
		}
		i++
	}
	if(count == 1)
		return (last_index);
	else
		return (-1);
}

// rc_map[row + size][i] != 1

int 


int solve_map(int ***map, int **grid, int *constraints,int x, int y, int size, int count)
{
	
}