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
		gotoxy(2, 1);
		puts("┏━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
		for (int i = 2; i < 24; i ++)
		{
			gotoxy(2, i);
			puts("┃");
			gotoxy(22, i);
			puts("┃");
			gotoxy(36, i);
			puts("┃");
			gotoxy(46, i);
			puts("┃");
			gotoxy(54, i);
			puts("┃");
			gotoxy(96, i);
			puts("┃");
		}
		for (int i = 3; i < 24; i += 2)
		{
			gotoxy(2, i);
			puts("┣━━━━━━━━━━━━━━━━━━━");
			gotoxy(22, i);
			puts("╋━━━━━━━━━━━━━");
			gotoxy(36, i);
			puts("╋━━━━━━━━━");
			gotoxy(46, i);
			puts("╋━━━━━━━");
			gotoxy(54, i);
			puts("┫");
		}
		gotoxy(36, 23);
		puts("┻━━━━━━━━━");
		gotoxy(46, 23);
		puts("┻━━━━━━━");
		gotoxy(2, 24);
		puts("┃");
		gotoxy(22, 24);
		puts("┃");
		gotoxy(54, 24);
		puts("┃");
		gotoxy(96, 24);
		puts("┃");
		gotoxy(2, 25);
		puts("┗━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
		break;
	case 4:
		gotoxy(3, 26);
		puts("치장 아이템은 하나씩만 소지 가능 합니다. / 구매시 기존 치장 아이템은 자동 판매 됩니다.");
		gotoxy(3, 28);
		puts("목록 이동: 방향키 ↑ ↓  ||  구매: ENTER                                   상점 나가기: ESC 키");
		gotoxy(11, 2);
		puts("항목");
		gotoxy(28, 2);
		puts("가격");
		gotoxy(39, 2);
		puts("보유수");
		gotoxy(49, 2);
		puts("선택");
		gotoxy(5, 4);
		puts("생명 추가");
		gotoxy(5, 6);
		puts("HP 회복");
		gotoxy(5, 8);
		puts("데미지 감소");
		gotoxy(5, 10);
		puts("추가 점수");
		gotoxy(5, 12);
		puts("빨강 페인트");
		gotoxy(5, 14);
		puts("파랑 페인트");
		gotoxy(5, 16);
		puts("노랑 페인트");
		gotoxy(5, 18);
		puts("빨간 총알");
		gotoxy(5, 20);
		puts("파란 총알");
		gotoxy(5, 22);
		puts("노란 총알");
		gotoxy(5, 24);
		puts("보유 포인트");
		break;
	}
}