#include <stdio.h>
#include "common.h"

void draw_symbol(int STATUS_POS_Y, int symbol, int count)
{
	int pos_x = 60;

	gotoxy(60, STATUS_POS_Y + 2);
	printf("          ");

	for (int i = 0; i < count; i++)
	{
		gotoxy(pos_x, STATUS_POS_Y + 2);
		switch (symbol)
		{
		case 0:
			printf("��");
			break;
		case 1:
			printf("��");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		}
		pos_x += 2;
	}
}