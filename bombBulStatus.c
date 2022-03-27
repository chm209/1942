#include <stdio.h>
#include "common.h"
#include "game.h"

void bombBulStatus(Bomb* bomb, Bomb_blt* bomb_bul, Bomb_blt* bomb_bul2, int num)
{
	switch (num)
	{
	// ÆøÅº ÃÑ¾Ë ¹ß»ç
	case 0:
		for (int i = 0; i < BOMB_BUL_SIZE; i++)
		{
			if ((bomb[0].pos_y >= 13 && bomb[0].pos_y <= 18) && bomb_bul[i].con == FALSE)
			{
				bomb_bul[i].pos_x = bomb[0].pos_x;
				bomb_bul[i].pos_y = bomb[0].pos_y - 2;
				bomb_bul[i].con = TRUE;
			}

			if ((bomb[1].pos_y >= 14 && bomb[1].pos_y <= 19) && bomb_bul2[i].con == FALSE)
			{
				bomb_bul2[i].pos_x = bomb[1].pos_x;
				bomb_bul2[i].pos_y = bomb[1].pos_y - 2;
				bomb_bul2[i].con = TRUE;
			}
		}
		break;
	// ÆøÅº ÃÑ¾Ë ÃµÀå µµ´Þ
	case 1:
		for (int i = 0; i < BOMB_BUL_SIZE; i++)
		{
			if (bomb_bul[i].con == TRUE && bomb_bul[i].pos_y == 0)
			{
				gotoxy(bomb_bul[i].pos_x, bomb_bul[i].pos_y);
				puts("                          ");
				bomb_bul[i].con = FALSE;
			}

			if (bomb_bul2[i].con == TRUE && bomb_bul2[i].pos_y == 0)
			{
				gotoxy(bomb_bul2[i].pos_x, bomb_bul2[i].pos_y);
				puts("                          ");
				bomb_bul2[i].con = FALSE;
			}
		}
		break;
	}
}