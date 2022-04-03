#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // GetAsyncKeyState ����� ����
#include "common.h"
#include "game.h"

void game(void)
{
	system("mode con: cols=80 lines=32");
	system("cls");
	
	// �÷��̾� - ��ź, ��ų ����
	Player player = { 28, 28, 1, 3, 0 }; // X��, Y��, ����, ü��, ����
	Bullet bullet[BULLET_SIZE] = { 0, }; // X��, Y��, Ȯ��
	Skill skill = { 3, 3, 0, 0 };
	Item item[ITEM_SIZE] = { 0, };
	Bomb bomb[BOMB_SIZE] = { 29, 24, 1, 5, FALSE, 6, 24, 0, 5, FALSE }; // // X��, Y��, �ܷ�, �ӵ�, Ȯ��
	Bomb_blt bomb_bul[BOMB_BUL_SIZE] = { 0, };
	Bomb_blt bomb_bul2[BOMB_BUL_SIZE] = { 0, };
	
	// ����
	int frame_cnt = 0; // �������� ������
	Enemy enemy[ENEMY_SIZE] = { 0, };

	while (1)
	{
		drawContent(1);
		drawStat(player, bomb);
		setColor(14, 2);
		gotoxy(player.pos_x, player.pos_y);
		puts("[-*-]");
		setColor(15, 2);

		// ���� Ű���� ����
		// GetAsyncKeyState()�� ��� �����ϱ� ���� �Լ�ȭ X
		// �Լ�ȭ �ϰų� getch()�� ������ �����ӵ��� ������
		{
			if (GetAsyncKeyState(VK_LEFT) && player.pos_x > 5) { //����
				gotoxy(player.pos_x, player.pos_y);
				printf("     ");
				player.pos_x--;
				gotoxy(player.pos_x, player.pos_y);
				puts("[-*-]");
			}
			if (GetAsyncKeyState(VK_RIGHT) && player.pos_x < 51) { //������
				gotoxy(player.pos_x, player.pos_y);
				printf("     ");
				player.pos_x++;
				gotoxy(player.pos_x, player.pos_y);
				puts("[-*-]");
			}
			if (GetAsyncKeyState(VK_UP) && player.pos_y > 4) { //��
				gotoxy(player.pos_x, player.pos_y);
				printf("     ");
				player.pos_y--;
				gotoxy(player.pos_x, player.pos_y);
				puts("[-*-]");
			}
			if (GetAsyncKeyState(VK_DOWN) && player.pos_y < 29) { //�Ʒ�
				gotoxy(player.pos_x, player.pos_y);
				printf("     ");
				player.pos_y++;
				gotoxy(player.pos_x, player.pos_y);
				puts("[-*-]");
			}
		}

		// ���� �Ͻ� ����
		if ((GetAsyncKeyState(VK_ESCAPE)))
		{
			int menu_num = 23;
			int key = 0;

			while (key != ENTER)
			{
				drawContent(2);
				gotoxy(menu_num, 14);
				printf("��");
				key = _getch();
				gotoxy(menu_num, 14);
				printf("  ");
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
		if ((GetAsyncKeyState(VK_SPACE)))
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

		// ��ź �߻� ZŰ, frame_cnt > 1�� ���� �����ϱ��� ZŰ�� �������� ��ų�� �����°� �����ϱ�����
		if (GetAsyncKeyState(0x5A) && frame_cnt > 1)
		{
			if (bomb[0].count > 0 && (bomb[0].con == FALSE && bomb[1].con == FALSE))
			{
				bomb[0].count--;
				bomb[0].con = TRUE;
				bomb[1].con = TRUE;
			}
		}

		// ��ų XŰ - ���� �߰�
		// STAT UI�� �ݿ��ؾ���
		if ((GetAsyncKeyState(0x58) && frame_cnt > 1) && (skill.life_count == 0 && skill.life_plus > 0))
		{
			player.life++;
			skill.life_plus--;

			if (bomb[0].count > 0 && (bomb[0].con == FALSE && bomb[1].con == FALSE))
			{
				bomb[0].con = TRUE;
				bomb[1].con = TRUE;
				// ��ų ���� �ð� ���� �ʿ�
				skill.life_count = 1000;
			}
			else
			{
				bomb[0].count++;
				// ��ų ���� �ð� ���� �ʿ�
				skill.life_count = 1000;
			}
		}

		// ���� ����
		enemyGen(enemy, frame_cnt);

		// ������ ����
		itemGen(item, frame_cnt);

		// ���� �̵�
		enemyMove(enemy);

		// ��ź �̵�
		if (bomb[0].con == TRUE || bomb[1].con == TRUE)
			bombMove(bomb);

		// �Ѿ� �̵�
		bulletMove(bullet);

		// ���� �Ѿ� �߻�
		player = enmBulStatus(enemy, player, bomb, bullet, 0);

		// �� �Ѿ� �̵�
		enmBulMove(enemy);
		
		// ������ �̵�
		itemMove(item);
		
		// ������ ���� �浹
		itemStatus(item, player, bullet, 0);

		// ������ �ٴ� �浹
		itemStatus(item, player, bullet, 1);
		
		// �� �Ѿ� �÷��̾� �浹
		player = enmBulStatus(enemy, player, bomb, bullet, 1);

		// �� �Ѿ� �ٴ� ����
		player = enmBulStatus(enemy, player, bomb, bullet, 2);
		
		// �� �Ѿ� �÷��̾� �Ѿ� �浹
		player = enmBulStatus(enemy, player, bomb, bullet, 3);
		
		// ��ź �߻�� �� �Ѿ� ��ź �տ��� ����
		player = enmBulStatus(enemy, player, bomb, bullet, 4);
		
		// ��ź - �� �浹
		bombStatus(bomb, enemy, 0);

		// ��ź�� õ�忡 �����ϸ� ����
		bombStatus(bomb, enemy, 1);

		// ������ �ٴڿ� �����ϸ� ����
		player = enmStatus(enemy, bomb, bomb_bul, bomb_bul2, player, bullet, 0);

		// �÷��̾� - �� �浹
		player = enmStatus(enemy, bomb, bomb_bul, bomb_bul2, player, bullet, 1);
		
		// �Ѿ� - �� �浹
		player = enmStatus(enemy, bomb, bomb_bul, bomb_bul2, player, bullet, 2);
		
		// ��ź �Ѿ� - �� �浹
		player = enmStatus(enemy, bomb, bomb_bul, bomb_bul2, player, bullet, 3);
		
		// �Ѿ��� õ�忡 �����ϸ� ����
		bulletStatus(bullet);
		
		// ��ź �Ѿ� �߻�
		bombBulStatus(bomb, bomb_bul, bomb_bul2, 0);

		// ��ź �Ѿ� �̵�
		bombBulMove(bomb, bomb_bul, bomb_bul2);

		// ��ź �Ѿ��� õ�忡 �����ϸ� ����
		bombBulStatus(bomb, bomb_bul, bomb_bul2, 1);
		
		// ��ų ���� ���
		if (skill.life_count > 0)
			skill.life_count--;

		// ���� ���� �˻�
		if (player.life == 0 && player.health == 0)
		{
			break;
		}

		frame_cnt++;
		Sleep(22);
	}
}