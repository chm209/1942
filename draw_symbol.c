#include <stdio.h>
#include "common.h"

void draw_symbol(int POS_Y, int symbol, int count)
{
	int POS_X = 67;

	gotoxy(POS_X, POS_Y);
	printf("          ");

	for (int i = 0; i < count; i++)
	{
		gotoxy(POS_X, POS_Y);
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
		POS_X += 2;
	}
}