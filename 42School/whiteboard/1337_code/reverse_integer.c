// Given a signed 32-bit integer x, return x with its digits reversed. 
// If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

// Example: 
// 123 -> 321
// -123 -> -321
// 120 -> 21

//2^31 = 2147483648
// inverse = 8463847412

#include <stdio.h>

int count_digits(int x)
{
	int i; 
	i = 0;

	while (x != 0)
	{
		x /= 10;
		i++;
	}
	return (i);
}

int power(int num, int pow)
{
	int multi;

	if(pow == 0)
		return (1);
	multi = num;
	while (pow > 1)
	{
		if(2147483647 / multi < num)
			return(-1);
		num = num * multi;
		pow--;
	}
	return (num);
}

int reverse(int x)
{
	int rev_num;
	int sign;
	int digits;
	int max;

	max = 2147483647;
	rev_num = 0;
	sign = 1;
	if (x < 0)
	{
		if(x == -2147483648)
			return(0);
		sign = sign * -1;
		x = x * -1;
	}

	digits = count_digits(x) - 1;
	while (x > 0)
	{
		int next_add;
		if(x % 10 > 2 && power(10, digits) > 999999999)
			return (0);
		next_add = (x % 10) * power(10, digits);
		if(max - rev_num < next_add || next_add < 0)
			return(0);
		rev_num += next_add;
		x = x / 10;
		digits--;
	}
	return (rev_num * sign);
}



int main(void)
{
	int testnum = 123;
	// printf("count_digits(416000001) = %d\n", count_digits(416000001));
	// printf("%d\n", power(10, 10));
	printf("%d -> %d\n", testnum, reverse(testnum));
}