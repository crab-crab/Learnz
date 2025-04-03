#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
	long	total_size;
	int		i;
	void *temp;

	total_size = nmemb * size;
	temp = malloc(total_size);
	if (temp)
	{
		ft_bzero(temp, total_size);
	}
	return(temp);
}


// int main(void)
// {
// 	int num = 10;
// 	int n_size = 5;
// 	int i = 0;

// 	char *mylist = (char*)ft_calloc(num, n_size);
// 	while (i < (num*n_size))
// 	{
// 		printf("i%d : %d\n", i, mylist[i]);
// 		i++;
// 	}
// }