#include <stdio.h>
#include <windows.h>
#include "common.h"
#define SHOP_POS_X 50

// TASK LIST
// 1. DB 연동 작업후 유저 포인트, 보유한 아이템 리스트 출력 필요
// 2. 치장 아이템은 타입별 하나만 소지 가능, 다른거 사면 자동으로 판매
// 
// common.h에 들어갈 구조체 정보
// char* 유저 아이디
// int 유저 포인트
// int[] 보유 아이템
// 
// 1. login - 데이터 저장
// 2. ranking - 데이터 출력
// 3. shop - 데이터 출력, 구매 아이템 저장
void shop()
{
	system("cls");
	draw_content(10); // 상점화면 프레임 출력
	draw_content(11); // 상점화면 아이템 리스트 출력
	// 유저 정보 (포인트, 보유 아이템 출력하는 함수 필요)
	shop_preview(4); // 상점화면 아이템 리스트 설명 출력, 처음에는 1번 항목 출력

	// shop에서 사용하는 변수
	int list_num = 4, choose_item = 0;

	// ESC 키를 입력할때까지 무한 반복
	while (choose_item != ESC)
	{
		gotoxy(SHOP_POS_X, list_num);
		puts("○");
		shop_preview(list_num);
		choose_item = getch();

		if (choose_item == ENTER)
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
			choose_item = 0;
		}
		else
		{
			gotoxy(SHOP_POS_X, list_num);
			puts("  ");
			// 화면번호, 입력받은 키 값, X 값, Y 값
			list_num = move(2, choose_item, SHOP_POS_X, list_num);
		}
	}
}