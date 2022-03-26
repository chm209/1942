#include <stdio.h>
#include "common.h"
#include "game.h"

void bulletMove(Bullet* bullet)
{
	for (int i = 0; i < BULLET_SIZE; i++)
	{
		if (bullet[i].con == TRUE)
		{
			gotoxy(bullet[i].pos_x, bullet[i].pos_y);
			puts("  ");
			bullet[i].pos_y--;
			gotoxy(bullet[i].pos_x, bullet[i].pos_y);
			switch (bullet[i].type)
			{
			case 0:
				puts("еб");
				break;
			case 1:
				puts("ев");
				break;
			case 2:
				puts("ег");
				break;
			}
		}
	}
}