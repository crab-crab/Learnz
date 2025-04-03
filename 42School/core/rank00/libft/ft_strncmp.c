#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s2 && n > 0 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

// int main(void)
// {
// 	char *s1 = "Hellow";
// 	char *s2 = "Helloooow";
// 	int n = 99;

// 	printf("strncmp result: %d\n", ft_strncmp(s1, s2, n));
// }