#include <stdio.h>
#include "game.h"
#include "common.h"

void enemyBul(Enemy* enemy, int num)
{
	switch (num)
	{
	case 0:
		for (int i = 0; i < ENEMY_SIZE; i++)
		{
			if (enemy[i].con == TRUE)
			{
				for (int j = 0; j < ENEMY_BUL_SIZE; j++)
				{
					if (enemy[i].move_pattern == 1 || enemy[i].move_pattern == 0)
					{
						if (enemy[i].bul_speed > 60 && (enemy[i].move_count == 1 || enemy[i].move_count == 3))
						{
							enemy[i].bul_pos_x[j] = enemy[i].pos_x + 2;
							enemy[i].bul_pos_y[j] = enemy[i].pos_y + 1;
							enemy[i].bul_con[j] = TRUE;
							enemy[i].bul_speed = 0;
							gotoxy(enemy[i].bul_pos_x[j], enemy[i].bul_pos_y[j]);
							printf("*");
						}
					}
				}
				enemy[i].bul_speed++;
			}
		}
		break;
	case 1:
		for (int i = 0; i < ENEMY_SIZE; i++)
		{
			for (int j = 0; j < ENEMY_BUL_SIZE; j++)
			{
				if (enemy[i].move_pattern == 1 || enemy[i].move_pattern == 0)
				{
					if (enemy[i].bul_con[j] == TRUE)
					{
						gotoxy(enemy[i].bul_pos_x[j], enemy[i].bul_pos_y[j]);
						puts("  ");
						enemy[i].bul_pos_y[j]++;
						gotoxy(enemy[i].bul_pos_x[j], enemy[i].bul_pos_y[j]);
						printf("*");
					}
				}
			}
		}
		break;
	}
}