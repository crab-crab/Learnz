#include "coord.h"

// microseconds since epoch start
long long t_since_epoch(void)
{
	struct timeval time;
	long long time_since_epoch;

	gettimeofday(&time, NULL);
	time_since_epoch = (long long)time.tv_sec * 1000000 + time.tv_usec;

	return (time_since_epoch);
}

// microseconds since start of last second
long cur_usec(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return ((long)time.tv_usec);
}

// int main(void)
// {
// 	printf("us: %ld\n", cur_usec());
// }