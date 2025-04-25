#include "ball.h"

int main(void)
{
	t_object ball;
	int rows = LINES;
	int cols = COLS;
	
	innit_scr(100);

	ball.pos_x = 0;
	ball.pos_y = 0;
	ft_strlcpy(ball.ch, "@", 10);
	ball.vector.d_x = 0;
	ball.vector.d_y = 0;



	while (1)
	{
		clear();
		box(stdscr, 0, 0);
		draw_obj(&ball);
		move_obj(&ball, rows, cols);
		refresh();

		int ch = getch();
		if (ch == 'q')
			break;
	}

	curs_set(1);
	endwin();
}