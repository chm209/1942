#include <stdio.h>
#include "common.h"
#include "game.h"

void bombBulMove(Bomb* bomb, Bomb_blt* bomb_bul, Bomb_blt* bomb_bul2)
{
	for (int i = 0; i < BOMB_BUL_SIZE; i++)
	{
		if (bomb_bul[i].con == TRUE)
		{
			gotoxy(bomb_bul[i].pos_x, bomb_bul[i].pos_y);
			puts("                      ");
			bomb_bul[i].pos_y--;
			gotoxy(bomb_bul[i].pos_x, bomb_bul[i].pos_y);
			puts("    ざ              ざ");
		}

		if (bomb_bul2[i].con == TRUE)
		{
			gotoxy(bomb_bul2[i].pos_x, bomb_bul2[i].pos_y);
			puts("                      ");
			bomb_bul2[i].pos_y--;
			gotoxy(bomb_bul2[i].pos_x, bomb_bul2[i].pos_y);
			puts("    ざ              ざ");
		}
	}
}