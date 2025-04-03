#include "libft.h"

void ft_bzero(void *s, size_t n)
{
	int i;
	char *tmp;

	tmp = (char *)s;
	i = 0;
	while (i < n)
	{
		tmp[i] = 0;
		i++;
	}
}