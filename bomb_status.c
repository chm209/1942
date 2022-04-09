#include <stdio.h>
#include "game.h"
#include "common.h"

void bomb_status(Bomb* bomb, Enemy* enemy, int num)
{
	switch (num)
	{
	// ÆøÅº - Àû Ãæµ¹
	case 0:
		if (bomb[0].con == TRUE && bomb[1].con == TRUE)
		{
			for (int i = 0; i < BOMB_SIZE; i++)
			{
				for (int j = 0; j < ENEMY_SIZE; j++)
				{
					if (bomb[i].pos_y == enemy[j].pos_y || (enemy[j].pos_y - bomb[i].pos_y > 0))
					{
						gotoxy(enemy[j].pos_x, enemy[j].pos_y);
						puts("      ");
						enemy[j].pos_x = 0;
						enemy[j].pos_y = 0;
						enemy[j].con = FALSE;
					}
				}
			}
		}
		break;
	// ÆøÅºÀÌ ÃµÀå¿¡ µµ´ÞÇÏ¸é »èÁ¦
	case 1:
		if (bomb[0].con == TRUE && bomb[0].pos_y == 0)
		{
			gotoxy(bomb[0].pos_x, bomb[0].pos_y);
			puts("                         ");
			gotoxy(bomb[0].pos_x + 11, bomb[0].pos_y + 1);
			puts("   ");
			gotoxy(bomb[0].pos_x + 11, bomb[0].pos_y + 2);
			puts("   ");
			gotoxy(bomb[0].pos_x + 11, bomb[0].pos_y + 3);
			puts("   ");
			gotoxy(bomb[0].pos_x + 7, bomb[0].pos_y + 4);
			puts("           ");
			bomb[0].pos_y = 24;
			bomb[0].con = FALSE;
		}

		if (bomb[1].con == TRUE && bomb[1].pos_y == 0)
		{
			gotoxy(bomb[1].pos_x, bomb[1].pos_y);
			puts("                         ");
			gotoxy(bomb[1].pos_x + 11, bomb[1].pos_y + 1);
			puts("   ");
			gotoxy(bomb[1].pos_x + 11, bomb[1].pos_y + 2);
			puts("   ");
			gotoxy(bomb[1].pos_x + 11, bomb[1].pos_y + 3);
			puts("   ");
			gotoxy(bomb[1].pos_x + 7, bomb[1].pos_y + 4);
			puts("           ");
			bomb[1].pos_y = 24;
			bomb[1].con = FALSE;
		}
		break;
	}
}