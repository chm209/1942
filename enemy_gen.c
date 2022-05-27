#include <stdio.h>
#include "common.h"
#include "game.h"

void enemy_gen(ENEMY* enemy, int frame_time)
{
	int is_created = FALSE;

	for (int i = 0; i < ENEMY_SIZE; i++)
	{
		if (enemy->condition[i] == FALSE)
		{
			if ((frame_time >= 45 && frame_time <= 315) && (frame_time - 45) % 90 == 0)
			{
				enemy->pos_x[i] = 6;
				enemy->pos_y[i] = 0;
				enemy->condition[i] = TRUE;
				enemy->design[i] = 0;
				enemy->pattern[i] = 0; // 대각선 우하향 & 직선 공격
				enemy->move_count[i] = 0;
				enemy->move_interval[i] = 0;
				enemy->hp[i] = 3;
				is_created = TRUE;
			}

			if ((frame_time >= 90 && frame_time <= 360) && (frame_time - 90) % 90 == 0)
			{
				enemy->pos_x[i] = 50;
				enemy->pos_y[i] = 1;
				enemy->condition[i] = TRUE;
				enemy->design[i] = 0;
				enemy->pattern[i] = 1; // 대각선 좌하향 & 직선 공격
				enemy->move_count[i] = 0;
				enemy->move_interval[i] = 0;
				enemy->hp[i] = 3;
				is_created = TRUE;
			}

			if (frame_time == 500)
			{
				enemy->pos_x[i] = 18;
				enemy->pos_y[i] = 1;
				enemy->pos_x[i + 1] = 13;
				enemy->pos_y[i + 1] = 0;
				enemy->pos_x[i + 2] = 23;
				enemy->pos_y[i + 2] = 0;

				for (int j = i; j < i+3; j++)
				{
					enemy->condition[j] = TRUE;
					enemy->design[j] = 1;
					enemy->pattern[j] = 2; // 아래로 직진 & 우측 대각선 공격
					enemy->move_count[j] = 0;
					enemy->move_interval[j] = 0;
					enemy->hp[j] = 5;
				}
				is_created = TRUE;
			}

			if (frame_time == 600)
			{
				enemy->pos_x[i] = 36;
				enemy->pos_y[i] = 1;
				enemy->pos_x[i + 1] = 31;
				enemy->pos_y[i + 1] = 0;
				enemy->pos_x[i + 2] = 41;
				enemy->pos_y[i + 2] = 0;

				for (int j = i; j < i+3; j++)
				{
					enemy->condition[j] = TRUE;
					enemy->design[j] = 1;
					enemy->pattern[j] = 3; // 아래로 직진 & 좌측 대각선 공격
					enemy->move_count[j] = 0;
					enemy->move_interval[j] = 0;
					enemy->hp[j] = 5;
				}
				is_created = TRUE;
			}

			if (frame_time == 780)
			{
				enemy->pos_x[i] = 13;
				enemy->pos_y[i] = 0;
				enemy->pos_x[i + 1] = 25;
				enemy->pos_y[i + 1] = 0;

				for (int j = i; j < i + 2; j++)
				{
					enemy->condition[j] = TRUE;
					enemy->design[j] = 2;
					enemy->pattern[j] = 4; // 등장해서 얼마간 공격하고 다시 위로 올라가서 사라짐
					enemy->move_count[j] = 0;
					enemy->move_interval[j] = 0;
					enemy->hp[j] = 5;
				}
				is_created = TRUE;
			}

			if (frame_time == 980)
			{
				enemy->pos_x[i] = 31;
				enemy->pos_y[i] = 0;
				enemy->pos_x[i + 1] = 43;
				enemy->pos_y[i + 1] = 0;

				for (int j = i; j < i + 2; j++)
				{
					enemy->condition[j] = TRUE;
					enemy->design[j] = 2;
					enemy->pattern[j] = 4; // 등장해서 얼마간 공격하고 다시 위로 올라가서 사라짐
					enemy->move_count[j] = 0;
					enemy->move_interval[j] = 0;
					enemy->hp[j] = 5;
				}
				is_created = TRUE;
			}
		}
		if (is_created == TRUE)
		{
			gotoxy(enemy->pos_x[i], enemy->pos_y[i]);
			switch (enemy->design[i])
			{
			case 0:
				printf("<WvW>");
				break;
			case 1:
				printf("<XVX>");
				break;
			case 2:
				printf("[TWT]");
				break;
			}
			break;
		}
	}
}