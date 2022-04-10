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

			// �Ʒ��� ����
			if (enemy[i].move_pattern == 2 || enemy[i].move_pattern == 3)
			{
				if (enemy[i].pos_y > 12)
				{
					// �ڱ� ���� ���� ����
					if (enemy[i].speed == 2)
					{
						enemy[i].pos_y++;

						if (enemy[i].move_count == 3)
							enemy[i].move_count = 0;
						else
							enemy[i].move_count++;

						// �� �ʱ�ȭ
						enemy[i].speed = 0;
					}
					else
					{
						enemy[i].speed++;
					}
				}
				else
				{
					// �ڱ� ���� ���� ����
					if (enemy[i].speed == 20)
					{
						enemy[i].pos_y++;

						if (enemy[i].move_count == 3)
							enemy[i].move_count = 0;
						else
							enemy[i].move_count++;

						// �� �ʱ�ȭ
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