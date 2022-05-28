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
	// 게임오버 글자 출력
	case 3:
		gotoxy(16, 3);
		printf("GAME OVER");
		gotoxy(16, 26);
		system("pause");
		break;
	// 게임클리어 글자 출력
	case 4:
		gotoxy(16, 3);
		printf("GAME CLEAR");
		gotoxy(16, 26);
		system("pause");
		break;
	// game_help, 엔딩 화면
	case 5:
		gotoxy(15, 4);
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
		gotoxy(15, 5);
		printf("┃                                              ┃");
		gotoxy(15, 6);
		printf("┃                                              ┃");
		gotoxy(15, 7);
		printf("┃                                              ┃");
		gotoxy(15, 8);
		printf("┃                                              ┃");
		gotoxy(15, 9);
		printf("┃                                              ┃");
		gotoxy(15, 10);
		printf("┃                                              ┃");
		gotoxy(15, 11);
		printf("┃                                              ┃");
		gotoxy(15, 12);
		printf("┃                                              ┃");
		gotoxy(15, 13);
		printf("┃                                              ┃");
		gotoxy(15, 14);
		printf("┃                                              ┃");
		gotoxy(15, 15);
		printf("┃                                              ┃");
		gotoxy(15, 16);
		printf("┃                                              ┃");
		gotoxy(15, 17);
		printf("┃                                              ┃");
		gotoxy(15, 18);
		printf("┃                                              ┃");
		gotoxy(15, 19);
		printf("┃                                              ┃");
		gotoxy(15, 20);
		printf("┃                                              ┃");
		gotoxy(15, 21);
		printf("┃                                              ┃");
		gotoxy(15, 22);
		printf("┃                                              ┃");
		gotoxy(15, 23);
		printf("┃                                              ┃");
		gotoxy(15, 24);
		printf("┃                                              ┃");
		gotoxy(15, 25);
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
		break;
	// game_help 화면
	case 6:
		gotoxy(20, 6);
		printf("게임 조작 방법");
		gotoxy(20, 8);
		printf("움직이기: 방향키");
		gotoxy(20, 10);
		printf("기본 공격: 스페이스바");
		gotoxy(20, 12);
		printf("폭탄 공격: Z 키");
		gotoxy(20, 14);
		printf("생명 추가 아이템: X 키");
		gotoxy(20, 16);
		printf("체력 회복 아이템: C 키");
		set_color(RED);
		gotoxy(20, 18);
		printf("추가 점수 아이템은 자동 적용됩니다.");
		set_color(WHITE);
		gotoxy(20, 21);
		printf("적 기체별 획득 점수가 다릅니다.");
		gotoxy(20, 23);
		printf("상점 아이템 이용시 점수가 차감됩니다.");
		break;
	}
}