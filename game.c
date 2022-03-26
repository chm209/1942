#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // GetAsyncKeyState ����� ����
#include "common.h"
#include "game.h"

void game(void)
{
	system("mode con: cols=80 lines=32");
	system("cls");

	// ����, ��ź, ü��, ����
	int stat_list[STAT] = { 1, 1, 3, 0 };

	// �÷��̾�
	// ��ġ, �Ѿ�, ��ź, ��ų ����
	Player player = { 28, 28, 1, 3, 0 }; // X��, Y��, ����, ü��, ����
	Bullet bullet[BULLET_SIZE] = { 0, }; // X��, Y��, Ȯ��
	Skill skill = { 3, 3, 0, 0 };
	Bomb bomb[BOMB_SIZE] = { 29, 24, 1, 5, FALSE, 6, 24, 0, 5, FALSE }; // // X��, Y��, �ܷ�, �ӵ�, Ȯ��
	Bomb_blt bomb_bul[BOMB_BUL_SIZE] = { 0, };
	Bomb_blt bomb_bul2[BOMB_BUL_SIZE] = { 0, };
	Item item[ITEM_SIZE] = { 0, };

	// ����
	int frame_cnt = 0;
	Enemy enemy[ENEMY_SIZE] = { 0, };

	while (1)
	{
		// �ݺ��Ҷ����� UI�� ������ ���� �׷���
		drawContent(1);
		drawStat(stat_list);
		gotoxy(player.pos_x, player.pos_y);
		puts("[-*-]");

		// ���� Ű���� ����
		// GetAsyncKeyState()�� ��� �����ϱ� ���� �Լ�ȭ X
		// �Լ�ȭ �ϰų� getch()�� ������ �����ӵ��� ������
		{
			if (GetAsyncKeyState(VK_LEFT) && player.pos_x > 5) { //����
				gotoxy(player.pos_x, player.pos_y);
				printf("     ");
				player.pos_x--;
				gotoxy(player.pos_x, player.pos_y);
				puts("[-*-]");
			}
			if (GetAsyncKeyState(VK_RIGHT) && player.pos_x < 51) { //������
				gotoxy(player.pos_x, player.pos_y);
				printf("     ");
				player.pos_x++;
				gotoxy(player.pos_x, player.pos_y);
				puts("[-*-]");
			}
			if (GetAsyncKeyState(VK_UP) && player.pos_y > 4) { //��
				gotoxy(player.pos_x, player.pos_y);
				printf("     ");
				player.pos_y--;
				gotoxy(player.pos_x, player.pos_y);
				puts("[-*-]");
			}
			if (GetAsyncKeyState(VK_DOWN) && player.pos_y < 29) { //�Ʒ�
				gotoxy(player.pos_x, player.pos_y);
				printf("     ");
				player.pos_y++;
				gotoxy(player.pos_x, player.pos_y);
				puts("[-*-]");
			}
		}

		// �÷��̾� �Ѿ� ���� �����̽���
		if ((GetAsyncKeyState(VK_SPACE)))
		{
			for (int i = 0; i < BULLET_SIZE; i++)
			{
				if (bullet[i].con == FALSE)
				{
					bullet[i].pos_x = player.pos_x + 1;
					bullet[i].pos_y = player.pos_y - 1;
					bullet[i].con = TRUE;
					break;
				}
			}
		}

		// ��ź �߻� ZŰ, frame_cnt > 1�� ���� �����ϱ��� ZŰ�� �������� ��ų�� �����°� �����ϱ�����
		if (GetAsyncKeyState(0x5A) && frame_cnt > 1)
		{
			if (bomb[0].count > 0 && (bomb[0].con == FALSE && bomb[1].con == FALSE))
			{
				bomb[0].count--;
				bomb[0].con = TRUE;
				bomb[1].con = TRUE;
			}
		}

		// ��ų XŰ - ���� �߰�
		// STAT UI�� �ݿ��ؾ���
		if ((GetAsyncKeyState(0x58) && frame_cnt > 1) && (skill.life_count == 0 && skill.life_plus > 0))
		{
			player.life++;
			skill.life_plus--;

			if (bomb[0].count > 0 && (bomb[0].con == FALSE && bomb[1].con == FALSE))
			{
				bomb[0].con = TRUE;
				bomb[1].con = TRUE;
				// ��ų ���� �ð� ���� �ʿ�
				skill.life_count = 1000;
			}
			else
			{
				bomb[0].count++;
				// ��ų ���� �ð� ���� �ʿ�
				skill.life_count = 1000;
			}
		}

		// ��ų CŰ - ���� ���
		if ((GetAsyncKeyState(0x43) && frame_cnt > 1))
		{
			// ���� ����� ���� ��������
			// �����̳� �Ѿ��� �������� �浹�ص� ������ ����
		}

		// ���� ����
		enemyGen(enemy, frame_cnt);

		// ������ ����
		itemGen(item, frame_cnt);

		// ���� �̵�
		enemyMove(enemy);

		// ��ź �̵�
		if (bomb[0].con == TRUE || bomb[1].con == TRUE)
			bombMove(bomb);

		// �Ѿ� �̵�
		bulletMove(bullet);

		// ���� �Ѿ� �߻�
		for (int i = 0; i < ENEMY_SIZE; i++)
		{
			if (enemy[i].con == TRUE)
			{
				for (int j = 0; j < ENEMY_BUL_SIZE; j++)
				{
					if (enemy[i].move_pattern == 1 || enemy[i].move_pattern == 0)
					{
						if (enemy[i].bul_speed > 60 && (enemy[i].move_count == 1 || enemy[i].move_count == 3))
						{
							enemy[i].bul_pos_x[j] = enemy[i].pos_x + 2;
							enemy[i].bul_pos_y[j] = enemy[i].pos_y + 1;
							enemy[i].bul_con[j] = TRUE;
							enemy[i].bul_speed = 0;
							gotoxy(enemy[i].bul_pos_x[j], enemy[i].bul_pos_y[j]);
							printf("*");
						}
					}
				}
				enemy[i].bul_speed++;
			}
		}

		// �� �Ѿ� �̵�
		for (int i = 0; i < ENEMY_SIZE; i++)
		{
			for (int j = 0; j < ENEMY_BUL_SIZE; j++)
			{
				if (enemy[i].move_pattern == 1 || enemy[i].move_pattern == 0)
				{
					if (enemy[i].bul_con[j] == TRUE)
					{
						gotoxy(enemy[i].bul_pos_x[j], enemy[i].bul_pos_y[j]);
						puts("  ");
						enemy[i].bul_pos_y[j]++;
						gotoxy(enemy[i].bul_pos_x[j], enemy[i].bul_pos_y[j]);
						printf("*");
					}
				}
			}
		}

		// ������ �̵�
		for (int i = 0; i < ITEM_SIZE; i++)
		{
			if (item[i].con == TRUE)
			{
				if (item[i].speed == 15)
				{
					item[i].speed = 0;
					gotoxy(item[i].pos_x, item[i].pos_y);
					puts("   ");
					item[i].pos_y++;
					gotoxy(item[i].pos_x, item[i].pos_y);
					switch (item[i].type)
					{
					case 0:
						printf("[P]");
						break;
					}
				}
				else
					item[i].speed++;
				
			}
		}

		// ������ ���� �浹
		for (int i = 0; i < ITEM_SIZE; i++)
		{
			if (item[i].con == TRUE)
			{
				if (item[i].pos_y == player.pos_y)
				{
					if (item[i].pos_x >= player.pos_x && item[i].pos_x <= player.pos_x + 5)
					{
						gotoxy(item[i].pos_x, item[i].pos_y);
						puts("   ");
						item[i].con = FALSE;
						
						switch (item[i].type)
						{
						// ���� ��
						case 0:
							bullet[0].type = 1;
							bullet[1].type = 1;
							bullet[2].type = 1;
							bullet[3].type = 1;
							break;
						case 1:
							bullet[0].type = 2;
							bullet[1].type = 2;
							bullet[2].type = 2;
							bullet[3].type = 2;
							break;
						}
					}
				}
			}
		}

		// ������ �ٴ� �浹
		for (int i = 0; i < ITEM_SIZE; i++)
		{
			if (item[i].con == TRUE)
			{
				if (item[i].pos_y == 30)
				{
					gotoxy(item[i].pos_x, item[i].pos_y);
					puts("   ");
					item[i].con = FALSE;
				}
			}
		}

		// �� �Ѿ� �÷��̾� �浹
		for (int i = 0; i < ENEMY_SIZE; i++)
		{
			for (int j = 0; j < ENEMY_BUL_SIZE; j++)
			{
				if (enemy[i].bul_con[j] == TRUE && enemy[i].bul_pos_y[j] == player.pos_y)
				{
					if ((enemy[i].bul_pos_x[j] >= player.pos_x) && (enemy[i].bul_pos_x[j] <= player.pos_x + 5))
					{
						gotoxy(enemy[i].bul_pos_x[j], enemy[i].bul_pos_y[j]);
						puts("  ");
						enemy[i].bul_con[j] = FALSE;

						if (player.health > 0)
							player.health--;
						else
						{
							if (player.life > 0)
							{
								player.life--;
								player.health = 3;
								bomb[0].con = TRUE;
								bomb[1].con = TRUE;
							}
							else
							{
								// ���� ����
								return 0;
							}
						}
						
					}
				}
			}
		}

		// �� �Ѿ� �ٴ� ����
		for (int i = 0; i < ENEMY_SIZE; i++)
		{
			for (int j = 0; j < ENEMY_BUL_SIZE; j++)
			{
				if (enemy[i].bul_con[j] == TRUE && enemy[i].bul_pos_y[j] > 29)
				{
					gotoxy(enemy[i].bul_pos_x[j], enemy[i].bul_pos_y[j]);
					puts("  ");
					enemy[i].bul_con[j] = FALSE;
				}
			}
		}

		// �� �Ѿ� �÷��̾� �Ѿ� �浹
		for (int i = 0; i < ENEMY_SIZE; i++)
		{
			for (int j = 0; j < ENEMY_BUL_SIZE; j++)
			{
				for (int k = 0; k < BULLET_SIZE; k++)
				{
					if (enemy[i].bul_con[j] == TRUE && bullet[k].con == TRUE)
					{
						if (enemy[i].bul_pos_y[j] == bullet[k].pos_y)
						{
							if (enemy[i].bul_pos_x[j] == bullet[k].pos_x)
							{
								gotoxy(enemy[i].bul_pos_x[j], enemy[i].bul_pos_y[j]);
								puts("  ");
								enemy[i].bul_con[j] = FALSE;
								bullet[k].con = FALSE;
							}
						}
					}
				}
			}
		}

		// ��ź �߻�� �� �Ѿ� ��ź �տ��� ����
		if (bomb[0].con == TRUE || bomb[1].con == TRUE)
		{
			for (int i = 0; i < ENEMY_SIZE; i++)
			{
				for (int j = 0; j < ENEMY_BUL_SIZE; j++)
				{
					if (enemy[i].bul_con[j] == TRUE && (enemy[i].bul_pos_y[j] >= bomb[0].pos_y || enemy[i].bul_pos_y[j] >= bomb[1].pos_y))
					{
						gotoxy(enemy[i].bul_pos_x[j], enemy[i].bul_pos_y[j]);
						puts("  ");
						enemy[i].bul_con[j] = FALSE;
					}
				}
			}
		}

		// �÷��̾� - �� �浹
		for (int i = 0; i < ENEMY_SIZE; i++)
		{
			if (player.pos_y == enemy[i].pos_y)
			{
				if ((enemy[i].pos_x <= player.pos_x && enemy[i].pos_x + 5 >= player.pos_x) && enemy[i].pos_x - 4 <= player.pos_x)
				{
					if (player.life > 0)
					{
						player.life--;
						player.pos_x = 26;
						player.pos_y = 26;
						gotoxy(enemy[i].pos_x, enemy[i].pos_y);
						puts("      ");
						enemy[i].pos_x = 0;
						enemy[i].pos_y = 0;
						enemy[i].con = FALSE;
						bomb[0].con = TRUE;
						bomb[1].con = TRUE;
						break;
					}
					else
					{
						// ���ӿ���
					}
					break;
				}
			}
		}

		// �Ѿ� - �� �浹
		for (int i = 0; i < BULLET_SIZE; i++)
		{
			for (int j = 0; j < ENEMY_SIZE; j++)
			{
				if ((bullet[i].con == TRUE && enemy[j].con == TRUE) && bullet[i].pos_y == enemy[j].pos_y)
				{
					if ((enemy[j].pos_x <= bullet[i].pos_x - 1) && (enemy[j].pos_x + 5) >= bullet[i].pos_x + 1)
					{
						gotoxy(enemy[j].pos_x, enemy[j].pos_y);
						puts("      ");

						enemy[j].pos_x = 0;
						enemy[j].pos_y = 0;
						enemy[j].con = FALSE;

						gotoxy(bullet[i].pos_x, bullet[i].pos_y);
						puts("  ");
						bullet[i].con = FALSE;
					}
				}
			}
		}

		// ��ź �Ѿ� �߻�
		bombBul(bomb, bomb_bul, bomb_bul2, 0);

		// ��ź �Ѿ� �̵�
		bombBul(bomb, bomb_bul, bomb_bul2, 1);

		// ��ź - �� �浹
		if (bomb[0].con == TRUE && bomb[1].con == TRUE)
		{
			for (int i = 0; i < BOMB_SIZE; i++)
			{
				for (int j = 0; j < ENEMY_SIZE; j++)
				{
					if (bomb[i].pos_y == enemy[j].pos_y || (enemy[j].pos_y - bomb[i].pos_y > 0))
					{
						gotoxy(enemy[j].pos_x, enemy[j].pos_y);
						puts("      ");
						enemy[j].pos_x = 0;
						enemy[j].pos_y = 0;
						enemy[j].con = FALSE;
					}
				}
			}
		}

		// ��ź �Ѿ� - �� �浹
		for (int i = 0; i < ENEMY_SIZE; i++)
		{
			for (int j = 0; j < BOMB_BUL_SIZE; j++)
			{
				if ((bomb_bul[j].con == TRUE && enemy[i].con == TRUE) && bomb_bul[j].pos_y == enemy[i].pos_y)
				{
					gotoxy(enemy[i].pos_x, enemy[i].pos_y);
					puts("      ");
					enemy[i].pos_x = 0;
					enemy[i].pos_y = 0;
					enemy[i].con = FALSE;
				}

				if ((bomb_bul2[j].con == TRUE && enemy[i].con == TRUE) && bomb_bul2[j].pos_y == enemy[i].pos_y)
				{
					gotoxy(enemy[i].pos_x, enemy[i].pos_y);
					puts("      ");
					enemy[i].pos_x = 0;
					enemy[i].pos_y = 0;
					enemy[i].con = FALSE;
				}
			}
		}

		// �Ѿ��� õ�忡 �����ϸ� ����
		for (int i = 0; i < BULLET_SIZE; i++)
		{
			if (bullet[i].con == TRUE && bullet[i].pos_y == 0)
			{
				gotoxy(bullet[i].pos_x, bullet[i].pos_y);
				puts("  ");
				bullet[i].con = FALSE;
			}
		}

		// ��ź�� õ�忡 �����ϸ� ����
		{
			if (bomb[0].con == TRUE && bomb[0].pos_y == 0)
			{
				gotoxy(bomb[0].pos_x, bomb[0].pos_y);
				puts("                         ");
				gotoxy(bomb[0].pos_x + 11, bomb[0].pos_y + 1);
				puts("   ");
				gotoxy(bomb[0].pos_x + 11, bomb[0].pos_y + 2);
				puts("   ");
				gotoxy(bomb[0].pos_x + 11, bomb[0].pos_y + 3);
				puts("   ");
				gotoxy(bomb[0].pos_x + 7, bomb[0].pos_y + 4);
				puts("           ");
				bomb[0].pos_y = 24;
				bomb[0].con = FALSE;
			}

			if (bomb[1].con == TRUE && bomb[1].pos_y == 0)
			{
				gotoxy(bomb[1].pos_x, bomb[1].pos_y);
				puts("                         ");
				gotoxy(bomb[1].pos_x + 11, bomb[1].pos_y + 1);
				puts("   ");
				gotoxy(bomb[1].pos_x + 11, bomb[1].pos_y + 2);
				puts("   ");
				gotoxy(bomb[1].pos_x + 11, bomb[1].pos_y + 3);
				puts("   ");
				gotoxy(bomb[1].pos_x + 7, bomb[1].pos_y + 4);
				puts("           ");
				bomb[1].pos_y = 24;
				bomb[1].con = FALSE;
			}
		}

		// ��ź �Ѿ��� õ�忡 �����ϸ� ����
		for (int i = 0; i < BOMB_BUL_SIZE; i++)
		{
			if (bomb_bul[i].con == TRUE && bomb_bul[i].pos_y == 0)
			{
				gotoxy(bomb_bul[i].pos_x, bomb_bul[i].pos_y);
				puts("                          ");
				bomb_bul[i].con = FALSE;
			}

			if (bomb_bul2[i].con == TRUE && bomb_bul2[i].pos_y == 0)
			{
				gotoxy(bomb_bul2[i].pos_x, bomb_bul2[i].pos_y);
				puts("                          ");
				bomb_bul2[i].con = FALSE;
			}
		}

		// ������ �ٴڿ� �����ϸ� ����
		for (int i = 0; i < ENEMY_SIZE; i++)
		{
			if (enemy[i].con == TRUE && enemy[i].pos_y == 29)
			{
				gotoxy(enemy[i].pos_x, enemy[i].pos_y);
				printf("     ");
				enemy[i].pos_x = 0;
				enemy[i].pos_y = 0;
				enemy[i].con = FALSE;
			}
		}

		// �÷��̾� ���� ����ȭ
		stat_list[0] = player.life; // ����
		stat_list[2] = player.health; // ü��
		stat_list[1] = bomb[0].count; // ��ź
		// stat_list[2] = ; // ü��
		// stat_list[3] = ; // ����

		// ��ų ���� ���
		if (skill.life_count > 0)
			skill.life_count--;

		frame_cnt++;
		Sleep(15);
	}
}