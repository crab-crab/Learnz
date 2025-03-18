#include <unistd.h>


int ft_strlen(char *str)
{
    int count = 0;
    while(str[count])
        count++;
    return (count);
}

// search through a string for char c, return index if found otherwise -1
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

int atoi(char *str)
{
    long result = 0;
    int sign = 1;

    while(*str == ' ')
        str++;
    while(*str == '-' || *str == '+')
    {
        if(*str == '-')
            sign = sign * -1;
        str++;
    }
    while(*str >= '0' && *str <= '9')
    {
        result = result * 10;
        result += *str - '0';
        str++;
    }
    return((int)result * sign);
}


// int main(void)
// {
//     char *nbr2 = "-48364875";
//     int nbr = -48364875;
//     ft_putnbr(atoi(nbr2));
//     write(1,"\n",1);
// }