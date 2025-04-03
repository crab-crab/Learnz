#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	const char *last;

	last = NULL;	
	while(*s)
	{
		if (*s == c)
			last = s;
		s++;
	}
	if (last != NULL)
		return ((char *)last);
	return (NULL);
}

// int main(void)
// {
// 	char *str = "The quick brown fox jumped over the lazy dog!";
// 	char c = 'e';

// 	printf("target char found: %c\n", *ft_strchr(str, c));
// 	printf("rest of string: %s\n", ft_strchr(str, c));
// }