#include <stdio.h>
#include <stdlib.h>  
#include "common.h"

void ranking(int screenNum)
{
	system("cls");
	int key = 0;

	switch (screenNum)
	{
	// ��α���
	case 0:
		draw_content(5);
		draw_content(6);
		// DB ���� �޾Ƽ� ���� �׷��ִ� �Լ�
		while (key != ESC)
		{
			key = getch();
		}
		break;
	// �α���
	case 1:
		draw_content(7);
		draw_content(8);
		// DB ���� �޾Ƽ� ���� �׷��ִ� �Լ�
		while (key != ESC)
		{
			key = getch();
		}
		break;
	}
}


// ��α���
// ���̺� ���� -> ��ü ���� 1~15�� (2~3 ������), Ű���� �¿� ����Ű, ESC ������
// �� ���������� ���� ���� (DB ��ŷ ���̺� �߰�) -> userID usertable, ranking usertable, item shop table
// 
// �α���
// ��� ���� ���
// �ϴ� ���̺� ���� -> ��ü ���� 1~10�� (2~3 ������), Ű���� �¿�, ESC ������
// �� ���������� ���� ���� (DB ��ŷ ���̺� �߰�) -> userID usertable, ranking usertable, item shop table
// 
// ��ü���� ������ �����