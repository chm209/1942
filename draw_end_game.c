#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "game.h"

void draw_end_game(PLAYER* player, SHOP_ITEM* shop_item)
{
	system("cls");
	// 80 30
	gotoxy(15, 4);
	printf("������������������������������������������������������������������������������������������������");
	gotoxy(15, 5);
	printf("��                                              ��");
	gotoxy(15, 6);
	printf("��                                              ��");
	gotoxy(15, 7);
	printf("��                                              ��");
	gotoxy(15, 8);
	printf("��                                              ��");
	gotoxy(15, 9);
	printf("��                                              ��");
	gotoxy(15, 10);
	printf("��                                              ��");
	gotoxy(15, 11);
	printf("��                                              ��");
	gotoxy(15, 12);
	printf("��                                              ��");
	gotoxy(15, 13);
	printf("��                                              ��");
	gotoxy(15, 14);
	printf("��                                              ��");
	gotoxy(15, 15);
	printf("��                                              ��");
	gotoxy(15, 16);
	printf("��                                              ��");
	gotoxy(15, 17);
	printf("��                                              ��");
	gotoxy(15, 18);
	printf("��                                              ��");
	gotoxy(15, 19);
	printf("��                                              ��");
	gotoxy(15, 20);
	printf("��                                              ��");
	gotoxy(15, 21);
	printf("��                                              ��");
	gotoxy(15, 22);
	printf("��                                              ��");
	gotoxy(15, 23);
	printf("��                                              ��");
	gotoxy(15, 24);
	printf("��                                              ��");
	gotoxy(15, 25);
	printf("������������������������������������������������������������������������������������������������");


	gotoxy(20, 6);
	printf("���� ���");
	gotoxy(20, 8);
	printf("�ְ� ����: %d", user.score);
	gotoxy(20, 10);
	printf("�̹��� ����: ");
	set_color(RED);
	gotoxy(33, 10);
	printf("%d", player->score);
	set_color(WHITE);
	gotoxy(20, 12);
	printf("���� ����Ʈ: %d", user.point);
	gotoxy(20, 14);
	printf("ȹ�� ����Ʈ: ");
	set_color(RED);
	gotoxy(33, 14);

	// ������ -�϶�
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
	printf("������ ��� ���");
	gotoxy(20, 19);
	printf("���� �߰�: ");
	gotoxy(20, 21);
	printf("ü�� ȸ��: ");
	gotoxy(20, 23);
	printf("�߰� ����: ");

	if (user.item[2] > 0)
	{
		set_color(YELLOW);
		gotoxy(31, 23);
		printf("��");
		set_color(WHITE);
	}
	else
	{
		set_color(WHITE);
		gotoxy(31, 23);
		printf("��");
	}

	if ((user.item[0] != shop_item->life_plus) && (user.item[1] != shop_item->hp_recover))
	{
		set_color(YELLOW);
		gotoxy(31, 19); // ���� �߰�
		printf("��");
		gotoxy(31, 21); // ü�� ȸ��
		printf("��");
		set_color(WHITE);
	}
	else if ((user.item[0] == shop_item->life_plus) && (user.item[1] != shop_item->hp_recover))
	{
		set_color(WHITE);
		gotoxy(31, 19); // ���� �߰�
		printf("��");
		set_color(YELLOW);
		gotoxy(31, 21); // ü�� ȸ��
		printf("��");
		set_color(WHITE);
	}
	else if ((user.item[0] != shop_item->life_plus) && (user.item[1] == shop_item->hp_recover))
	{
		set_color(YELLOW);
		gotoxy(31, 19); // ���� �߰�
		printf("��");
		set_color(WHITE); 
		gotoxy(31, 21); // ü�� ȸ��
		printf("��");
	}
	else if ((user.item[0] == shop_item->life_plus) && (user.item[1] == shop_item->hp_recover))
	{
		gotoxy(31, 19); // ���� �߰�
		printf("��");
		gotoxy(31, 21); // ü�� ȸ��
		printf("��");
	}

	gotoxy(16, 26); // ü�� ȸ��
	system("pause");
}