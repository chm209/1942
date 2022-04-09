#include <stdio.h>
#include "common.h"
#include "game.h"

void enemy_gen(Enemy* enemy, int frame_cnt)
{
	int isCreated = FALSE;
	for (int i = 0; i < ENEMY_SIZE; i++)
	{
		if ((enemy[i].con == FALSE && (frame_cnt >= 45 && frame_cnt <= 315) && (frame_cnt - 45) % 90 == 0))
		{
			enemy[i].pos_x = 6;
			enemy[i].pos_y = 0;
			enemy[i].type = 0; // <[W]> * * * * * * *
			enemy[i].move_pattern = 0; // 오른쪽 대각선 이동
			enemy[i].move_count = 0;
			enemy[i].speed = 0;
			enemy[i].health = 5;
			enemy[i].con = TRUE;
			isCreated = TRUE;
		}

		if ((enemy[i].con == FALSE && (frame_cnt >= 90 && frame_cnt <= 360) && (frame_cnt - 90) % 90 == 0))
		{
			enemy[i].pos_x = 50;
			enemy[i].pos_y = 1;
			enemy[i].type = 0;
			enemy[i].move_pattern = 1; // 왼쪽 대각선으로 이동
			enemy[i].move_count = 0;
			enemy[i].speed = 0;
			enemy[i].health = 5;
			enemy[i].con = TRUE;
			isCreated = TRUE;
		}

		if (enemy[i].con == FALSE && frame_cnt == 500)
		{
			enemy[i].pos_x = 18;
			enemy[i].pos_y = 1;
			enemy[i].type = 1;
			enemy[i].move_pattern = 2; // 아래로 직진
			enemy[i].move_count = 0;
			enemy[i].speed = 0;
			enemy[i].health = 5;
			enemy[i].con = TRUE;

			enemy[i + 1].pos_x = 13;
			enemy[i + 1].pos_y = 0;
			enemy[i + 1].type = 1;
			enemy[i + 1].move_pattern = 2; // 아래로 직진
			enemy[i + 1].move_count = 0;
			enemy[i + 1].speed = 0;
			enemy[i + 1].health = 5;
			enemy[i + 1].con = TRUE;

			enemy[i + 2].pos_x = 23;
			enemy[i + 2].pos_y = 0;
			enemy[i + 2].type = 1;
			enemy[i + 2].move_pattern = 2; // 아래로 직진
			enemy[i + 2].move_count = 0;
			enemy[i + 2].speed = 0;
			enemy[i + 2].health = 5;
			enemy[i + 2].con = TRUE;

			isCreated = TRUE;
		}

		if (enemy[i].con == FALSE && frame_cnt == 650)
		{
			enemy[i].pos_x = 36;
			enemy[i].pos_y = 1;
			enemy[i].type = 1;
			enemy[i].move_pattern = 3; // 아래로 직진
			enemy[i].move_count = 0;
			enemy[i].speed = 0;
			enemy[i].health = 5;
			enemy[i].con = TRUE;

			enemy[i + 1].pos_x = 31;
			enemy[i + 1].pos_y = 0;
			enemy[i + 1].type = 1;
			enemy[i + 1].move_pattern = 3; // 아래로 직진
			enemy[i + 1].move_count = 0;
			enemy[i + 1].speed = 0;
			enemy[i + 1].health = 5;
			enemy[i + 1].con = TRUE;

			enemy[i + 2].pos_x = 41;
			enemy[i + 2].pos_y = 0;
			enemy[i + 2].type = 1;
			enemy[i + 2].move_pattern = 3; // 아래로 직진
			enemy[i + 2].move_count = 0;
			enemy[i + 2].speed = 0;
			enemy[i + 2].health = 5;
			enemy[i + 2].con = TRUE;

			isCreated = TRUE;
		}

		if (isCreated == TRUE)
		{
			gotoxy(enemy[i].pos_x, enemy[i].pos_y);
			switch (enemy[i].type)
			{
			case 0:
				printf("<WvW>");
				break;
			case 1:
				printf("<XVX>");
				break;
			}
			break;
		}
	}
}