#include <stdio.h>
#include "game.h"
#include "common.h"

void itemMove(Item* item)
{
	for (int i = 0; i < ITEM_SIZE; i++)
	{
		if (item[i].con == TRUE)
		{
			if (item[i].speed == 15)
			{
				item[i].speed = 0;
				gotoxy(item[i].pos_x, item[i].pos_y);
				puts("   ");
				item[i].pos_y++;
				gotoxy(item[i].pos_x, item[i].pos_y);
				switch (item[i].type)
				{
				case 0:
					printf("[P]");
					break;
				}
			}
			else
				item[i].speed++;

		}
	}
}