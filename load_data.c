#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include "common.h"
#include "game.h"
#pragma commnet(lib, "libmysql.lib")

#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASS "abc123"
#define DB_NAME "game_db"

void load_data(SHOP_ITEM* shop_item)
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
		return FAIL;
	}

	// 소지 아이템 불러오기
	sprintf(query, "select * from item_list where id = '%s'", user.id);
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
		shop_item->life_plus = atoi(row[1]);
		shop_item->hp_recover = atoi(row[2]);
		shop_item->score_buff = atoi(row[3]);
		shop_item->combat_color = WHITE;
		shop_item->cannon_color = WHITE;

		// 전투기 색상
		if (atoi(row[4]) != 0)
		{
			shop_item->combat_color = RED;
			shop_item->combat_design = COMBAT2;
		}
		else if (atoi(row[5]) != 0)
		{
			shop_item->combat_color = BLUE;
			shop_item->combat_design = COMBAT3;
		}
		else if (atoi(row[6]) != 0)
		{
			shop_item->combat_color = YELLOW;
			shop_item->combat_design = COMBAT4;
		}

		// 캐논 색상
		if (atoi(row[7]) != 0)
		{
			shop_item->cannon_color = RED;
			shop_item->cannon_design = CANNON2;
		}
		else if (atoi(row[8]) != 0)
		{
			shop_item->cannon_color = BLUE;
			shop_item->cannon_design = CANNON3;
		}
		else if (atoi(row[9]) != 0)
		{
			shop_item->cannon_color = YELLOW;
			shop_item->cannon_design = CANNON4;
		}
	}
	mysql_free_result(result);
	mysql_close(connection);
}