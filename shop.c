#include <stdio.h>
#include <windows.h>
#include "common.h"
#define POS_X 50

// ■ 개발 메모
// 1. DB 연동후 유저 포인트, 보유한 아이템 리스트 출력 필요
// 2. 치장아이템은 타입별 하나만 소지 가능, 다른거 사면 자동 판매

// DB - 구조체
// 유저 아이디 - char*
// 포인트 - int
// 보유 아이템 - 배열

// main -> 최초 로그인할때 DB 데이터를 구조체에 저장
// shop -> 들어갔다 나올때마다 DB 데이터 갱신 필요
// game -> 들어갔다 나올때마다 DB 데이터 갱신 필요
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
		
			/*
			if (유저 보유 포인트 >= 아이템 가격)
			{
				if (item_num < 치장 아이템(테이블에서 초반이 기능, 후반이 치장))
				{
					switch (item_num)
					{
					case 0:
						if (DB에서 불러온 아이템 보유 개수가 3 미만일때)
						{
							포인트 차감
								0번 아이템 + 1
						}
						else
						{
							아이템 보유 개수 때문에 구매 불가 알림
						}
						break;
					case 1:
						if (DB에서 불러온 아이템 보유 개수가 5 미만일때)
						{
							포인트 차감
								1번 아이템 + 1
						}
						else
						{
							아이템 보유 개수 때문에 구매 불가 알림
						}
						break
					default:
						포인트 차감
							1번 아이템 + 1
						break;
					}
				}
				else
				{
					// 치장 아이템일때
					치장 아이템도 기능 아이템처럼 if문으로 검사하고 보유 개수가 0일때만 구매 가능하게 함
					구매하고 나서 빠져나오기전에 만약 같은 타입의 다른 치장 아이템을 가지고 있다면 자동 판매함
				}
			}
			else
			{
				포인트 부족으로 구매 불가 알림
			}*/
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