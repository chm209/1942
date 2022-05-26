#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void shop_preview(int list_num)
{
	for (int i = 4; i < 24; i++)
	{
		gotoxy(59, i);
		printf("                                     ");
	}

	gotoxy(59, 4);
	printf("[아이템 이름]");
	gotoxy(59, 7);
	printf("[아이템 설명]");
	gotoxy(59, 10);
	printf("[조건]");

	switch (list_num)
	{
	case 4:
		gotoxy(59, 5);
		printf("생명 추가");
		gotoxy(59, 8);
		printf("플레이어의 LIFE를 1 추가한다.");
		gotoxy(59, 11);
		printf("1. 플레이어의 체력이 3미만일때는");
		gotoxy(59, 12);
		printf("체력을 1 추가하고 폭탄 한발을");
		gotoxy(59, 13);
		printf("무료로 자동 발사 해준다.");
		gotoxy(59, 15);
		printf("2. 폭탄이 발사중인 상태에서는");
		gotoxy(59, 16);
		printf("폭탄의 개수를 1개 추가한다.");
		gotoxy(59, 18);
		printf("3. 플레이어의 체력이 3이라면");
		gotoxy(59, 19);
		printf("폭탄을 2개 추가한다.");
		gotoxy(59, 21);
		printf("4. 폭탄이 3개라면 추가 하지 않는다.");
		gotoxy(59, 23);
		printf("5. 최대 3개까지 보유 가능하다.");
		break;
	case 6:
		gotoxy(59, 5);
		printf("HP 회복");
		gotoxy(59, 8);
		printf("플레이어의 HP를 1 회복한다.");
		gotoxy(59, 11);
		printf("1. 연속 사용 가능");
		gotoxy(59, 13);
		printf("2. HP가 3일때는 사용 불가");
		gotoxy(59, 15);
		printf("3. 게임이 종료시 아이템 삭제");
		gotoxy(59, 17);
		printf("4. 최대 5개까지 보유 가능하다.");
		break;
	case 8:
		gotoxy(59, 5);
		printf("추가 점수");
		gotoxy(59, 8);
		printf("적 파괴시 추가 점수 획득 가능");
		gotoxy(59, 11);
		printf("1. 게임 시작시 자동 사용");
		gotoxy(59, 13);
		printf("2. 랭킹 확인시 아이템 사용 표시");
		gotoxy(59, 15);
		printf("3. 포인트 추가 획득 가능");
		gotoxy(59, 17);
		printf("4. 무제한 구매 가능");
		break;
	case 10:
		gotoxy(59, 5);
		printf("빨강 페인트");
		gotoxy(59, 8);
		printf("플레이어의 전투기 색상을 변경한다.");
		gotoxy(59, 11);
		printf("1. 다른 색상 구매시 자동 판매");
		gotoxy(59, 13);
		printf("2. 전투기 디자인 변경");
		gotoxy(59, 15);
		printf("3. 데미지 차이는 없다.");
		gotoxy(59, 18);
		printf("변경전\t\t변경후");
		gotoxy(59, 20);
		printf("[-*-]");
		gotoxy(80, 20);
		set_color(RED);
		printf("<-*->");
		set_color(WHITE);
		break;
	case 12:
		gotoxy(59, 5);
		printf("파랑 페인트");
		gotoxy(59, 8);
		printf("플레이어의 전투기 색상을 변경한다.");
		gotoxy(59, 11);
		printf("1. 다른 색상 구매시 자동 판매");
		gotoxy(59, 13);
		printf("2. 전투기 디자인 변경");
		gotoxy(59, 15);
		printf("3. 데미지 차이는 없다.");
		gotoxy(59, 18);
		printf("변경전\t\t변경후");
		gotoxy(59, 20);
		printf("[-*-]");
		gotoxy(80, 20);
		set_color(BLUE);
		printf("{:*:}");
		set_color(WHITE);
		break;
	case 14:
		gotoxy(59, 5);
		printf("노랑 페인트");
		gotoxy(59, 8);
		printf("플레이어의 전투기 색상을 변경한다.");
		gotoxy(59, 11);
		printf("1. 다른 색상 구매시 자동 판매");
		gotoxy(59, 13);
		printf("2. 전투기 디자인 변경");
		gotoxy(59, 15);
		printf("3. 데미지 차이는 없다.");
		gotoxy(59, 18);
		printf("변경전\t\t변경후");
		gotoxy(59, 20);
		printf("[-*-]");
		gotoxy(80, 20);
		set_color(YELLOW);
		printf("H:*:H");
		set_color(WHITE);
		break;
	case 16:
		gotoxy(59, 5);
		printf("빨간 총알");
		gotoxy(59, 8);
		printf("플레이어의 총알 색상을 변경한다.");
		gotoxy(59, 11);
		printf("1. 다른 색상 구매시 자동 판매");
		gotoxy(59, 13);
		printf("2. 총알 디자인 변경");
		gotoxy(59, 15);
		printf("3. 데미지 차이는 없다.");
		gotoxy(59, 18);
		printf("변경전\t\t변경후");
		gotoxy(59, 20);
		printf("ⅰ ⅱ ⅲ");
		gotoxy(80, 20);
		set_color(RED);
		printf("γ ψ Ψ");
		set_color(WHITE);
		break;
	case 18:
		gotoxy(59, 5);
		printf("파란 총알");
		gotoxy(59, 8);
		printf("플레이어의 총알 색상을 변경한다.");
		gotoxy(59, 11);
		printf("1. 다른 색상 구매시 자동 판매");
		gotoxy(59, 13);
		printf("2. 총알 디자인 변경");
		gotoxy(59, 15);
		printf("3. 데미지 차이는 없다.");
		gotoxy(59, 18);
		printf("변경전\t\t변경후");
		gotoxy(59, 20);
		printf("ⅰ ⅱ ⅲ");
		gotoxy(80, 20);
		set_color(BLUE);
		printf("＋ ± ÷");
		set_color(WHITE);
		break;
	case 20:
		gotoxy(59, 5);
		printf("노란 총알");
		gotoxy(59, 8);
		printf("플레이어의 총알 색상을 변경한다.");
		gotoxy(59, 11);
		printf("1. 다른 색상 구매시 자동 판매");
		gotoxy(59, 13);
		printf("2. 총알 디자인 변경");
		gotoxy(59, 15);
		printf("3. 데미지 차이는 없다.");
		gotoxy(59, 18);
		printf("변경전\t\t변경후");
		gotoxy(59, 20);
		printf("ⅰ ⅱ ⅲ");
		gotoxy(80, 20);
		set_color(YELLOW);
		printf("★ ♠ ♣");
		set_color(WHITE);
		break;
	case 22:
		gotoxy(59, 5);
		printf("랭킹창 꾸미기");
		gotoxy(59, 8);
		printf("랭킹창의 유저명을 꾸며줍니다.");
		gotoxy(59, 11);
		printf("1. 랜덤 색상을 부여합니다.");
		gotoxy(59, 13);
		printf("2. 색상은 14가지 입니다.");
		gotoxy(59, 15);
		printf("2. 재구매시 색상이 변경 됩니다.");
		break;
	}
}