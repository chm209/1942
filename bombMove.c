#include <stdio.h>
#include "common.h"
#include "game.h"

void bombMove(Bomb* bomb)
{
	int pos_x = 0;
	int pos_y = 0;

	pos_x = bomb[0].pos_x;
	pos_y = bomb[0].pos_y;

	// 폭탄 0번이 TRUE 상태인지 한번 더 검사하는 이유는
	// 폭탄 1번이 0번보다 느리게 끝나기 때문에
	// 한번 더 검사하지 않으면 폭탄 1번이 끝나는 시점에서
	// 하단에 폭탄 0번이 찍혀버리기 때문
	if (bomb[0].con == TRUE)
	{
		// 폭탄 0번 느리게 움직일때
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

		// 폭탄 0번 빠르게 움직일때
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

	// 폭탄 0번이 특정 위치까지 갔을때 폭탄 1번 이동
	if (pos_y < 18 || (bomb[0].con == FALSE && bomb[1].con == TRUE))
	{
		pos_x = bomb[1].pos_x;
		pos_y = bomb[1].pos_y;

		// 천천히
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
		//빨리
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