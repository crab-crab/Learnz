
#ifndef COORD_H
#define COORD_H

// constants
extern const double	PI;
extern const int	EARTH_RADIUS;
extern const int	MAX_BUFFER_SIZE;
extern const int	MAX_CITY_NAME_SIZE;
extern const char* 	CITY_TABLE_FILE;
extern const int	MAX_CSV_COLUMNS;
extern const int	MAX_ANSWER_SIZE;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <sys/time.h>
#include <stdarg.h>

typedef struct s_city
{
	char	name[50];
	float	latitude;
	float	longitude;
} t_city;

// struct timeval {
//     time_t      tv_sec;  // seconds
//     suseconds_t tv_usec; // microseconds
// };

// string.c
int ft_cntchr(char *s, char c);
size_t ft_strlen(const char *s);
int ft_atoi(char *str);
float ft_atof(char *str);
size_t ft_strlcpy(char *dst, const char *restrict src, size_t dsize);

// city.c
t_city *innit_city_table(size_t size);
void pt_city_table(t_city *city_table, size_t size);
void set_city_table(t_city *city_table, size_t i, char* name, float lat, float lon);
void rm_city_table(t_city *city_table, size_t i);

// csv.c
char *rd_csv_line(char *csv, char **contents);
int open_csv_file(const char *filename);
void csv_to_struct(char **contents, t_city *city_table, int i);
void load_city_csv(t_city * city_table);

// math_helper.c
float calcc_dist(t_city city1, t_city city2);
float calc_distance(float lat_1, float lon_1, float lat_2, float lon_2);
int check_power_of(long number, int divisor);
long ft_power(int num, int pow);

// random.c
float ft_prand(void);
int ft_prandb(void);
float ft_prandr(float min, float max);

// time.c
long long t_since_epoch(void);
long cur_usec(void);

// user_input.c

char *simple_scan(int n);




#endif