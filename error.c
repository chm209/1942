#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void error(int error_code)
{
	system("cls");
	set_color(RED);
	gotoxy(22, 10);
	puts("�� DB ���� �Ұ�");
	gotoxy(22, 12);
	puts("���α׷� ������ �ڵ带 �ٽ� Ȯ�� �Ͻʽÿ�.");
	set_color(WHITE);
	gotoxy(22, 14);
	switch (error_code)
	{
	case 0:
		puts("DB ���� ���� �ڵ�");
		break;
	case 1:
		puts("DB TABLE ���� ���� �ڵ�");
		break;
	case 2	:
		puts("�α��� ��ȸ ������ ���� �ڵ�");
		break;
	}
	gotoxy(22, 16);
	puts("                                                       ");
	gotoxy(22, 16);
}