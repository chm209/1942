#include <stdio.h>
#include "common.h"
#include "game.h"

void bullet_move(Bullet* bullet)
{
	// �ӵ� ������ ������ ��Ƽ� �����
	char* shape = bullet->shape;
	for (int i = 0; i < BULLET_SIZE; i++)
	{
		if (bullet[i].con == TRUE)
		{
			gotoxy(bullet[i].pos_x, bullet[i].pos_y);
			puts("  ");
			bullet[i].pos_y--;
			gotoxy(bullet[i].pos_x, bullet[i].pos_y);
			set_color(bullet->color);
			puts(shape);
			set_color(15);
		}
	}
}