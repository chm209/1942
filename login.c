#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int login(int screen_num)
{
	char* user_id = malloc(sizeof(char) * 20);
	char* user_password = malloc(sizeof(char) * 20);

	switch (screen_num)
	{
	case 0:
		gotoxy(39, 18);
		printf("                            ");
		gotoxy(39, 20);
		printf("                            ");
		gotoxy(39, 22);
		printf("                            ");
		gotoxy(39, 24);
		printf("                            ");
		cursor(1);
		gotoxy(39, 18);
		printf("회원가입");
		gotoxy(39, 20);
		printf("20자 이내에 입력하십시오");
		gotoxy(39, 22);
		printf("아이디: ");
		scanf("%s", user_id);
		gotoxy(39, 24);
		printf("비밀번호: ");
		scanf("%s", user_password);
		cursor(0);
		/*
		* 회원가입후 로그인 과정을 위해 break 생략
		* DB 데이터에서 ID 중복 확인 필요함
		* DB 저장 기능 필요함
		*/
	case 1:
		gotoxy(39, 18);
		printf("                            ");
		gotoxy(39, 20);
		printf("                            ");
		gotoxy(39, 22);
		printf("                            ");
		gotoxy(39, 24);
		printf("                            ");
		cursor(1);
		gotoxy(39, 18);
		printf("로그인");
		gotoxy(39, 20);
		printf("아이디: ");
		scanf("%s", user_id);
		gotoxy(39, 22);
		printf("비밀번호: ");
		scanf("%s", user_password);
		cursor(0);
		/*
		* DB 데이터에서 ID 확인 필요함
		*/
		break;
	}

	free(user_id);
	free(user_password);
	return 1;
}