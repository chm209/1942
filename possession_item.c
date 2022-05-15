#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void possession_item(void)
{
	gotoxy(40, 4);
	printf("%d 개", item_list.item1);
	gotoxy(40, 6);
	printf("%d 개", item_list.item2);
	gotoxy(40, 8);
	printf("%d 개", item_list.item3);
	gotoxy(40, 10);
	printf("%d 개", item_list.item4);
	gotoxy(40, 12);
	printf("%d 개", item_list.item5);
	gotoxy(40, 14);
	printf("%d 개", item_list.item6);
	gotoxy(40, 16);
	printf("%d 개", item_list.item7);
	gotoxy(40, 18);
	printf("%d 개", item_list.item8);
	gotoxy(40, 20);
	printf("%d 개", item_list.item9);
	gotoxy(40, 22);
	printf("%d 개", item_list.item10);
	gotoxy(40, 24);
	printf("%11d pt", user.point);
}