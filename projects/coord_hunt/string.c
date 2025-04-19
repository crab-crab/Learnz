#include "coord.h"

// counts the number of times char c comes up in string s
int ft_cntchr(char *s, char c)
{
	int	count;
	
	count = 0;
	while (*s)
	{
		if (*s == c)
			count++;
		s++;
	}
	return (count);
}

int ft_atoi(char *str)
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

float ft_atof(char *str)
{
	long result = 0;
	int sign = 1;
	int exponent = 0;

	while (*str == ' ')
		str++;
	
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
	if (*str == '.')
	{
		str++;
		while ('0' <= *str && *str <= '9')
		{
			result = result * 10;
			result += *str - '0';
			exponent++;
			str++;
		}
	}
	return ((float)(result * sign) / ft_power(10, exponent));

}

size_t ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

size_t ft_strlcpy(char *dst, const char *restrict src, size_t dsize)
{
	size_t	src_len;
	
	src_len = ft_strlen(src);
	while (*src && dsize > 1)
	{
		*dst = *src;
		dst++;
		src++;
		dsize--;
	}
	if (dsize > 0)
		*dst = '\0';
	return (src_len);
}
