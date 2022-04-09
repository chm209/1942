#include <stdio.h>
#include "common.h"
#include "game.h"

void item_status(Item* item, Player player, Bullet* bullet, int num)
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

						switch (item[i].type)
						{
							// ¹«±â ¾÷
						case 0:
							bullet[0].type = 1;
							bullet[1].type = 1;
							bullet[2].type = 1;
							bullet[3].type = 1;
							break;
						case 1:
							bullet[0].type = 2;
							bullet[1].type = 2;
							bullet[2].type = 2;
							bullet[3].type = 2;
							break;
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