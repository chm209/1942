#include <stdio.h>
#include "common.h"
#include "game.h"

void bCannon_status(BOMB* bomb, int state)
{
	switch (state)
	{
	// ÆøÅº Ä³³í ¹ß»ç
	case 0:
		for (int i = 0; i < BOMB_CANNON_SIZE; i++)
		{
			if ((bomb->pos_y[0] >= 13 && bomb->pos_y[0] <= 18) && bomb->bomb_cannon[0]->condition[i] == FALSE)
			{
				bomb->bomb_cannon[0]->pos_x[i] = bomb->pos_x[0];
				bomb->bomb_cannon[0]->pos_y[i] = bomb->pos_y[0] - 2;
				bomb->bomb_cannon[0]->condition[i] = TRUE;
			}

			if ((bomb->pos_y[1] >= 14 && bomb->pos_y[1] <= 19) && bomb->bomb_cannon[1]->condition[i] == FALSE)
			{
				bomb->bomb_cannon[1]->pos_x[i] = bomb->pos_x[1];
				bomb->bomb_cannon[1]->pos_y[i] = bomb->pos_y[1] - 2;
				bomb->bomb_cannon[1]->condition[i] = TRUE;
			}
		}
		break;
	// ÆøÅº Ä³³í ÃµÀå µµ´Þ
	case 1:
		for (int i = 0; i < BOMB_CANNON_SIZE; i++)
		{
			if (bomb->bomb_cannon[0]->condition[i] == TRUE && bomb->bomb_cannon[0]->pos_y[i] == 0)
			{
				gotoxy(bomb->bomb_cannon[0]->pos_x[i], bomb->bomb_cannon[0]->pos_y[i]);
				printf("                          ");
				bomb->bomb_cannon[0]->condition[i] = FALSE;
			}

			if (bomb->bomb_cannon[1]->condition[i] == TRUE && bomb->bomb_cannon[1]->pos_y[i] == 0)
			{
				gotoxy(bomb->bomb_cannon[1]->pos_x[i], bomb->bomb_cannon[1]->pos_y[i]);
				printf("                          ");
				bomb->bomb_cannon[1]->condition[i] = FALSE;
			}
		}
		break;
	}
}