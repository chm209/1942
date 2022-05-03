#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // GetAsyncKeyState ����� ����
#include "common.h"
#include "game.h"

void game(void)
{
	system("mode con: cols=80 lines=32");
	system("cls");
	
	// �÷��̾� - ��ź, ��ų, ���� ����
	Player player = { 28, 28, 1, 3, 0 }; // X��, Y��, ����, ü��, ����
	Bullet bullet[BULLET_SIZE] = { 0, }; // X��, Y��, Ȯ��
	Item item[ITEM_SIZE] = { 0, };
	Bomb bomb[BOMB_SIZE] = { 29, 24, 1, 5, FALSE, 6, 24, 0, 5, FALSE }; // X��, Y��, �ܷ�, �ӵ�, Ȯ��
	Bomb_blt bomb_bul[BOMB_BUL_SIZE] = { 0, };
	Bomb_blt bomb_bul2[BOMB_BUL_SIZE] = { 0, };
	Shop shop = { 0, 0, 0, 0, 2, 1}; // ġ�� �������� ��� 0�� �⺻ Ÿ���� �ǹ�

	// ����
	int frame_count = 0; // �������� ������
	Enemy enemy[ENEMY_SIZE] = { 0, };

	// �÷��̾� ����� ����
	switch (shop.paint_color)
	{
	case 0:
		player.shape = "[-*-]";
		player.color = 15;
		break;
	case 1:
		player.shape = "<-*->";
		player.color = 12;
		break;
	case 2:
		player.shape = "{:*:}";
		player.color = 9;
		break;
	case 3:
		player.shape = "H:*:H";
		player.color = 14;
		break;
	}

	// �÷��̾� �Ѿ� ����
	switch (shop.bullet_color)
	{
	case 0:
		bullet->shape = "��";
		bullet->color = 15;
		break;
	case 1:
		bullet->shape = "��";
		bullet->color = 12;
		break;
	case 2:
		bullet->shape = "��";
		bullet->color = 9;
		break;
	case 3:
		bullet->shape = "��";
		bullet->color = 14;
		break;
	}

	while (1)
	{
		draw_content(1);
		draw_stat(player, bomb, shop);
		gotoxy(player.pos_x, player.pos_y);
		set_color(player.color);
		puts(player.shape);
		set_color(15);

		// ���� Ű���� ����
		// GetAsyncKeyState()�� ��� �����ϱ� ���� �Լ�ȭ X
		// �Լ�ȭ �ϰų� getch()�� ������ �����ӵ��� ������
		{
			if (GetAsyncKeyState(VK_LEFT) && player.pos_x > 5) { //����
				gotoxy(player.pos_x, player.pos_y);
				puts("     ");
				player.pos_x--;
				gotoxy(player.pos_x, player.pos_y);
				set_color(player.color);
				puts(player.shape);
				set_color(15);
			}
			if (GetAsyncKeyState(VK_RIGHT) && player.pos_x < 51) { //������
				gotoxy(player.pos_x, player.pos_y);
				puts("     ");
				player.pos_x++;
				gotoxy(player.pos_x, player.pos_y);
				set_color(player.color);
				puts(player.shape);
				set_color(15);
			}
			if (GetAsyncKeyState(VK_UP) && player.pos_y > 4) { //��
				gotoxy(player.pos_x, player.pos_y);
				puts("     ");
				player.pos_y--;
				gotoxy(player.pos_x, player.pos_y);
				set_color(player.color);
				puts(player.shape);
				set_color(15);
			}
			if (GetAsyncKeyState(VK_DOWN) && player.pos_y < 29) { //�Ʒ�
				gotoxy(player.pos_x, player.pos_y);
				puts("     ");
				player.pos_y++;
				gotoxy(player.pos_x, player.pos_y);
				set_color(player.color);
				puts(player.shape);
				set_color(15);
			}
		}

		// ���� �Ͻ� ����
		if (GetAsyncKeyState(VK_ESCAPE) && frame_count > 0)
		{
			int menu_num = 23;
			int key = 0;

			while (key != ENTER)
			{
				draw_content(2);
				gotoxy(menu_num, 14);
				puts("��");
				key = getch();
				gotoxy(menu_num, 14);
				puts("  ");
				menu_num = move(1, key, menu_num, 14);
			}

			if (menu_num == 23) // ��
			{
				// ���� ���ھ� ����
				break;
			}
			else // menu_num == 39 : �ƴϿ�
			{
				system("cls");
				continue;
			}
		}

		// �÷��̾� �Ѿ� ���� �����̽���
		if (GetAsyncKeyState(VK_SPACE) && frame_count > 0)
		{
			for (int i = 0; i < BULLET_SIZE; i++)
			{
				if (bullet[i].con == FALSE)
				{
					bullet[i].pos_x = player.pos_x + 1;
					bullet[i].pos_y = player.pos_y - 1;
					bullet[i].con = TRUE;
					break;
				}
			}
		}

		// ��ź �߻� ZŰ, frame_count > 1�� ���� �����ϱ��� ZŰ�� �������� ��ų�� �����°� �����ϱ�����
		if (GetAsyncKeyState(0x5A) && frame_count > 0)
		{
			if (bomb[0].count > 0 && (bomb[0].con == FALSE && bomb[1].con == FALSE))
			{
				bomb[0].count--;
				bomb[0].con = TRUE;
				bomb[1].con = TRUE;
			}
		}

		// ��ų XŰ - ���� �߰�
		// ���� STAT UI�� ��ų ������ ǥ���������
		if ((GetAsyncKeyState(0x58) && frame_count > 1) && (shop.cool_time == 0 && shop.life_plus > 0))
		{
			player.life++;
			shop.life_plus--;
			shop.cool_time = 1000;

			if (bomb[0].count > 0 && (bomb[0].con == FALSE && bomb[1].con == FALSE))
			{
				bomb[0].con = TRUE;
				bomb[1].con = TRUE;
			}
			else
			{
				bomb[0].count++;
			}
		}

		// ��ų CŰ - HP ȸ��
		// ���� STAT UI�� ��ų ������ ǥ���������
		if ((GetAsyncKeyState(0x43) && frame_count > 1) && (shop.hp_plus > 0 && player.health < 3))
		{
			shop.hp_plus--;
			player.health++;
			// ��ų ���� �ð� ª�� ó���ϰ�
			// ��ų ���� �ð� �׸��� �������� ��������
		}

		// ���� ����
		enemy_gen(enemy, frame_count);

		// ������ ����
		item_gen(item, frame_count);

		// ���� �̵�
		enemy_move(enemy);

		// ��ź �̵�
		if (bomb[0].con == TRUE || bomb[1].con == TRUE)
			bomb_move(bomb);

		// �Ѿ� �̵�
		bullet_move(bullet);

		// ���� �Ѿ� �߻�
		player = enm_bull_status(enemy, player, bomb, bullet, 0);

		// �� �Ѿ� �̵�
		enm_bull_move(enemy);
		
		// ������ �̵�
		item_move(item);
		
		// ������ ���� �浹
		item_status(item, player, bullet, shop, 0);

		// ������ �ٴ� �浹
		item_status(item, player, bullet, shop, 1);
		
		// �� �Ѿ� �÷��̾� �浹
		player = enm_bull_status(enemy, player, bomb, bullet, 1);

		// �� �Ѿ� �ٴ� ����
		player = enm_bull_status(enemy, player, bomb, bullet, 2);
		
		// �� �Ѿ� �÷��̾� �Ѿ� �浹
		player = enm_bull_status(enemy, player, bomb, bullet, 3);
		
		// ��ź �߻�� �� �Ѿ� ��ź �տ��� ����
		player = enm_bull_status(enemy, player, bomb, bullet, 4);
		
		// ��ź - �� �浹
		bomb_status(bomb, enemy, 0);

		// ��ź�� õ�忡 �����ϸ� ����
		bomb_status(bomb, enemy, 1);

		// ������ �ٴڿ� �����ϸ� ����
		player = enm_status(enemy, bomb, bomb_bul, bomb_bul2, player, bullet, 0);

		// �÷��̾� - �� �浹
		player = enm_status(enemy, bomb, bomb_bul, bomb_bul2, player, bullet, 1);
		
		// �Ѿ� - �� �浹
		player = enm_status(enemy, bomb, bomb_bul, bomb_bul2, player, bullet, 2);
		
		// ��ź �Ѿ� - �� �浹
		player = enm_status(enemy, bomb, bomb_bul, bomb_bul2, player, bullet, 3);
		
		// �Ѿ��� õ�忡 �����ϸ� ����
		bullet_status(bullet);
		
		// ��ź �Ѿ� �߻�
		bomb_bull_status(bomb, bomb_bul, bomb_bul2, 0);

		// ��ź �Ѿ� �̵�
		bomb_bull_move(bomb, bomb_bul, bomb_bul2);

		// ��ź �Ѿ��� õ�忡 �����ϸ� ����
		bomb_bull_status(bomb, bomb_bul, bomb_bul2, 1);
		
		// ��ų ���� ���
		if (shop.cool_time > 0)
			shop.cool_time--;

		// ���� ���� �˻�
		if (player.life == 0 && player.health == 0)
		{
			break;
		}

		frame_count++;
		Sleep(22);
	}
}