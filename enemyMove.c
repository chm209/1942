#include <stdio.h>
#include "common.h"
#include "game.h"

void enemyMove(Enemy* enemy)
{
	for (int i = 0; i < ENEMY_SIZE; i++)
	{
		if (enemy[i].con == TRUE)
		{
			gotoxy(enemy[i].pos_x, enemy[i].pos_y);
			printf("     ");

			// ������ �밢�� �̵�
			if (enemy[i].move_pattern == 0)
			{
				// �ڱ� ���� ���� ����
				if (enemy[i].speed == 6)
				{
					// �Ʒ��� ������ �������� ������ �� �������� �˻�
					if (enemy[i].move_count == 3)
					{
						enemy[i].pos_y++;
						enemy[i].move_count = 0;
					}
					else
					{
						// �������� ������ �˻�, �������� ������ move_count �ø� �ʿ� ����
						if (enemy[i].pos_x > 48)
							enemy[i].pos_y++;
						else
						{
							enemy[i].pos_x++;
							enemy[i].move_count++;
						}
					}
					// �� �ʱ�ȭ
					enemy[i].speed = 0;
				}
				else
				{
					enemy[i].speed++;
				}
			}

			// ���� �밢�� �̵�
			if (enemy[i].move_pattern == 1)
			{
				// �ڱ� ���� ���� ����
				if (enemy[i].speed == 9)
				{
					// �Ʒ��� ������ �������� ������ �� �������� �˻�
					if (enemy[i].move_count == 2)
					{
						enemy[i].pos_y++;
						enemy[i].move_count = 0;
					}
					else
					{
						// �������� ������ �˻�, �������� ������ move_count �ø� �ʿ� ����
						if (enemy[i].pos_x < 10)
							enemy[i].pos_y++;
						else
						{
							enemy[i].pos_x -= 2;
							enemy[i].move_count++;
						}
					}
					// �� �ʱ�ȭ
					enemy[i].speed = 0;
				}
				else
				{
					enemy[i].speed++;
				}
			}

			gotoxy(enemy[i].pos_x, enemy[i].pos_y);
			switch (enemy[i].type)
			{
			case 0:
				printf("<WvW>");
				break;
			}
		}
	}
}