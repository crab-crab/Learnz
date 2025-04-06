#include "coord.h"

int main(void)
{
	size_t	size = 6;
	t_city *city_table = innit_city_table(size);
	float distance;
	
	load_city_csv(city_table);
	printf("\nload success\n");
	pt_city_table(city_table, size);

	int city1 = (int)ft_prandr(0, size);
	int city2 = (int)ft_prandr(0, size);

	distance = calcc_dist(city_table[city1], city_table[city2]);
	printf("distance between %s and %s: %f\n",city_table[city1].name, city_table[city2].name, distance);
	printf("earch circumference: %d\n", (int)(EARTH_RADIUS * 2 * PI));

}