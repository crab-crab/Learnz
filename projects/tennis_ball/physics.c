#include "ball.h"

void move_obj(t_object *obj, int rows, int cols);
void bounce(t_object *obj, int rows, int cols);
int collision(t_object *obj, int rows, int cols);
void edge_bind(t_object *obj, int rows, int cols);


void move_obj(t_object *obj, int rows, int cols)
{
	obj->pos_x += (int)obj->vector.d_x;
	obj->pos_y += (int)obj->vector.d_y;

	edge_bind(obj, rows, cols);

	if (collision(obj, rows, cols))
		bounce(obj, rows, cols);
}

void edge_bind(t_object *obj, int rows, int cols)
{
	if (obj->pos_x < 0)
		obj->pos_x = 0;
	if (obj->pos_x > rows)
		obj->pos_x = rows;
	if (obj->pos_y < 0)
		obj->pos_y = 0;
	if (obj->pos_x > cols)
		obj->pos_x = cols;
}

void bounce(t_object *obj, int rows, int cols)
{
	int x;
	int y;

	x = obj->pos_x;
	y = obj->pos_y;
	
	if ( x == 0 || x == cols)
		obj->vector.d_x *= -1;
	if (y == 0 || y == rows)
		obj->vector.d_x *= -1;
}

int collision(t_object *obj, int rows, int cols)
{
	int x;
	int y;

	x = obj->pos_x;
	y = obj->pos_y;

	if ( x == 0 || x == cols || y == 0 || y == rows)
	{
		return (1);
	}
	else
		return (0);
}