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
	case 2:
		gotoxy(58, 1);
		puts("┏━━━━━━━━━━━━━━━━━━┓");
		gotoxy(58, 2);
		puts("┃                  ┃");
		gotoxy(58, 3);
		puts("┣━━━━━━━━━━━━━━━━━━┫");
		gotoxy(58, 4);
		puts("┃                  ┃");
		gotoxy(58, 5);
		puts("┗━━━━━━━━━━━━━━━━━━┛");
		gotoxy(59, 6);
		puts("ㆍㆍㆍㆍㆍㆍㆍㆍㆍㆍ");
		gotoxy(58, 7);
		puts("┏━━━━━━━━━━━━━━━━━━┓");
		gotoxy(58, 8);
		puts("┃                  ┃");
		gotoxy(58, 9);
		puts("┣━━━━━━━━━━━━━━━━━━┫");
		gotoxy(58, 10);
		puts("┃                  ┃");
		gotoxy(58, 11);
		puts("┗━━━━━━━━━━━━━━━━━━┛");
		gotoxy(59, 12);
		puts("ㆍㆍㆍㆍㆍㆍㆍㆍㆍㆍ");
		gotoxy(58, 13);
		puts("┏━━━━━━━━━━━━━━━━━━┓");
		gotoxy(58, 14);
		puts("┃                  ┃");
		gotoxy(58, 15);
		puts("┣━━━━━━━━━━━━━━━━━━┫");
		gotoxy(58, 16);
		puts("┃                  ┃");
		gotoxy(58, 17);
		puts("┗━━━━━━━━━━━━━━━━━━┛");
		gotoxy(59, 18);
		puts("ㆍㆍㆍㆍㆍㆍㆍㆍㆍㆍ");
		gotoxy(58, 19);
		puts("┏━━━━━━━━━━━━━━━━━━┓");
		gotoxy(58, 20);
		puts("┃                  ┃");
		gotoxy(58, 21);
		puts("┣━━━━━━━━━━━━━━━━━━┫");
		gotoxy(58, 22);
		puts("┃                  ┃");
		gotoxy(58, 23);
		puts("┗━━━━━━━━━━━━━━━━━━┛");
		gotoxy(59, 24);
		puts("ㆍㆍㆍㆍㆍㆍㆍㆍㆍㆍ");
		gotoxy(58, 25);
		puts("┏━━━━━━━━━━━━━━━━━━┓");
		gotoxy(58, 26);
		puts("┃                  ┃");
		gotoxy(58, 27);
		puts("┣━━━━━━━━━━━━━━━━━━┫");
		gotoxy(58, 28);
		puts("┃                  ┃");
		gotoxy(58, 29);
		printf("┗━━━━━━━━━━━━━━━━━━┛");
		break;
	}
}