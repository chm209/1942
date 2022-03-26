#include <stdio.h>
#include "game.h"
#include "common.h"

Player enmBulStatus(Enemy* enemy, Player player, Bomb* bomb, Bullet* bullet, int num)
{
	switch (num)
	{
	case 0:
		for (int i = 0; i < ENEMY_SIZE; i++)
		{
			for (int j = 0; j < ENEMY_BUL_SIZE; j++)
			{
				if (enemy[i].bul_con[j] == TRUE && enemy[i].bul_pos_y[j] == player.pos_y)
				{
					if ((enemy[i].bul_pos_x[j] >= player.pos_x) && (enemy[i].bul_pos_x[j] <= player.pos_x + 5))
					{
						gotoxy(enemy[i].bul_pos_x[j], enemy[i].bul_pos_y[j]);
						puts("  ");
						enemy[i].bul_con[j] = FALSE;

						if (player.health > 0)
							player.health--;
						else
						{
							if (player.life > 0)
							{
								player.life--;
								player.health = 3;
								bomb[0].con = TRUE;
								bomb[1].con = TRUE;
							}
						}

					}
				}
			}
		}
		break;
	case 1:
		for (int i = 0; i < ENEMY_SIZE; i++)
		{
			for (int j = 0; j < ENEMY_BUL_SIZE; j++)
			{
				if (enemy[i].bul_con[j] == TRUE && enemy[i].bul_pos_y[j] > 29)
				{
					gotoxy(enemy[i].bul_pos_x[j], enemy[i].bul_pos_y[j]);
					puts("  ");
					enemy[i].bul_con[j] = FALSE;
				}
			}
		}
		break;
	case 2:
		for (int i = 0; i < ENEMY_SIZE; i++)
		{
			for (int j = 0; j < ENEMY_BUL_SIZE; j++)
			{
				for (int k = 0; k < BULLET_SIZE; k++)
				{
					if (enemy[i].bul_con[j] == TRUE && bullet[k].con == TRUE)
					{
						if (enemy[i].bul_pos_y[j] == bullet[k].pos_y)
						{
							if (enemy[i].bul_pos_x[j] == bullet[k].pos_x)
							{
								gotoxy(enemy[i].bul_pos_x[j], enemy[i].bul_pos_y[j]);
								puts("  ");
								enemy[i].bul_con[j] = FALSE;
								bullet[k].con = FALSE;
							}
						}
					}
				}
			}
		}
		break;
	case 3:
		if (bomb[0].con == TRUE || bomb[1].con == TRUE)
		{
			for (int i = 0; i < ENEMY_SIZE; i++)
			{
				for (int j = 0; j < ENEMY_BUL_SIZE; j++)
				{
					if (enemy[i].bul_con[j] == TRUE && (enemy[i].bul_pos_y[j] >= bomb[0].pos_y || enemy[i].bul_pos_y[j] >= bomb[1].pos_y))
					{
						gotoxy(enemy[i].bul_pos_x[j], enemy[i].bul_pos_y[j]);
						puts("  ");
						enemy[i].bul_con[j] = FALSE;
					}
				}
			}
		}
		break;
	}

	return player;
}