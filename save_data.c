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

void save_data(PLAYER* player, SHOP_ITEM* shop_item)
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

	// ����� ������ DB�� �ݿ�
	// c���� '\'�� ��ȣ�� ���� �ٳѱ� �� �� ����
	sprintf(query, "update item_list set item1 = %d, item2 = %d, item3 = %d", shop_item->life_plus, shop_item->hp_recover, shop_item->score_buff);
	query_stat = mysql_query(connection, query);
	if (query_stat != 0)
	{
		system("cls");
		fprintf(stderr, "%s", mysql_error(&conn));
		system("pause");
	}

	// user.score���� �ְ� ����� ����Ǿ� �־ �ֱ� ������ ������ ���ؼ� �����Ѵ�.
	// �ְ� ��� ���Ž� ��ŷ ���̺� ������Ʈ
	if (user.score < player->score)
	{
		// ��� ������ �ʱ�ȭ ����
		// �ʱ�ȭ�� ���������� ���� ����� ���� �־ ���� ������Ʈ�� ������ϱ� ������
		// ������ ������Ʈ�Ұ� �ϰ������� �ʱ�ȭ ����
		sprintf(query, "update ranking set score = %d, item1 = %d, item2 = %d, item3 = %d where id = '%s'", 0, 0, 0, 0, user.id);
		query_stat = mysql_query(connection, query);
		if (query_stat != 0)
		{
			system("cls");
			fprintf(stderr, "%s", mysql_error(&conn));
			system("pause");
		}

		user.score = player->score;

		// �߰� ���� �������� �������� �ڵ� ����
		if (user.item[2] != shop_item->score_buff)
		{
			if ((user.item[0] != shop_item->life_plus) && (user.item[1] != shop_item->hp_recover))
			{
				sprintf(query, "update ranking set score = %d, item1 = %d, item2 = %d, item3 = %d where id = '%s'", user.score, 1, 1, 1, user.id);
			}
			else if ((user.item[0] == shop_item->life_plus) && (user.item[1] != shop_item->hp_recover))
			{
				sprintf(query, "update ranking set score = %d, item2 = %d, item3 = %d where id = '%s'", user.score, 1, 1, user.id);
			}
			else if ((user.item[0] != shop_item->life_plus) && (user.item[1] == shop_item->hp_recover))
			{
				sprintf(query, "update ranking set score = %d, item1 = %d, item3 = %d where id = '%s'", user.score, 1, 1, user.id);
			}
			else if ((user.item[0] == shop_item->life_plus) && (user.item[1] == shop_item->hp_recover))
			{
				sprintf(query, "update ranking set score = %d, item3 = %d where id = '%s'", user.score, 1, user.id);
			}
		}
		else
		{
			if ((user.item[0] != shop_item->life_plus) && (user.item[1] != shop_item->hp_recover))
			{
				sprintf(query, "update ranking set score = %d, item1 = %d, item2 = %d where id = '%s'", user.score, 1, 1, user.id);
			}
			else if ((user.item[0] == shop_item->life_plus) && (user.item[1] != shop_item->hp_recover))
			{
				sprintf(query, "update ranking set score = %d, item2 = %d where id = '%s'", user.score, 1, user.id);
			}
			else if ((user.item[0] != shop_item->life_plus) && (user.item[1] == shop_item->hp_recover))
			{
				sprintf(query, "update ranking set score = %d, item1 = %d where id = '%s'", user.score, 1, user.id);
			}
			else if ((user.item[0] == shop_item->life_plus) && (user.item[1] == shop_item->hp_recover))
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
	if ((player->score * 0.5) > 0)
	{
		user.point = user.point + (player->score * 0.5);
	}
	// ������ ����Ʈ ���
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