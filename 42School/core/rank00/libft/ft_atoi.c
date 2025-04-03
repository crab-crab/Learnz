#include "libft.h"

int ft_atoi(const char *nptr)
{
	long num;
	int sign;

	sign = 1;
	num = 0;
	while (*nptr == '\f' || *nptr == '\n' || *nptr == '\r' 
		|| *nptr == '\t' || *nptr == ' ' || *nptr == '\v')
		nptr++;
	while (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		num *= 10;
		num += *nptr - '0';
		nptr++;
	}
	if ((num > 2147483647 && sign == 1) || (num > 2147483648 && sign == -1))
		return (0);
	return ((int)(num * sign));
}


// int main(void)
// {
// 	char *string_num = "      -2147483648";
// 	printf("%d\n", ft_atoi(string_num));
// }