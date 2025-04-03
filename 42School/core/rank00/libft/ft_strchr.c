#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	while(*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

// int main(void)
// {
// 	char *str = "The quick brown fox jumped over the lazy dog!";
// 	char c = 'f';

// 	printf("target char found: %c\n", *strchr(str, c));
// 	printf("rest of string: %s\n", strchr(str, c));
// }