#include "coord.h"

int main(void)
{
	size_t	size;
	t_city *city_table;
	t_city city1;
	t_city player;
	t_geo_vector heading;
	
	// load static city data
	size = 21; // static data size currently hard coded, parse csv file for newline count?
	city_table = innit_city_table(size);
	load_city_csv(city_table);

	// generate random city
	city1 = city_table[(int)ft_prandr(0, size)];

	// user input
	printf("What are the coordinates of %s?\n", city1.name);
	printf("latitude: ");
	player.latitude = ft_atof(simple_scan(MAX_ANSWER_SIZE));
	printf("longitude: ");
	player.longitude = ft_atof(simple_scan(MAX_ANSWER_SIZE));

	// calculate heading between city 1 and city 2
	set_heading(city1, player, &heading);
	printf("You landed %.0f km %s of %s\n", heading.distance, heading.cardinal, city1.name);

}
