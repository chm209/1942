#include <stdio.h>
#include "common.h"

void draw_content(int screen_number)
{
	switch (screen_number)
	{
	// 메인 화면
	case 0:
		system("cls");
		// 1
		gotoxy(25, 3);
		printf("▥▥");
		gotoxy(23, 4);
		printf("▨▥▥");
		gotoxy(21, 5);
		printf("▨▨▥▥");
		gotoxy(25, 6);
		printf("▥▥");
		gotoxy(25, 7);
		printf("▥▥");
		gotoxy(25, 8);
		printf("▥▥");
		gotoxy(25, 9);
		printf("▥▥");
		gotoxy(21, 10);
		printf("▤▤▥▥▤▤");
		gotoxy(21, 11);
		printf("▤▤▥▥▤▤");
		// 9
		gotoxy(35, 3);
		printf("▩▤▤▥▥");
		gotoxy(35, 4);
		printf("▥    ▥▥");
		gotoxy(35, 5);
		printf("▥    ▥▥");
		gotoxy(35, 6);
		printf("▩▤▤▥▥");
		gotoxy(41, 7);
		printf("▥▥");
		gotoxy(41, 8);
		printf("▥▥");
		gotoxy(41, 9);
		printf("▥▥");
		gotoxy(41, 10);
		printf("▥▥");
		gotoxy(41, 11);
		printf("▥▥");
		// 4
		gotoxy(49, 3);
		printf("▥    ▥▥");
		gotoxy(49, 4);
		printf("▥    ▥▥");
		gotoxy(49, 5);
		printf("▥    ▥▥");
		gotoxy(49, 6);
		printf("▥    ▥▥");
		gotoxy(49, 7);
		printf("▩▤▤▥▥▤▤");
		gotoxy(55, 8);
		printf("▥▥");
		gotoxy(55, 9);
		printf("▥▥");
		gotoxy(55, 10);
		printf("▥▥");
		gotoxy(55, 11);
		printf("▥▥");
		// 2
		gotoxy(65, 3);
		printf("▤▤▤▤▤▥▩");
		gotoxy(65, 4);
		printf("▤▤▤▤▤▥▥");
		gotoxy(75, 5);
		printf("▥▥");
		gotoxy(75, 6);
		printf("▥▥");
		gotoxy(65, 7);
		printf("▩▥▤▤▤▥▥");
		gotoxy(65, 8);
		printf("▥▥▤▤▤▥▩");
		gotoxy(65, 9);
		printf("▥▥");
		gotoxy(65, 10);
		printf("▥▥");
		gotoxy(65, 11);
		printf("▩▥▤▤▤▤▤");
		// 기타
		gotoxy(51, 13);
		printf("1705095 이창민 기말 프로젝트");
		gotoxy(41, 18);
		printf("로그인");
		gotoxy(41, 20);
		printf("회원가입");
		gotoxy(41, 22);
		printf("랭킹확인");
		gotoxy(41, 24);
		printf("게임종료");
		gotoxy(2, 29);
		printf("조작방법: 방향 ↑ ↓ ← → 선택 ENTER");
	}
}