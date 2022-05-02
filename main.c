#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "common.h"
#define POS_X 59

int main(void)
{
	system("mode con: cols=100 lines=30");
	system("title 1705095 이창민 - 1942 프로젝트");
	cursor(0); // 0은 커서 가림, 1은 커서 보임
	
	int login_chk = 0;
	int menu_num = 18;
	int key = 0;

	while (menu_num != 24)
	{
		system("cls");
		draw_content(0);

		switch (login_chk)
		{
		default: // 비로그인
			gotoxy(39, 18);
			puts("로그인");
			gotoxy(39, 20);
			puts("회원가입");
			gotoxy(39, 22);
			puts("랭킹화면");
			gotoxy(39, 24);
			puts("게임종료");
			break;
		case 1: // 로그인
			gotoxy(39, 18);
			puts("게임시작");
			gotoxy(39, 20);
			puts("상점");
			gotoxy(39, 22);
			puts("랭킹확인");
			gotoxy(39, 24);
			puts("게임종료");
			break;
		}

		while (key != ENTER)
		{
			gotoxy(POS_X, menu_num);
			puts("◀");
			key = getch();
			gotoxy(POS_X, menu_num);
			puts("  ");
			// 화면번호, 입력받은 키 값, X 값, Y 값
			menu_num = move(0, key, POS_X, menu_num);
		}
		key = 0;

		switch (menu_num)
		{
		case 18:
			login_chk % 2 == 0 ? login_chk = login(1) : game();
			system("mode con: cols=100 lines=30");
			break;
		case 20:
			login_chk % 2 == 0 ? login_chk = login(0) : shop();
			break;
		case 22:
			// login_chk % 2 == 0 ? ranking(0) : ranking(1);
			break;
		case 24:
			break;
		}
	}
	return 0;
}