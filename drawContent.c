#include <stdio.h>
#include <stdlib.h>
#include "common.h"

// ȭ���ȣ�� �Է¹޾� ��Ȳ�� �°� �׷���
void drawContent(int scr_num)
{
	switch (scr_num)
	{
	// ���� ȭ��
	case 0:
		system("cls");
		// 1
		gotoxy(25, 3);
		printf("�Ȣ�");
		gotoxy(23, 4);
		printf("�ɢȢ�");
		gotoxy(21, 5);
		printf("�ɢɢȢ�");
		gotoxy(25, 6);
		printf("�Ȣ�");
		gotoxy(25, 7);
		printf("�Ȣ�");
		gotoxy(25, 8);
		printf("�Ȣ�");
		gotoxy(25, 9);
		printf("�Ȣ�");
		gotoxy(21, 10);
		printf("�ǢǢȢȢǢ�");
		gotoxy(21, 11);
		printf("�ǢǢȢȢǢ�");
		// 9
		gotoxy(35, 3);
		printf("�̢ǢǢȢ�");
		gotoxy(35, 4);
		printf("��    �Ȣ�");
		gotoxy(35, 5);
		printf("��    �Ȣ�");
		gotoxy(35, 6);
		printf("�̢ǢǢȢ�");
		gotoxy(41, 7);
		printf("�Ȣ�");
		gotoxy(41, 8);
		printf("�Ȣ�");
		gotoxy(41, 9);
		printf("�Ȣ�");
		gotoxy(41, 10);
		printf("�Ȣ�");
		gotoxy(41, 11);
		printf("�Ȣ�");
		// 4
		gotoxy(49, 3);
		printf("��    �Ȣ�");
		gotoxy(49, 4);
		printf("��    �Ȣ�");
		gotoxy(49, 5);
		printf("��    �Ȣ�");
		gotoxy(49, 6);
		printf("��    �Ȣ�");
		gotoxy(49, 7);
		printf("�̢ǢǢȢȢǢ�");
		gotoxy(55, 8);
		printf("�Ȣ�");
		gotoxy(55, 9);
		printf("�Ȣ�");
		gotoxy(55, 10);
		printf("�Ȣ�");
		gotoxy(55, 11);
		printf("�Ȣ�");
		// 2
		gotoxy(65, 3);
		printf("�ǢǢǢǢǢȢ�");
		gotoxy(65, 4);
		printf("�ǢǢǢǢǢȢ�");
		gotoxy(75, 5);
		printf("�Ȣ�");
		gotoxy(75, 6);
		printf("�Ȣ�");
		gotoxy(65, 7);
		printf("�̢ȢǢǢǢȢ�");
		gotoxy(65, 8);
		printf("�ȢȢǢǢǢȢ�");
		gotoxy(65, 9);
		printf("�Ȣ�");
		gotoxy(65, 10);
		printf("�Ȣ�");
		gotoxy(65, 11);
		printf("�̢ȢǢǢǢǢ�");
		gotoxy(51, 13);
		printf("1705095 ��â�� �⸻ ������Ʈ");
		gotoxy(2, 29);
		printf("���۹��: ���� �� �� �� �� ���� ENTER ������ Z X C");
		break;
	// ���� ȭ��
	case 1:
		for (int i = 0; i <= 30; i += 1)
		{
			gotoxy(4, i);
			printf(":");
			gotoxy(56, i);
			printf(":");
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
	}
}