#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "game.h"

void draw_help(void)
{
	system("cls");
	draw_game(5);
	draw_game(6);
	gotoxy(16, 26);
	system("pause");
	system("cls");
}