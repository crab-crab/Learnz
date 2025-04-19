#include "coord.h"

int main(void)
{
	size_t	size;
	t_city *city_table;
	float distance;
	t_city answer;
	

	// load static city data
	size = 21; // static data size currently hard coded, parse csv file for newline count?
	city_table = innit_city_table(size);
	load_city_csv(city_table);
	// pt_city_table(city_table, size);

	// generate random index
	int city1 = (int)ft_prandr(0, size);

	// user input
	printf("What are the coordinates of %s?\n", city_table[city1].name);
	printf("latitude: ");
	answer.latitude = ft_atof(simple_scan(MAX_ANSWER_SIZE));
	printf("longitude: ");
	answer.longitude = ft_atof(simple_scan(MAX_ANSWER_SIZE));

	// calculate distance between city 1 and city 2
	distance = calcc_dist(city_table[city1], answer);
	printf("You landed %.0f km from %s\n", distance, city_table[city1].name);

}
