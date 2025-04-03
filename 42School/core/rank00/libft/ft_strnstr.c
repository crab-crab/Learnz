#include "libft.h"

char *ft_strnstr(const char *haystack,	const char *needle, size_t len)
{
	int len_left;
	const char *pt_needle;
	const char *pt_haystack;
	
	if (!*needle)
		return((char *)haystack);
	while (*haystack && len > 0)
	{
		pt_haystack = haystack;
		pt_needle = needle;
		len_left = len;
		while (*pt_haystack == *pt_needle && len_left > 0
				&& *pt_haystack && *pt_needle)
		{
			pt_haystack++;
			pt_needle++;
			len_left--;
		}
		if (*pt_needle == '\0')
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}


// int main(void)
// {
// 	char *str = "The quick brown fox jumped over the lazy dog";
// 	char *substr = "laz";
// 	size_t ln = 99;

// 	printf("rest of string: %s\n", ft_strnstr(str, substr, ln));
// }
