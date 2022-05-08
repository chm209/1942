#include <stdio.h>
#include "common.h"
#include "game.h"

Player item_status(Item* item, Player player, Bullet* bullet, Shop shop, int num)
{
	switch (num)
	{
	// 아이템 - 플레이어 충돌
	case 0:
		for (int i = 0; i < ITEM_SIZE; i++)
		{
			if (item[i].con == TRUE)
			{
				if (item[i].pos_y == player.pos_y)
				{
					if (item[i].pos_x >= player.pos_x && item[i].pos_x <= player.pos_x + 5)
					{
						gotoxy(item[i].pos_x, item[i].pos_y);
						printf("   ");
						item[i].con = FALSE;
						player.score += 10;

						switch (item[i].type)
						{
						case 0:
							if (bullet->type == 0)
							{
								bullet->type = 1;
								switch (shop.bullet_color)
								{
								case 0:
									bullet->shape = "ⅱ";
									break;
								case 1:
									bullet->shape = "ψ";
									break;
								case 2:
									bullet->shape = "±";
									break;
								case 3:
									bullet->shape = "♠";
									break;
								}
							}
							else if (bullet->type == 1)
							{
								bullet->type = 2;
								switch (shop.bullet_color)
								{
								case 0:
									bullet->shape = "ⅲ";
									break;
								case 1:
									bullet->shape = "Ψ";
									break;
								case 2:
									bullet->shape = "÷";
									break;
								case 3:
									bullet->shape = "♣";
									break;
								}
							}
							break;
						case 1:
							if (player.quantity < 5)
							{
								player.quantity++;
							}
							break;
						}
					}
				}
			}
		}
		break;
	// 아이템 바닥 도달
	case 1:
		for (int i = 0; i < ITEM_SIZE; i++)
		{
			if (item[i].con == TRUE)
			{
				if (item[i].pos_y == 29)
				{
					gotoxy(item[i].pos_x, item[i].pos_y);
					printf("    ");
					item[i].con = FALSE;
				}
			}
		}
		break;
	}
	return player;
}