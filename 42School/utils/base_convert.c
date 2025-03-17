// #include "math.c"
// #include "string.c"
#include <stdlib.h>
#include <stdio.h>

int char_search(char *base_str, char c)
{
    int index = 0;
    while(base_str[index])
    {
        if(base_str[index] == c)
            return (index);
        index++;
    }
    return (-1);
}

int ft_strlen(char *str)
{
    int count = 0;
    while(str[count])
        count++;
    return (count);
}

// takes a number "num" and multiplies it by itself "pow" times
// only works for positive pow values
int ft_power(int num, int pow)
{
    int multiplier = num;
    if(pow < 0)
        return(0);    
    if(pow == 0)
        return (1);
    while (pow > 1)
    {
        num = num *multiplier;
        pow--;
    }
    return(num);
}

// determines to what power the "divisor" must be raised to result in "number"
int check_power_of(int number, int divisor)
{
    int divide_count = 0;

    while(number >= divisor)
    {
        number = number / divisor;
        divide_count++;
    }
    return (divide_count);
}

// base_str contains contains character set for that base, eg. binary -> "01"
// returns decimal representation of input
int base_from(char *base_str, char *input)
{
    int index = 0;
    int result = 0;
    int base_int = ft_strlen(base_str);
    int len = ft_strlen(input)-1;

    while(input[index])
    {
        result += ft_power(base_int, (len - index)) * char_search(base_str,input[index]);
        index++;
    }
    return (result);
}

char *base_to(char *base_str, int input)
{
    int index = 0;
    int base_int = ft_strlen(base_str);
    int ch_pow = check_power_of(input, base_int);

    char *result = (char *)malloc((ch_pow + 2) * sizeof(char)); 
    // ch_pow +2 for index 0 counting and for '\0'

    while (index <= ch_pow)
    {
        int base_power = ft_power(base_int, (ch_pow - index));
        result[index] = base_str[input / base_power];
        input -=  base_power * (input / base_power);
        index++;
        printf("base_p: %d |result: %s \n", base_power, result);
    }
    result[index] = '\0';
    return (result);
}

#include <stdio.h>

int main(void)
{
    int testnum = 1337;
    char *base_2 = "01";
    char *base_10 = "0123456789";
    char *base_16 = "0123456789ABCDEF";

    char *input = "909";

    int result = base_from(base_10, input);


    printf("%s in base [%s] --> %d in decimal\n", input, base_2, result);
    //printf("the number %d in base %s is: %s\n", testnum, base_2, base_to(base_2, testnum));
    return (0);
}