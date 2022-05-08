#include <stdio.h>
#include "common.h"

void draw_symbol(int STATUS_POS_Y, int symbol, int count)
{
	int pos_x = 58;

	gotoxy(58, STATUS_POS_Y + 1);
	printf("          ");

	for (int i = 0; i < count; i++)
	{
		gotoxy(pos_x, STATUS_POS_Y + 1);
		switch (symbol)
		{
		case 0:
			printf("¢¾");
			break;
		case 1:
			printf("¢Á");
			break;
		case 2:
			printf("¡Ú");
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