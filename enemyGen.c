#include <stdio.h>
#include "common.h"
#include "game.h"

void enemyGen(Enemy* enemy, int frame_cnt)
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

		if (isCreated == TRUE)
		{
			gotoxy(enemy[i].pos_x, enemy[i].pos_y);
			switch (enemy[i].type)
			{
			case 0:
				printf("<WvW>");
				break;
			}
			break;
		}
	}
}