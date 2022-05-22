#include <stdio.h>
#include "common.h"
#include "game.h"

void item_gen(DROP_ITEM* drop_item, int frame_time)
{
	int isCreated = FALSE;

	for (int i = 0; i < ITEM_SIZE; i++)
	{
		if (frame_time == 700 && drop_item->condition[i] == FALSE)
		{
			drop_item->pos_x[i] = 10;
			drop_item->pos_y[i] = 0;
			drop_item->condition[i] = TRUE;
			drop_item->type[i] = 0;
			isCreated = TRUE;
		}

		if (frame_time == 900 && drop_item->condition[i] == FALSE)
		{
			drop_item->pos_x[i] = 30;
			drop_item->pos_y[i] = 0;
			drop_item->condition[i] = TRUE;
			drop_item->type[i] = 1;
			isCreated = TRUE;
		}

		if (isCreated == TRUE)
		{
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
			break;
		}
	}
}	