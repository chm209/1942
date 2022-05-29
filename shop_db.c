#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include "common.h"
#pragma commnet(lib, "libmysql.lib")

void shop_db(void)
{
	MYSQL* connection = NULL;
	MYSQL conn = { 0, };
	MYSQL_RES* result = NULL;
	MYSQL_ROW row = { 0, };
	int query_stat = 0;
	char query[255] = { 0, };

	mysql_init(&conn);
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);

	if (connection == NULL)
	{
		draw_error(0);
		fprintf(stderr, "%s", mysql_error(&conn));
		gotoxy(22, 17);
		system("pause");
		exit(0);
	}

	// c언어에서 '\'나 괄호를 쓰면 줄넘김 할 수 있음
	sprintf(query, "update item_list set item1 = %d, item2 = %d, item3 = %d, \
		item4 = %d, item5 = %d, item6 = %d, item7 = %d, item8 = %d, item9 = %d, \
		item10 = %d where id = '%s'", user.item[0], user.item[1], user.item[2], \
		user.item[3], user.item[4], user.item[5], user.item[6], user.item[7], \
		user.item[8], user.item[9], user.id);
	query_stat = mysql_query(connection, query);
	if (query_stat != 0)
	{
		system("cls");
		fprintf(stderr, "%s", mysql_error(&conn));
		system("pause");
	}

	sprintf(query, "update user set point = %d where id = '%s'", user.point, user.id);
	query_stat = mysql_query(connection, query);
	if (query_stat != 0)
	{
		system("cls");
		fprintf(stderr, "%s", mysql_error(&conn));
		system("pause");
	}

	sprintf(query, "update ranking set item4 = %d where id = '%s'", user.item[9], user.id);
	query_stat = mysql_query(connection, query);
	if (query_stat != 0)
	{
		system("cls");
		fprintf(stderr, "%s", mysql_error(&conn));
		system("pause");
	}

	mysql_close(connection);
}