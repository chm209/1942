#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>
#include "common.h"
#pragma commnet(lib, "libmysql.lib")

#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASS "abc123"
#define DB_NAME "game_db"
#define CHOP(x) x[strlen(x) - 1] = ' '

int login_db(int sign)
{
	MYSQL* connection = NULL;
	MYSQL conn = { 0, };
	MYSQL_RES* result = NULL;
	MYSQL_ROW row = { 0, };
	int query_stat = 0;
	int is_successed = FAIL;
	int join_success = FAIL;
	char id[20] = { 0, };
	char passwd[20] = { 0, };
	char query[255] = { 0, };

	mysql_init(&conn);
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);

	if (connection == NULL)
	{
		draw_error(0);
		fprintf(stderr, "%s", mysql_error(&conn));
		return FAIL;
	}

	switch (sign)
	{
	// ȸ������
	case FALSE:
		while (join_success == FAIL)
		{
			draw_content(5);
			gotoxy(34, 18);
			printf("ȸ������");
			gotoxy(34, 20);
			printf("20�� �̳��� �������� �Է��Ͻʽÿ�");
			gotoxy(34, 22);
			printf("���̵�: ");
			fgets(id, 20, stdin);
			CHOP(id);
			gotoxy(34, 24);
			printf("��й�ȣ: ");
			fgets(passwd, 20, stdin);
			CHOP(passwd);
			cursor(0);

			// �Է¹��� ���̵�, ��й�ȣ DB ���
			sprintf(query, "insert into user values " "('%s', '%s', '%d', '%d')", id, passwd, 0, 0);
			query_stat = mysql_query(connection, query);
			if (query_stat != 0)
			{
				draw_error(2);
				fprintf(stderr, "%s", mysql_error(&conn));
				Sleep(3500);
				system("cls");
				draw_content(0); // ��Ʈ ���
				draw_content(1); // 1942 �׸� ���
				continue;
			}

			// �Է¹��� ���̵� �������� item_list db�� �ʱⰪ ���
			sprintf(query, "insert into item_list values " "('%s', '%d', '%d', '%d', '%d', '%d', '%d', '%d', '%d', '%d', '%d')", id, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15);
			query_stat = mysql_query(connection, query);
			if (query_stat != 0)
			{
				draw_error(2);
				fprintf(stderr, "%s", mysql_error(&conn));
				Sleep(3500);
				return FAIL;
			} 

			// �Է¹��� ���̵� �������� ranking db�� �ʱⰪ ���
			sprintf(query, "insert into ranking values " "('%s', '%d', '%d', '%d', '%d', '%d')", id, 0, 0, 0, 0, 15);
			query_stat = mysql_query(connection, query);
			if (query_stat != 0)
			{
				draw_error(2);
				fprintf(stderr, "%s", mysql_error(&conn));
				Sleep(3500);
				return FAIL;
			}
			join_success = TRUE;
		}
		return SUCCESS;
	// �α���
	case TRUE:
		draw_content(5);
		gotoxy(34, 18);
		printf("�α���");
		gotoxy(34, 20);
		printf("���̵�: ");
		fgets(id, 20, stdin);
		CHOP(id);
		gotoxy(34, 22);
		printf("��й�ȣ: ");
		fgets(passwd, 20, stdin);
		CHOP(passwd);
		cursor(0);

		sprintf(query, "select * from user where id = '%s' and passwd = '%s'", id, passwd);
		query_stat = mysql_query(connection, query);
		if (query_stat != 0)
		{
			draw_error(2);
			fprintf(stderr, "%s", mysql_error(&conn));
			Sleep(3500);
			system("cls");
			draw_content(0); // ��Ʈ ���
			draw_content(1); // 1942 �׸� ���
			return FAIL;
		}

		result = mysql_store_result(connection);
		while ((row = mysql_fetch_row(result)) != NULL)
		{
			// ����, ����Ʈ �ҷ�����
			strcpy(user.id, id);
			user.score = atoi(row[2]);
			user.point = atoi(row[3]);
			is_successed = TRUE;
		}
		mysql_free_result(result);

		if (is_successed == TRUE)
		{
			// ���� ������ �ҷ�����
			sprintf(query, "select * from item_list where id = '%s'", id);
			query_stat = mysql_query(connection, query);
			if (query_stat != 0)
			{
				draw_error(2);
				fprintf(stderr, "%s", mysql_error(&conn));
				Sleep(3500);
				return FAIL;
			}

			result = mysql_store_result(connection);
			while ((row = mysql_fetch_row(result)) != NULL)
			{
				// �ҷ����� ����
				for (int i = 0; i < 10; i++)
				{
					user.item[i] = atoi(row[i+1]);
				}
				is_successed = TRUE;
			}
			mysql_free_result(result);
			mysql_close(connection);
			return SUCCESS;
		}
		break;
	}
	mysql_close(connection);
	return FAIL;
}