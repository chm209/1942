#include <stdio.h>
#include <windows.h>
#include "common.h"
#define POS_X 50

// �� ���� �޸�
// 1. DB ������ ���� ����Ʈ, ������ ������ ����Ʈ ��� �ʿ�
// 2. ġ��������� Ÿ�Ժ� �ϳ��� ���� ����, �ٸ��� ��� �ڵ� �Ǹ�
void shop()
{
	system("cls");
	int key = 0, item_num = 4; // ����Ʈ ù��° Y���� 4

	draw_content(3); // ��ü���� UI
	// ���� ���� (����Ʈ, ���� ������ ��� �ʿ�)
	draw_content(4); // ������ �׸�
	shop_preview(item_num);

	while (key != ESC)
	{
		gotoxy(POS_X, item_num);
		puts("��");
		shop_preview(item_num);
		key = getch();

		if (key == ENTER)
		{
			// ���� ���μ���
			// ���� ���� ����Ʈ�� ������ ���� ��
			// ���� ���� ����Ʈ�� �� ũ�ٸ� ġ�� ���������� Ȯ��
			// ġ�� �������� �ƴ϶�� �ִ� ���� ���� �̸����� ������ �ִ��� Ȯ��
			// ���� ����ϸ� ����
			// �ϳ��� �ɸ��� ���� �Ұ�, ���� �Ұ� ���� ���
			key = 0;
		}
		else
		{
			gotoxy(POS_X, item_num);
			puts("  ");
			// ȭ���ȣ, �Է¹��� Ű ��, X ��, Y ��
			item_num = move(2, key, POS_X, item_num);
		}
	}
}