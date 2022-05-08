#include <stdio.h>
#include "common.h"
#include "game.h"

void item_gen(Item* item, int frame_count)
{
	int isCreated = FALSE;

	for (int i = 0; i < ITEM_SIZE; i++)
	{
		if (frame_count == 700 && item[i].con == FALSE)
		{
			item[i].con = TRUE;
			item[i].pos_x = 10;
			item[i].pos_y = 0;
			item[i].type = 0;
			isCreated = TRUE;
		}

		if (frame_count == 900 && item[i].con == FALSE)
		{
			item[i].con = TRUE;
			item[i].pos_x = 30;
			item[i].pos_y = 0;
			item[i].type = 1;
			isCreated = TRUE;
		}

		if (isCreated == TRUE)
		{
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
			break;
		}
	}
}	