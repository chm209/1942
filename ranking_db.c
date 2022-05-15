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

void ranking_db(int is_logined)
{
	MYSQL* connection = NULL;
	MYSQL conn = { 0, };
	MYSQL_RES* result = NULL;
	MYSQL_ROW row = { 0, };
	int query_stat = 0;
	char id[20] = { 0, };
	char passwd[20] = { 0, };
	char query[255] = { 0, };
	int pos_y = 4;

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

	switch (is_logined)
	{
	// 비로그인
	case FALSE:
		mysql_query(connection, "select * from ranking order by score desc");
		result = mysql_store_result(connection);
		while ((row = mysql_fetch_row(result)) != NULL)
		{
			gotoxy(10, pos_y);
			int indent = (20 - strlen(row[0])) / 2; // 왼쪽 여백 구하기 
			for (int i = 0; i < indent; i++)
			{
				putchar(' '); // 왼쪽 여백 채우기 
			}
			printf("%s", row[0]);

			gotoxy(39, pos_y);
			printf("%11s", row[1]);

			if (row[2] != NULL)
			{
				gotoxy(60, pos_y);
				printf("%s", row[2]);
				indent = strlen(row[2]) + 1;
			}

			if (row[2] != NULL && row[3] != NULL)
			{
				gotoxy(60 + indent, pos_y);
				printf("%s", row[3]);
				indent = strlen(row[3]);
			}
			else if (row[2] == NULL && row[3] != NULL)
			{
				gotoxy(60, pos_y);
				printf("%s", row[3]);
				indent = strlen(row[3]);
			}

			if ((row[2] != NULL && row[3] != NULL) && row[4] != NULL)
			{
				gotoxy(60 + indent * 2, pos_y);
				printf("%s", row[4]);
			}
			else if ((row[2] == NULL && row[3] != NULL) && row[4] != NULL)
			{
				gotoxy(60 + indent, pos_y);
				printf("%s", row[4]);
			}
			else if ((row[2] == NULL && row[3] == NULL) && row[4] != NULL)
			{
				gotoxy(60, pos_y);
				printf("%s", row[3]);
			}

			pos_y += 2;
		}
		mysql_free_result(result);
		break;
	// 로그인
	case TRUE:
		break;
	}
	mysql_close(connection);
	return FAIL;
}