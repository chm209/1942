#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void error(int error_code)
{
	system("cls");
	set_color(RED);
	gotoxy(22, 10);
	puts("※ DB 접속 불가");
	gotoxy(22, 12);
	puts("프로그램 종료후 코드를 다시 확인 하십시오.");
	set_color(WHITE);
	gotoxy(22, 14);
	switch (error_code)
	{
	case 0:
		puts("DB 접속 에러 코드");
		break;
	case 1:
		puts("DB TABLE 접속 에러 코드");
		break;
	case 2	:
		puts("로그인 조회 쿼리문 에러 코드");
		break;
	}
	gotoxy(22, 16);
	puts("                                                       ");
	gotoxy(22, 16);
}