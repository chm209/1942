#include <stdio.h>
#include "common.h"
#include "game.h"

// +----------------+-----------+
// | enemy gen time | time      |
// +----------------+-----------+
// | pattern 1 L    | 45-315    |
// | pattern 1 R    | 90-360    |
// | pattern 2 L    | 500       |
// | pattern 2 R    | 600       |
// | pattern 3 L    | 780       |
// | pattern 3 R    | 980       |
// | pattern 4 C    | 1225      |
// | pattern 4 L    | 1510      |
// | pattern 4 R    | 1720      |
// | pattern 1 L    | 1850-2120 |
// | pattern 1 R    | 1895-2165 |
// | pattern 3 L    | 2290      |
// | pattern 3 R    | 2400      |
// | pattern 2 R    | 2620      |
// | pattern 4 L    | 2680      |
// | pattern 2 L    | 2950      |
// | pattern 4 R    | 3100      |
// +----------------+-----------+

void enemy_gen(ENEMY* enemy, int frame_time)
{
	int is_created = FALSE;

	for (int i = 0; i < ENEMY_SIZE; i++)
	{
		if (enemy->condition[i] == FALSE)
		{
			// 패턴1 - 왼쪽
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

			// 패턴1 - 오른쪽
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

			// 패턴2 왼쪽
			if (frame_time == 500 || frame_time == 2950)
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

			// 패턴2 오른쪽
			if (frame_time == 600 || frame_time == 2620)
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

			// 패턴3 왼쪽
			if (frame_time == 780 || frame_time == 2290)
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
			
			// 패턴3 오른쪽
			if (frame_time == 980 || frame_time == 2400)
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

			// 패턴4 중앙
			if (frame_time == 1225)
			{
				enemy->pos_x[i] = 28;
				enemy->pos_y[i] = 0;
				enemy->condition[i] = TRUE;
				enemy->design[i] = 3;
				enemy->pattern[i] = 5; // 직선으로 내려오면서 정면, 좌우로 공격
				enemy->move_count[i] = 0;
				enemy->move_interval[i] = 0;
				enemy->hp[i] = 10;
				is_created = TRUE;
			}

			// 패턴4 왼쪽
			if (frame_time == 1510 || frame_time == 2680)
			{
				enemy->pos_x[i] = 12;
				enemy->pos_y[i] = 0;
				enemy->condition[i] = TRUE;
				enemy->design[i] = 3;
				enemy->pattern[i] = 5; // 직선으로 내려오면서 정면, 좌우로 공격
				enemy->move_count[i] = 0;
				enemy->move_interval[i] = 0;
				enemy->hp[i] = 10;
				is_created = TRUE;
			}

			// 패턴4 오른쪽
			if (frame_time == 1720 || frame_time == 3100)
			{
				enemy->pos_x[i] = 42;
				enemy->pos_y[i] = 0;
				enemy->condition[i] = TRUE;
				enemy->design[i] = 3;
				enemy->pattern[i] = 5; // 직선으로 내려오면서 정면, 좌우로 공격
				enemy->move_count[i] = 0;
				enemy->move_interval[i] = 0;
				enemy->hp[i] = 10;
				is_created = TRUE;
			}

			// 패턴1 - 왼쪽
			if ((frame_time >= 1850 && frame_time <= 2120) && (frame_time - 45) % 90 == 0)
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

			// 패턴1 - 오른쪽
			if ((frame_time >= 1895 && frame_time <= 2165) && (frame_time - 90) % 90 == 0)
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
			case 3:
				printf("(pWq)");
				break;
			}
			break;
		}
	}
}