#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // GetAsyncKeyState ����� ����
#include "common.h"
#include "game.h"

// �Լ�
void stage(int);

// ���� ����
Enemy enemy[ENEMY_SIZE] = { 0, };

void game(void)
{
	system("mode con: cols=80 lines=31");
	system("cls");

	// ����, ��ź, ü��, ����
	int stat_list[STAT] = { 5, 3, 5, 0 };

	// �÷��̾�
	// ��ġ, �Ѿ�, ��ź, ��ų ����
	Player player = { 28, 28, 1, 3, 0 }; // X��, Y��, ����, ü��, ����
	Bullet bullet[BULLET_SIZE] = { 0, }; // X��, Y��, Ȯ��
	Skill skill = { 3, 3, 0, 0 };
	Bomb bomb[BOMB_SIZE] = { 29, 24, 3, 5, FALSE, 6, 24, 0, 5, FALSE }; // // X��, Y��, �ܷ�, �ӵ�, Ȯ��
	Bomb_blt bomb_bul[BOMB_BUL_SIZE] = { 0, };
	Bomb_blt bomb_bul2[BOMB_BUL_SIZE] = { 0, };
	
	// ����
	int frame_cnt = 0;

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
		if ((GetAsyncKeyState(0x58) && frame_cnt > 1 ) && (skill.life_count == 0 && skill.life_plus > 0 ))
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
		stage(frame_cnt);

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
		for (int i = 0; i < BOMB_BUL_SIZE; i++)
		{
			if ((bomb[0].pos_y >= 13 && bomb[0].pos_y <= 18) && bomb_bul[i].con == FALSE)
			{
				bomb_bul[i].pos_x = bomb[0].pos_x;
				bomb_bul[i].pos_y = bomb[0].pos_y - 2;
				bomb_bul[i].con = TRUE;
			}

			if ((bomb[1].pos_y >= 14 && bomb[1].pos_y <= 19) && bomb_bul2[i].con == FALSE)
			{
				bomb_bul2[i].pos_x = bomb[1].pos_x;
				bomb_bul2[i].pos_y = bomb[1].pos_y - 2;
				bomb_bul2[i].con = TRUE;
			}
		}

		// ��ź �Ѿ� �̵�
		for (int i = 0; i < BOMB_BUL_SIZE; i++)
		{
			if (bomb_bul[i].con == TRUE)
			{
				gotoxy(bomb_bul[i].pos_x, bomb_bul[i].pos_y);
				puts("                      ");
				bomb_bul[i].pos_y--;
				gotoxy(bomb_bul[i].pos_x, bomb_bul[i].pos_y);
				puts("    ��              ��");
			}

			if (bomb_bul2[i].con == TRUE)
			{
				gotoxy(bomb_bul2[i].pos_x, bomb_bul2[i].pos_y);
				puts("                      ");
				bomb_bul2[i].pos_y--;
				gotoxy(bomb_bul2[i].pos_x, bomb_bul2[i].pos_y);
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

void stage(int frame_cnt)
{
	for (int i = 0; i < ENEMY_SIZE; i++)
	{
		if ((enemy[i].con == FALSE && (frame_cnt >= 45 && frame_cnt <= 315) && (frame_cnt - 45) % 90 == 0))
		{
			enemy[i].pos_x = 6;
			enemy[i].pos_y = 0;
			enemy[i].type = 0; // <[W]> * * * * * * *
			enemy[i].move_pattern = 0; // ������ �밢�� �̵�
			enemy[i].move_count = 0;
			enemy[i].speed = 0;
			enemy[i].con = TRUE;
			gotoxy(enemy[i].pos_x, enemy[i].pos_y);
			switch (enemy[i].type)
			{
			case 0:
				printf("<WvW>");
				break;
			}
			break;
		}
		if ((enemy[i].con == FALSE && (frame_cnt >= 90 && frame_cnt <= 360) && (frame_cnt - 90) % 90 == 0))
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
