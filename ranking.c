#include <stdio.h>
#include <stdlib.h>  
#include "common.h"

void ranking(int is_logined)
{
	system("cls");
	int key = 0;

	switch (is_logined)
	{
	// 비로그인
	case FALSE:
		draw_content(6);
		draw_content(7);
		ranking_db(0);
		while (key != ESC)
		{
			key = getch();
		}
		break;
	// 로그인
	case TRUE:
		draw_content(8);
		draw_content(9);
		ranking_db(1);
		while (key != ESC)
		{
			key = getch();
		}
		break;
	}
}


// 비로그인
// 테이블 형식 -> 전체 순위, ESC 나가기
// ※ 상점아이템 적용 여부 (DB 랭킹 테이블 추가) -> userID usertable, ranking usertable, item shop table
// 
// 로그인
// 상단 본인 기록
// 하단 테이블 형식 -> 전체 순위, ESC 나가기
// ※ 상점아이템 적용 여부 (DB 랭킹 테이블 추가) -> userID usertable, ranking usertable, item shop table