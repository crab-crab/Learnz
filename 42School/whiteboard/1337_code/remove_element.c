// Change the array nums such that the first k elements of nums contain the elements which are not equal to val 
// The remaining elements of nums are not important as well as the size of nums
// Return k

int removeElement(int* nums, int numsSize, int val) 
{
	int	k;
	int i;

	k = 0;
	i = 0;

	while (i < numsSize)
	{
		if (nums[i] == val)
			k++;
		else
			nums[i - k] = nums[i];
		i++;
	}
	return (numsSize - k);
}

// #include <stdio.h>

// void print_list(int *list, int size)
// {
// 	int i = 0;

// 	printf("numlist: ");
// 	while (i < size)
// 	{
// 		printf(" %d", list[i]);
// 		i++;
// 	}
// 	printf("\n");
// }

// int main(void)
// {
// 	int size = 8;
// 	int nums[8] = {0,1,2,2,3,0,4,2};

// 	print_list(nums, size);
// 	printf("%d numbers left\n", removeElement(nums, size, 2));
// 	print_list(nums, size);
// }
