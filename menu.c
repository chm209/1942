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
		puts("���� ��");
		user_input = getch();
		gotoxy(MENU_POS_X, choose_menu);
		puts("       ");
		// ȭ���ȣ, �Է¹��� Ű ��, X ��, Y ��
		choose_menu = move(0, user_input, MENU_POS_X, choose_menu);
	}

	return choose_menu;
}