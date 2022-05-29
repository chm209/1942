#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "common.h"
#define SHOP_POS_X 50

void shop(void)
{
	system("cls");
	draw_content(10); // 상점화면 프레임 출력
	draw_content(11); // 상점화면 아이템 리스트 출력
	draw_content(12); // 아이템 가격 출력
	draw_owned_item(); // 유저 정보 (포인트, 보유 아이템 출력하는 함수 필요)
	shop_preview(4); // 상점화면 아이템 리스트 설명 출력, 처음에는 1번 항목 출력

	// shop에서 사용하는 변수
	int list_num = 4;
	int choose_item = 0;
	int price = 0;

	// ESC 키를 입력할때까지 무한 반복
	while (choose_item != ESC)
	{
		gotoxy(SHOP_POS_X, list_num);
		puts("○");
		draw_owned_item(user);
		shop_preview(list_num);
		choose_item = getch();

		if (choose_item == ENTER)
		{
			switch (list_num)
			{
			case 4:
				price = 1000;
				break;
			case 6:
				price = 500;
				break;
			case 8:
				price = 2000;
				break;
			case 10:
				price = 3500;
				break;
			case 12:
				price = 4500;
				break;
			case 14:
				price = 5500;
				break;
			case 16:
				price = 3500;
				break;
			case 18:
				price = 4500;
				break;
			case 20:
				price = 5500;
				break;
			case 22:
				price = 100000;
				break;
			}
		
			if (user.point >= price)
			{
				// 기능 아이템
				if (list_num < 10)
				{
					switch (list_num)
					{
					// 생명 추가
					case 4:
						if (user.item[0] < 3)
						{
							user.point -= 1000;
							user.item[0]++;
						}
						break;
					// HP 회복
					case 6:
						if (user.item[1] < 5)
						{
							user.point -= 500;
							user.item[1]++;
						}
						break;
					// 추가 점수
					case 8:
						user.point -= 2000;
						user.item[2]++;
						break;
					}
				}
				// 치장 아이템
				else
				{
					switch (list_num)
					{
					// 빨강 페인트
					case 10:
						if (user.item[3] == 0)
						{
							user.point -= 3500;
							user.item[3]++;

							if (user.item[4] == 1)
							{
								user.item[4] = 0;
								user.point += 2700;
							}
							else if (user.item[5] == 1)
							{
								user.item[5] = 0;
								user.point += 3300;
							}
						}
						else
						{
							user.point += 1700;
							user.item[3]--;
						}
						break;
					// 파랑 페인트
					case 12:
						if (user.item[4] == 0)
						{
							user.point -= 4500;
							user.item[4]++;

							if (user.item[3] == 1)
							{
								user.item[3] = 0;
								user.point += 2100;
							}
							else if (user.item[5] == 1)
							{
								user.item[5] = 0;
								user.point += 3300;
							}
						}
						else
						{
							user.point += 2700;
							user.item[4]--;
						}
						break;
					// 노랑 페인트
					case 14:
						if (user.item[5] == 0)
						{
							user.point -= 5500;
							user.item[5]++;

							if (user.item[3] == 1)
							{
								user.item[3] = 0;
								user.point += 2100;
							}
							else if (user.item[4] == 1)
							{
								user.item[4] = 0;
								user.point += 2700;
							}
						}
						else
						{
							user.point += 3300;
							user.item[5]--;
						}
						break;
					// 빨간 캐논
					case 16:
						if (user.item[6] == 0)
						{
							user.point -= 3500;
							user.item[6]++;

							if (user.item[7] == 1)
							{
								user.item[7] = 0;
								user.point += 2700;
							}
							else if (user.item[8] == 1)
							{
								user.item[8] = 0;
								user.point += 3300;
							}
						}
						else
						{
							user.point += 1700;
							user.item[6]--;
						}
						break;
					// 파란 캐논
					case 18:
						if (user.item[7] == 0)
						{
							user.point -= 4500;
							user.item[7]++;

							if (user.item[6] == 1)
							{
								user.item[6] = 0;
								user.point += 2100;
							}
							else if (user.item[8] == 1)
							{
								user.item[8] = 0;
								user.point += 3300;
							}
						}
						else
						{
							user.point += 2700;
							user.item[7]--;
						}
						break;
					// 노란 캐논
					case 20:
						if (user.item[8] == 0)
						{
							user.point -= 5500;
							user.item[8]++;

							if (user.item[6] == 1)
							{
								user.item[6] = 0;
								user.point += 2100;
							}
							else if (user.item[7] == 1)
							{
								user.item[7] = 0;
								user.point += 2700;
							}
						}
						else
						{
							user.point += 3300;
							user.item[8]--;
						}
						break;
					case 22:
						user.point -= 100000;
						srand(time(NULL));
						user.item[9] = rand() % 14 + 1;
						break;
					}
				}
			}
			else
			{
				draw_content(13); // 구매불가 알림
				Sleep(800);
			}
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
	// db 저장
	shop_db(user);
}