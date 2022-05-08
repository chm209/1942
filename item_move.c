#include <stdio.h>
#include "game.h"
#include "common.h"

void item_move(Item* item)
{
	for (int i = 0; i < ITEM_SIZE; i++)
	{
		if (item[i].con == TRUE)
		{
			if (item[i].speed == 10)
			{
				item[i].speed = 0;
				gotoxy(item[i].pos_x, item[i].pos_y);
				printf("     ");
				item[i].pos_y++;
				gotoxy(item[i].pos_x, item[i].pos_y);
				switch (item[i].type)
				{
				case 0:
					printf("[P]");
					break;
				case 1:
					printf("[ег]");
					break;
				}
			}
			else
			{
				item[i].speed++;
			}
		}
	}
}