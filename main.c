#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "common.h"

int main(void)
{
	system("mode con: cols=100 lines=30");
	system("title 1705095 이창민 - 1942 프로젝트");
	cursor(0);

	int menu_num = 0, key = 0, position_y = 18;
	draw_content(0);

	while (position_y != 24)
	{
		// position_y = 18;

		while (key != ENTER)
		{
			gotoxy(57, position_y);
			printf("◀");
			key = _getch();
			gotoxy(57, position_y);
			printf("  ");
			// 키보드 동작 처리 (화면 번호, 동작, X, Y 값)
			position_y = action(0, key, 57, position_y);
		}

		switch (position_y)
		{
		// 로그인
		case 18:
			break;
		// 회원가입
		case 20:
			break;
		// 랭킹확인
		case 22:
			break;
		// 게임종료
		case 24:
			break;
		}
	}

	/*
	while (menu_num != 17)
	{
		MenuChoice = menu();

		switch (MenuChoice)
		{
		case 11:
			game();
			break;
		case 13:
			help(0);
			break;
		case 15:
			help(1);
			break;
		default:
			break;
		}
	}*/

	return 0;
}