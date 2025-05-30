#include "coord.h"

t_city *innit_city_table(size_t size);
void pt_city_table(t_city *city_table, size_t size);
void set_city_table(t_city *city_table, size_t i, char* name, float lat, float lon);
void rm_city_table(t_city *city_table, size_t i);

// initialise city_table
t_city *innit_city_table(size_t size)
{
	size_t	i;
	t_city *city_table;

	i = 0;
	city_table = (t_city *)malloc(size * sizeof(t_city));
	if (city_table == NULL)
	{
		printf("city_table malloc error\n");
		return (NULL);
	}
	while (i < size)
	{
		rm_city_table(city_table, i);
		i++;
	}
	return (city_table);
}

// print city_table
void pt_city_table(t_city *city_table, size_t size)
{
	size_t i;

	i = 0;
	printf("\ncity_table:\n");
	while (i < size)
	{
				printf("City %zu: %s,\t Latitude: %.4f,\t Longitude: %.4f\n", 
			i + 1, city_table[i].name, city_table[i].latitude, city_table[i].longitude);
		i++;
	}
}

// set the values to one of the items in city_table array
void set_city_table(t_city *city_table, size_t i, char* name, float lat, float lon)
{
	ft_strlcpy(city_table[i].name, name, MAX_CITY_NAME_SIZE);
	city_table[i].latitude = lat;
	city_table[i].longitude = lon;
}

// remove city_table entry
void rm_city_table(t_city *city_table, size_t i) // change this to use set_city_table()
{
	ft_strlcpy(city_table[i].name, "0", MAX_CITY_NAME_SIZE);
	city_table[i].latitude = 0;
	city_table[i].longitude = 0;
}
