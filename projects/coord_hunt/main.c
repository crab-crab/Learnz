#include "coord.h"

int main(void)
{
	size_t	size = 6;
	t_city *city_table = innit_city_table(size);
	float distance;
	
	load_city_csv(city_table);
	printf("\nload success\n");
	pt_city_table(city_table, size);

	int city1 = 2;
	int city2 = 4;

	distance = calcc_dist(city_table[city1], city_table[city2]);
	printf("distance between %s and %s: %f\n",city_table[city1].name, city_table[city2].name, distance);

	long long time_since_epoch = t_since_epoch();
	printf("Time since epoch (microseconds): %lld\n", time_since_epoch);

	long us = cur_usec();
	printf("current microseconds: %ld\n", us);
}