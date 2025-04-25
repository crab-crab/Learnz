#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


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

char *simple_scan(int n)
{
	char buff[100];
	char *result;
	size_t buff_len;

	fgets(buff, n, stdin);
	buff_len = ft_strlen(buff);
	result = (char *)malloc(buff_len);
	(void)ft_strlcpy(result, buff, buff_len);

	return(result);
}

int main(void)
{
	printf("Enter a string: ");
	printf("%s\n", simple_scan(50));
}