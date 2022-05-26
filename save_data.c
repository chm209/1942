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

void save_data(PLAYER* player, SHOP_ITEM* shop_item, RECORD* record)
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

	// 사용한 아이템 DB에 반영
	// c언어에서 '\'나 괄호를 쓰면 줄넘김 할 수 있음
	sprintf(query, "update item_list set item1 = %d, item2 = %d, item3 = %d", shop_item->life_plus, shop_item->hp_recover, shop_item->score_buff);
	query_stat = mysql_query(connection, query);
	if (query_stat != 0)
	{
		system("cls");
		fprintf(stderr, "%s", mysql_error(&conn));
		system("pause");
	}

	// user.score에는 최고 기록이 저장되어 있어서 최근 게임의 점수와 비교해서 저장한다.
	// 최고 기록 갱신시 랭킹 테이블 업데이트
	if (user.score < player->score)
	{
		user.score = player->score;

		// 추가 점수 아이템이 있을때는 자동 적용
		if (user.item[2] > 0)
		{
			if ((user.item[1] != shop_item->life_plus) && (user.item[2] != shop_item->hp_recover))
			{
				sprintf(query, "update ranking set score = %d, item1 = %d, item2 = %d, item3 = %d where id = '%s'", user.score, \
					user.item[1] - shop_item->life_plus, user.item[2] - shop_item->hp_recover, user.item[3] - shop_item->score_buff, user.id);
			}
			else if ((user.item[1] == shop_item->life_plus) && (user.item[2] != shop_item->hp_recover))
			{
				sprintf(query, "update ranking set score = %d, item2 = %d, item3 = %d where id = '%s'", user.score, \
					user.item[2] - shop_item->hp_recover, user.item[3] - shop_item->score_buff, user.id);
			}
			else if ((user.item[1] != shop_item->life_plus) && (user.item[2] == shop_item->hp_recover))
			{
				sprintf(query, "update ranking set score = %d, item1 = %d, item3 = %d where id = '%s'", user.score, \
					user.item[1] - shop_item->life_plus, user.item[3] - shop_item->score_buff, user.id);
			}
			else if ((user.item[1] == shop_item->life_plus) && (user.item[2] == shop_item->hp_recover))
			{
				sprintf(query, "update ranking set score = %d, item3 = %d where id = '%s'", user.score, \
					user.item[3] - shop_item->score_buff, user.id);
			}
		}
		else
		{
			if ((user.item[1] != shop_item->life_plus) && (user.item[2] != shop_item->hp_recover))
			{
				sprintf(query, "update ranking set score = %d, item1 = %d, item2 = %d where id = '%s'", user.score, \
					user.item[1] - shop_item->life_plus, user.item[2] - shop_item->hp_recover, user.id);
			}
			else if (record->life_plus == 0 && record->hp_recover > 0)
			{
				sprintf(query, "update ranking set score = %d, item2 = %d where id = '%s'", user.score, \
					user.item[2] - shop_item->hp_recover, user.id);
			}
			else if (record->life_plus > 0 && record->hp_recover == 0)
			{
				sprintf(query, "update ranking set score = %d, item1 = %d where id = '%s'", user.score, \
					user.item[1] - shop_item->life_plus, user.id);
			}
			else if (record->life_plus == 0 && record->hp_recover == 0)
			{
				sprintf(query, "update ranking set score = %d where id = '%s'", user.score, user.id);
			}
		}

		query_stat = mysql_query(connection, query);
		if (query_stat != 0)
		{
			system("cls");
			fprintf(stderr, "%s", mysql_error(&conn));
			system("pause");
		}
	}
	user.point = user.point + (player->score * 0.5);

	// 점수와 포인트 기록
	sprintf(query, "update user set score = %d, point = %d where id = '%s'", user.score, user.point, user.id);
	query_stat = mysql_query(connection, query);
	if (query_stat != 0)
	{
		system("cls");
		fprintf(stderr, "%s", mysql_error(&conn));
		system("pause");
	}

	user.item[0] = shop_item->life_plus;
	user.item[1] = shop_item->hp_recover;
	user.item[2] = shop_item->score_buff;

	return 0;
}