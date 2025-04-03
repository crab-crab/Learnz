#include "libft.h"


int tst_ft_islower(void)
{
	char *str = "19 +=-/\naLjJdkLK9";
	while(*str)
	{
		int ft = ft_islower(*str);
		int lb = islower(*str);
		if (!(ft > 0 && lb > 0) && !(ft == 0 && lb == 0))
		{
			printf("fail '%c' | ft: %d | lib: %d\n", *str, ft, lb);
			return (0);
		}
		str++;
	}
	return (1);
}

int tst_ft_isupper(void)
{
	char *str = "19 +=-/\naLjJdkLK9";
	while(*str)
	{
		int ft = ft_isupper(*str);
		int lb = isupper(*str);
		if (!(ft > 0 && lb > 0) && !(ft == 0 && lb == 0))
		{
			printf("fail '%c' | ft: %d | lib: %d\n", *str, ft, lb);
			return (0);
		}
		str++;
	}
	return (1);
}


int main(void)
{
	printf("islower: %d\n", tst_ft_islower());
	printf("isupper: %d\n", tst_ft_isupper());
}