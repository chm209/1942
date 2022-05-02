#include <stdio.h>
#include "common.h"
#include "game.h"

void item_status(Item* item, Player player, Bullet* bullet, Shop shop, int num)
{
	switch (num)
	{
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
						puts("   ");
						item[i].con = FALSE;
						
						if (item[i].type == 0)
						{
							bullet->type = 1;
							switch (shop.bullet_color)
							{
							case 0:
								bullet->shape = "¥¢";
								break;
							case 1:
								bullet->shape = "¥÷";
								break;
							case 2:
								bullet->shape = "¡¾";
								break;
							case 3:
								bullet->shape = "¢¼";
								break;
							}
						}
						else if (item[i].type == 1)
						{
							bullet[0].type = 2;
							bullet[1].type = 2;
							bullet[2].type = 2;
							bullet[3].type = 2;
							switch (shop.bullet_color)
							{
							case 0:
								bullet->shape = "¥£";
								break;
							case 1:
								bullet->shape = "¥×";
								break;
							case 2:
								bullet->shape = "¡À";
								break;
							case 3:
								bullet->shape = "¢À";
								break;
							}
						}
					}
				}
			}
		}
		break;
	case 1:
		for (int i = 0; i < ITEM_SIZE; i++)
		{
			if (item[i].con == TRUE)
			{
				if (item[i].pos_y == 30)
				{
					gotoxy(item[i].pos_x, item[i].pos_y);
					puts("   ");
					item[i].con = FALSE;
				}
			}
		}
		break;
	}
}