#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void draw_content(int screen_num)
{
	switch (screen_num)
	{
	// ���� ȭ��
	case 0:
		system("cls");
		// 1
		gotoxy(25, 3);
		puts("�Ȣ�");
		gotoxy(23, 4);
		puts("�ɢȢ�");
		gotoxy(21, 5);
		puts("�ɢɢȢ�");
		gotoxy(25, 6);
		puts("�Ȣ�");
		gotoxy(25, 7);
		puts("�Ȣ�");
		gotoxy(25, 8);
		puts("�Ȣ�");
		gotoxy(25, 9);
		puts("�Ȣ�");
		gotoxy(21, 10);
		puts("�ǢǢȢȢǢ�");
		gotoxy(21, 11);
		puts("�ǢǢȢȢǢ�");
		// 9
		gotoxy(35, 3);
		puts("�̢ǢǢȢ�");
		gotoxy(35, 4);
		puts("��    �Ȣ�");
		gotoxy(35, 5);
		puts("��    �Ȣ�");
		gotoxy(35, 6);
		puts("�̢ǢǢȢ�");
		gotoxy(41, 7);
		puts("�Ȣ�");
		gotoxy(41, 8);
		puts("�Ȣ�");
		gotoxy(41, 9);
		puts("�Ȣ�");
		gotoxy(41, 10);
		puts("�Ȣ�");
		gotoxy(41, 11);
		puts("�Ȣ�");
		// 4
		gotoxy(49, 3);
		puts("��    �Ȣ�");
		gotoxy(49, 4);
		puts("��    �Ȣ�");
		gotoxy(49, 5);
		puts("��    �Ȣ�");
		gotoxy(49, 6);
		puts("��    �Ȣ�");
		gotoxy(49, 7);
		puts("�̢ǢǢȢȢǢ�");
		gotoxy(55, 8);
		puts("�Ȣ�");
		gotoxy(55, 9);
		puts("�Ȣ�");
		gotoxy(55, 10);
		puts("�Ȣ�");
		gotoxy(55, 11);
		puts("�Ȣ�");
		// 2
		gotoxy(65, 3);
		puts("�ǢǢǢǢǢȢ�");
		gotoxy(65, 4);
		puts("�ǢǢǢǢǢȢ�");
		gotoxy(75, 5);
		puts("�Ȣ�");
		gotoxy(75, 6);
		puts("�Ȣ�");
		gotoxy(65, 7);
		puts("�̢ȢǢǢǢȢ�");
		gotoxy(65, 8);
		puts("�ȢȢǢǢǢȢ�");
		gotoxy(65, 9);
		puts("�Ȣ�");
		gotoxy(65, 10);
		puts("�Ȣ�");
		gotoxy(65, 11);
		puts("�̢ȢǢǢǢǢ�");
		gotoxy(51, 13);
		puts("1705095 ��â�� �⸻ ������Ʈ");
		gotoxy(2, 29);
		puts("���۹��: ���� �� �� �� �� ���� ENTER ������ Z X");
		break;
	// ���� ȭ��
	case 1:
		for (int i = 0; i <= 30; i += 1)
		{
			gotoxy(4, i);
			puts(":");
			gotoxy(56, i);
			puts(":");
		}
		break;
	// pause ȭ��
	case 2:
		gotoxy(16, 10);
		puts("PAUSE");
		gotoxy(15, 11);
		puts("��������������������������������������������������������������");
		gotoxy(15, 12);
		puts("��  ������ ���� �Ͻðڽ��ϱ�?  ��");
		gotoxy(15, 13);
		puts("��������������������������������������������������������������");
		gotoxy(15, 14);
		puts("��   �� (  )  ��  �ƴϿ� (  )   ��");
		gotoxy(15, 15);
		puts("��������������������������������������������������������������");
		break;
	// ���� ȭ��
	case 3:
		gotoxy(4, 1);
		puts("����������������������������������������������������������������������������������������������������������������������");
		break;
	}
}