#include <stdio.h>
#include "common.h"
#include "game.h"

void bCannon_move(BOMB* bomb)
{
	for (int i = 0; i < BOMB_CANNON_SIZE; i++)
	{
		if (bomb->bomb_cannon[0]->condition[i] == TRUE)
		{
			gotoxy(bomb->bomb_cannon[0]->pos_x[i], bomb->bomb_cannon[0]->pos_y[i]);
			puts("                      ");
			bomb->bomb_cannon[0]->pos_y[i]--;
			gotoxy(bomb->bomb_cannon[0]->pos_x[i], bomb->bomb_cannon[0]->pos_y[i]);
			puts("    ざ              ざ");
		}

		if (bomb->bomb_cannon[1]->condition[i] == TRUE)
		{
			gotoxy(bomb->bomb_cannon[1]->pos_x[i], bomb->bomb_cannon[1]->pos_y[i]);
			puts("                      ");
			bomb->bomb_cannon[1]->pos_y[i]--;
			gotoxy(bomb->bomb_cannon[1]->pos_x[i], bomb->bomb_cannon[1]->pos_y[i]);
			puts("    ざ              ざ");
		}
	}
}