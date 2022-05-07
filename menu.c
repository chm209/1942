#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "common.h"
#define MENU_POS_X 69

int menu(int choose_menu)
{
	int user_input = 0;

	while (user_input != ENTER)
	{
		gotoxy(MENU_POS_X, choose_menu);
		puts("ㆍㆍ ◀");
		user_input = getch();
		gotoxy(MENU_POS_X, choose_menu);
		puts("       ");
		// 화면번호, 입력받은 키 값, X 값, Y 값
		choose_menu = move(0, user_input, MENU_POS_X, choose_menu);
	}

	return choose_menu;
}