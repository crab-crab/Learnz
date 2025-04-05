#include "coord.h"

long mid_square(long seed)
{
	long square;
	long middle;
	int	seed_size;

	seed_size = check_power_of(seed, 10) + 1;
	square = seed * seed;
	middle = (square % ft_power(10,(3*seed_size)/2)) / ft_power(10, seed_size/2);
	return (middle);
}