#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void shop_preview(int list_num)
{
	for (int i = 4; i < 24; i++)
	{
		gotoxy(59, i);
		puts("                                     ");
	}

	gotoxy(59, 4);
	puts("[������ �̸�]");
	gotoxy(59, 7);
	puts("[������ ����]");
	gotoxy(59, 10);
	puts("[����]");

	switch (list_num)
	{
	case 4:
		gotoxy(59, 5);
		puts("���� �߰�");
		gotoxy(59, 8);
		puts("�÷��̾��� LIFE�� 1 �߰��Ѵ�.");
		gotoxy(59, 11);
		puts("1. �÷��̾��� ü���� 3�̸��϶���");
		gotoxy(59, 12);
		puts("ü���� 1 �߰��ϰ� ��ź �ѹ���");
		gotoxy(59, 13);
		puts("����� �ڵ� �߻� ���ش�.");
		gotoxy(59, 15);
		puts("2. ��ź�� �߻����� ���¿�����");
		gotoxy(59, 16);
		puts("��ź�� ������ 1�� �߰��Ѵ�.");
		gotoxy(59, 18);
		puts("3. �÷��̾��� ü���� 3�̶��");
		gotoxy(59, 19);
		puts("��ź�� 2�� �߰��Ѵ�.");
		gotoxy(59, 21);
		puts("4. ��ź�� 3����� �߰� ���� �ʴ´�.");
		gotoxy(59, 23);
		puts("5. �ִ� 3������ ���� �����ϴ�.");
		break;
	case 6:
		gotoxy(59, 5);
		puts("HP ȸ��");
		gotoxy(59, 8);
		puts("�÷��̾��� HP�� 1 ȸ���Ѵ�.");
		gotoxy(59, 11);
		puts("1. ���� ��� ����");
		gotoxy(59, 13);
		puts("2. HP�� 3�϶��� ��� �Ұ�");
		gotoxy(59, 15);
		puts("3. ������ ����� ������ ����");
		gotoxy(59, 17);
		puts("4. �ִ� 5������ ���� �����ϴ�.");
		break;
	case 8:
		gotoxy(59, 5);
		puts("�߰� ����");
		gotoxy(59, 8);
		puts("�� �ı��� �߰� ���� ȹ�� ����");
		gotoxy(59, 11);
		puts("1. ���� ���۽� �ڵ� ���");
		gotoxy(59, 13);
		puts("2. ��ŷ Ȯ�ν� ������ ��� ǥ��");
		gotoxy(59, 15);
		puts("3. ����Ʈ �߰� ȹ�� ����");
		gotoxy(59, 17);
		puts("4. ������ ���� ����");
		break;
	case 10:
		gotoxy(59, 5);
		puts("���� ����Ʈ");
		gotoxy(59, 8);
		puts("�÷��̾��� ������ ������ �����Ѵ�.");
		gotoxy(59, 11);
		puts("1. �ٸ� ���� ���Ž� �ڵ� �Ǹ�");
		gotoxy(59, 13);
		puts("2. ������ ������ ����");
		gotoxy(59, 15);
		puts("3. ������ ���̴� ����.");
		gotoxy(59, 18);
		puts("������\t\t������");
		gotoxy(59, 20);
		puts("[-*-]");
		gotoxy(80, 20);
		set_color(12);
		puts("<-*->");
		set_color(15);
		break;
	case 12:
		gotoxy(59, 5);
		puts("�Ķ� ����Ʈ");
		gotoxy(59, 8);
		puts("�÷��̾��� ������ ������ �����Ѵ�.");
		gotoxy(59, 11);
		puts("1. �ٸ� ���� ���Ž� �ڵ� �Ǹ�");
		gotoxy(59, 13);
		puts("2. ������ ������ ����");
		gotoxy(59, 15);
		puts("3. ������ ���̴� ����.");
		gotoxy(59, 18);
		puts("������\t\t������");
		gotoxy(59, 20);
		puts("[-*-]");
		gotoxy(80, 20);
		set_color(9);
		puts("{:*:}");
		set_color(15);
		break;
	case 14:
		gotoxy(59, 5);
		puts("��� ����Ʈ");
		gotoxy(59, 8);
		puts("�÷��̾��� ������ ������ �����Ѵ�.");
		gotoxy(59, 11);
		puts("1. �ٸ� ���� ���Ž� �ڵ� �Ǹ�");
		gotoxy(59, 13);
		puts("2. ������ ������ ����");
		gotoxy(59, 15);
		puts("3. ������ ���̴� ����.");
		gotoxy(59, 18);
		puts("������\t\t������");
		gotoxy(59, 20);
		puts("[-*-]");
		gotoxy(80, 20);
		set_color(14);
		puts("H:*:H");
		set_color(15);
		break;
	case 16:
		gotoxy(59, 5);
		puts("���� �Ѿ�");
		gotoxy(59, 8);
		puts("�÷��̾��� �Ѿ� ������ �����Ѵ�.");
		gotoxy(59, 11);
		puts("1. �ٸ� ���� ���Ž� �ڵ� �Ǹ�");
		gotoxy(59, 13);
		puts("2. �Ѿ� ������ ����");
		gotoxy(59, 15);
		puts("3. ������ ���̴� ����.");
		gotoxy(59, 18);
		puts("������\t\t������");
		gotoxy(59, 20);
		puts("�� �� ��");
		gotoxy(80, 20);
		set_color(12);
		puts("�� �� ��");
		set_color(15);
		break;
	case 18:
		gotoxy(59, 5);
		puts("�Ķ� �Ѿ�");
		gotoxy(59, 8);
		puts("�÷��̾��� �Ѿ� ������ �����Ѵ�.");
		gotoxy(59, 11);
		puts("1. �ٸ� ���� ���Ž� �ڵ� �Ǹ�");
		gotoxy(59, 13);
		puts("2. �Ѿ� ������ ����");
		gotoxy(59, 15);
		puts("3. ������ ���̴� ����.");
		gotoxy(59, 18);
		puts("������\t\t������");
		gotoxy(59, 20);
		puts("�� �� ��");
		gotoxy(80, 20);
		set_color(9);
		puts("�� �� ��");
		set_color(15);
		break;
	case 20:
		gotoxy(59, 5);
		puts("��� �Ѿ�");
		gotoxy(59, 8);
		puts("�÷��̾��� �Ѿ� ������ �����Ѵ�.");
		gotoxy(59, 11);
		puts("1. �ٸ� ���� ���Ž� �ڵ� �Ǹ�");
		gotoxy(59, 13);
		puts("2. �Ѿ� ������ ����");
		gotoxy(59, 15);
		puts("3. ������ ���̴� ����.");
		gotoxy(59, 18);
		puts("������\t\t������");
		gotoxy(59, 20);
		puts("�� �� ��");
		gotoxy(80, 20);
		set_color(14);
		puts("�� �� ��");
		set_color(15);
		break;
	case 22:
		gotoxy(59, 5);
		puts("��ŷâ �ٹ̱�");
		gotoxy(59, 8);
		puts("��ŷâ�� �������� �ٸ��ݴϴ�.");
		gotoxy(59, 11);
		puts("1. ������ ���� ������ �ο��մϴ�.");
		gotoxy(59, 13);
		puts("2. ����");
		break;
	}
}