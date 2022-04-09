#include <stdio.h>
#include "game.h"
#include "common.h"

void draw_stat(Player player, Bomb* bomb)
{
	int pos_y = 0;
	
	// »ý¸í
	pos_y = 5;
	gotoxy(58, pos_y);
	puts("LIFE");
	draw_symbol(pos_y, 1, player.life);

	// ÆøÅº
	pos_y = 8;
	gotoxy(58, pos_y);
	puts("BOMB");
	draw_symbol(pos_y, 2, bomb[0].count);

	// Ã¼·Â
	pos_y = 11;
	gotoxy(58, pos_y);
	puts("HP");
	draw_symbol(pos_y, 3, player.health);

	// Á¡¼ö
	gotoxy(58, 2);
	puts("SCORE");
	gotoxy(58, 3);
	printf("%d", player.score);
}