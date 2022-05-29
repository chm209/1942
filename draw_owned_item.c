#include <stdio.h>
#include "common.h"

void draw_owned_item(void)
{
	int count = 0;

	for (int POS_Y = 4; POS_Y <= 20; POS_Y += 2)
	{
		gotoxy(40, POS_Y);
		printf("%d °³", user.item[count]);
		count++;
	}

	if (user.item[9] != 15)
	{
		gotoxy(40, 22);
		printf("1 °³");
	}
	else
	{
		gotoxy(40, 22);
		printf("0 °³");
	}

	gotoxy(40, 24);
	printf("%11d pt", user.point);
}