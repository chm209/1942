#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "game.h"

void draw_end_game(PLAYER* player, SHOP_ITEM* shop_item)
{
	draw_game(5);
	gotoxy(20, 6);
	printf("게임 결과");
	gotoxy(20, 8);
	printf("최고 점수: %d", user.score);
	gotoxy(20, 10);
	printf("이번판 점수: ");
	set_color(RED);
	gotoxy(33, 10);
	printf("%d", player->score);
	set_color(WHITE);
	gotoxy(20, 12);
	printf("기존 포인트: %d", user.point);
	gotoxy(20, 14);
	printf("획득 포인트: ");
	set_color(RED);
	gotoxy(33, 14);
	// 점수가 -일때
	if ((player->score * 0.5) < 0)
	{
		printf("0");
	}
	else
	{
		printf("%d", (int)(player->score * 0.5));
	}
	set_color(WHITE);
	gotoxy(20, 17);
	printf("아이템 사용 목록");
	gotoxy(20, 19);
	printf("생명 추가: ");
	gotoxy(20, 21);
	printf("체력 회복: ");
	gotoxy(20, 23);
	printf("추가 점수: ");

	if (user.item[2] > 0)
	{
		set_color(YELLOW);
		gotoxy(31, 23);
		printf("◎");
		set_color(WHITE);
	}
	else
	{
		set_color(WHITE);
		gotoxy(31, 23);
		printf("×");
	}

	if ((user.item[0] != shop_item->life_plus) && (user.item[1] != shop_item->hp_recover))
	{
		set_color(YELLOW);
		gotoxy(31, 19); // 생명 추가
		printf("◎");
		gotoxy(31, 21); // 체력 회복
		printf("◎");
		set_color(WHITE);
	}
	else if ((user.item[0] == shop_item->life_plus) && (user.item[1] != shop_item->hp_recover))
	{
		set_color(WHITE);
		gotoxy(31, 19); // 생명 추가
		printf("×");
		set_color(YELLOW);
		gotoxy(31, 21); // 체력 회복
		printf("◎");
		set_color(WHITE);
	}
	else if ((user.item[0] != shop_item->life_plus) && (user.item[1] == shop_item->hp_recover))
	{
		set_color(YELLOW);
		gotoxy(31, 19); // 생명 추가
		printf("◎");
		set_color(WHITE); 
		gotoxy(31, 21); // 체력 회복
		printf("×");
	}
	else if ((user.item[0] == shop_item->life_plus) && (user.item[1] == shop_item->hp_recover))
	{
		gotoxy(31, 19); // 생명 추가
		printf("×");
		gotoxy(31, 21); // 체력 회복
		printf("×");
	}
}