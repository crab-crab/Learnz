#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


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
