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
	}
}