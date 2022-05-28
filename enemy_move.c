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

			// ������ �밢�� �̵�
			if (enemy->pattern[i] == 0)
			{
				if (enemy->move_interval[i] == 6)
				{
					// �Ʒ��� ������ �������� ������ �� �������� �˻�
					if (enemy->move_count[i] == 3)
					{
						enemy->pos_y[i]++;
						enemy->move_count[i] = 0;
					}
					else
					{
						// ���� �پ����� �˻� & �پ����� move_count�� �ø� �ʿ� ����
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

			// ���� �밢�� �̵�
			if (enemy->pattern[i] == 1)
			{
				if (enemy->move_interval[i] == 9)
				{
					// �Ʒ��� ������ �������� ������ �� �������� �˻�
					if (enemy->move_count[i] == 2)
					{
						enemy->pos_y[i]++;
						enemy->move_count[i] = 0;
					}
					else
					{
						// ���� �پ����� �˻� & �پ����� move_count�� �ø� �ʿ� ����
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

			// �Ʒ��� ���� & �ӵ� ���� ���� ����
			if (enemy->pattern[i] == 2 || enemy->pattern[i] == 3)
			{
				if (enemy->pos_y[i] > 12)
				{
					// �ڱ� ���� ���� ����
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
						// �� �ʱ�ȭ
						enemy->move_interval[i] = 0;
					}
					else
					{
						enemy->move_interval[i]++;
					}
				}
				else
				{
					// �ڱ� ���� ���� ����
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
						// �� �ʱ�ȭ
						enemy->move_interval[i] = 0;
					}
					else
					{
						enemy->move_interval[i]++;
					}
				}
			}

			// �Ʒ��� ���ٰ� �ٽ� �ö����
			if (enemy->pattern[i] == 4)
			{
				if (enemy->move_count[i] == 1)
				{
					// �ڱ� ���� ���� ����
					if ((enemy->move_interval[i] > 150) && (enemy->move_interval[i] % 100 == 0))
					{
						// �ٽ� �ڷ� ���ư��� �����̶� ���⼭ ó��
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
						// �ٽ� �ڷ� ���ư����ϱ� ������ �ϼ��� �ʱ�ȭ ���� ����
					}
					else
					{
						enemy->move_interval[i]++;
					}
				}
				else
				{
					// �ڱ� ���� ���� ����
					if (enemy->move_interval[i] == 5)
					{
						enemy->pos_y[i]++;
						if (enemy->pos_y[i] > 4)
						{
							enemy->move_count[i]++;
						}
						// �� �ʱ�ȭ
						enemy->move_interval[i] = 0;
					}
					else
					{
						enemy->move_interval[i]++;
					}
				}
			}

			// ���������� ������ - ������ ������
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