#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
	char *tmp;
	int i;

	tmp = (char *)s;
	i = 0;
	while (i < n)
	{
		tmp[i] = c;
		i++;
	}
	return (s);
}
