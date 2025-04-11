#include "coord.h"

// args			(csv -> csv file being read in | contents -> array csv parsing results is being stored in)
// transform	(read csv values into contents)
// return		(pointer to start of next CSV file line)
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
		return fd;
	}
}

// create a struct instance for each one of the items in CONTENTS, fill values as required
void csv_to_struct(char **contents, t_city *city_table, int i)
{
	float lat;
	float lon;

	lat = (float)ft_atoi(contents[1]);
	lon = (float)ft_atoi(contents[2]);
	set_city_table(city_table, i, contents[0], lat, lon);
}

// 
void load_city_csv(t_city *city_table)
{
	int fd;
	char buffer[MAX_BUFFER_SIZE];
	char **contents;
	char *csv_line;
	int i;

	fd = open_csv_file(CITY_TABLE_FILE);

	//(void)'ing return value of read as it is unused -> to get around -Werror -> is this safe?
	(void)read(fd, buffer, sizeof(buffer));
	i = 0;
	csv_line = buffer;
	contents = (char**)malloc(3 * sizeof(char*));
	while (csv_line != NULL)
	{
		csv_line = rd_csv_line(csv_line, contents);
		csv_to_struct(contents, city_table, i);
		i++;
	}
}
