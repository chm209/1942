#include <stdio.h>
#include "common.h"
#include "game.h"

void bullet_status(Bullet* bullet)
{
	for (int i = 0; i < BULLET_SIZE; i++)
	{
		if (bullet[i].con == TRUE && bullet[i].pos_y == 0)
		{
			gotoxy(bullet[i].pos_x, bullet[i].pos_y);
			puts("  ");
			bullet[i].con = FALSE;
		}
	}
}