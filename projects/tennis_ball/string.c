#include "ball.h"

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