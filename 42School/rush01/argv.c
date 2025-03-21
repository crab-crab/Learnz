#include "rush.h"

// These functions handle the program arguments


void ft_putnbr(int nbr)
{
    if(nbr == -2147483648)
    {
        write(1, "-2147483648", 11);
        return;
    }
    if(nbr < 0)
    {
        write(1, "-", 1);
        nbr = nbr * -1;
    }
    if( nbr >= 0 && nbr <= 9)
    {
        char c = '0' + nbr;
        write(1, &c, 1);
        return;
    }
    ft_putnbr(nbr / 10);
    ft_putnbr(nbr % 10);
}

// counts how many numbers are present in the input
// ignores spaces, expects an integer between 0-9
int count_inputs(char *input)
{
    int count = 0;
    while(*input)
    {
        if(*input >= '0' && *input <= '9')
            count++;
        input++;
    }
    return(count);
}

// extracts numbers from input string and returns array of ints
// expects an integer between 0-9
int *parse_input(char *input, int size)
{
    int index = 0;
    int *out_array = (int *)malloc(size * sizeof(int));

    while(*input)
    {
        if(*input >= '0' && *input <= '9')
        {
            out_array[index] = *input - '0';
            index++;
        }
        input++;
    }
    return (out_array);
}

// print values in a 1D array of ints
void pt_parsed_input(int *input, int size)
{
	int i = 0;

	while(i < size * 4)
	{
		ft_putnbr(input[i]);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

void free_constraints(int *constraints, int size)
{
	if (constraints != NULL)
	{
		free(constraints);
		constraints = NULL;
	}
}