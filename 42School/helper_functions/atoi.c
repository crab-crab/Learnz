#include <stdio.h>

int atoi(char *str)
{
	int result = 0;
	int sign = 1;

	while (*str == ' ')
	{
		str++;
	}
	
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10;
		result += *str - '0';
		str++;
	}
	return (result * sign);

}

// int main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		printf("your int: %d\n", atoi(argv[1]));
// 	}
// 	return (0);
// }