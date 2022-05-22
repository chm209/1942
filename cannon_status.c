#include <stdio.h>
#include "common.h"
#include "game.h"

void cannon_status(CANNON* cannon)
{
	for (int i = 0; i < CANNON_SIZE; i++)
	{
		if (cannon->condition[i] == TRUE && cannon->pos_y[i] == 0)
		{
			gotoxy(cannon->pos_x[i], cannon->pos_y[i]);
			printf("  ");
			cannon->condition[i] = FALSE;
		}
	}
}