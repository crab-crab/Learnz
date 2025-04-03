#include "libft.h"

char *ft_strdup(const char *s)
{
	size_t	s_len;
	char	*s_dup;

	s_len = ft_strlen(s) + 1;
	s_dup = (char*)malloc(s_len);
	if (s_dup == NULL)
		return (NULL); // confirm proper error handling?
	ft_strlcpy(s_dup, s, s_len);
	return (s_dup);
}



// int main(void)
// {
// 	char s1[50] = "Here be the source";

// 	printf("%s\n", ft_strdup(s1));
// }