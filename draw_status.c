#include <stdio.h>
#include "game.h"
#include "common.h"

void draw_status(PLAYER* player, SHOP_ITEM* shop_item)
{
	int POS_Y = 0;

	// ����â ������ ���
	draw_game(2);

	// ���� ���
	gotoxy(66, 2);
	printf("SCORE");
	gotoxy(60, 4);
	printf("%16d", player->score);

	// ���� ���
	POS_Y = 8;
	gotoxy(59, POS_Y);
	puts("����");
	draw_symbol(POS_Y, 0, player->life);

	// ü�� ���
	POS_Y = 11;
	gotoxy(59, POS_Y);
	puts("ü��: ");
	draw_symbol(POS_Y, 1, player->hp);

	// ��ź ���
	POS_Y = 14;
	gotoxy(59, POS_Y);
	puts("Z-��ź: ");
	draw_symbol(POS_Y, 2, player->bomb_quantity);
	
	// ��ų - ���� ȸ��
	POS_Y = 17;
	gotoxy(59, POS_Y);
	puts("X-����: ");
	draw_symbol(POS_Y, 3, shop_item->life_plus);

	// ��ų - HP ȸ��
	POS_Y = 20;
	gotoxy(59, POS_Y);
	puts("C-ü��: ");
	draw_symbol(POS_Y, 4, shop_item->hp_recover);
}