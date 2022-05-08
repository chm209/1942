#include <stdio.h>
#include "game.h"
#include "common.h"

void draw_status(Player player, Bomb* bomb, Shop shop)
{
	// ��ǥ�� Y
	int STATUS_POS_Y = 0;
	draw_game(2);

	// ���� ���
	gotoxy(66, 2);
	puts("SCORE");
	gotoxy(60, 4);
	printf("%16d", player.score);

	// ���� ���
	STATUS_POS_Y = 8;
	gotoxy(66, STATUS_POS_Y);
	puts("����");
	draw_symbol(STATUS_POS_Y, 0, player.life);

	// ��ź ���
	STATUS_POS_Y = 20;
	gotoxy(66, STATUS_POS_Y);
	puts("��ź");
	draw_symbol(STATUS_POS_Y, 1, bomb[0].count);
	
	// ü�� ���
	STATUS_POS_Y = 14;
	gotoxy(66, STATUS_POS_Y);
	puts("ü��");
	draw_symbol(STATUS_POS_Y, 2, player.health);

	// ��ų - ���� ȸ��
	STATUS_POS_Y = 26;
	gotoxy(66, STATUS_POS_Y);
	puts("���� �߰�");
	draw_symbol(STATUS_POS_Y, 3, shop.life_plus);

	// ��ų - HP ȸ��
	STATUS_POS_Y = 26;
	gotoxy(66, STATUS_POS_Y);
	puts("ü�� ȸ��");
	draw_symbol(STATUS_POS_Y, 4, shop.hp_plus);
}