#include <stdio.h>
#include "game.h"
#include "common.h"

void drawSymbol(int pos_y, int symbol, int num)
{
	int pos_x = 58;

	gotoxy(58, pos_y+1);
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

void drawStat(int* stat_list)
{
	int pos_y = 0;
	
	// »ý¸í
	pos_y = 5;
	gotoxy(58, pos_y);
	printf("LIFE");
	drawSymbol(pos_y, 1, stat_list[0]);

	// ÆøÅº
	pos_y = 8;
	gotoxy(58, pos_y);
	printf("BOMB");
	drawSymbol(pos_y, 2, stat_list[1]);

	// Ã¼·Â
	pos_y = 11;
	gotoxy(58, pos_y);
	printf("HP");
	drawSymbol(pos_y, 3, stat_list[2]);

	// Á¡¼ö
	gotoxy(58, 2);
	printf("SCORE");
	gotoxy(58, 3);
	printf("%d", stat_list[3]);
}