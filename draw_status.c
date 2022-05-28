#include <stdio.h>
#include "game.h"
#include "common.h"

void draw_status(PLAYER* player, SHOP_ITEM* shop_item)
{
	int POS_Y = 0;

	// 스탯창 프레임 출력
	draw_game(2);

	// 점수 출력
	gotoxy(66, 2);
	printf("SCORE");
	gotoxy(60, 4);
	printf("%16d", player->score);

	// 생명 출력
	POS_Y = 8;
	gotoxy(59, POS_Y);
	puts("생명");
	draw_symbol(POS_Y, 0, player->life);

	// 체력 출력
	POS_Y = 11;
	gotoxy(59, POS_Y);
	puts("체력: ");
	draw_symbol(POS_Y, 1, player->hp);

	// 폭탄 출력
	POS_Y = 14;
	gotoxy(59, POS_Y);
	puts("Z-폭탄: ");
	draw_symbol(POS_Y, 2, player->bomb_quantity);
	
	// 스킬 - 생명 회복
	POS_Y = 17;
	gotoxy(59, POS_Y);
	puts("X-생명: ");
	draw_symbol(POS_Y, 3, shop_item->life_plus);

	// 스킬 - HP 회복
	POS_Y = 20;
	gotoxy(59, POS_Y);
	puts("C-체력: ");
	draw_symbol(POS_Y, 4, shop_item->hp_recover);
}