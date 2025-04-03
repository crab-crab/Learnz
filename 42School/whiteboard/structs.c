#include <stdio.h>

struct s_animals
{
	char name[50];
	int ferocity;
	int cuteness;
	int speed;
	int size;
}polar_bear = {"Polar Bear", 9, 6, 5, 7};

void pt_sinfo(struct s_animals *animal);
void innit_struct(struct s_animals *animal, char *name, int fero, int cute, int speed, int size);
void simplecpy(char *dest, char *src);

int main(void)
{
	struct s_animals penguin;
	struct s_animals owl;
	innit_struct(&penguin, "Penguin", 3, 9, 4, 4);
	simplecpy(owl.name, "Owl");
	owl.ferocity = 6;
	owl.cuteness = 8;
	owl.speed = 8;
	owl.size = 2;

	pt_sinfo(&polar_bear);
	pt_sinfo(&penguin);
	pt_sinfo(&owl);
}

void innit_struct(struct s_animals *animal, char *name, int fero, int cute, int speed, int size)
{
	simplecpy(animal->name, name);
	animal->ferocity = fero;
	animal->cuteness = cute;
	animal->speed = speed;
	animal->size = size;
}

void pt_sinfo(struct s_animals *animal)
{
	printf("STATS: %s\nFerocity: %d\nCuteness: %d\nSpeed: %d\nSize: %d\n",
		animal->name, animal->ferocity, animal->cuteness, animal->speed, animal->size);
}
void simplecpy(char *dest, char *src)
{
	int i;

	i = 0;
	while(src[i])
	{
		dest[i] = src[i];
		i++;
	}
}