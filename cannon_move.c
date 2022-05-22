#include <stdio.h>
#include "common.h"
#include "game.h"

void cannon_move(CANNON* cannon, SHOP_ITEM* shop_item)
{
	for (int i = 0; i < CANNON_SIZE; i++)
	{
		if (cannon->condition[i] == TRUE)
		{
			gotoxy(cannon->pos_x[i], cannon->pos_y[i]);
			printf("  ");
			cannon->pos_y[i]--;
			gotoxy(cannon->pos_x[i], cannon->pos_y[i]);
			set_color(shop_item->cannon_color);
			puts(shop_item->cannon_design);
			set_color(WHITE);
		}
	}
}