#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "common.h"
#define POS_X 50

// DB ������ �۾� ����
// ���� ����Ʈ �ҷ�����, ǥ�� �ʿ�
// ġ�� �������� �̹� ������ ��� �����׸� ��� �ʿ�
// �Ѿ� ���1�� �⺻ 2�� Ŀ����
// 2�� ��� 1�� �ڵ����� �Ǹ��ع����� ������� ġ�� ������ ����
// shop_preview �Լ� ���� �ʿ�
// ������ ����� ���� �÷��̾��� ���� ���������� ���� �ʿ�
void shop()
{
	system("cls");
	int key = 0, item_num = 4;
	
	while (1)
	{
		draw_content(3); // UI ���� ���
		draw_content(4); // ���� �׸� ���
		// ���ݰ� �������� DB������ �ٸ� �Լ��� ���� ����ؾ� �ҵ�
		shop_preview(item_num);
		gotoxy(POS_X, item_num);
		puts("��");

		while (key != ENTER && key != ESC)
		{
			gotoxy(POS_X, item_num);
			puts("��");
			key = getch();

			if (key != ESC)
			{
				gotoxy(POS_X, item_num);
				puts("  ");
				// ȭ���ȣ, �Է¹��� Ű ��, X ��, Y ��
				item_num = move(2, key, POS_X, item_num);
				shop_preview(item_num);
			}
			else
			{
				break;
			}
		}
		if (key == ESC)
		{
			break;
		}
		key = 0;
	}
}