#ifndef BALL_H
#define BALL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <sys/time.h>
#include <stdarg.h>
#include <ncurses.h>

// constants

extern const float G;

typedef struct s_vector
{
	float d_x;
	float d_y;
} t_vector;

typedef struct s_object
{
	char	ch[20];
	int		pos_x;
	int		pos_y;
	int		siz_x;
	int		siz_y;
	t_vector vector;
} t_object;

// screen.c
void innit_scr(int refresh);
void draw_obj(t_object *obj);

// physics.c

void move_obj(t_object *obj, int rows, int cols);
void bounce(t_object *obj, int rows, int cols);
int collision(t_object *obj, int rows, int cols);
void edge_bind(t_object *obj, int rows, int cols);

// string.c

size_t ft_strlen(const char *s);
size_t ft_strlcpy(char *dst, const char *restrict src, size_t dsize);


#endif