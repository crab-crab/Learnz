#include "coord.h"

// degrees to radian converter
double dtor(float degrees)
{
	double radians;

	radians = degrees * (PI / 180); // are we losing data due to C division?
	return ((double)radians);
}

// calculate distance between two sets of coordinates (in degrees)
float calc_distance(float lat_1, float lon_1, float lat_2, float lon_2)
{
	double distance;

	distance = haver_formula(dtor(lat_1), dtor(lon_1), dtor(lat_2), dtor(lon_2));
	return ((float)distance);
}

// calculate distance between 2 cities
float calcc_dist(t_city city1, t_city city2)
{
	float distance;

	distance = calc_distance(city1.latitude, city1.longitude, city2.latitude, city2.longitude);
	return(distance);
}

// innefective log approximation
int check_power_of(long number, int divisor)
{
    int divide_count = 0;

    while(number >= divisor)
    {
        number = number / divisor;
        divide_count++;
    }
    return (divide_count);
}

// takes a number "num" and multiplies it by itself "pow" times
long ft_power(int num, int pow)
{
    int multiplier = num;
    if(pow < 0)
        return(0);    
    if(pow == 0)
        return (1);
    while (pow > 1)
    {
        num = num *multiplier;
        pow--;
    }
    return(num);
}
