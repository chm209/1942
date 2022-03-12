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

	while (position_y != 24)
	{
		system("cls");
		draw_content(0);

		switch (menu_num)
		{
		default:
			gotoxy(39, 18);
			printf("로그인");
			gotoxy(39, 20);
			printf("회원가입");
			gotoxy(39, 22);
			printf("랭킹화면");
			gotoxy(39, 24);
			printf("게임종료");
			break;
		case 1:
			gotoxy(39, 18);
			printf("게임시작");
			gotoxy(39, 20);
			printf("상점");
			gotoxy(39, 22);
			printf("랭킹확인");
			gotoxy(39, 24);
			printf("게임종료");
			break;
		}

		while (key != ENTER)
		{
			gotoxy(59, position_y);
			printf("◀");
			key = _getch();
			gotoxy(59, position_y);
			printf("  ");
			// 키보드 동작 처리 (화면 번호, 동작, X, Y 값)
			position_y = action(0, key, 59, position_y);
		}

		switch (position_y)
		{
		// 0번 로그인 1번 게임시작
		case 18:
			menu_num = login(1);
			// menu_num % 2 == 0 ? menu_num = login(1) : game();
			break;
		// 0번 회원가입 1번 상점
		case 20:
			menu_num % 2 == 0 ? menu_num = login(0) : shop();
			break;
		// 랭킹확인 0번 비회원 1번 회원
		case 22:
			menu_num % 2 == 0 ? ranking(0) : ranking(1);
			break;
		// 게임종료
		case 24:
			break;
		}

		key = 0;
	}

	return 0;
}