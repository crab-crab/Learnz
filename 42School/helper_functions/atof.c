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


