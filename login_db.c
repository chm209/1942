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
	// 회원가입
	case FALSE:
		while (join_success == FAIL)
		{
			draw_content(5);
			gotoxy(34, 18);
			printf("회원가입");
			gotoxy(34, 20);
			printf("20자 이내에 영문으로 입력하십시오");
			gotoxy(34, 22);
			printf("아이디: ");
			fgets(id, 20, stdin);
			CHOP(id);
			gotoxy(34, 24);
			printf("비밀번호: ");
			fgets(passwd, 20, stdin);
			CHOP(passwd);
			cursor(0);

			// 입력받은 아이디, 비밀번호 DB 등록
			sprintf(query, "insert into user values " "('%s', '%s', '%d', '%d')", id, passwd, 0, 0);
			query_stat = mysql_query(connection, query);
			if (query_stat != 0)
			{
				draw_error(2);
				fprintf(stderr, "%s", mysql_error(&conn));
				Sleep(3500);
				system("cls");
				draw_content(0); // 도트 출력
				draw_content(1); // 1942 그림 출력
				continue;
			}

			// 입력받은 아이디를 기준으로 item_list db에 초기값 등록
			sprintf(query, "insert into item_list values " "('%s', '%d', '%d', '%d', '%d', '%d', '%d', '%d', '%d', '%d', '%d')", id, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15);
			query_stat = mysql_query(connection, query);
			if (query_stat != 0)
			{
				draw_error(2);
				fprintf(stderr, "%s", mysql_error(&conn));
				Sleep(3500);
				return FAIL;
			} 

			// 입력받은 아이디를 기준으로 ranking db에 초기값 등록
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
	// 로그인
	case TRUE:
		draw_content(5);
		gotoxy(34, 18);
		printf("로그인");
		gotoxy(34, 20);
		printf("아이디: ");
		fgets(id, 20, stdin);
		CHOP(id);
		gotoxy(34, 22);
		printf("비밀번호: ");
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
			draw_content(0); // 도트 출력
			draw_content(1); // 1942 그림 출력
			return FAIL;
		}

		result = mysql_store_result(connection);
		while ((row = mysql_fetch_row(result)) != NULL)
		{
			// 점수, 포인트 불러오기
			strcpy(user.id, id);
			user.score = atoi(row[2]);
			user.point = atoi(row[3]);
			is_successed = TRUE;
		}
		mysql_free_result(result);

		if (is_successed == TRUE)
		{
			// 소지 아이템 불러오기
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
				// 불러오기 성공
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