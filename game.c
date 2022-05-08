#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // GetAsyncKeyState ����� ����
#include "common.h"
#include "game.h"

void game(void)
{
	system("mode con: cols=80 lines=30");
	system("cls");

	// �÷��̾� ���� ����ü ����
	// Player: ��ǥ X��, ��ǥ Y��, ����, ü��, ����, ������ ���, ������ ����
	// Bullet[]: ��ǥ X��, ��ǥ Y��, ���� Ȯ�ο�, �Ѿ� Ÿ��, �Ѿ� ���, �Ѿ� ����
	// Item[]: ��ǥ X��, ��ǥ Y��, ���� Ȯ�ο�, ������ Ÿ��, ������ ������ �ӵ�
	// Bomb[]: ��ǥ X��, ��ǥ Y��, ��ź ����, ��ź ������ �ӵ�, ��ź ���� Ȯ�ο� * 2
	// bomb_bul[]: ��ǥ X��, ��ǥ Y��, ��ź �Ѿ� ���� Ȯ�ο�
	// bomb_bul2[]: ��ǥ X��, ��ǥ Y��, ��ź �Ѿ� ���� Ȯ�ο�
	// Shop: ���� �߰� ����, ü�� ȸ�� ����, �߰� ���� ����, ��ų ��Ÿ��, ������ ����, �Ѿ� ����
	// ���� DB ������ �պ��� �ϴ� ����ü ����, ġ�� �������� 0�� Default ������ �ǹ�
	Player player = { 28, 28, 1, 3, 2, 0, NULL, 0 };
	Bullet bullet[BULLET_SIZE] = { 0, 0, 0, 0, NULL, 0 };
	Item item[ITEM_SIZE] = { 0, };
	Bomb bomb[BOMB_SIZE] = { 29, 24, 1, 5, FALSE, 6, 24, 0, 5, FALSE };
	Bomb_blt bomb_bul[BOMB_BUL_SIZE] = { 0, };
	Bomb_blt bomb_bul2[BOMB_BUL_SIZE] = { 0, };
	Shop shop = { 0, 0, 0, 0, 0, 0};

	// ���� ���� ����
	// Enemy[]: ��ǥ X��, ��ǥ Y��, �� ����� Ÿ��, ������ ����, ������ Ƚ��, ������ �ӵ�, ü��, ���� Ȯ�ο�
	// �Ѿ� X��, �Ѿ� Y��, ����Ȯ��, �ӵ�
	int frame_count = 0; // �������� ������
	Enemy enemy[ENEMY_SIZE] = { 0, };
	Enemy_bul enemy_bul[ENEMY_SIZE] = { 0, };

	// ���� ������ �ʱ� ����
	// 1. �÷��̾� ������ ������, ������ ����, �Ѿ� ������, �Ѿ� ���� ����
	// 2. ���� ����� �����⸦ �ѹ��� ���������Ѵ�.
	// -�� DB ������ �ʱ⼳���� ���⼭ ó��
	player = set_player(player, bullet, shop);

	while (1)
	{
		// UI �׸���
		// 1. ������ ���
		// 2. �÷��̾� ���� ���
		// 3. �÷��̾� ������ ���
		draw_game(0);
		draw_status(player, bomb, shop);
		{
			gotoxy(player.pos_x, player.pos_y);
			set_color(player.color);
			printf(player.shape);
			set_color(15);
		}

		// Ű���� �Է� ����
		// �Լ�ȭ, getch()�� ���� ��� ���� �����ӵ��� �������ų� ���� ����
		{
			// ���� �̵�
			if (GetAsyncKeyState(VK_LEFT) && player.pos_x > LEFT_LIMIT)
			{
				gotoxy(player.pos_x, player.pos_y);
				puts("     ");
				player.pos_x--;
				gotoxy(player.pos_x, player.pos_y);
				set_color(player.color);
				printf(player.shape);
				set_color(15);
			}

			// ������ �̵�
			if (GetAsyncKeyState(VK_RIGHT) && player.pos_x < RIGHT_LIMIT)
			{
				gotoxy(player.pos_x, player.pos_y);
				puts("     ");
				player.pos_x++;
				gotoxy(player.pos_x, player.pos_y);
				set_color(player.color);
				printf(player.shape);
				set_color(15);
			}

			// ���� �̵�
			if (GetAsyncKeyState(VK_UP) && player.pos_y > UP_LIMIT)
			{
				gotoxy(player.pos_x, player.pos_y);
				puts("     ");
				player.pos_y--;
				gotoxy(player.pos_x, player.pos_y);
				set_color(player.color);
				printf(player.shape);
				set_color(15);
			}

			// �Ʒ��� �̵�
			if (GetAsyncKeyState(VK_DOWN) && player.pos_y < DOWN_LIMIT)
			{
				gotoxy(player.pos_x, player.pos_y);
				puts("     ");
				player.pos_y++;
				gotoxy(player.pos_x, player.pos_y);
				set_color(player.color);
				printf(player.shape);
				set_color(15);
			}
		}

		// ���� �Ͻ� ����
		// ���� ������ ���� Ű�� �������� ���� frame_count�� �˻�
		if (GetAsyncKeyState(VK_ESCAPE) && frame_count > 0)
		{
			int key = 0, do_exit = 23;

			while (key != ENTER)
			{
				// PAUSE ȭ�� ���
				draw_game(1);
				gotoxy(do_exit, 14);
				printf("��");
				key = getch();
				gotoxy(do_exit, 14);
				printf("  ");
				do_exit = move(1, key, do_exit, 14);
			}
			// �� ����
			if (do_exit == 23) // ��
			{
				system("cls");
				// ���� ���ھ�, ����Ʈ, ����� ������ ��� DB�� ����
				break;
			}
			// �ƴϿ� ����
			else
			{
				system("cls");
				continue;
			}
		}

		// �÷��̾� ���� - �����̽���
		if (GetAsyncKeyState(VK_SPACE) && frame_count > 0)
		{
			for (int i = 0; i < player.quantity; i++)
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

		// ��ź ���� - ZŰ
		if (GetAsyncKeyState(0x5A) && frame_count > 0)
		{
			if (bomb[0].count > 0 && (bomb[0].con == FALSE && bomb[1].con == FALSE))
			{
				bomb[0].count--;
				bomb[0].con = TRUE;
				bomb[1].con = TRUE;
			}
		}

		// ���� �߰� - XŰ
		if ((GetAsyncKeyState(0x58) && frame_count > 1) && (shop.cool_time == 0 && shop.life_plus > 0))
		{
			player.life++;
			player.score -= 50;
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

		// ü�� ȸ�� - CŰ
		if ((GetAsyncKeyState(0x43) && frame_count > 1) && (shop.hp_plus > 0 && player.health < 3))
		{
			shop.hp_plus--;
			player.health++;
			player.score -= 10;
		}

		// ���� ����
		enemy_gen(enemy, frame_count);

		// ������ ����
		item_gen(item, frame_count);

		// ���� �̵�
		enemy_move(enemy);

		// ��ź �̵�
		if (bomb[0].con == TRUE || bomb[1].con == TRUE)
		{
			bomb_move(bomb);
		}

		// �Ѿ� �̵�
		bullet_move(bullet);

		// ���� �Ѿ� �߻�
		player = enm_bull_status(enemy, player, bomb, bullet, 0);

		// �� �Ѿ� �̵�
		enm_bull_move(enemy);
		
		// ������ �̵�
		item_move(item);
		
		// ������ ���� �浹
		player = item_status(item, player, bullet, shop, 0);

		// ������ �ٴ� �浹
		player = item_status(item, player, bullet, shop, 1);
		
		// �� �Ѿ� �÷��̾� �浹
		player = enm_bull_status(enemy, player, bomb, bullet, 1);

		// �� �Ѿ� �ٴ� ����
		player = enm_bull_status(enemy, player, bomb, bullet, 2);
		
		// �� �Ѿ� �÷��̾� �Ѿ� �浹
		player = enm_bull_status(enemy, player, bomb, bullet, 3);
		
		// ��ź �߻�� �� �Ѿ� ��ź �տ��� ����
		player = enm_bull_status(enemy, player, bomb, bullet, 4);
		
		// ��ź - �� �浹
		bomb_status(bomb, enemy, player, 0);

		// ��ź�� õ�忡 �����ϸ� ����
		bomb_status(bomb, enemy, player, 1);

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
		{
			shop.cool_time--;
		}

		// ���� ���� �˻�
		if (player.life == 0 && player.health == 0)
		{
			break;
		}

		frame_count++;
		Sleep(22);
	}
}