#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "common.h"
#define POS_X 59

int main(void)
{
	system("mode con: cols=100 lines=30");
	system("title 1705095 ��â�� - 1942 ������Ʈ");
	cursor(0); // 0�� Ŀ�� ����, 1�� Ŀ�� ����
	
	int login_chk = 0;
	int menu_num = 18;
	int key = 0;

	while (menu_num != 24)
	{
		system("cls");
		draw_content(0);

		switch (login_chk)
		{
		default: // ��α���
			gotoxy(39, 18);
			puts("�α���");
			gotoxy(39, 20);
			puts("ȸ������");
			gotoxy(39, 22);
			puts("��ŷȭ��");
			gotoxy(39, 24);
			puts("��������");
			break;
		case 1: // �α���
			gotoxy(39, 18);
			puts("���ӽ���");
			gotoxy(39, 20);
			puts("����");
			gotoxy(39, 22);
			puts("��ŷȮ��");
			gotoxy(39, 24);
			puts("��������");
			break;
		}

		while (key != ENTER)
		{
			gotoxy(POS_X, menu_num);
			puts("��");
			key = getch();
			gotoxy(POS_X, menu_num);
			puts("  ");
			// ȭ���ȣ, �Է¹��� Ű ��, X ��, Y ��
			menu_num = move(0, key, POS_X, menu_num);
		}
		key = 0;

		switch (menu_num)
		{
		case 18:
			login_chk % 2 == 0 ? login_chk = login(1) : game();
			system("mode con: cols=100 lines=30");
			break;
		case 20:
			login_chk % 2 == 0 ? login_chk = login(0) : shop();
			break;
		case 22:
			// login_chk % 2 == 0 ? ranking(0) : ranking(1);
			break;
		case 24:
			break;
		}
	}
	return 0;
}