#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void draw_game(int screen_num)
{
	switch (screen_num)
	{
	// 게임화면 - 조작 범위 프레임
	case 0:
		for (int i = 0; i < 30; i++)
		{
			gotoxy(4, i);
			printf(":");
			gotoxy(56, i);
			printf(":");
			// draw_content(0) 보면 printf 사용한 이유 나옴
		}
		break;
	// 게임화면 - PAUSE 화면
	case 1:
		gotoxy(16, 10);
		puts("PAUSE");
		gotoxy(15, 11);
		puts("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
		gotoxy(15, 12);
		printf("┃  게임을 종료 하시겠습니까?  ┃");
		gotoxy(15, 13);
		puts("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫");
		gotoxy(15, 14);
		printf("┃   예 (  )  │  아니요 (  )   ┃");
		gotoxy(15, 15);
		puts("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
		break;
	// 스탯창
	case 2:
		gotoxy(58, 1);
		printf("┏━━━━━━━━━━━━━━━━━━┓");
		gotoxy(58, 2);
		printf("┃                  ┃");
		gotoxy(58, 3);
		printf("┣━━━━━━━━━━━━━━━━━━┫");
		gotoxy(58, 4);
		printf("┃                  ┃");
		gotoxy(58, 5);
		printf("┗━━━━━━━━━━━━━━━━━━┛");
		gotoxy(59, 6);
		printf("ㆍㆍㆍㆍㆍㆍㆍㆍㆍㆍ");
		break;
	}
}