#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void draw_content(int screen_num)
{
	switch (screen_num)
	{
	// ����ȭ�� - ��Ʈ ���
	case 0:
		system("cls");
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 100; j += 2)
			{
				gotoxy(j, i);
				printf("��");
			}
		}
		break;
	// ����ȭ�� - 1942 ���� ���
	case 1:
	{
		// 1
		gotoxy(24, 3);
		printf("�ܡ�");
		gotoxy(22, 4);
		printf("�ܡܡ�");
		gotoxy(20, 5);
		printf("�ܡܡܡ�");
		gotoxy(24, 6);
		printf("�ܡ�");
		gotoxy(24, 7);
		printf("�ܡ�");
		gotoxy(24, 8);
		printf("�ܡ�");
		gotoxy(24, 9);
		printf("�ܡ�");
		gotoxy(20, 10);
		printf("�ܡܡܡܡܡ�");
		gotoxy(20, 11);
		printf("�ܡܡܡܡܡ�");
		// 9
		gotoxy(38, 3);
		printf("�ܡܡ�");
		gotoxy(36, 4);
		printf("��");
		gotoxy(44, 4);
		printf("��");
		gotoxy(36, 5);
		printf("��");
		gotoxy(44, 5);
		printf("��");
		gotoxy(36, 6);
		printf("��");
		gotoxy(44, 6);
		printf("��");
		gotoxy(38, 7);
		printf("�ܡܡܡ�");
		gotoxy(42, 8);
		printf("�ܡ�");
		gotoxy(42, 9);
		printf("�ܡ�");
		gotoxy(42, 10);
		printf("�ܡ�");
		gotoxy(42, 11);
		printf("�ܡ�");
		// 4
		gotoxy(60, 3);
		printf("��");
		gotoxy(58, 4);
		printf("�ܡ�");
		gotoxy(56, 5);
		printf("��");
		gotoxy(60, 5);
		printf("��");
		gotoxy(54, 6);
		printf("��");
		gotoxy(60, 6);
		printf("��");
		gotoxy(52, 7);
		printf("��");
		gotoxy(60, 7);
		printf("��");
		gotoxy(50, 8);
		printf("�ܡܡܡܡܡܡ�");
		gotoxy(60, 9);
		printf("��");
		gotoxy(60, 10);
		printf("��");
		gotoxy(60, 11);
		printf("��");
		// 2
		gotoxy(70, 3);
		printf("�ܡܡܡ�");
		gotoxy(68, 4);
		printf("��");
		gotoxy(78, 4);
		printf("��");
		gotoxy(68, 5);
		printf("��");
		gotoxy(78, 5);
		printf("��");
		gotoxy(76, 6);
		printf("��");
		gotoxy(74, 7);
		printf("��");
		gotoxy(72, 8);
		printf("��");
		gotoxy(70, 9);
		printf("��");
		gotoxy(68, 10);
		printf("��");
		gotoxy(68, 11);
		printf("�ܡܡܡܡܡ�");
		}
		break;
	// ����ȭ�� - ����Ű ������, �ؽ�Ʈ ���
	case 2:
	{
		gotoxy(18, 17);
		printf("��������������������������������������������������������");
		gotoxy(18, 18);
		printf("��                          ��");
		gotoxy(18, 19);
		printf("��                          ��");
		gotoxy(18, 20);
		printf("��                          ��");
		gotoxy(18, 21);
		printf("��                          ��");
		gotoxy(18, 22);
		printf("��                          ��");
		gotoxy(18, 23);
		printf("��                          ��");
		gotoxy(18, 24);
		printf("��                          ��");
		gotoxy(18, 25);
		printf("��                          ��");
		gotoxy(18, 26);
		printf("��                          ��");
		gotoxy(18, 27);
		printf("��������������������������������������������������������");
		gotoxy(21, 18);
		printf("����ȭ�� ����Ű");
		gotoxy(18, 19);
		printf("��������������������������������������������������������");
		gotoxy(21, 21);
		printf("��   | Ű���� ����Ű ��");
		gotoxy(21, 23);
		printf("�Ʒ� | Ű���� ����Ű ��");
		gotoxy(21, 25);
		printf("Ȯ�� | Ű���� ����Ű");
	}
		break;
	// ����ȭ�� - �α����� �ؽ�Ʈ ���
	case 3:
	{
		gotoxy(56, 19);
		printf("�α���");
		gotoxy(56, 21);
		printf("ȸ������");
		gotoxy(56, 23);
		printf("��ŷȭ��");
		gotoxy(56, 25);
		printf("��������");
	}
		break;
	// ����ȭ�� - �α����� �ؽ�Ʈ ���
	case 4:
	{
		gotoxy(56, 19);
		printf("���ӽ���");
		gotoxy(56, 21);
		printf("����");
		gotoxy(56, 23);
		printf("��ŷȮ��");
		gotoxy(56, 25);
		printf("��������");
		gotoxy(0, 29);
		printf("�α��� ����: %s", user.id);
	}
		break;
	// �α��� ȭ�� - ȭ�� ����⸦ ���� ���� ���
	case 5:
	{
		gotoxy(34, 18);
		printf("                                 ");
		gotoxy(34, 20);
		printf("                                 ");
		gotoxy(34, 22);
		printf("                                 ");
		gotoxy(34, 24);
		printf("                                 ");
		cursor(1);
	}
		break;
	// ��ŷȭ�� - ��α��� ���� ������ ���
	case 6:
	{
		gotoxy(2, 1);
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
		for (int i = 2; i < 27; i++)
		{
			gotoxy(2, i);
			printf("��");
			gotoxy(8, i);
			printf("��");
			gotoxy(30, i);
			printf("��");
			gotoxy(50, i);
			printf("��");
			gotoxy(96, i);
			printf("��");
		}
		for (int i = 3; i < 27; i += 2)
		{
			gotoxy(3, i);
			printf("������������");
			gotoxy(9, i);
			printf("��������������������������������������������");
			gotoxy(31, i);
			printf("����������������������������������������������������������������������������������������������������������������������������������");
		}
		gotoxy(2, 27);
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
	}
		break;
	// ��ŷȭ�� - ��α��� ���� �ؽ�Ʈ ���
	case 7:
	{
		gotoxy(4, 2);
		printf("����");
		int colum = 4;
		for (int i = 1; i < 13; i++)
		{
			gotoxy(5, colum);
			printf("%2d", i);
			colum += 2;
		}
		gotoxy(18, 2);
		printf("�̸�");
		gotoxy(39, 2);
		printf("����");
		gotoxy(68, 2);
		printf("��� ������");
		gotoxy(74, 28);
		printf("��ŷȭ�� ������: ESC Ű");
	}
		break;
	// ��ŷȭ�� - �α��� ���� ������ ���
	case 8:
	{
		gotoxy(2, 1);
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
		for (int i = 2; i < 9; i++)
		{
			gotoxy(2, i);
			printf("��");
			gotoxy(96, i);
			printf("��");
		}
		for (int i = 2; i < 9; i++)
		{
			gotoxy(30, i);
			printf("��");
		}
		for (int i = 9; i < 27; i++)
		{
			gotoxy(2, i);
			printf("��");
			gotoxy(8, i);
			printf("��");
			gotoxy(30, i);
			printf("��");
			gotoxy(50, i);
			printf("��");
			gotoxy(96, i);
			printf("��");
		}
		gotoxy(2, 9);
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
		for (int i = 11; i < 27; i += 2)
		{
			gotoxy(3, i);
			printf("������������");
			gotoxy(9, i);
			printf("��������������������������������������������");
			gotoxy(31, i);
			printf("����������������������������������������������������������������������������������������������������������������������������������");
		}
		gotoxy(2, 27);
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
	}
		break;
	// ��ŷȭ�� - �α��� ���� �ؽ�Ʈ ���
	case 9:
	{
		// ���� ����
		gotoxy(5, 3);
		printf("�� ������: ");
		gotoxy(5, 5);
		printf("�Ѿ� ���: ");
		gotoxy(5, 7);
		printf("���� ����: ");
		gotoxy(33, 3);
		printf("�̸�");
		gotoxy(33, 5);
		printf("����Ʈ");
		gotoxy(64, 3);
		printf("�ְ�����");
		gotoxy(33, 7);
		printf("����� ������");
		// ���� ����Ʈ
		gotoxy(4, 10);
		printf("����");
		int colum = 12;
		for (int i = 1; i < 9; i++)
		{
			gotoxy(5, colum);
			printf("%d", i);
			colum += 2;
		}
		gotoxy(18, 10);
		printf("�̸�");
		gotoxy(39, 10);
		printf("����");
		gotoxy(68, 10);
		printf("��� ������");
		gotoxy(74, 28);
		printf("��ŷȭ�� ������: ESC Ű");
	}
		break;
	// ����ȭ�� - ������ ���
	case 10:
	{
		gotoxy(2, 1);
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
		for (int i = 2; i < 24; i++)
		{
			gotoxy(2, i);
			printf("��");
			gotoxy(22, i);
			printf("��");
			gotoxy(36, i);
			printf("��");
			gotoxy(46, i);
			printf("��");
			gotoxy(54, i);
			printf("��");
			gotoxy(96, i);
			printf("��");
		}
		for (int i = 3; i < 24; i += 2)
		{
			gotoxy(2, i);
			printf("����������������������������������������");
			gotoxy(22, i);
			printf("����������������������������");
			gotoxy(36, i);
			printf("��������������������");
			gotoxy(46, i);
			printf("����������������");
			gotoxy(54, i);
			printf("��");
		}
		gotoxy(36, 23);
		printf("��������������������");
		gotoxy(46, 23);
		printf("����������������");
		gotoxy(2, 24);
		printf("��");
		gotoxy(22, 24);
		printf("��");
		gotoxy(54, 24);
		printf("��");
		gotoxy(96, 24);
		printf("��");
		gotoxy(2, 25);
		printf("����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������");
	}
		break;
	// ����ȭ�� - �ؽ�Ʈ ���
	case 11:
	{
		gotoxy(3, 26);
		printf("ġ�� �������� �ϳ����� ���� ���� �մϴ�. / ���� ġ�� �������� 60%% ���ݿ� �ڵ� �Ǹ� �˴ϴ�.");
		gotoxy(3, 28);
		printf("��� �̵�: ����Ű �� ��  ||  ����: ����Ű                                  ���� ������: ESC Ű");
		gotoxy(11, 2);
		printf("�׸�");
		gotoxy(28, 2);
		printf("����");
		gotoxy(39, 2);
		printf("������");
		gotoxy(49, 2);
		printf("����");
		gotoxy(5, 4);
		printf("���� �߰�");
		gotoxy(5, 6);
		printf("HP ȸ��");
		gotoxy(5, 8);
		printf("�߰� ����");
		gotoxy(5, 10);
		printf("���� ����Ʈ");
		gotoxy(5, 12);
		printf("�Ķ� ����Ʈ");
		gotoxy(5, 14);
		printf("��� ����Ʈ");
		gotoxy(5, 16);
		printf("���� �Ѿ�");
		gotoxy(5, 18);
		printf("�Ķ� �Ѿ�");
		gotoxy(5, 20);
		printf("��� �Ѿ�");
		gotoxy(5, 22);
		printf("��ŷâ �ٹ̱�");
		gotoxy(5, 24);
		printf("���� ����Ʈ");
	}
		break;
	case 12:
	{
		gotoxy(29, 4);
		printf("1000 pt");
		gotoxy(30, 6);
		printf("500 pt");
		gotoxy(29, 8);
		printf("2000 pt");
		gotoxy(29, 10);
		printf("3500 pt");
		gotoxy(29, 12);
		printf("4500 pt");
		gotoxy(29, 14);
		printf("5500 pt");
		gotoxy(29, 16);
		printf("3500 pt");
		gotoxy(29, 18);
		printf("4500 pt");
		gotoxy(29, 20);
		printf("5500 pt");
		gotoxy(27, 22);
		printf("100000 pt");
	}
		break;
	case 13:
	{
		for (int i = 4; i < 24; i++)
		{
			gotoxy(59, i);
			printf("                                     ");
		}
		gotoxy(59, 5);
		printf("���� �Ұ�");
		set_color(12);
		gotoxy(59, 8);
		printf("����Ʈ�� �����մϴ�.");
		set_color(15);
	}
		break;
	}
}