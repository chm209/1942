#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int login(int screen_num)
{
	char* user_id = malloc(sizeof(char) * 20);
	char* user_password = malloc(sizeof(char) * 20);

	switch (screen_num)
	{
	case 0:
		gotoxy(39, 18);
		printf("                            ");
		gotoxy(39, 20);
		printf("                            ");
		gotoxy(39, 22);
		printf("                            ");
		gotoxy(39, 24);
		printf("                            ");
		cursor(1);
		gotoxy(39, 18);
		printf("ȸ������");
		gotoxy(39, 20);
		printf("20�� �̳��� �Է��Ͻʽÿ�");
		gotoxy(39, 22);
		printf("���̵�: ");
		scanf("%s", user_id);
		gotoxy(39, 24);
		printf("��й�ȣ: ");
		scanf("%s", user_password);
		cursor(0);
		/*
		* ȸ�������� �α��� ������ ���� break ����
		* DB �����Ϳ��� ID �ߺ� Ȯ�� �ʿ���
		* DB ���� ��� �ʿ���
		*/
	case 1:
		gotoxy(39, 18);
		printf("                            ");
		gotoxy(39, 20);
		printf("                            ");
		gotoxy(39, 22);
		printf("                            ");
		gotoxy(39, 24);
		printf("                            ");
		cursor(1);
		gotoxy(39, 18);
		printf("�α���");
		gotoxy(39, 20);
		printf("���̵�: ");
		scanf("%s", user_id);
		gotoxy(39, 22);
		printf("��й�ȣ: ");
		scanf("%s", user_password);
		cursor(0);
		/*
		* DB �����Ϳ��� ID Ȯ�� �ʿ���
		*/
		break;
	}

	free(user_id);
	free(user_password);
	return 1;
}