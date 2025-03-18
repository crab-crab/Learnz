
#include <stdio.h>
#include "string.c"

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

int squrt(int i)
{
    int count = 0;
    int sum = 0;
    int odd = 1;

    while(i > sum)
    {
        sum += odd;
        odd += 2;
        count++;
    }
    return (count);
}



int main(void)
{
    int a = 2;
    int b = 27;
    int c = 81;

    printf("the squrt of %d is: %d\n", c, squrt(c));

    //printf("%d to the power of %d is %d\n", a, b, check_power_of(b, a));
}