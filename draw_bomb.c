#include <stdio.h>
#include "common.h"

void draw_bomb(int state, int POS_X, int POS_Y)
{
	switch (state)
	{
	case 0:
		gotoxy(POS_X, POS_Y);
		puts("                         ");
		gotoxy(POS_X + 11, POS_Y + 1);
		puts("   ");
		gotoxy(POS_X + 11, POS_Y + 2);
		puts("   ");
		gotoxy(POS_X + 11, POS_Y + 3);
		puts("   ");
		gotoxy(POS_X + 7, POS_Y + 4);
		puts("           ");
		break;
	case 1:
		gotoxy(POS_X, POS_Y);
		puts("<<[[*]]:=:{-*-}:=:[[*]]>>");
		gotoxy(POS_X + 11, POS_Y + 1);
		puts("| |");
		gotoxy(POS_X + 11, POS_Y + 2);
		puts("| |");
		gotoxy(POS_X + 11, POS_Y + 3);
		puts("| |");
		gotoxy(POS_X + 7, POS_Y + 4);
		puts("<[[::=::]]>");
		break;
	}
}