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

void ranking_db(int is_logined)
{
	MYSQL* connection = NULL;
	MYSQL conn = { 0, };
	MYSQL_RES* result = NULL;
	MYSQL_ROW row = { 0, };
	int query_stat = 0;
	char query[255] = { 0, };
	int POS_Y = 4;
	int count = 1;

	mysql_init(&conn);
	connection = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);

	if (connection == NULL)
	{
		draw_error(0);
		fprintf(stderr, "%s", mysql_error(&conn));
		return FAIL;
	}

	switch (is_logined)
	{
	// ��α���
	case FALSE:
		mysql_query(connection, "select * from ranking order by score desc");
		result = mysql_store_result(connection);
		while ((row = mysql_fetch_row(result)) != NULL)
		{
			// �̸� ���
			set_color(atoi(row[5]));
			gotoxy(10, POS_Y);
			int indent = (20 - strlen(row[0])) / 2; // ���� ���� ���ϱ� 
			for (int i = 0; i < indent; i++)
			{
				putchar(' '); // ���� ���� ä��� 
			}
			printf("%s", row[0]);
			set_color(15);

			// ���� ���
			gotoxy(39, POS_Y);
			printf("%11s", row[1]);

			// ����� ������ ���
			if (atoi(row[2]) != 0)
			{
				gotoxy(53, POS_Y);
				printf("�����߰�");
			}

			if (atoi(row[2]) != 0 && atoi(row[3]) != 0)
			{
				gotoxy(61, POS_Y);
				printf(", ü�� ȸ��");
			}
			else if (atoi(row[2]) == 0 && atoi(row[3]) != 0)
			{
				gotoxy(53, POS_Y);
				printf("ü�� ȸ��");
			}

			if ((atoi(row[2]) != 0 && atoi(row[3]) != 0) && atoi(row[4]) != 0)
			{
				gotoxy(72, POS_Y);
				printf(", �߰����� ����");
			}
			else if ((atoi(row[2]) == 0 && atoi(row[3]) != 0) && atoi(row[4]) != 0)
			{
				gotoxy(62, POS_Y);
				printf(", �߰����� ����");
			}
			else if ((atoi(row[2]) != 0 && atoi(row[3]) == 0) && atoi(row[4]) != 0)
			{
				gotoxy(61, POS_Y);
				printf(", �߰����� ����");
			}
			else if ((atoi(row[2]) == 0 && atoi(row[3]) == 0) && atoi(row[4]) != 0)
			{
				gotoxy(53, POS_Y);
				printf("�߰����� ����");
			}

			if (count == 11)
			{
				break;
			}

			POS_Y += 2;
			count++;
		}
		mysql_free_result(result);
		break;
	// �α���
	case TRUE:
		// ������ ���, �Ѿ�, �������� ���
		sprintf(query, "select * from item_list where id = '%s'", user.id);
		query_stat = mysql_query(connection, query);
		if (query_stat != 0)
		{
			draw_error(2);
			fprintf(stderr, "%s", mysql_error(&conn));
			Sleep(3500);
			return FAIL;
		}

		mysql_query(connection, "select * from item_list where id = '%s'", user.id);
		result = mysql_store_result(connection);
		while ((row = mysql_fetch_row(result)) != NULL)
		{
			if (atoi(row[4]) == 1)
			{
				set_color(RED);
				gotoxy(16, 3);
				printf("<-*->");
				set_color(WHITE);
			}
			else if (atoi(row[5]) == 1)
			{
				set_color(BLUE);
				gotoxy(16, 3);
				printf("{:*:}");
				set_color(WHITE);
			}
			else if (atoi(row[6]) == 1)
			{
				set_color(YELLOW);
				gotoxy(16, 3);
				printf("H:*:H");
				set_color(WHITE);
			}
			else // default ����
			{
				gotoxy(16, 3);
				printf("[-*-]");
			}

			if (atoi(row[7]) == 1)
			{
				set_color(RED);
				gotoxy(16, 5);
				printf("�� �� ��");
				set_color(WHITE);
			}
			else if (atoi(row[8]) == 1)
			{
				set_color(BLUE);
				gotoxy(16, 5);
				printf("�� �� ��");
				set_color(WHITE);
			}
			else if (atoi(row[9]) == 1)
			{
				set_color(YELLOW);
				gotoxy(16, 5);
				printf("�� �� ��");
				set_color(WHITE);
			}
			else // default ����
			{
				gotoxy(16, 5);
				printf("�� �� ��");
			}
			set_color(atoi(row[10]));
			gotoxy(16, 7);
			switch (atoi(row[10]))
			{
			case 1:
				printf("BLUE");
				break;
			case 2:
				printf("GREEN");
				break;
			case 3:
				printf("CYAN");
				break;
			case 4:
				printf("RED");
				break;
			case 5:
				printf("MAGENTA");
				break;
			case 6:
				printf("BROWN");
				break;
			case 7:
				printf("LIGHT GRAY");
				break;
			case 8:
				printf("DARK GRAY");
				break;
			case 9:
				printf("LIGHT BLUE");
				break;
			case 10:
				printf("LIGHT GREEN");
				break;
			case 11:
				printf("LIGHT CYAN");
				break;
			case 12:
				printf("LIGHT RED");
				break;
			case 13:
				printf("LIGHT MAGENTA");
				break;
			case 14:
				printf("YELLOW");
				break;
			default:
				printf("DEAFULT");
				break;
			}
			set_color(WHITE);
		}
		mysql_free_result(result);

		// �̸�, ����Ʈ, ����� ������, �ְ�����
		sprintf(query, "select * from ranking where id = '%s'", user.id);
		query_stat = mysql_query(connection, query);
		if (query_stat != 0)
		{
			draw_error(2);
			fprintf(stderr, "%s", mysql_error(&conn));
			Sleep(3500);
			return FAIL;
		}

		mysql_query(connection, "select * from ranking where id = '%s'", user.id);
		result = mysql_store_result(connection);
		while ((row = mysql_fetch_row(result)) != NULL)
		{
			set_color(atoi(row[5]));
			gotoxy(37, 3);
			printf(": %s", row[0]);
			set_color(15);

			gotoxy(72, 3);
			printf(": %s", row[1]);

			gotoxy(39, 5);
			printf(": %d", user.point);

			// ����� ������ ���
			if (atoi(row[2]) != 0)
			{
				gotoxy(46, 7);
				printf(": �����߰�");
			}

			if (atoi(row[2]) != 0 && atoi(row[3]) != 0)
			{
				gotoxy(56, 7);
				printf(", ü�� ȸ��");
			}
			else if (atoi(row[2]) == 0 && atoi(row[3]) != 0)
			{
				gotoxy(46, 7);
				printf(": ü�� ȸ��");
			}

			if ((atoi(row[2]) != 0 && atoi(row[3]) != 0) && atoi(row[4]) != 0)
			{
				gotoxy(67, 7);
				printf(", �߰����� ����");
			}
			else if ((atoi(row[2]) == 0 && atoi(row[3]) != 0) && atoi(row[4]) != 0)
			{
				gotoxy(57, 7);
				printf(", �߰����� ����");
			}
			else if ((atoi(row[2]) != 0 && atoi(row[3]) == 0) && atoi(row[4]) != 0)
			{
				gotoxy(56, 7);
				printf(", �߰����� ����");
			}
			else if ((atoi(row[2]) == 0 && atoi(row[3]) == 0) && atoi(row[4]) != 0)
			{
				gotoxy(46, 7);
				printf(": �߰����� ����");
			}
			else if ((atoi(row[2]) == 0 && atoi(row[3]) == 0) && atoi(row[4]) == 0)
			{
				gotoxy(46, 7);
				printf(": ����");
			}
		}
		mysql_free_result(result);

		// ���� ���
		mysql_query(connection, "select * from ranking order by score desc");
		result = mysql_store_result(connection);
		POS_Y = 12;
		while ((row = mysql_fetch_row(result)) != NULL)
		{
			// �̸� ���
			gotoxy(10, POS_Y);
			int indent = (20 - strlen(row[0])) / 2; // ���� ���� ���ϱ� 
			for (int i = 0; i < indent; i++)
			{
				putchar(' '); // ���� ���� ä��� 
			}
			set_color(atoi(row[5]));
			printf("%s", row[0]);
			set_color(15);

			// ���� ���
			gotoxy(39, POS_Y);
			printf("%11s", row[1]);

			// ����� ������ ���
			if (atoi(row[2]) != 0)
			{
				gotoxy(53, POS_Y);
				printf("�����߰�");
			}

			if (atoi(row[2]) != 0 && atoi(row[3]) != 0)
			{
				gotoxy(61, POS_Y);
				printf(", ü�� ȸ��");
			}
			else if (atoi(row[2]) == 0 && atoi(row[3]) != 0)
			{
				gotoxy(53, POS_Y);
				printf("ü�� ȸ��");
			}

			if ((atoi(row[2]) != 0 && atoi(row[3]) != 0) && atoi(row[4]) != 0)
			{
				gotoxy(72, POS_Y);
				printf(", �߰����� ����");
			}
			else if ((atoi(row[2]) == 0 && atoi(row[3]) != 0) && atoi(row[4]) != 0)
			{
				gotoxy(62, POS_Y);
				printf(", �߰����� ����");
			}
			else if ((atoi(row[2]) != 0 && atoi(row[3]) == 0) && atoi(row[4]) != 0)
			{
				gotoxy(61, POS_Y);
				printf(", �߰����� ����");
			}
			else if ((atoi(row[2]) == 0 && atoi(row[3]) == 0) && atoi(row[4]) != 0)
			{
				gotoxy(53, POS_Y);
				printf("�߰����� ����");
			}
			else if ((atoi(row[2]) == 0 && atoi(row[3]) == 0) && atoi(row[4]) == 0)
			{
				gotoxy(53, POS_Y);
				printf("����");
			}

			if (count == 8)
			{
				break;
			}

			POS_Y += 2;
			count++;
		}
		mysql_free_result(result);
		break;
	}
	mysql_close(connection);
	return FAIL;
}