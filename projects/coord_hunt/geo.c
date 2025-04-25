#include "coord.h"

// haversine function
double ft_haver(double theta)
{
	double result;

	result = sin(theta * 0.5);
	result *= result;
	return (result);
}

// haversine formula
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

// bearing from point 1 -> point 2 (degrees)
float calc_bearing(double lat1, double lon1, double lat2, double lon2)
{
    double delta_lon = lon2 - lon1;

    double y = sin(delta_lon) * cos(lat2);
    double x = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(delta_lon);

    double theta = atan2(y, x);

	// convert to degrees
    double bearing = theta * (180.0 / PI); 

    if (bearing < 0)
        bearing += 360.0;

    return (float)bearing;
}

// bearing from city_structs
float calcc_bearing(t_city city1, t_city city2)
{
	double lat1 = (double)dtor(city1.latitude);
    double lat2 = (double)dtor(city2.latitude);
    double lon1 = (double)dtor(city1.longitude);
    double lon2 = (double)dtor(city2.longitude);

	return(calc_bearing(lat1, lon1, lat2, lon2));
}

// return a cardinal direction string from degree bearing
const char *get_direction_from_bearing(float bearing, const char **directions)
{
	// Normalize 0–360
	if (bearing < 0)
		bearing += 360.0f;
	bearing = fmodf(bearing, 360.0f);

	// Each direction spans 45 degrees
	int index = (int)((bearing + 22.5f) / 45.0f) % 8;
	return directions[index];
}

void set_heading(t_city city1, t_city city2, t_geo_vector *heading)
{
	heading->distance = calcc_dist(city1, city2);
	heading->bearing = calcc_bearing(city1, city2);
	ft_strlcpy(heading->cardinal, get_direction_from_bearing(heading->bearing, DIRECTIONS), 30);
}