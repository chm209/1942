#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "common.h"

int main(void)
{
	system("mode con: cols=100 lines=30");
	system("title 1705095 ��â�� - 1942 ������Ʈ");
	cursor(0);

	int menu_num = 0, key = 0, position_y = 18;
	draw_content(0);

	while (position_y != 24)
	{
		// position_y = 18;

		while (key != ENTER)
		{
			gotoxy(57, position_y);
			printf("��");
			key = _getch();
			gotoxy(57, position_y);
			printf("  ");
			// Ű���� ���� ó�� (ȭ�� ��ȣ, ����, X, Y ��)
			position_y = action(0, key, 57, position_y);
		}

		switch (position_y)
		{
		// �α���
		case 18:
			break;
		// ȸ������
		case 20:
			break;
		// ��ŷȮ��
		case 22:
			break;
		// ��������
		case 24:
			break;
		}
	}

	/*
	while (menu_num != 17)
	{
		MenuChoice = menu();

		switch (MenuChoice)
		{
		case 11:
			game();
			break;
		case 13:
			help(0);
			break;
		case 15:
			help(1);
			break;
		default:
			break;
		}
	}*/

	return 0;
}