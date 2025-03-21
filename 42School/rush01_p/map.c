#include "rush.h"

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
			while (i < n)
			{
				map[y][x][i] = i + 1;
				i++;
			}
			x++;
		}
		y++;
	}
}


// initialise map - 3d array n x n x n
// describes a map[y][x] where each position contains a list of all possible values
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
			map[i][j] = (int*)malloc(n * sizeof(int));
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