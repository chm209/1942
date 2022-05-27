#include <stdio.h>
#include "game.h"
#include "common.h"

void eCannon_move(ENEMY* enemy)
{
	for (int i = 0; i < ENEMY_SIZE; i++)
	{
		for (int j = 0; j < ENEMY_CANNON_SIZE; j++)
		{
			if (enemy->enemy_cannon[i]->condition[j] == TRUE && (enemy->pattern[i] == 1 || enemy->pattern[i] == 0))
			{
				gotoxy(enemy->enemy_cannon[i]->pos_x[j], enemy->enemy_cannon[i]->pos_y[j]);
				printf("  ");
				enemy->enemy_cannon[i]->pos_y[j]++;
				gotoxy(enemy->enemy_cannon[i]->pos_x[j], enemy->enemy_cannon[i]->pos_y[j]);
				printf("*");
			}
			if (enemy->enemy_cannon[i]->condition[j] == TRUE && enemy->pattern[i] == 2)
			{
				gotoxy(enemy->enemy_cannon[i]->pos_x[j], enemy->enemy_cannon[i]->pos_y[j]);
				printf("  ");
				enemy->enemy_cannon[i]->pos_x[j]++;
				enemy->enemy_cannon[i]->pos_y[j]++;
				gotoxy(enemy->enemy_cannon[i]->pos_x[j], enemy->enemy_cannon[i]->pos_y[j]);
				printf("¢´");
			}
			if (enemy->enemy_cannon[i]->condition[j] == TRUE && enemy->pattern[i] == 3)
			{
				gotoxy(enemy->enemy_cannon[i]->pos_x[j], enemy->enemy_cannon[i]->pos_y[j]);
				printf("  ");
				enemy->enemy_cannon[i]->pos_x[j]--;
				enemy->enemy_cannon[i]->pos_y[j]++;
				gotoxy(enemy->enemy_cannon[i]->pos_x[j], enemy->enemy_cannon[i]->pos_y[j]);
				printf("¢´");
			}
			if (enemy->enemy_cannon[i]->condition[j] == TRUE && enemy->pattern[i] == 4)
			{
				gotoxy(enemy->enemy_cannon[i]->pos_x[j], enemy->enemy_cannon[i]->pos_y[j]);
				printf("  ");
				enemy->enemy_cannon[i]->pos_y[j]++;
				gotoxy(enemy->enemy_cannon[i]->pos_x[j], enemy->enemy_cannon[i]->pos_y[j]);
				printf("W");
			}
		}
	}
}