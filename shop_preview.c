#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void shop_preview(int list_num)
{
	for (int i = 4; i < 24; i++)
	{
		gotoxy(59, i);
		printf("                                     ");
	}

	gotoxy(59, 4);
	printf("[������ �̸�]");
	gotoxy(59, 7);
	printf("[������ ����]");
	gotoxy(59, 10);
	printf("[����]");

	switch (list_num)
	{
	case 4:
		gotoxy(59, 5);
		printf("���� �߰�");
		gotoxy(59, 8);
		printf("�÷��̾��� LIFE�� 1 �߰��Ѵ�.");
		gotoxy(59, 11);
		printf("1. �÷��̾��� ü���� 3�̸��϶���");
		gotoxy(59, 12);
		printf("ü���� 1 �߰��ϰ� ��ź �ѹ���");
		gotoxy(59, 13);
		printf("����� �ڵ� �߻� ���ش�.");
		gotoxy(59, 15);
		printf("2. ��ź�� �߻����� ���¿�����");
		gotoxy(59, 16);
		printf("��ź�� ������ 1�� �߰��Ѵ�.");
		gotoxy(59, 18);
		printf("3. �÷��̾��� ü���� 3�̶��");
		gotoxy(59, 19);
		printf("��ź�� 2�� �߰��Ѵ�.");
		gotoxy(59, 21);
		printf("4. ��ź�� 3����� �߰� ���� �ʴ´�.");
		gotoxy(59, 23);
		printf("5. �ִ� 3������ ���� �����ϴ�.");
		break;
	case 6:
		gotoxy(59, 5);
		printf("HP ȸ��");
		gotoxy(59, 8);
		printf("�÷��̾��� HP�� 1 ȸ���Ѵ�.");
		gotoxy(59, 11);
		printf("1. ���� ��� ����");
		gotoxy(59, 13);
		printf("2. HP�� 3�϶��� ��� �Ұ�");
		gotoxy(59, 15);
		printf("3. ������ ����� ������ ����");
		gotoxy(59, 17);
		printf("4. �ִ� 5������ ���� �����ϴ�.");
		break;
	case 8:
		gotoxy(59, 5);
		printf("�߰� ����");
		gotoxy(59, 8);
		printf("�� �ı��� �߰� ���� ȹ�� ����");
		gotoxy(59, 11);
		printf("1. ���� ���۽� �ڵ� ���");
		gotoxy(59, 13);
		printf("2. ��ŷ Ȯ�ν� ������ ��� ǥ��");
		gotoxy(59, 15);
		printf("3. ����Ʈ �߰� ȹ�� ����");
		gotoxy(59, 17);
		printf("4. ������ ���� ����");
		break;
	case 10:
		gotoxy(59, 5);
		printf("���� ����Ʈ");
		gotoxy(59, 8);
		printf("�÷��̾��� ������ ������ �����Ѵ�.");
		gotoxy(59, 11);
		printf("1. �ٸ� ���� ���Ž� �ڵ� �Ǹ�");
		gotoxy(59, 13);
		printf("2. ������ ������ ����");
		gotoxy(59, 15);
		printf("3. ������ ���̴� ����.");
		gotoxy(59, 18);
		printf("������\t\t������");
		gotoxy(59, 20);
		printf("[-*-]");
		gotoxy(80, 20);
		set_color(RED);
		printf("<-*->");
		set_color(WHITE);
		break;
	case 12:
		gotoxy(59, 5);
		printf("�Ķ� ����Ʈ");
		gotoxy(59, 8);
		printf("�÷��̾��� ������ ������ �����Ѵ�.");
		gotoxy(59, 11);
		printf("1. �ٸ� ���� ���Ž� �ڵ� �Ǹ�");
		gotoxy(59, 13);
		printf("2. ������ ������ ����");
		gotoxy(59, 15);
		printf("3. ������ ���̴� ����.");
		gotoxy(59, 18);
		printf("������\t\t������");
		gotoxy(59, 20);
		printf("[-*-]");
		gotoxy(80, 20);
		set_color(BLUE);
		printf("{:*:}");
		set_color(WHITE);
		break;
	case 14:
		gotoxy(59, 5);
		printf("��� ����Ʈ");
		gotoxy(59, 8);
		printf("�÷��̾��� ������ ������ �����Ѵ�.");
		gotoxy(59, 11);
		printf("1. �ٸ� ���� ���Ž� �ڵ� �Ǹ�");
		gotoxy(59, 13);
		printf("2. ������ ������ ����");
		gotoxy(59, 15);
		printf("3. ������ ���̴� ����.");
		gotoxy(59, 18);
		printf("������\t\t������");
		gotoxy(59, 20);
		printf("[-*-]");
		gotoxy(80, 20);
		set_color(YELLOW);
		printf("H:*:H");
		set_color(WHITE);
		break;
	case 16:
		gotoxy(59, 5);
		printf("���� �Ѿ�");
		gotoxy(59, 8);
		printf("�÷��̾��� �Ѿ� ������ �����Ѵ�.");
		gotoxy(59, 11);
		printf("1. �ٸ� ���� ���Ž� �ڵ� �Ǹ�");
		gotoxy(59, 13);
		printf("2. �Ѿ� ������ ����");
		gotoxy(59, 15);
		printf("3. ������ ���̴� ����.");
		gotoxy(59, 18);
		printf("������\t\t������");
		gotoxy(59, 20);
		printf("�� �� ��");
		gotoxy(80, 20);
		set_color(RED);
		printf("�� �� ��");
		set_color(WHITE);
		break;
	case 18:
		gotoxy(59, 5);
		printf("�Ķ� �Ѿ�");
		gotoxy(59, 8);
		printf("�÷��̾��� �Ѿ� ������ �����Ѵ�.");
		gotoxy(59, 11);
		printf("1. �ٸ� ���� ���Ž� �ڵ� �Ǹ�");
		gotoxy(59, 13);
		printf("2. �Ѿ� ������ ����");
		gotoxy(59, 15);
		printf("3. ������ ���̴� ����.");
		gotoxy(59, 18);
		printf("������\t\t������");
		gotoxy(59, 20);
		printf("�� �� ��");
		gotoxy(80, 20);
		set_color(BLUE);
		printf("�� �� ��");
		set_color(WHITE);
		break;
	case 20:
		gotoxy(59, 5);
		printf("��� �Ѿ�");
		gotoxy(59, 8);
		printf("�÷��̾��� �Ѿ� ������ �����Ѵ�.");
		gotoxy(59, 11);
		printf("1. �ٸ� ���� ���Ž� �ڵ� �Ǹ�");
		gotoxy(59, 13);
		printf("2. �Ѿ� ������ ����");
		gotoxy(59, 15);
		printf("3. ������ ���̴� ����.");
		gotoxy(59, 18);
		printf("������\t\t������");
		gotoxy(59, 20);
		printf("�� �� ��");
		gotoxy(80, 20);
		set_color(YELLOW);
		printf("�� �� ��");
		set_color(WHITE);
		break;
	case 22:
		gotoxy(59, 5);
		printf("��ŷâ �ٹ̱�");
		gotoxy(59, 8);
		printf("��ŷâ�� �������� �ٸ��ݴϴ�.");
		gotoxy(59, 11);
		printf("1. ���� ������ �ο��մϴ�.");
		gotoxy(59, 13);
		printf("2. ������ 14���� �Դϴ�.");
		gotoxy(59, 15);
		printf("2. �籸�Ž� ������ ���� �˴ϴ�.");
		break;
	}
}