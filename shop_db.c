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

void shop_db(void)
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

	// c언어에서 '\'나 괄호를 쓰면 줄넘김 할 수 있음
	sprintf(query, "update item_list set item1 = %d, item2 = %d, item3 = %d, \
		item4 = %d, item5 = %d, item6 = %d, item7 = %d, item8 = %d, item9 = %d, \
		item10 = %d where id = '%s'", item_list.item1, item_list.item2, item_list.item3, \
		item_list.item4, item_list.item5, item_list.item6, item_list.item7, item_list.item8, \
		item_list.item9, item_list.item10, user.id);
	query_stat = mysql_query(connection, query);
	if (query_stat != 0)
	{
		system("cls");
		fprintf(stderr, "%s", mysql_error(&conn));
		system("pause");
	}

	mysql_close(connection);
}