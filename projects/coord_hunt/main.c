#include "coord.h"

int main(void)
{
	size_t	size;
	t_city *city_table;
	float distance;
	

	// load static city data
	size = 6; // static data size currently hard coded, parse csv file for newline count?
	city_table = innit_city_table(size);
	load_city_csv(city_table);
	printf("\ncity_table load success\n");

	// generate 2x random indices
	int city1 = (int)ft_prandr(0, size);
	int city2 = (int)ft_prandr(0, size);

	// calculate distance between city 1 and city 2
	distance = calcc_dist(city_table[city1], city_table[city2]);
	printf("distance between %s and %s: %.0f km \n",city_table[city1].name, city_table[city2].name, distance);

}