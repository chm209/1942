#include <stdio.h>
#include "game.h"
#include "common.h"

void bomb_status(BOMB* bomb, ENEMY* enemy, PLAYER* player, int state)
{
	switch (state)
	{
	// ÆøÅº - Àû Ãæµ¹
	case 0:
		if (bomb->condition[0] == TRUE || bomb->condition[1] == TRUE)
		{
			for (int i = 0; i < BOMB_SIZE; i++)
			{
				for (int j = 0; j < ENEMY_SIZE; j++)
				{
					if (enemy->condition[j] == TRUE)
					{
						if (bomb->pos_y[i] == enemy->pos_y[j] || (enemy->pos_y[j] - bomb->pos_y[i] > 0))
						{
							gotoxy(enemy->pos_x[j], enemy->pos_y[j]);
							printf("      ");
							enemy->pos_x[j] = 0;
							enemy->pos_y[j] = 0;
							enemy->condition[j] = FALSE;
							switch (enemy->design[j])
							{
							case 0:
								player->score += 10;
								break;
							case 1:
								player->score += 20;
								break;
							}
						}
					}
				}
			}
		}
		break;
	// ÆøÅºÀÌ ÃµÀå¿¡ µµ´ÞÇÏ¸é »èÁ¦
	case 1:
		if (bomb->condition[0] == TRUE && bomb->pos_y[0] == 0)
		{
			draw_bomb(0, bomb->pos_x[0], bomb->pos_y[0]);
			bomb->pos_y[0] = 24;
			bomb->condition[0] = FALSE;
			bomb->move_interval[0] = 5;
		}

		if (bomb->condition[1] == TRUE && bomb->pos_y[1] == 0)
		{
			draw_bomb(0, bomb->pos_x[1], bomb->pos_y[1]);
			bomb->pos_y[1] = 24;
			bomb->condition[1] = FALSE;
			bomb->move_interval[1] = 5;
		}
		break;
	}
}