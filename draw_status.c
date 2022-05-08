#include <stdio.h>
#include "game.h"
#include "common.h"

void draw_status(Player player, Bomb* bomb, Shop shop)
{
	// 좌표값 Y
	int STATUS_POS_Y = 0;

	// 생명 출력
	STATUS_POS_Y = 5;
	gotoxy(58, STATUS_POS_Y);
	puts("생명");
	draw_symbol(STATUS_POS_Y, 0, player.life);

	// 폭탄 출력
	STATUS_POS_Y = 8;
	gotoxy(58, STATUS_POS_Y);
	puts("폭탄");
	draw_symbol(STATUS_POS_Y, 1, bomb[0].count);
	
	// 체력 출력
	STATUS_POS_Y = 11;
	gotoxy(58, STATUS_POS_Y);
	puts("체력");
	draw_symbol(STATUS_POS_Y, 2, player.health);

	// 스킬 - 생명 회복
	STATUS_POS_Y = 14;
	gotoxy(58, STATUS_POS_Y);
	puts("생명 추가");
	draw_symbol(STATUS_POS_Y, 3, shop.life_plus);

	// 스킬 - HP 회복
	STATUS_POS_Y = 17;
	gotoxy(58, STATUS_POS_Y);
	puts("체력 회복");
	draw_symbol(STATUS_POS_Y, 4, shop.hp_plus);

	// 점수
	gotoxy(58, 2);
	puts("점수");
	gotoxy(58, 3);
	printf("%d", player.score);
}