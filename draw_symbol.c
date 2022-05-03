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
			puts("¢¾");
		else if (symbol == 2)
			puts("¢Á");
		else if (symbol == 3)
			puts("¡Ú");
		else if (symbol == 4)
			puts("¢£");
		else if (symbol == 5)
			puts("¢Â");
		pos_x += 2;
	}
}