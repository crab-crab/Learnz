#include <stdio.h>
#include <string.h>

struct s_mountain
{
	char name[50];
	int height;
	int difficulty;
} everest = {"Mount Everest", 8849, 7};

int main(void)
{
	struct s_mountain k2;
	strcpy(k2.name, "K2");
	k2.height = 8611;
	k2.difficulty = 9;
	
	printf("%s, height: %d, difficulty: %d\n", everest.name, everest.height, everest.difficulty);
	printf("%s, height: %d, difficulty: %d\n", k2.name, k2.height, k2.difficulty);
}