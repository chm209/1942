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

	while (position_y != 24)
	{
		system("cls");
		draw_content(0);

		switch (menu_num)
		{
		default:
			gotoxy(39, 18);
			printf("�α���");
			gotoxy(39, 20);
			printf("ȸ������");
			gotoxy(39, 22);
			printf("��ŷȭ��");
			gotoxy(39, 24);
			printf("��������");
			break;
		case 1:
			gotoxy(39, 18);
			printf("���ӽ���");
			gotoxy(39, 20);
			printf("����");
			gotoxy(39, 22);
			printf("��ŷȮ��");
			gotoxy(39, 24);
			printf("��������");
			break;
		}

		while (key != ENTER)
		{
			gotoxy(59, position_y);
			printf("��");
			key = _getch();
			gotoxy(59, position_y);
			printf("  ");
			// Ű���� ���� ó�� (ȭ�� ��ȣ, ����, X, Y ��)
			position_y = action(0, key, 59, position_y);
		}

		switch (position_y)
		{
		// 0�� �α��� 1�� ���ӽ���
		case 18:
			menu_num = login(1);
			// menu_num % 2 == 0 ? menu_num = login(1) : game();
			break;
		// 0�� ȸ������ 1�� ����
		case 20:
			menu_num % 2 == 0 ? menu_num = login(0) : shop();
			break;
		// ��ŷȮ�� 0�� ��ȸ�� 1�� ȸ��
		case 22:
			menu_num % 2 == 0 ? ranking(0) : ranking(1);
			break;
		// ��������
		case 24:
			break;
		}

		key = 0;
	}

	return 0;
}