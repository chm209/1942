#include <stdio.h>
#include "common.h"

void draw_symbol(int pos_y, int symbol, int num)
{
	int pos_x = 58;

	gotoxy(58, pos_y + 1);
	puts("          ");

	for (int i = 0; i < num; i++)
	{
		gotoxy(pos_x, pos_y + 1);
		if (symbol == 1)
			puts("\u2665");
		else if (symbol == 2)
			puts("\u2299");
		else
			puts("\u2605");
		pos_x += 2;
	}
}