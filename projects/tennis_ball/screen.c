#include "ball.h"

void innit_scr(int refresh)
{
	initscr();
	noecho();
	curs_set(0);
	timeout(refresh);
}

void draw_obj(t_object *obj)
{
	mvprintw(obj->pos_x, obj->pos_y, "%s", obj->ch);
}