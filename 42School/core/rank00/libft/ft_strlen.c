#include "libft.h"

size_t ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}


// int main(void)
// {
// 	char *mystring = "Hello?";
// 	printf("%s is %ld chars\n", mystring, ft_strlen(mystring));
// }