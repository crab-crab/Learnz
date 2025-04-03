// Roman to Integer
// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV.
// Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. 
// There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given a roman numeral, convert it to an integer.

struct s_roman
{
	char rom;
	int val;
} r_I = {'I', 1}, r_V = {'V', 5}, r_X = {'X', 10}, r_L = {'L', 50}, r_C = {'C', 100}, r_D = {'D', 500}, r_M = {'M', 1000};

int get_int(char c, struct s_roman* r_list)
{
	int i = 0;
	while (i < 7)
	{
		if(r_list[i].rom == c)
			return (r_list[i].val);
		i++;
	}
}

int romanToInt(char *s)
{
	struct s_roman r_list[7] = {r_I, r_V, r_X, r_L, r_C, r_D, r_M};
	int num = 0;
	int i = 0;
	int prev = 1000;

	while(s[i])
	{
		int cur = get_int(s[i], r_list);
		if (cur <= prev)
		{
			num += cur;
			prev = cur;
		}
		else
		{
			num += cur - 2*prev;
		}
		i++;
	}

	return (num);
}

#include <stdio.h>

int main(void)
{
	
	char *test_roman = "MCMXCIV";
	printf("Roman: %s -> Int: %d\n", test_roman, romanToInt(test_roman));
}