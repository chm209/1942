#include <stdio.h>
#include "game.h"
#include "common.h"

void drawStat(Player player, Bomb* bomb)
{
	int pos_y = 0;
	
	// ����
	pos_y = 5;
	gotoxy(58, pos_y);
	printf("LIFE");
	drawSymbol(pos_y, 1, player.life);

	// ��ź
	pos_y = 8;
	gotoxy(58, pos_y);
	printf("BOMB");
	drawSymbol(pos_y, 2, bomb[0].count);

	// ü��
	pos_y = 11;
	gotoxy(58, pos_y);
	printf("HP");
	drawSymbol(pos_y, 3, player.health);

	// ����
	gotoxy(58, 2);
	printf("SCORE");
	gotoxy(58, 3);
	printf("%d", player.score);
}