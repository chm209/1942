#include <stdio.h>
#include <stdlib.h>  
#include "common.h"

void ranking(int screenNum)
{
	system("cls");
	int key = 0;

	switch (screenNum)
	{
	// 비로그인
	case 0:
		draw_content(5);
		draw_content(6);
		// DB 정보 받아서 순위 그려주는 함수
		while (key != ESC)
		{
			key = getch();
		}
		break;
	// 로그인
	case 1:
		draw_content(7);
		draw_content(8);
		// DB 정보 받아서 순위 그려주는 함수
		while (key != ESC)
		{
			key = getch();
		}
		break;
	}
}


// 비로그인
// 테이블 형식 -> 전체 순위 1~15위 (2~3 페이지), 키보드 좌우 방향키, ESC 나가기
// ※ 상점아이템 적용 여부 (DB 랭킹 테이블 추가) -> userID usertable, ranking usertable, item shop table
// 
// 로그인
// 상단 본인 기록
// 하단 테이블 형식 -> 전체 순위 1~10위 (2~3 페이지), 키보드 좌우, ESC 나가기
// ※ 상점아이템 적용 여부 (DB 랭킹 테이블 추가) -> userID usertable, ranking usertable, item shop table
// 
// 전체적인 구조는 비슷함