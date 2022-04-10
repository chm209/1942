#include <stdio.h>
#include "common.h"
#include "game.h"

void enemy_move(Enemy* enemy)
{
	for (int i = 0; i < ENEMY_SIZE; i++)
	{
		if (enemy[i].con == TRUE)
		{
			gotoxy(enemy[i].pos_x, enemy[i].pos_y);
			puts("     ");

			// 오른쪽 대각선 이동
			if (enemy[i].move_pattern == 0)
			{
				// 자기 턴이 오면 진행
				if (enemy[i].speed == 6)
				{
					// 아래로 내려갈 차례인지 옆으로 갈 차례인지 검사
					if (enemy[i].move_count == 3)
					{
						enemy[i].pos_y++;
						enemy[i].move_count = 0;
					}
					else
					{
						// 벽쪽으로 갔는지 검사, 벽쪽으로 갔으면 move_count 올릴 필요 없음
						if (enemy[i].pos_x > 48)
							enemy[i].pos_y++;
						else
						{
							enemy[i].pos_x++;
							enemy[i].move_count++;
						}
					}
					// 턴 초기화
					enemy[i].speed = 0;
				}
				else
				{
					enemy[i].speed++;
				}
			}

			// 왼쪽 대각선 이동
			if (enemy[i].move_pattern == 1)
			{
				// 자기 턴이 오면 진행
				if (enemy[i].speed == 9)
				{
					// 아래로 내려갈 차례인지 옆으로 갈 차례인지 검사
					if (enemy[i].move_count == 2)
					{
						enemy[i].pos_y++;
						enemy[i].move_count = 0;
					}
					else
					{
						// 벽쪽으로 갔는지 검사, 벽쪽으로 갔으면 move_count 올릴 필요 없음
						if (enemy[i].pos_x < 10)
							enemy[i].pos_y++;
						else
						{
							enemy[i].pos_x -= 2;
							enemy[i].move_count++;
						}
					}
					// 턴 초기화
					enemy[i].speed = 0;
				}
				else
				{
					enemy[i].speed++;
				}
			}

			// 아래로 직진
			if (enemy[i].move_pattern == 2 || enemy[i].move_pattern == 3)
			{
				if (enemy[i].pos_y > 12)
				{
					// 자기 턴이 오면 진행
					if (enemy[i].speed == 2)
					{
						enemy[i].pos_y++;

						if (enemy[i].move_count == 3)
							enemy[i].move_count = 0;
						else
							enemy[i].move_count++;

						// 턴 초기화
						enemy[i].speed = 0;
					}
					else
					{
						enemy[i].speed++;
					}
				}
				else
				{
					// 자기 턴이 오면 진행
					if (enemy[i].speed == 20)
					{
						enemy[i].pos_y++;

						if (enemy[i].move_count == 3)
							enemy[i].move_count = 0;
						else
							enemy[i].move_count++;

						// 턴 초기화
						enemy[i].speed = 0;
					}
					else
					{
						enemy[i].speed++;
					}
				}
			}

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
		}
	}
}