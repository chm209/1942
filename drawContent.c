#include <stdio.h>
#include <stdlib.h>
#include "common.h"

// 화면번호를 입력받아 상황에 맞게 그려줌
void drawContent(int scr_num)
{
	switch (scr_num)
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
		gotoxy(51, 13);
		printf("1705095 이창민 기말 프로젝트");
		gotoxy(2, 29);
		printf("조작방법: 방향 ↑ ↓ ← → 선택 ENTER 아이템 Z X C");
		break;
	// 게임 화면
	case 1:
		for (int i = 0; i <= 30; i += 1)
		{
			gotoxy(4, i);
			printf(":");
			gotoxy(56, i);
			printf(":");
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
	}
}