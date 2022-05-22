#include <stdio.h>
#include "common.h"

void draw_symbol(int POS_Y, int symbol, int count)
{
	int pos_x = 66;

	gotoxy(66, POS_Y);
	printf("          ");

	for (int i = 0; i < count; i++)
	{
		gotoxy(pos_x, POS_Y);
		switch (symbol)
		{
		case 0:
			printf("¢¾");
			break;
		case 1:
			printf("¡Ú");
			break;
		case 2:
			printf("¢Á");
			break;
		case 3:
			printf("¢£");
			break;
		case 4:
			printf("¢Â");
			break;
		}
		pos_x += 2;
	}
}