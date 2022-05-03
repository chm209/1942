#include <stdio.h>
#include "game.h"
#include "common.h"

void draw_stat(Player player, Bomb* bomb, Shop shop)
{
	int pos_y = 0;
	
	// 생명
	pos_y = 5;
	gotoxy(58, pos_y);
	puts("LIFE");
	draw_symbol(pos_y, 1, player.life);

	// 폭탄
	pos_y = 8;
	gotoxy(58, pos_y);
	puts("BOMB");
	draw_symbol(pos_y, 2, bomb[0].count);

	// 체력
	pos_y = 11;
	gotoxy(58, pos_y);
	puts("HP");
	draw_symbol(pos_y, 3, player.health);

	// 스킬 - 생명 회복
	pos_y = 14;
	gotoxy(58, pos_y);
	puts("LIFE 추가");
	draw_symbol(pos_y, 4, shop.life_plus);

	// 스킬 - HP 회복
	pos_y = 17;
	gotoxy(58, pos_y);
	puts("HP 회복");
	draw_symbol(pos_y, 5, shop.hp_plus);

	// 점수
	gotoxy(58, 2);
	puts("SCORE");
	gotoxy(58, 3);
	printf("%d", player.score);
}