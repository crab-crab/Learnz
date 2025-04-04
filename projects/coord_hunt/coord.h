
#ifndef COORD_H
#define COORD_H

// constants
extern const double	PI;
extern const int	MAX_BUFFER_SIZE;
extern const int	MAX_CITY_NAME_SIZE;
extern const char* 	CITY_TABLE_FILE;
extern const int	MAX_CSV_COLUMNS;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_city
{
	char	name[50];
	float	latitude;
	float	longitude;
} t_city;

// string.c

int ft_cntchr(char *s, char c);
int ft_atoi(char *str);
size_t ft_strlcpy(char *dst, const char *restrict src, size_t dsize);

// city.c

t_city *innit_city_table(size_t size);
void pt_city_table(t_city *city_table, size_t size);
void set_city_table(t_city *city_table, size_t i, char* name, float lat, float lon);
void rm_city_table(t_city *city_table, size_t i);

// csv.c









#endif