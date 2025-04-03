#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *s_pointer;

	s_pointer = (unsigned char *)s;
	while (n > 0)
	{
		if (*s_pointer == (unsigned char)c)
			return ((void *)s_pointer);
		s_pointer++;
		n--;
	}
	return (NULL);
}

// int main(void)
// {
// 	char *s = "The quick brown fox jumped over the lazy dog!";
// 	void *str = (void *)s;
// 	char c = 'f';
// 	size_t n = ft_strlen(s) + 1;

// 	printf("target char found: %c\n", *(char *)ft_memchr(str, c, n));
// 	printf("rest of string: %s\n", (char *)ft_memchr(str, c, n));
// }