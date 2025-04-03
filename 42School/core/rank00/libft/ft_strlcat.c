#include "libft.h"

size_t ft_strlcat(char *dst, const char *restrict src, size_t dsize)
{
	size_t dst_len;
	size_t src_len;
	size_t i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	while (src[i] && (i + dst_len) < dsize)  // confirm wether should be dsize > 1??
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if ((i + dst_len) < dsize)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}


// int main(void)
// {
// 	char *source = "water flows";
// 	char destination[50] = "trees grow ";
// 	char t_destination[50] = "trees grow ";
// 	size_t size = 50;

// 	printf("source:\t\t%s\ndestination:\t%s\n", source, destination);
// 	printf("ft_len: %zu | lib_len: %zu\n", ft_strlcat(destination, source, size), strlcat(t_destination, source, size));
// 	printf("source:\t\t%s\ndestination:\t%s\nt_destination:\t%s\n", source, destination, t_destination);
// }