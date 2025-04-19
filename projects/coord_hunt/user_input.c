#include "coord.h"


// read up to n characters from stdin
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


// int my_scanf(const char *format, ...)
// {
//     char buffer[MAX_BUFFER_SIZE];

    
// }