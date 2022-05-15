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
	char id[20] = { 0, };
	char passwd[20] = { 0, };
	char query[255] = { 0, };

	mysql_init(&conn);
	mysql_options(&conn, MYSQL_SET_CHARSET_NAME, "euckr");
	mysql_options(&conn, MYSQL_INIT_COMMAND, "SET NAMES euckr");
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);

	if (connection == NULL)
	{
		error(0);
		fprintf(stderr, "%s", mysql_error(&conn));
		return FAIL;
	}

	switch (sign)
	{
	// ȸ������
	case FALSE:
		draw_content(5);
		gotoxy(39, 18);
		printf("ȸ������");
		gotoxy(39, 20);
		printf("20�� �̳��� �Է��Ͻʽÿ�");
		gotoxy(39, 22);
		printf("���̵�: ");
		fgets(id, 20, stdin);
		CHOP(id);
		gotoxy(39, 24);
		printf("��й�ȣ: ");
		fgets(passwd, 20, stdin);
		CHOP(passwd);
		cursor(0);

		sprintf(query, "insert into user values " "('%s', '%s', '%d', '%d')", id, passwd, 0, 0);
		query_stat = mysql_query(connection, query);
		if (query_stat != 0)
		{
			error(2);
			fprintf(stderr, "%s", mysql_error(&conn));
			Sleep(4000);
			system("cls");
			draw_content(0); // ��Ʈ ���
			draw_content(1); // 1942 �׸� ���
			return FAIL;
		}
		return SUCCESS;
	// �α���
	case TRUE:
		draw_content(5);
		gotoxy(39, 18);
		printf("�α���");
		gotoxy(39, 20);
		printf("���̵�: ");
		fgets(id, 20, stdin);
		CHOP(id);
		gotoxy(39, 22);
		printf("��й�ȣ: ");
		fgets(passwd, 20, stdin);
		CHOP(passwd);
		cursor(0);

		sprintf(query, "select * from user where id = '%s' and passwd = '%s'", id, passwd);
		query_stat = mysql_query(connection, query);
		if (query_stat != 0)
		{
			error(2);
			fprintf(stderr, "%s", mysql_error(&conn));
			Sleep(4000);
			system("cls");
			draw_content(0); // ��Ʈ ���
			draw_content(1); // 1942 �׸� ���
			return FAIL;
		}
		result = mysql_store_result(connection);
		while ((row = mysql_fetch_row(result)) != NULL)
		{
			// �α��� ����
			strcpy(user_id, id);
			user_score = atoi(row[2]);
			user_point = atoi(row[3]);
			mysql_close(connection);
			return SUCCESS;
		}
		break;
	}
	mysql_close(connection);
	return FAIL;
}