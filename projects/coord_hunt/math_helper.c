#include "coord.h"

double ft_haver(double theta)
{
	double result;

	result = sin(theta * 0.5);
	result *= result;
	return (result);
}

double haver_formula(double lat_1, double lon_1, double lat_2, double lon_2)
{
	double distance;
	double hav_theta;
	double delta_lat;
	double delta_lon;

	delta_lat = (double)(lat_2 - lat_1);
	delta_lon = (double)(lon_2 - lon_1);

	hav_theta = ft_haver(delta_lat) + (cos(lat_1) * cos(lat_2) * ft_haver(delta_lon));
	distance = EARTH_RADIUS * 2 * atan2(sqrt(hav_theta), sqrt(1 - hav_theta));
	return (distance);
}

double dtor(float degrees)
{
	double radians;

	radians = degrees * (PI / 180); // are we losing data due to C division?
	return ((double)radians);
}

float calc_distance(float lat_1, float lon_1, float lat_2, float lon_2)
{
	double distance;

	distance = haver_formula(dtor(lat_1), dtor(lon_1), dtor(lat_2), dtor(lon_2));
	return ((float)distance);
}

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


// int main(void)
// {
// 	float lat1 = 52.1;
// 	float lon1 = 2.6;
// 	float lat2 = 23.4;
// 	float lon2 = 43.1;

// 	float distance = calc_distance(lat1, lon1, lat2, lon2);
// 	printf("distance: %f\n", distance);
// }