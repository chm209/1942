#include <stdio.h>
#include "common.h"
#include "game.h"

void item_status(DROP_ITEM* drop_item, PLAYER* player, CANNON* cannon, SHOP_ITEM* shop_item, int state)
{
	switch (state)
	{
	// 아이템 - 플레이어 충돌
	case 0:
		for (int i = 0; i < ITEM_SIZE; i++)
		{
			if (drop_item->condition[i] == TRUE)
			{
				if (drop_item->pos_y[i] == player->pos_y)
				{
					if (drop_item->pos_x[i] >= player->pos_x && drop_item->pos_x[i] <= player->pos_x + 5)
					{
						gotoxy(drop_item->pos_x[i], drop_item->pos_y[i]);
						printf("   ");
						drop_item->condition[i] = FALSE;
						player->score += 10;

						switch (drop_item->type[i])
						{
						case 0:
							if (cannon->upgrade == CANNONE_LEVEL1)
							{
								cannon->upgrade = CANNONE_LEVEL2;
								switch (shop_item->cannon_color)
								{
								case WHITE:
									shop_item->cannon_design = CANNON5;
									break;
								case RED:
									shop_item->cannon_design = CANNON6;
									break;
								case BLUE:
									shop_item->cannon_design = CANNON7;
									break;
								case YELLOW:
									shop_item->cannon_design = CANNON8;
									break;
								}
							}
							else if (cannon->upgrade == CANNONE_LEVEL2)
							{
								cannon->upgrade = CANNONE_LEVEL3;
								switch (shop_item->cannon_color)
								{
								case WHITE:
									shop_item->cannon_design = CANNON9;
									break;
								case RED:
									shop_item->cannon_design = CANNON10;
									break;
								case BLUE:
									shop_item->cannon_design = CANNON11;
									break;
								case YELLOW:
									shop_item->cannon_design = CANNON12;
									break;
								}
							}
							break;
						case 1:
							if (player->cannon_limit < 5)
							{
								player->cannon_limit++;
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
			if (drop_item->condition[i] == TRUE)
			{
				if (drop_item->pos_y[i] == 29)
				{
					gotoxy(drop_item->pos_x[i], drop_item->pos_y[i]);
					printf("    ");
					drop_item->condition[i] = FALSE;
				}
			}
		}
		break;
	}
}