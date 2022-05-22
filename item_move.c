#include <stdio.h>
#include "game.h"
#include "common.h"

void item_move(DROP_ITEM* drop_item)
{
	for (int i = 0; i < ITEM_SIZE; i++)
	{
		if (drop_item->condition[i] == TRUE)
		{
			if (drop_item->move_interval[i] == 10)
			{
				drop_item->move_interval[i] = 0;
				gotoxy(drop_item->pos_x[i], drop_item->pos_y[i]);
				printf("     ");
				drop_item->pos_y[i]++;
				gotoxy(drop_item->pos_x[i], drop_item->pos_y[i]);
				switch (drop_item->type[i])
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
				drop_item->move_interval[i]++;
			}
		}
	}
}