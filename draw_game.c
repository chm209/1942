#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void draw_game(int screen_num)
{
	switch (screen_num)
	{
	// ����ȭ�� - ���� ���� ������
	case 0:
		for (int i = 0; i < 30; i++)
		{
			gotoxy(4, i);
			printf(":");
			gotoxy(56, i);
			printf(":");
			// draw_content(0) ���� printf ����� ���� ����
		}
		break;
	// ����ȭ�� - PAUSE ȭ��
	case 1:
		gotoxy(16, 10);
		puts("PAUSE");
		gotoxy(15, 11);
		puts("��������������������������������������������������������������");
		gotoxy(15, 12);
		printf("��  ������ ���� �Ͻðڽ��ϱ�?  ��");
		gotoxy(15, 13);
		puts("��������������������������������������������������������������");
		gotoxy(15, 14);
		printf("��   �� (  )  ��  �ƴϿ� (  )   ��");
		gotoxy(15, 15);
		puts("��������������������������������������������������������������");
		break;
	// ����â
	case 2:
		gotoxy(58, 1);
		printf("����������������������������������������");
		gotoxy(58, 2);
		printf("��                  ��");
		gotoxy(58, 3);
		printf("����������������������������������������");
		gotoxy(58, 4);
		printf("��                  ��");
		gotoxy(58, 5);
		printf("����������������������������������������");
		gotoxy(59, 6);
		printf("��������������������");
		break;
	// ���ӿ��� ���� ���
	case 3:
		gotoxy(16, 3);
		printf("GAME OVER");
		gotoxy(16, 26);
		system("pause");
		break;
	// ����Ŭ���� ���� ���
	case 4:
		gotoxy(16, 3);
		printf("GAME CLEAR");
		gotoxy(16, 26);
		system("pause");
		break;
	// game_help, ���� ȭ��
	case 5:
		gotoxy(15, 4);
		printf("������������������������������������������������������������������������������������������������");
		gotoxy(15, 5);
		printf("��                                              ��");
		gotoxy(15, 6);
		printf("��                                              ��");
		gotoxy(15, 7);
		printf("��                                              ��");
		gotoxy(15, 8);
		printf("��                                              ��");
		gotoxy(15, 9);
		printf("��                                              ��");
		gotoxy(15, 10);
		printf("��                                              ��");
		gotoxy(15, 11);
		printf("��                                              ��");
		gotoxy(15, 12);
		printf("��                                              ��");
		gotoxy(15, 13);
		printf("��                                              ��");
		gotoxy(15, 14);
		printf("��                                              ��");
		gotoxy(15, 15);
		printf("��                                              ��");
		gotoxy(15, 16);
		printf("��                                              ��");
		gotoxy(15, 17);
		printf("��                                              ��");
		gotoxy(15, 18);
		printf("��                                              ��");
		gotoxy(15, 19);
		printf("��                                              ��");
		gotoxy(15, 20);
		printf("��                                              ��");
		gotoxy(15, 21);
		printf("��                                              ��");
		gotoxy(15, 22);
		printf("��                                              ��");
		gotoxy(15, 23);
		printf("��                                              ��");
		gotoxy(15, 24);
		printf("��                                              ��");
		gotoxy(15, 25);
		printf("������������������������������������������������������������������������������������������������");
		break;
	// game_help ȭ��
	case 6:
		gotoxy(20, 6);
		printf("���� ���� ���");
		gotoxy(20, 8);
		printf("�����̱�: ����Ű");
		gotoxy(20, 10);
		printf("�⺻ ����: �����̽���");
		gotoxy(20, 12);
		printf("��ź ����: Z Ű");
		gotoxy(20, 14);
		printf("���� �߰� ������: X Ű");
		gotoxy(20, 16);
		printf("ü�� ȸ�� ������: C Ű");
		set_color(RED);
		gotoxy(20, 18);
		printf("�߰� ���� �������� �ڵ� ����˴ϴ�.");
		set_color(WHITE);
		gotoxy(20, 21);
		printf("�� ��ü�� ȹ�� ������ �ٸ��ϴ�.");
		gotoxy(20, 23);
		printf("���� ������ �̿�� ������ �����˴ϴ�.");
		break;
	}
}