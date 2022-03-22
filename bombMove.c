#include <stdio.h>
#include "common.h"
#include "game.h"

void bombMove(Bomb* bomb)
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