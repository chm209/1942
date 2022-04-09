#include <stdio.h>
#include "game.h"
#include "common.h"

void enm_bull_move(Enemy* enemy)
{
	for (int i = 0; i < ENEMY_SIZE; i++)
	{
		for (int j = 0; j < ENEMY_BUL_SIZE; j++)
		{
			if (enemy[i].bul_con[j] == TRUE && (enemy[i].move_pattern == 1 || enemy[i].move_pattern == 0))
			{
				gotoxy(enemy[i].bul_pos_x[j], enemy[i].bul_pos_y[j]);
				puts("  ");
				enemy[i].bul_pos_y[j]++;
				gotoxy(enemy[i].bul_pos_x[j], enemy[i].bul_pos_y[j]);
				printf("*");
			}
			if (enemy[i].bul_con[j] == TRUE && enemy[i].move_pattern == 2)
			{
				gotoxy(enemy[i].bul_pos_x[j], enemy[i].bul_pos_y[j]);
				puts("  ");
				enemy[i].bul_pos_x[j]++;
				enemy[i].bul_pos_y[j]++;
				gotoxy(enemy[i].bul_pos_x[j], enemy[i].bul_pos_y[j]);
				printf("¢´");
			}
			if (enemy[i].bul_con[j] == TRUE && enemy[i].move_pattern == 3)
			{
				gotoxy(enemy[i].bul_pos_x[j], enemy[i].bul_pos_y[j]);
				puts("  ");
				enemy[i].bul_pos_x[j]--;
				enemy[i].bul_pos_y[j]++;
				gotoxy(enemy[i].bul_pos_x[j], enemy[i].bul_pos_y[j]);
				printf("¢´");
			}
		}
	}
}