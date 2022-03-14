#include <stdio.h>
#include "game.h"

void drawSymbol(int pos_x, int symbol, int num)
{
	if (pos_x != 44)
		pos_x += 5;
	else
		pos_x += 3;

	gotoxy(pos_x, 29);
	printf("          ");

	for (int i = 0; i < num; i++)
	{
		gotoxy(pos_x, 29);
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
	int pos_x = 0;
	

	// »ý¸í
	pos_x = 12;
	gotoxy(pos_x, 29);
	printf("LIFE");
	drawSymbol(pos_x, 1, stat_list[0]);

	// ÆøÅº
	pos_x = 30;
	gotoxy(pos_x, 29);
	printf("BOMB");
	drawSymbol(pos_x, 2, stat_list[1]);

	// Ã¼·Â
	pos_x = 44;
	gotoxy(pos_x, 29);
	printf("HP");
	drawSymbol(pos_x, 3, stat_list[2]);

	// Á¡¼ö
	gotoxy(68, 29);
	printf("SCORE : %11d", stat_list[3]);
}