#include <stdio.h>
#include <stdlib.h>
#include "common.h"

char user_id[20] = { 0 ,};
int user_point = 0;
int user_score = 0;

int main(void)
{
	// cmd 설정
	system("mode con: cols=100 lines=30");
	system("title 1942 프로젝트 - 1705095 이창민");
	cursor(0); // 0: 커서 가림, 1: 커서 보이기
	
	// main에서만 사용하는 변수
	int is_logined = FALSE;
	int choose_menu = 19;
	User *user = { 0, };

	// 유저가 게임종료를 선택할때까지 무한반복
	while (choose_menu != 24)
	{
		system("cls");
		draw_content(0); // 도트 출력
		draw_content(1); // 1942 그림 출력
		draw_content(2); // 조작키 설명 프레임, 텍스트 출력

		// draw_content(3) = 비로그인 / draw_content(4) = 로그인
		is_logined % 2 == 1 ? draw_content(4) : draw_content(3);
		choose_menu = menu(choose_menu);

		if (choose_menu == 19)
		{
			is_logined % 2 == 0 ? is_logined = login(1) : game();
			system("mode con: cols=100 lines=30");
		}
		else if (choose_menu == 21)
		{
			is_logined % 2 == 0 ? is_logined = login(0) : shop();
		}
		else if (choose_menu == 23)
		{
			is_logined % 2 == 0 ? ranking(0) : ranking(1);
		}
		else
		{
			break;
		}
		choose_menu = 19;
	}
	return 0;
}