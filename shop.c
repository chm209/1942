#include <stdio.h>
#include <windows.h>
#include "common.h"
#define POS_X 50

// ■ 개발 메모
// 1. DB 연동후 유저 포인트, 보유한 아이템 리스트 출력 필요
// 2. 치장아이템은 타입별 하나만 소지 가능, 다른거 사면 자동 판매
void shop()
{
	system("cls");
	int key = 0, item_num = 4; // 리스트 첫번째 Y값이 4

	draw_content(3); // 전체적인 UI
	// 유저 정보 (포인트, 보유 아이템 출력 필요)
	draw_content(4); // 아이템 항목
	shop_preview(item_num);

	while (key != ESC)
	{
		gotoxy(POS_X, item_num);
		puts("√");
		shop_preview(item_num);
		key = getch();

		if (key == ENTER)
		{
			// 구매 프로세스
			// 유저 보유 포인트와 아이템 가격 비교
			// 유저 보유 포인트가 더 크다면 치장 아이템인지 확인
			// 치장 아이템이 아니라면 최대 보유 개수 미만으로 가지고 있는지 확인
			// 전부 통과하면 구매
			// 하나라도 걸리면 구매 불가, 구매 불가 사유 출력
			key = 0;
		}
		else
		{
			gotoxy(POS_X, item_num);
			puts("  ");
			// 화면번호, 입력받은 키 값, X 값, Y 값
			item_num = move(2, key, POS_X, item_num);
		}
	}
}