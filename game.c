#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // GetAsyncKeyState ����� ����
#include "common.h"
#include "game.h"

// 1. ���� ������ DB�� �����ؼ� ���� ������ ���� �ҷ����� �ʿ�
// 2. ���� ����� ����� ���� ������ ����, ����, ȹ���� ����Ʈ, ��ŷ ������Ʈ �ʿ�

void game(void)
{
	system("mode con: cols=80 lines=40");

	// ����, ��ź, ü��, ����
	int stat_list[STAT_SIZE] = { 5, 3, 5, 0 };

	// �÷��̾� => ��ġ, �Ѿ�, ��ź, ��ų
	PLAYER player;
	BULLET bullet[BULLET_SIZE] = { 0, };
	BOMB bomb[BOMB_SIZE] = { 0, };
	BOMB_BULLET bomb_bullet[BOMB_BUL_SIZE] = { 0, };
	BOMB_BULLET bomb_bullet2[BOMB_BUL_SIZE] = { 0, };

	player.pos_x = 28;
	player.pos_y = 34;
	bomb[0].pos_x = 29;
	bomb[0].pos_y = 34;
	bomb[0].count = 3;
	bomb[0].speed = 5;
	bomb[0].con = FALSE;
	bomb[1].pos_x = 6;
	bomb[1].pos_y = 34;
	bomb[1].speed = 5;
	bomb[1].con = FALSE;

	system("cls");
	drawContent(1);
	
	while (1)
	{
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
			if (GetAsyncKeyState(VK_UP) && player.pos_y > 10) { //��
				gotoxy(player.pos_x, player.pos_y);
				printf("     ");
				player.pos_y--;
				gotoxy(player.pos_x, player.pos_y);
				puts("[-*-]");
			}
			if (GetAsyncKeyState(VK_DOWN) && player.pos_y < 38) { //�Ʒ�
				gotoxy(player.pos_x, player.pos_y);
				printf("     ");
				player.pos_y++;
				gotoxy(player.pos_x, player.pos_y);
				puts("[-*-]");
			}
		}

		// �÷��̾� �Ѿ� ����
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

		// ��ź �߻�
		if ((GetAsyncKeyState(0x5A)))
		{
			if (bomb[0].count > 0 && (bomb[0].con == FALSE && bomb[1].con == FALSE))
			{
				bomb[0].count--;
				stat_list[1]--;
				bomb[0].con = TRUE;
				bomb[1].con = TRUE;
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
				if ((pos_y >= 16 && pos_y <= 24) && bomb[0].speed < 1)
				{
					gotoxy(pos_x, pos_y);
					puts("                           ");
					gotoxy(pos_x + 11, pos_y + 1);
					puts("   ");
					gotoxy(pos_x + 11, pos_y + 2);
					puts("   ");
					gotoxy(pos_x +11, pos_y + 3);
					puts("   ");
					gotoxy(pos_x+7, pos_y + 4);
					puts("           ");
					bomb[0].pos_y--;
					pos_y = bomb[0].pos_y;
					gotoxy(pos_x, pos_y);
					puts("<<[[*]]:=:{-*-}:=:[[*]]>>");
					gotoxy(pos_x + 11, pos_y + 1);
					puts("| |");
					gotoxy(pos_x + 11, pos_y + 2);
					puts("| |");
					gotoxy(pos_x+11, pos_y + 3);
					puts("| |");
					gotoxy(pos_x+7, pos_y + 4);
					puts("<[[::=::]]>");
					bomb[0].speed = 20;
				}

				// ��ź 0�� ������ �����϶�
				if (pos_y > 24 || pos_y < 16)
				{
					gotoxy(pos_x, pos_y);
					puts("                           ");
					gotoxy(pos_x + 11, pos_y + 1);
					puts("   ");
					gotoxy(pos_x + 11, pos_y + 2);
					puts("   ");
					gotoxy(pos_x + 11, pos_y + 3);
					puts("   ");
					gotoxy(pos_x+7, pos_y + 4);
					puts("           ");
					bomb[0].pos_y--;
					pos_y = bomb[0].pos_y;
					gotoxy(pos_x, pos_y);
					puts("<<[[*]]:=:{-*-}:=:[[*]]>>");
					gotoxy(pos_x + 11, pos_y + 1);
					puts("| |");
					gotoxy(pos_x + 11, pos_y + 2);
					puts("| |");
					gotoxy(pos_x+11, pos_y + 3);
					puts("| |");
					gotoxy(pos_x+7, pos_y + 4);
					puts("<[[::=::]]>");
				}
			}

			// ��ź 0���� Ư�� ��ġ���� ������ ��ź 1�� �̵�
			if (pos_y < 30 || (bomb[0].con == FALSE && bomb[1].con == TRUE))
			{
				pos_x = bomb[1].pos_x;
				pos_y = bomb[1].pos_y;

				// õõ��
				if ((pos_y >= 18 && pos_y <= 26) && bomb[1].speed < 1)
				{
					gotoxy(pos_x, pos_y);
					puts("                         ");
					gotoxy(pos_x + 11, pos_y + 1);
					puts("   ");
					gotoxy(pos_x+11, pos_y + 2);
					puts("   ");
					gotoxy(pos_x+11, pos_y + 3);
					puts("   ");
					gotoxy(pos_x+7, pos_y + 4);
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
				if (pos_y > 26 || pos_y < 18)
				{
					gotoxy(pos_x, pos_y);
					puts("                         ");
					gotoxy(pos_x+11, pos_y + 1);
					puts("   ");
					gotoxy(pos_x+11, pos_y + 2);
					puts("   ");
					gotoxy(pos_x+11, pos_y + 3);
					puts("   ");
					gotoxy(pos_x+7, pos_y + 4);
					puts("           ");
					bomb[1].pos_y--;
					pos_y = bomb[1].pos_y;
					gotoxy(pos_x, pos_y);
					puts("<<[[*]]:=:{-*-}:=:[[*]]>>");
					gotoxy(pos_x+11, pos_y + 1);
					puts("| |");
					gotoxy(pos_x + 11, pos_y + 2);
					puts("| |");
					gotoxy(pos_x + 11, pos_y + 3);
					puts("| |");
					gotoxy(pos_x+7, pos_y + 4);
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

		// ��ź �Ѿ� �߻�
		for (int i = 0; i < BOMB_BUL_SIZE; i++)
		{
			if ((bomb[0].pos_y >= 15 && bomb[0].pos_y <= 23) && bomb_bullet[i].con == FALSE)
			{
				bomb_bullet[i].pos_x = bomb[0].pos_x;
				bomb_bullet[i].pos_y = bomb[0].pos_y - 2;
				bomb_bullet[i].con = TRUE;
			}

			if ((bomb[1].pos_y >= 17 && bomb[1].pos_y <= 25) && bomb_bullet2[i].con == FALSE)
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
				gotoxy(bomb[0].pos_x+11, bomb[0].pos_y + 3);
				puts("   ");
				gotoxy(bomb[0].pos_x+7, bomb[0].pos_y + 4);
				puts("           ");
				bomb[0].pos_y = 34;
				bomb[0].con = FALSE;
			}

			if (bomb[1].con == TRUE && bomb[1].pos_y == 0)
			{
				gotoxy(bomb[1].pos_x, bomb[1].pos_y);
				puts("                         ");
				gotoxy(bomb[1].pos_x+11, bomb[1].pos_y + 1);
				puts("   ");
				gotoxy(bomb[1].pos_x + 11, bomb[1].pos_y + 2);
				puts("   ");
				gotoxy(bomb[1].pos_x + 11, bomb[1].pos_y + 3);
				puts("   ");
				gotoxy(bomb[1].pos_x+7, bomb[1].pos_y + 4);
				puts("           ");
				bomb[1].pos_y = 34;
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

		Sleep(20);
		// Sleep(18);
	}
}
