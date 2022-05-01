#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void draw_content(int screen_num)
{
	switch (screen_num)
	{
	// 메인 화면
	case 0:
		system("cls");
		// 1
		gotoxy(25, 3);
		puts("▥▥");
		gotoxy(23, 4);
		puts("▨▥▥");
		gotoxy(21, 5);
		puts("▨▨▥▥");
		gotoxy(25, 6);
		puts("▥▥");
		gotoxy(25, 7);
		puts("▥▥");
		gotoxy(25, 8);
		puts("▥▥");
		gotoxy(25, 9);
		puts("▥▥");
		gotoxy(21, 10);
		puts("▤▤▥▥▤▤");
		gotoxy(21, 11);
		puts("▤▤▥▥▤▤");
		// 9
		gotoxy(35, 3);
		puts("▩▤▤▥▥");
		gotoxy(35, 4);
		puts("▥    ▥▥");
		gotoxy(35, 5);
		puts("▥    ▥▥");
		gotoxy(35, 6);
		puts("▩▤▤▥▥");
		gotoxy(41, 7);
		puts("▥▥");
		gotoxy(41, 8);
		puts("▥▥");
		gotoxy(41, 9);
		puts("▥▥");
		gotoxy(41, 10);
		puts("▥▥");
		gotoxy(41, 11);
		puts("▥▥");
		// 4
		gotoxy(49, 3);
		puts("▥    ▥▥");
		gotoxy(49, 4);
		puts("▥    ▥▥");
		gotoxy(49, 5);
		puts("▥    ▥▥");
		gotoxy(49, 6);
		puts("▥    ▥▥");
		gotoxy(49, 7);
		puts("▩▤▤▥▥▤▤");
		gotoxy(55, 8);
		puts("▥▥");
		gotoxy(55, 9);
		puts("▥▥");
		gotoxy(55, 10);
		puts("▥▥");
		gotoxy(55, 11);
		puts("▥▥");
		// 2
		gotoxy(65, 3);
		puts("▤▤▤▤▤▥▩");
		gotoxy(65, 4);
		puts("▤▤▤▤▤▥▥");
		gotoxy(75, 5);
		puts("▥▥");
		gotoxy(75, 6);
		puts("▥▥");
		gotoxy(65, 7);
		puts("▩▥▤▤▤▥▥");
		gotoxy(65, 8);
		puts("▥▥▤▤▤▥▩");
		gotoxy(65, 9);
		puts("▥▥");
		gotoxy(65, 10);
		puts("▥▥");
		gotoxy(65, 11);
		puts("▩▥▤▤▤▤▤");
		gotoxy(51, 13);
		puts("1705095 이창민 기말 프로젝트");
		gotoxy(2, 29);
		puts("조작방법: 방향 ↑ ↓ ← → 선택 ENTER 아이템 Z X");
		break;
	// 게임 화면
	case 1:
		for (int i = 0; i <= 30; i += 1)
		{
			gotoxy(4, i);
			puts(":");
			gotoxy(56, i);
			puts(":");
		}
		break;
	// pause 화면
	case 2:
		gotoxy(16, 10);
		puts("PAUSE");
		gotoxy(15, 11);
		puts("┌─────────────────────────────┐");
		gotoxy(15, 12);
		puts("│  게임을 종료 하시겠습니까?  │");
		gotoxy(15, 13);
		puts("├─────────────────────────────┤");
		gotoxy(15, 14);
		puts("│   예 (  )  │  아니요 (  )   │");
		gotoxy(15, 15);
		puts("└─────────────────────────────┘");
		break;
	// 상점 화면
	case 3:
		gotoxy(4, 1);
		puts("┌─────────────────────────────────────────────────────────┐");
		break;
	}
}