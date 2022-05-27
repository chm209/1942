#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // GetAsyncKeyState ����� ����
#include "common.h"
#include "game.h"

void game(void)
{
	system("mode con: cols=80 lines=30");
	system("cls");

	// ���� �ð� ����
	int frame_time = 750;
	int pause_flag = FALSE;

	// ����ü ����
	PLAYER* player = malloc(sizeof(PLAYER));
	CANNON* cannon = malloc(sizeof(CANNON));
	BOMB* bomb = malloc(sizeof(BOMB));
	bomb->bomb_cannon[0] = malloc(sizeof(BOMB_CANNON));
	bomb->bomb_cannon[1] = malloc(sizeof(BOMB_CANNON));
	DROP_ITEM* drop_item = malloc(sizeof(DROP_ITEM));
	SHOP_ITEM* shop_item = malloc(sizeof(SHOP_ITEM));
	ENEMY* enemy = malloc(sizeof(ENEMY));
	for (int i = 0; i < ENEMY_SIZE; i++)
	{
		enemy->enemy_cannon[i] = malloc(sizeof(ENEMY));
	}

	// ����ü ���� �ʱ�ȭ
	init_variables(player, cannon, bomb, drop_item, shop_item, enemy);

	// DB���� �����͸� �о� �ʱ� ���� ����
	load_data(shop_item);

	// �ڵ�����
	if (shop_item->score_buff > 0)
	{
		shop_item->score_buff--;
		shop_item->buff_on = TRUE;
	}

	while (1)
	{
		gotoxy(0, 0);
		printf("%d", frame_time);

		draw_game(0); // ���� UI ���
		draw_status(player, shop_item); // ���� ���
		// ������ ���
		{
			gotoxy(player->pos_x, player->pos_y);
			set_color(shop_item->combat_color);
			printf(shop_item->combat_design);
			set_color(WHITE);
		}

		// Ű���� �Է� ����
		// �Լ�ȭ, getch()�� ���� ��� ���� �����ӵ��� �������� ���� ����
		{
			// ���� �̵�
			if ((GetAsyncKeyState(VK_LEFT) & 0x8000) && player->pos_x > LEFT_LIMIT)
			{
				gotoxy(player->pos_x, player->pos_y);
				printf("     ");
				player->pos_x--;
				gotoxy(player->pos_x, player->pos_y);
				set_color(shop_item->combat_color);
				printf(shop_item->combat_design);
				set_color(WHITE);
			}

			// ������ �̵�
			if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) && player->pos_x < RIGHT_LIMIT)
			{
				gotoxy(player->pos_x, player->pos_y);
				printf("     ");
				player->pos_x++;
				gotoxy(player->pos_x, player->pos_y);
				set_color(shop_item->combat_color);
				printf(shop_item->combat_design);
				set_color(WHITE);
			}

			// ���� �̵�
			if ((GetAsyncKeyState(VK_UP) & 0x8000) && player->pos_y > UP_LIMIT)
			{
				gotoxy(player->pos_x, player->pos_y);
				printf("     ");
				player->pos_y--;
				gotoxy(player->pos_x, player->pos_y);
				set_color(shop_item->combat_color);
				printf(shop_item->combat_design);
				set_color(WHITE);
			}

			// �Ʒ��� �̵�
			if ((GetAsyncKeyState(VK_DOWN) & 0x8000) && player->pos_y < DOWN_LIMIT)
			{
				gotoxy(player->pos_x, player->pos_y);
				printf("     ");
				player->pos_y++;
				gotoxy(player->pos_x, player->pos_y);
				set_color(shop_item->combat_color);
				printf(shop_item->combat_design);
				set_color(WHITE);
			}
		}

		// ���� �Ͻ� ����
		// ���� ������ ���� Ű�� �������� ���� frame_time�� �˻�
		// https://genesis8.tistory.com/138 ���ñ�
		if ((GetAsyncKeyState(VK_ESCAPE) & 0x0001) && frame_time > 0)
		{
			int key = 0;
			int do_exit = 23;

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
				draw_end_game(player, shop_item);
				save_data(player, shop_item);
				free(player);
				free(cannon);
				free(bomb->bomb_cannon[0]);
				free(bomb->bomb_cannon[1]);
				free(bomb);
				free(drop_item);
				free(shop_item);
				for (int i = 0; i < ENEMY_SIZE; i++)
				{
					free(enemy->enemy_cannon[i]);
				}
				free(enemy);
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
		if ((GetAsyncKeyState(VK_SPACE) & 0x8000) && frame_time > 0)
		{
			for (int i = 0; i < player->cannon_limit; i++)
			{
				if (cannon->condition[i] == FALSE)
				{
					cannon->pos_x[i] = player->pos_x + 1;
					cannon->pos_y[i] = player->pos_y - 1;
					cannon->condition[i] = TRUE;
					break;
				}
			}
		}

		// ��ź ���� - ZŰ
		if ((GetAsyncKeyState(0x5A) & 0x0001) && frame_time > 0)
		{
			if (player->bomb_quantity > 0 && (bomb->condition[0] == FALSE && bomb->condition[1] == FALSE))
			{
				player->bomb_quantity--;
				bomb->condition[0] = TRUE;
				bomb->condition[1] = TRUE;
			}
		}

		// ���� �߰� - XŰ
		if (((GetAsyncKeyState(0x58) & 0x0001) && frame_time > 1) && (shop_item->cooldown_time == 0 && shop_item->life_plus > 0))
		{
			player->life++;
			player->score -= 50;
			shop_item->life_plus--;
			shop_item->cooldown_time = 1000;

			if (player->bomb_quantity > 0)
			{
				bomb->condition[0] = TRUE;
				bomb->condition[1] = TRUE; 
			}
			else
			{
				player->bomb_quantity++;
			}
		}

		// ü�� ȸ�� - CŰ
		if (((GetAsyncKeyState(0x43) & 0x0001) && frame_time > 1) && (shop_item->hp_recover > 0 && player->hp < 3))
		{
			shop_item->hp_recover--;
			player->hp++;
			player->score -= 10;
		}

		// ���� ����
		enemy_gen(enemy, frame_time);

		// ������ ����
		item_gen(drop_item, frame_time);

		// ���� �̵�
		enemy_move(enemy);

		// ��ź �̵�
		if (bomb->condition[0] == TRUE || bomb->condition[1] == TRUE)
		{
			bomb_move(bomb);
		}

		// �Ѿ� �̵�
		cannon_move(cannon, shop_item);

		// ���� �Ѿ� �߻�
		eCannon_status(enemy, player, bomb, cannon, 0);

		// �� �Ѿ� �̵�
		eCannon_move(enemy);
		
		// ������ �̵�
		item_move(drop_item);
		
		// ������ ���� �浹
		item_status(drop_item, player, cannon, shop_item, 0);

		// ������ �ٴ� �浹
		item_status(drop_item, player, cannon, shop_item, 1);
		
		// �� �Ѿ� �÷��̾� �浹
		eCannon_status(enemy, player, bomb, cannon, 1);

		// �� �Ѿ� �ٴ� ����
		eCannon_status(enemy, player, bomb, cannon, 2);
		
		// �� �Ѿ� �÷��̾� �Ѿ� �浹
		eCannon_status(enemy, player, bomb, cannon, 3);
		
		// ��ź �߻�� �� �Ѿ� ��ź �տ��� ����
		eCannon_status(enemy, player, bomb, cannon, 4);
		
		// ��ź - �� �浹
		bomb_status(bomb, enemy, player, shop_item, 0);

		// ��ź�� õ�忡 �����ϸ� ����
		bomb_status(bomb, enemy, player, shop_item, 1);

		// ������ �ٴڿ� �����ϸ� ����
		enemy_status(enemy, bomb, player, cannon, shop_item, 0);

		// �÷��̾� - �� �浹
		enemy_status(enemy, bomb, player, cannon, shop_item, 1);
		
		// �Ѿ� - �� �浹
		enemy_status(enemy, bomb, player, cannon, shop_item, 2);
		
		// ��ź �Ѿ� - �� �浹
		enemy_status(enemy, bomb, player, cannon, shop_item, 3);
		
		// �Ѿ��� õ�忡 �����ϸ� ����
		cannon_status(cannon);
		
		// ��ź �Ѿ� �߻�
		bCannon_status(bomb, 0);

		// ��ź �Ѿ� �̵�
		bCannon_move(bomb);

		// ��ź �Ѿ��� õ�忡 �����ϸ� ����
		bCannon_status(bomb, 1);
		
		// ��ų ���� ���
		if (shop_item->cooldown_time > 0)
		{
			shop_item->cooldown_time--;
		}

		// ���� ���� �˻�
		if (player->life == 0 && player->hp == 0)
		{
			draw_end_game(player, shop_item);
			save_data(player, shop_item);
			free(player);
			free(cannon);
			free(bomb->bomb_cannon[0]);
			free(bomb->bomb_cannon[1]);
			free(bomb);
			free(drop_item);
			free(shop_item);
			for (int i = 0; i < ENEMY_SIZE; i++)
			{
				free(enemy->enemy_cannon[i]);
			}
			free(enemy);
			break;
		}

		frame_time++;
		Sleep(22);
	}
}