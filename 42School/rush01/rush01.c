#include <unistd.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    if(argc != 2)
    {
        write(1, "expected 2 program arguments", 28);
        exit(EXIT_FAILURE);        
    }

    // preparse input string to find number of characters
    int arg_size = count_inputs(argv[1]);
    // from math, squrt to get length of one side
    int size = squrt(arg_size); 
    // return one dimensional int array containing constraints
    int *constraints = parse_input(argv[1], arg_size);


}
