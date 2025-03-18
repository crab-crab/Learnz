#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// int squrt(int i)
// {
//     int count = 0;
//     int sum = 0;
//     int odd = 1;

//     while(i > sum)
//     {
//         sum += odd;
//         odd += 2;
//         count++;
//     }
//     return (count);
// }

// counts how many numbers are present in the input
// ignores spaces, expects an integer between 0-9
int count_inputs(char *input) //!checked!
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
int *parse_input(char *input, int size) //!checked!
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



// int main(int argc, char **argv)
// {
// 	if(argc != 2)
//     {
//         write(1, "expected 2 program arguments", 28);
//         exit(EXIT_FAILURE);        
//     }

//     // preparse input string to find number of characters
//     int arg_size = count_inputs(argv[1]);

//     // from math, squrt to get length of one side
//     int size = squrt(arg_size);

//     // return one dimensional int array containing constraints
//     int *constraints = parse_input(argv[1], arg_size);

// 	printf("arg_size = %d, n_size = %d\n", arg_size, size);

// 	int i = 0;
// 	while(i < arg_size)
// 	{
// 		printf("n%d = %d\n", i, constraints[i]);
// 		i++;
// 	}
// }