#include "libft.h"


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


// int main(void)
// {
// 	char *source = "water flows";
// 	char destination[50] = "trees grow";
// 	char t_destination[50] = "trees grow";
// 	size_t size = 50;

// 	printf("source:\t\t%s\ndestination:\t%s\n", source, destination);
// 	printf("ft_len: %zu | lib_len: %zu\n", ft_strlcpy(destination, source, size), strlcpy(t_destination, source, size));
// 	printf("source:\t\t%s\ndestination:\t%s\nt_destination:\t%s\n", source, destination, t_destination);
// }