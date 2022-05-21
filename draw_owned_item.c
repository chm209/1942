#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void draw_owned_item(void)
{
	int count = 0;

	for (int POS_Y = 4; POS_Y <= 22; POS_Y += 2)
	{
		gotoxy(40, POS_Y);
		printf("%d °³", user.item[count]);
		count++;
	}
	gotoxy(40, 24);
	printf("%11d pt", user.point);
}