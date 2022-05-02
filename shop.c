#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "common.h"
#define POS_X 50

// DB 연동후 작업 내용
// 유저 포인트 불러오기, 표시 필요
// 치장 아이템은 이미 소유한 경우 보유항목에 출력 필요
// 총알 모양1은 기본 2는 커스텀
// 2를 사면 1을 자동으로 판매해버리는 방식으로 치장 아이템 관리
// shop_preview 함수 수정 필요
// 변경전 모양을 실제 플레이어의 장착 아이템으로 변경 필요
void shop()
{
	system("cls");
	int key = 0, item_num = 4;
	
	while (1)
	{
		draw_content(3); // UI 뼈대 출력
		draw_content(4); // 상점 항목 출력
		// 가격과 보유수는 DB연동후 다른 함수를 만들어서 출력해야 할듯
		shop_preview(item_num);
		gotoxy(POS_X, item_num);
		puts("√");

		while (key != ENTER && key != ESC)
		{
			gotoxy(POS_X, item_num);
			puts("√");
			key = getch();

			if (key != ESC)
			{
				gotoxy(POS_X, item_num);
				puts("  ");
				// 화면번호, 입력받은 키 값, X 값, Y 값
				item_num = move(2, key, POS_X, item_num);
				shop_preview(item_num);
			}
			else
			{
				break;
			}
		}
		if (key == ESC)
		{
			break;
		}
		key = 0;
	}
}