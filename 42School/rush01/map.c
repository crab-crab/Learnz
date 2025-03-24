#include "rush.h"

// confirms the number for a cell in the map by asigning that number to index 0
// removes possibilities for any other numbers in that cell
// removes possibility for that number appearing anywhere else in that row/col
void map_set_num(int ***map, int x, int y, int num, int size) //unfinished!
{
	int i = 1;
	
	map[y][x][0] = num;
	while (i <= size)
	{
		map[y][x][i] = 0;
		i++;
	}

	i = 0;
	while(i < size)
	{
		map[y][i][num] = 0;
		map[i][x][num] = 0;
		i++;
	}
}

// sets number in cell of map, updates row/col map to show that number has been assigned
void map_add_num(int ***map, **rc_map, int x, int y, int num, int size)
{
	map_set_num(map, x, y, num, size);
	rc_map[x][num - 1] = 1;
	rc_map[y + size][num - 1] = 1;
}


// initialise and fill a row/col map
// this will describe which values have been confirmed in a row/col
int **rc_map(int n)
{
	int i = 0;
	int j = 0;
	int **rowcol_map = (int **)malloc(2 * n * sizeof(int *));
	while (i < 2 * n)
	{
		rowcol_map[i] = (int *)malloc(n * sizeof(int));
		while (j < n)
		{
			rowcol_map[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return(rowcol_map);
}


// fill each spot in the map with numbers 1 to n
void fill_map(int ***map, int n)
{
    int y = 0;
	int x = 0;
	int i = 0;
	while (y < n)
	{
		while (x < n)
		{
			while (i <= n)
			{
				map[y][x][i] = i;
				i++;
			}
			x++;
		}
		y++;
	}
}


// initialise map - 3d array n x n x (n + 1)
// describes a map[y][x] where each position contains a list of all possible values
// each position's list of values will contain a "0" index[0] if that position is still unknown
// if position is known index 0 will contain the solution number
int ***map_innit(int n)
{
    int i = 0;
	int j = 0;
    int ***map = (int ***)malloc(n * sizeof(int **));
    if(map == NULL)
    {
        write(1, "map innit error\n", 16);
        return (NULL);
    }

    while (i < n)
    {
        map[i] = (int **)malloc(n * sizeof(int*));
        if(map[i] == NULL)
        {
            write(1, "map row innit error\n", 20);
            return (NULL);
        }
        i++;
    }
	i = 0;

	while (i < n)
	{
		while (j < n)
		{
			map[i][j] = (int*)malloc((n + 1) * sizeof(int));
			if(map[i] == NULL)
			{
				write(1, "map values innit error\n", 23);
				return (NULL);
			}
			j++;
		}
		i++;
	}


    return (map);
}