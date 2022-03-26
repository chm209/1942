#include <stdio.h>
#include "common.h"

void drawSymbol(int pos_y, int symbol, int num)
{
	int pos_x = 58;

	gotoxy(58, pos_y + 1);
	printf("          ");

	for (int i = 0; i < num; i++)
	{
		gotoxy(pos_x, pos_y + 1);
		if (symbol == 1)
			printf("\u2665");
		else if (symbol == 2)
			printf("\u2299");
		else
			printf("\u2605");
		pos_x += 2;
	}
}