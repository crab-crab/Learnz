#include "coord.h"

int main(void)
{
	size_t	size = 6;
	t_city *city_table = innit_city_table(size);
	
	load_city_csv(city_table);
	printf("\nload success\n");
	pt_city_table(city_table, size);
}