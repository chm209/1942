#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int login(int is_logined)
{
	system("cls");
	draw_content(0); // ��Ʈ ���
	draw_content(1); // 1942 �׸� ���

	// �α��� ���� ������ ���� ����
	// * DB ���� �۾��� �α����� ���� ����ü���ٰ� �����ϵ��� ���� ����
	char* user_id = malloc(sizeof(char) * 20);
	char* user_password = malloc(sizeof(char) * 20);

	// ȸ������
	// ȸ�������� �α��� ������ ���� if�� �и�
	// �Է¹��� ������ DB���� �ߺ� Ȯ�� ���� �ʿ���
	// �ڵ� ��� ���� & �α��� ������ ���� �Լ� �и� ����
	// ����ϸ� DB�� ����
	if (is_logined == FALSE)
	{
		draw_content(5);
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
		is_logined = TRUE;
	}

	// �α���
	if (is_logined == TRUE)
	{
		draw_content(5);
		gotoxy(39, 18);
		printf("�α���");
		gotoxy(39, 20);
		printf("���̵�: ");
		scanf("%s", user_id);
		gotoxy(39, 22);
		printf("��й�ȣ: ");
		scanf("%s", user_password);
		cursor(0);
		// DB���� ���̵�, ��й�ȣ ��ȸ �ʿ�
	}

	free(user_id);
	free(user_password);
	return 1;
}