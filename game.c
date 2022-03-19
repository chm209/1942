#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // GetAsyncKeyState ����� ����
#include "common.h"
#include "game.h"

// 1. ���� ������ DB�� �����ؼ� ���� ������ ���� �ҷ����� �ʿ�
// 2. ���� ����� ����� ���� ������ ����, ����, ȹ���� ����Ʈ, ��ŷ ������Ʈ �ʿ�

ENEMY enemy[ENEMY_SIZE] = { 0, };

void stage(int stage_count)
{
	for (int i = 0; i < ENEMY_SIZE; i++)
	{
		if ((enemy[i].con == FALSE && (stage_count >= 45 && stage_count <= 315) && (stage_count - 45) % 90 == 0))
		{
			enemy[i].pos_x = 6;
			enemy[i].pos_y = 0;
			// <[W]> * * * * * * *
			enemy[i].type = 0;
			// ������ �밢�� �̵�
			enemy[i].move_pattern = 0;
			enemy[i].con = TRUE;
			enemy[i].move_count = 0;
			enemy[i].speed = 0;
			gotoxy(enemy[i].pos_x, enemy[i].pos_y);
			switch (enemy[i].type)
			{
			case 0:
				printf("<WvW>");
				break;
			}
			break;
		}
		if ((enemy[i].con == FALSE && (stage_count >= 90 && stage_count <= 360) && (stage_count - 90) % 90 == 0))
		{
			enemy[i].pos_x = 50;
			enemy[i].pos_y = 1;
			// <[W]> * * * * * * *
			enemy[i].type = 0;
			// ���� �밢������ �̵�
			enemy[i].move_pattern = 1;
			enemy[i].con = TRUE;
			enemy[i].move_count = 0;
			enemy[i].speed = 0;
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

	// ������������ ���� ����
	// �����Ϲ����� f_cnt�� �����Ͽ� 45~315���� 90���� ������ �������� ���� ����
	// n_enemy(x��ǥ, y��ǥ, Ÿ��, �̵�����, ����)���� ����
	// ������ ������ �������� �Լ��� ���ܾ��� 
	// 5 ~ 55 ���̿� ��ġ�ؾ���
	// printf("<[W]>");
	// printf("<WvvW>");
	// printf("[-|-]");;
}

void game(void)
{
	system("mode con: cols=80 lines=30");

	// ����, ��ź, ü��, ����
	int stat_list[STAT_SIZE] = { 5, 3, 5, 0 };

	// �÷��̾� => ��ġ, �Ѿ�, ��ź, ��ų
	PLAYER player;
	BULLET bullet[BULLET_SIZE] = { 0, };
	BOMB bomb[BOMB_SIZE] = { 0, };
	BOMB_BULLET bomb_bullet[BOMB_BUL_SIZE] = { 0, };
	BOMB_BULLET bomb_bullet2[BOMB_BUL_SIZE] = { 0, };
	SKILL skill;

	player.pos_x = 28;
	player.pos_y = 28;
	player.life = 3;
	player.health = 3;
	player.score = 0;
	skill.life_plus = 3;
	skill.invincible = 3;
	skill.life_count = 0;
	skill.invin_count = 0;
	bomb[0].pos_x = 29;
	bomb[0].pos_y = 24;
	bomb[0].count = 3;
	bomb[0].speed = 5;
	bomb[0].con = FALSE;
	bomb[1].pos_x = 6;
	bomb[1].pos_y = 24;
	bomb[1].speed = 5;
	bomb[1].con = FALSE;

	// ����
	int stage_count = 1;

	system("cls");
	drawContent(1);

	while (1)
	{
		gotoxy(2, 2);
		printf("%d", stage_count);

		// �ݺ��Ҷ����� ���Ȱ� �÷��̾� ���� �׷���
		drawStat(stat_list);
		gotoxy(player.pos_x, player.pos_y);
		puts("[-*-]");

		// �� Ű���� �Է� �޴� ��ɵ� �Լ��� �и��ϰų�
		// �� kbhit���� ��� ó���ϸ�����ӵ��� ������

		// �÷��̾� ������
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
			if (GetAsyncKeyState(VK_DOWN) && player.pos_y < 28) { //�Ʒ�
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
					break; // ������ ���߿� ������ ���� ��Ȳ�� ����
				}
			}
		}

		// ��ź �߻� ZŰ
		if ((GetAsyncKeyState(0x5A)))
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
		if ((GetAsyncKeyState(0x58) && skill.life_plus > 0) && skill.life_count == 0)
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
		if ((GetAsyncKeyState(0x43)))
		{
			// ���� ����� ���� ��������
			// �����̳� �Ѿ��� �������� �浹�ص� ������ ����
		}

		// ���� ����
		stage(stage_count);

		// ���� �̵�
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

		// ��ź �̵�
		if (bomb[0].con == TRUE || bomb[1].con == TRUE)
		{
			int pos_x = 0;
			int pos_y = 0;

			pos_x = bomb[0].pos_x;
			pos_y = bomb[0].pos_y;

			// ��ź 0���� TRUE �������� �ѹ� �� �˻��ϴ� ������
			// ��ź 1���� 0������ ������ ������ ������
			// �ѹ� �� �˻����� ������ ��ź 1���� ������ ��������
			// �ϴܿ� ��ź 0���� ���������� ����
			if (bomb[0].con == TRUE)
			{
				// ��ź 0�� ������ �����϶�
				if ((pos_y >= 13 && pos_y <= 18) && bomb[0].speed < 1)
				{
					gotoxy(pos_x, pos_y);
					puts("                           ");
					gotoxy(pos_x + 11, pos_y + 1);
					puts("   ");
					gotoxy(pos_x + 11, pos_y + 2);
					puts("   ");
					gotoxy(pos_x + 11, pos_y + 3);
					puts("   ");
					gotoxy(pos_x + 7, pos_y + 4);
					puts("           ");
					bomb[0].pos_y--;
					pos_y = bomb[0].pos_y;
					gotoxy(pos_x, pos_y);
					puts("<<[[*]]:=:{-*-}:=:[[*]]>>");
					gotoxy(pos_x + 11, pos_y + 1);
					puts("| |");
					gotoxy(pos_x + 11, pos_y + 2);
					puts("| |");
					gotoxy(pos_x + 11, pos_y + 3);
					puts("| |");
					gotoxy(pos_x + 7, pos_y + 4);
					puts("<[[::=::]]>");
					bomb[0].speed = 20;
				}

				// ��ź 0�� ������ �����϶�
				if (pos_y > 18 || pos_y < 13)
				{
					gotoxy(pos_x, pos_y);
					puts("                           ");
					gotoxy(pos_x + 11, pos_y + 1);
					puts("   ");
					gotoxy(pos_x + 11, pos_y + 2);
					puts("   ");
					gotoxy(pos_x + 11, pos_y + 3);
					puts("   ");
					gotoxy(pos_x + 7, pos_y + 4);
					puts("           ");
					bomb[0].pos_y--;
					pos_y = bomb[0].pos_y;
					gotoxy(pos_x, pos_y);
					puts("<<[[*]]:=:{-*-}:=:[[*]]>>");
					gotoxy(pos_x + 11, pos_y + 1);
					puts("| |");
					gotoxy(pos_x + 11, pos_y + 2);
					puts("| |");
					gotoxy(pos_x + 11, pos_y + 3);
					puts("| |");
					gotoxy(pos_x + 7, pos_y + 4);
					puts("<[[::=::]]>");
				}
			}

			// ��ź 0���� Ư�� ��ġ���� ������ ��ź 1�� �̵�
			if (pos_y < 18 || (bomb[0].con == FALSE && bomb[1].con == TRUE))
			{
				pos_x = bomb[1].pos_x;
				pos_y = bomb[1].pos_y;

				// õõ��
				if ((pos_y >= 14 && pos_y <= 19) && bomb[1].speed < 1)
				{
					gotoxy(pos_x, pos_y);
					puts("                         ");
					gotoxy(pos_x + 11, pos_y + 1);
					puts("   ");
					gotoxy(pos_x + 11, pos_y + 2);
					puts("   ");
					gotoxy(pos_x + 11, pos_y + 3);
					puts("   ");
					gotoxy(pos_x + 7, pos_y + 4);
					puts("           ");
					bomb[1].pos_y--;
					pos_y = bomb[1].pos_y;
					gotoxy(pos_x, pos_y);
					puts("<<[[*]]:=:{-*-}:=:[[*]]>>");
					gotoxy(pos_x + 11, pos_y + 1);
					puts("| |");
					gotoxy(pos_x + 11, pos_y + 2);
					puts("| |");
					gotoxy(pos_x + 11, pos_y + 3);
					puts("| |");
					gotoxy(pos_x + 7, pos_y + 4);
					puts("<[[::=::]]>");
					bomb[1].speed = 20;
				}
				//����
				if (pos_y > 19 || pos_y < 14)
				{
					gotoxy(pos_x, pos_y);
					puts("                         ");
					gotoxy(pos_x + 11, pos_y + 1);
					puts("   ");
					gotoxy(pos_x + 11, pos_y + 2);
					puts("   ");
					gotoxy(pos_x + 11, pos_y + 3);
					puts("   ");
					gotoxy(pos_x + 7, pos_y + 4);
					puts("           ");
					bomb[1].pos_y--;
					pos_y = bomb[1].pos_y;
					gotoxy(pos_x, pos_y);
					puts("<<[[*]]:=:{-*-}:=:[[*]]>>");
					gotoxy(pos_x + 11, pos_y + 1);
					puts("| |");
					gotoxy(pos_x + 11, pos_y + 2);
					puts("| |");
					gotoxy(pos_x + 11, pos_y + 3);
					puts("| |");
					gotoxy(pos_x + 7, pos_y + 4);
					puts("<[[::=::]]>");
				}
				bomb[1].speed--;
			}
			bomb[0].speed--;
		}

		// �Ѿ� �̵�
		for (int i = 0; i < BULLET_SIZE; i++)
		{
			if (bullet[i].con == TRUE)
			{
				gotoxy(bullet[i].pos_x, bullet[i].pos_y);
				puts("  ");
				bullet[i].pos_y--;
				gotoxy(bullet[i].pos_x, bullet[i].pos_y);
				puts("��");
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
						enemy[j].con = FALSE;

						gotoxy(bullet[i].pos_x, bullet[i].pos_y);
						puts("  ");
						bullet[i].con = FALSE;
					}
				}
			}
		}

		// ��ź �Ѿ� �߻�
		for (int i = 0; i < BOMB_BUL_SIZE; i++)
		{
			if ((bomb[0].pos_y >= 13 && bomb[0].pos_y <= 18) && bomb_bullet[i].con == FALSE)
			{
				bomb_bullet[i].pos_x = bomb[0].pos_x;
				bomb_bullet[i].pos_y = bomb[0].pos_y - 2;
				bomb_bullet[i].con = TRUE;
			}

			if ((bomb[1].pos_y >= 14 && bomb[1].pos_y <= 19) && bomb_bullet2[i].con == FALSE)
			{
				bomb_bullet2[i].pos_x = bomb[1].pos_x;
				bomb_bullet2[i].pos_y = bomb[1].pos_y - 2;
				bomb_bullet2[i].con = TRUE;
			}
		}

		// ��ź �Ѿ� �̵�
		for (int i = 0; i < BOMB_BUL_SIZE; i++)
		{
			if (bomb_bullet[i].con == TRUE)
			{
				gotoxy(bomb_bullet[i].pos_x, bomb_bullet[i].pos_y);
				puts("                      ");
				bomb_bullet[i].pos_y--;
				gotoxy(bomb_bullet[i].pos_x, bomb_bullet[i].pos_y);
				puts("    ��              ��");
			}

			if (bomb_bullet2[i].con == TRUE)
			{
				gotoxy(bomb_bullet2[i].pos_x, bomb_bullet2[i].pos_y);
				puts("                      ");
				bomb_bullet2[i].pos_y--;
				gotoxy(bomb_bullet2[i].pos_x, bomb_bullet2[i].pos_y);
				puts("    ��              ��");
			}
		}

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
				if ((bomb_bullet[j].con == TRUE && enemy[i].con == TRUE) && bomb_bullet[j].pos_y == enemy[i].pos_y)
				{
					gotoxy(enemy[i].pos_x, enemy[i].pos_y);
					puts("      ");
					enemy[i].con = FALSE;
				}

				if ((bomb_bullet2[j].con == TRUE && enemy[i].con == TRUE) && bomb_bullet2[j].pos_y == enemy[i].pos_y)
				{
					gotoxy(enemy[i].pos_x, enemy[i].pos_y);
					puts("      ");
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
			if (bomb_bullet[i].con == TRUE && bomb_bullet[i].pos_y == 0)
			{
				gotoxy(bomb_bullet[i].pos_x, bomb_bullet[i].pos_y);
				puts("                          ");
				bomb_bullet[i].con = FALSE;
			}

			if (bomb_bullet2[i].con == TRUE && bomb_bullet2[i].pos_y == 0)
			{
				gotoxy(bomb_bullet2[i].pos_x, bomb_bullet2[i].pos_y);
				puts("                          ");
				bomb_bullet2[i].con = FALSE;
			}
		}

		// ������ �ٴڿ� �����ϸ� ����
		for (int i = 0; i < ENEMY_SIZE; i++)
		{
			if (enemy[i].con == TRUE && enemy[i].pos_y == 29)
			{
				gotoxy(enemy[i].pos_x, enemy[i].pos_y);
				printf("     ");
				enemy[i].con = FALSE;
			}
		}

		// �÷��̾� ���� ����ȭ
		stat_list[0] = player.life; // ����
		stat_list[1] = bomb[0].count; // ��ź
		// stat_list[2] = ; // ü��
		// stat_list[3] = ; // ����

		// ��ų ���� ���
		if (skill.life_count > 0)
			skill.life_count--;

		stage_count++;
		Sleep(20);
		// Sleep(18);
	}
}
