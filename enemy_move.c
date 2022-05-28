#include <stdio.h>
#include "common.h"
#include "game.h"

void enemy_move(ENEMY* enemy)
{
	for (int i = 0; i < ENEMY_SIZE; i++)
	{
		if (enemy->condition[i] == TRUE)
		{
			gotoxy(enemy->pos_x[i], enemy->pos_y[i]);
			printf("     ");

			// 오른쪽 대각선 이동
			if (enemy->pattern[i] == 0)
			{
				if (enemy->move_interval[i] == 6)
				{
					// 아래로 내려갈 차례인지 옆으로 갈 차례인지 검사
					if (enemy->move_count[i] == 3)
					{
						enemy->pos_y[i]++;
						enemy->move_count[i] = 0;
					}
					else
					{
						// 벽에 붙었는지 검사 & 붙었으면 move_count는 올릴 필요 없음
						if (enemy->pos_x[i] > 48)
						{
							enemy->pos_y[i]++;
						}
						else
						{
							enemy->pos_x[i]++;
							enemy->move_count[i]++;
						}
					}
					enemy->move_interval[i] = 0;
				}
				else
				{
					enemy->move_interval[i]++;
				}
			}

			// 왼쪽 대각선 이동
			if (enemy->pattern[i] == 1)
			{
				if (enemy->move_interval[i] == 9)
				{
					// 아래로 내려갈 차례인지 옆으로 갈 차례인지 검사
					if (enemy->move_count[i] == 2)
					{
						enemy->pos_y[i]++;
						enemy->move_count[i] = 0;
					}
					else
					{
						// 벽에 붙었는지 검사 & 붙었으면 move_count는 올릴 필요 없음
						if (enemy->pos_x[i] < 10)
						{
							enemy->pos_y[i]++;
						}
						else
						{
							enemy->pos_x[i] -= 2;
							enemy->move_count[i]++;
						}
					}
					enemy->move_interval[i] = 0;
				}
				else
				{
					enemy->move_interval[i]++;
				}
			}

			// 아래로 직진 & 속도 조절 동시 진행
			if (enemy->pattern[i] == 2 || enemy->pattern[i] == 3)
			{
				if (enemy->pos_y[i] > 12)
				{
					// 자기 턴이 오면 진행
					if (enemy->move_interval[i] == 2)
					{
						enemy->pos_y[i]++;

						if (enemy->move_count[i] == 3)
						{
							enemy->move_count[i] = 0;
						}
						else
						{
							enemy->move_count[i]++;
						}
						// 턴 초기화
						enemy->move_interval[i] = 0;
					}
					else
					{
						enemy->move_interval[i]++;
					}
				}
				else
				{
					// 자기 턴이 오면 진행
					if (enemy->move_interval[i] == 20)
					{
						enemy->pos_y[i]++;

						if (enemy->move_count[i] == 3)
						{
							enemy->move_count[i] = 0;
						}
						else
						{
							enemy->move_count[i]++;
						}
						// 턴 초기화
						enemy->move_interval[i] = 0;
					}
					else
					{
						enemy->move_interval[i]++;
					}
				}
			}

			// 아래로 갔다가 다시 올라오기
			if (enemy->pattern[i] == 4)
			{
				if (enemy->move_count[i] == 1)
				{
					// 자기 턴이 오면 진행
					if ((enemy->move_interval[i] > 150) && (enemy->move_interval[i] % 100 == 0))
					{
						// 다시 뒤로 돌아가는 패턴이라서 여기서 처리
						if (enemy->pos_y[i] == 0)
						{
							gotoxy(enemy->pos_x[i], enemy->pos_y[i]);
							printf("     ");
							enemy->pos_x[i] = 0;
							enemy->pos_y[i] = 0;
							enemy->condition[i] = FALSE;
						}
						else
						{
							enemy->pos_y[i]--;
						}
						// 다시 뒤로 돌아가야하기 때문에 턴수를 초기화 하지 않음
					}
					else
					{
						enemy->move_interval[i]++;
					}
				}
				else
				{
					// 자기 턴이 오면 진행
					if (enemy->move_interval[i] == 5)
					{
						enemy->pos_y[i]++;
						if (enemy->pos_y[i] > 4)
						{
							enemy->move_count[i]++;
						}
						// 턴 초기화
						enemy->move_interval[i] = 0;
					}
					else
					{
						enemy->move_interval[i]++;
					}
				}
			}

			// 일직선으로 내려감 - 공격은 전방위
			if (enemy->pattern[i] == 5)
			{
				if (enemy->pos_y[i] > 16)
				{
					if (enemy->move_interval[i] == 1)
					{
						enemy->pos_y[i]++;
						enemy->move_interval[i] = 0;
					}
					else
					{
						enemy->move_interval[i]++;
					}
				}
				else
				{
					if (enemy->move_interval[i] == 35)
					{
						enemy->pos_y[i]++;
						enemy->move_interval[i] = 0;
					}
					else
					{
						enemy->move_interval[i]++;
					}
				}
			}

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
		}
	}
}