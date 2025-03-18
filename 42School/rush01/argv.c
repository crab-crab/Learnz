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

int *parse_input(char *input, int size)
{
    int index = 0;
    int *out_array = (int *)malloc(size * sizeof(char));

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