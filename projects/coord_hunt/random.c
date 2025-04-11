#include "coord.h"

// middle square method
long mid_square(long seed)
{
	long square;
	long middle;
	int	seed_size;
	int square_size;

	seed_size = check_power_of(seed, 10) + 1;
	square = seed * seed;
	square_size = check_power_of(square, 10) + 1;
	

	middle = square % ft_power(10, (square_size - seed_size/2));
	middle = middle / ft_power(10, (square_size - 3*seed_size/2));

	//printf("seed_size: %d, square_size %d, square: %ld\n", seed_size, square_size, square);
	//middle = (square % ft_power(10,(3*seed_size)/2)) / ft_power(10, seed_size/2);
	
	while (check_power_of(middle, 10) + 1 < seed_size)
		middle = (10 * middle) + (cur_usec() % 10);

	return (middle);
}

// returns pseudo random float between 0 and 1
float ft_prand(void)
{
	long	seed;
	int		i;
	float	result;
	int 	seed_len;
	
	seed = cur_usec();
	i = cur_usec()%20;

	while (i > 0)
	{
		seed = mid_square(seed);
		i--;
	}
	seed_len = check_power_of(seed, 10) + 1;
	result = (float)seed / ft_power(10, seed_len);
	//printf("seed: %ld  result: %d\n", seed, result);

	return (result);
}

// returns psrandom int - 0 or 1
int ft_prandb(void)
{
	if (ft_prand() > 0.5)
		return (1);
	else
		return (0);
}

// returns psrandom float between min and max
float ft_prandr(float min, float max)
{
	float average;
	float range;

	average = (min + max)/2;
	range = max - average;
	if(ft_prandb())
		range *= -1;
	return(average + ft_prand()*range);

}
