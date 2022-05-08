#include <stdio.h>
#include "game.h"
#include "common.h"

void draw_status(Player player, Bomb* bomb, Shop shop)
{
	// ��ǥ�� Y
	int STATUS_POS_Y = 0;

	// ���� ���
	STATUS_POS_Y = 5;
	gotoxy(58, STATUS_POS_Y);
	puts("����");
	draw_symbol(STATUS_POS_Y, 0, player.life);

	// ��ź ���
	STATUS_POS_Y = 8;
	gotoxy(58, STATUS_POS_Y);
	puts("��ź");
	draw_symbol(STATUS_POS_Y, 1, bomb[0].count);
	
	// ü�� ���
	STATUS_POS_Y = 11;
	gotoxy(58, STATUS_POS_Y);
	puts("ü��");
	draw_symbol(STATUS_POS_Y, 2, player.health);

	// ��ų - ���� ȸ��
	STATUS_POS_Y = 14;
	gotoxy(58, STATUS_POS_Y);
	puts("���� �߰�");
	draw_symbol(STATUS_POS_Y, 3, shop.life_plus);

	// ��ų - HP ȸ��
	STATUS_POS_Y = 17;
	gotoxy(58, STATUS_POS_Y);
	puts("ü�� ȸ��");
	draw_symbol(STATUS_POS_Y, 4, shop.hp_plus);

	// ����
	gotoxy(58, 2);
	puts("����");
	gotoxy(58, 3);
	printf("%d", player.score);
}