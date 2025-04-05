#include "coord.h"

char *rd_csv_line(char *csv, char **contents)
{
	int		i;
	
	i = 0;
	while (*csv != '\n' && *csv != '\0')
	{
		
		contents[i] = csv;
		i++;
		while (*csv != ',' && *csv != '\n' && *csv != '\0')
		{
			csv++;
		}
		if (*csv == '\0')
			return (NULL);
		if (*csv == '\n')
		{
			*csv = '\0';
			csv++;
			return (csv);
		}
		*csv = '\0';
		csv++;
	}
	return (NULL);
}

int open_csv_file(const char *filename)
{
	int fd;
	
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("File open failed\n");
		exit(0);
	}
	else
	{
		printf("File open success\n");
		printf("fd : %d\n", fd);
		return fd;
	}
}

void csv_to_struct(char **contents, t_city *city_table, int i)
{
	//char name[MAX_CITY_NAME_SIZE];
	float lat;
	float lon;

	lat = (float)ft_atoi(contents[1]);
	lon = (float)ft_atoi(contents[2]);
	set_city_table(city_table, i, contents[0], lat, lon);
}


void load_city_csv(t_city * city_table)
{
	int fd;
	char buffer[MAX_BUFFER_SIZE];
	char **contents;
	size_t bytesread;
	char *csv_line;
	int i;

	fd = open_csv_file(CITY_TABLE_FILE);
	bytesread = read(fd, buffer, sizeof(buffer));
	printf("Bytesread : %zu\n\n", bytesread);
	// if (write(1, buffer, bytesread) < 0)
	// {
	// 	printf("print error");
	// 	exit(0);
	// }
	i = 0;
	csv_line = buffer;
	contents = (char**)malloc(3 * sizeof(char*));
	while (csv_line != NULL)
	{
		csv_line = rd_csv_line(csv_line, contents);
		// printf("parse success\n");
		// printf("contents array:\n%s\n%s\n%s\n", contents[0], contents[1], contents[2]);
		csv_to_struct(contents, city_table, i);
		i++;
	}
}
