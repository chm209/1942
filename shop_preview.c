#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void shop_preview(int list_num)
{
	for (int i = 4; i < 24; i++)
	{
		gotoxy(59, i);
		puts("                                     ");
	}

	gotoxy(59, 4);
	puts("[아이템 이름]");
	gotoxy(59, 7);
	puts("[아이템 설명]");
	gotoxy(59, 10);
	puts("[조건]");

	switch (list_num)
	{
	case 4:
		gotoxy(59, 5);
		puts("생명 추가");
		gotoxy(59, 8);
		puts("플레이어의 LIFE를 1 추가한다.");
		gotoxy(59, 11);
		puts("1. 플레이어의 체력이 3미만일때는");
		gotoxy(59, 12);
		puts("체력을 1 추가하고 폭탄 한발을");
		gotoxy(59, 13);
		puts("무료로 자동 발사 해준다.");
		gotoxy(59, 15);
		puts("2. 폭탄이 발사중인 상태에서는");
		gotoxy(59, 16);
		puts("폭탄의 개수를 1개 추가한다.");
		gotoxy(59, 18);
		puts("3. 플레이어의 체력이 3이라면");
		gotoxy(59, 19);
		puts("폭탄을 2개 추가한다.");
		gotoxy(59, 21);
		puts("4. 폭탄이 3개라면 추가 하지 않는다.");
		gotoxy(59, 23);
		puts("5. 최대 3개까지 보유 가능하다.");
		break;
	case 6:
		gotoxy(59, 5);
		puts("HP 회복");
		gotoxy(59, 8);
		puts("플레이어의 HP를 1 회복한다.");
		gotoxy(59, 11);
		puts("1. 연속 사용 가능");
		gotoxy(59, 13);
		puts("2. HP가 3일때는 사용 불가");
		gotoxy(59, 15);
		puts("3. 게임이 종료시 아이템 삭제");
		gotoxy(59, 17);
		puts("4. 최대 5개까지 보유 가능하다.");
		break;
	case 8:
		gotoxy(59, 5);
		puts("추가 점수");
		gotoxy(59, 8);
		puts("적 파괴시 추가 점수 획득 가능");
		gotoxy(59, 11);
		puts("1. 게임 시작시 자동 사용");
		gotoxy(59, 13);
		puts("2. 랭킹 확인시 아이템 사용 표시");
		gotoxy(59, 15);
		puts("3. 포인트 추가 획득 가능");
		gotoxy(59, 17);
		puts("4. 무제한 구매 가능");
		break;
	case 10:
		gotoxy(59, 5);
		puts("빨강 페인트");
		gotoxy(59, 8);
		puts("플레이어의 전투기 색상을 변경한다.");
		gotoxy(59, 11);
		puts("1. 다른 색상 구매시 자동 판매");
		gotoxy(59, 13);
		puts("2. 전투기 디자인 변경");
		gotoxy(59, 15);
		puts("3. 데미지 차이는 없다.");
		gotoxy(59, 18);
		puts("변경전\t\t변경후");
		gotoxy(59, 20);
		puts("[-*-]");
		gotoxy(80, 20);
		set_color(12);
		puts("<-*->");
		set_color(15);
		break;
	case 12:
		gotoxy(59, 5);
		puts("파랑 페인트");
		gotoxy(59, 8);
		puts("플레이어의 전투기 색상을 변경한다.");
		gotoxy(59, 11);
		puts("1. 다른 색상 구매시 자동 판매");
		gotoxy(59, 13);
		puts("2. 전투기 디자인 변경");
		gotoxy(59, 15);
		puts("3. 데미지 차이는 없다.");
		gotoxy(59, 18);
		puts("변경전\t\t변경후");
		gotoxy(59, 20);
		puts("[-*-]");
		gotoxy(80, 20);
		set_color(9);
		puts("{:*:}");
		set_color(15);
		break;
	case 14:
		gotoxy(59, 5);
		puts("노랑 페인트");
		gotoxy(59, 8);
		puts("플레이어의 전투기 색상을 변경한다.");
		gotoxy(59, 11);
		puts("1. 다른 색상 구매시 자동 판매");
		gotoxy(59, 13);
		puts("2. 전투기 디자인 변경");
		gotoxy(59, 15);
		puts("3. 데미지 차이는 없다.");
		gotoxy(59, 18);
		puts("변경전\t\t변경후");
		gotoxy(59, 20);
		puts("[-*-]");
		gotoxy(80, 20);
		set_color(14);
		puts("H:*:H");
		set_color(15);
		break;
	case 16:
		gotoxy(59, 5);
		puts("빨간 총알");
		gotoxy(59, 8);
		puts("플레이어의 총알 색상을 변경한다.");
		gotoxy(59, 11);
		puts("1. 다른 색상 구매시 자동 판매");
		gotoxy(59, 13);
		puts("2. 총알 디자인 변경");
		gotoxy(59, 15);
		puts("3. 데미지 차이는 없다.");
		gotoxy(59, 18);
		puts("변경전\t\t변경후");
		gotoxy(59, 20);
		puts("γ ψ Ψ");
		gotoxy(80, 20);
		set_color(12);
		puts("γ ψ Ψ");
		set_color(15);
		break;
	case 18:
		gotoxy(59, 5);
		puts("파란 총알");
		gotoxy(59, 8);
		puts("플레이어의 총알 색상을 변경한다.");
		gotoxy(59, 11);
		puts("1. 다른 색상 구매시 자동 판매");
		gotoxy(59, 13);
		puts("2. 총알 디자인 변경");
		gotoxy(59, 15);
		puts("3. 데미지 차이는 없다.");
		gotoxy(59, 18);
		puts("변경전\t\t변경후");
		gotoxy(59, 20);
		puts("＋ ± ÷");
		gotoxy(80, 20);
		set_color(9);
		puts("＋ ± ÷");
		set_color(15);
		break;
	case 20:
		gotoxy(59, 5);
		puts("노란 총알");
		gotoxy(59, 8);
		puts("플레이어의 총알 색상을 변경한다.");
		gotoxy(59, 11);
		puts("1. 다른 색상 구매시 자동 판매");
		gotoxy(59, 13);
		puts("2. 총알 디자인 변경");
		gotoxy(59, 15);
		puts("3. 데미지 차이는 없다.");
		gotoxy(59, 18);
		puts("변경전\t\t변경후");
		gotoxy(59, 20);
		puts("★ ♠ ♣");
		gotoxy(80, 20);
		set_color(14);
		puts("★ ♠ ♣");
		set_color(15);
		break;
	case 22:
		gotoxy(59, 5);
		puts("랭킹창 꾸미기");
		gotoxy(59, 8);
		puts("랭킹창의 유저명을 꾸며줍니다.");
		gotoxy(59, 11);
		puts("1. 선착순 고유 색상을 부여합니다.");
		gotoxy(59, 13);
		puts("2. 미정");
		break;
	}
}