#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

int main(void)
{
	struct timeval start, end;
	gettimeofday(&start, NULL);

	int i = 0;
	int j = 0;
	int size = 100;
	int sum = 0;
	while(i < size)
	{
		while(j < size)
		{
			printf("hello hello hello hello\n");
			printf("hello hello hello hello\n");
			sum += i + j;
			j++;
		}
		j = 0;
		i++;
	}	

	gettimeofday(&end, NULL);
	long int time_taken = (end.tv_sec * 1000000 + end.tv_usec) 
						- (start.tv_sec * 1000000 + start.tv_usec);

	printf("Time taken is : %ld micro seconds\n", time_taken);
	printf("Time taken is : %ld milli seconds\n", time_taken/1000);

	return(0);
}