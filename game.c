#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h> // GetAsyncKeyState 사용을 위함
#include <time.h>
#include "common.h"
#define STATSIZE 4
#define BULLETSIZE 5
#define TRUE 1
#define FALSE 0

typedef struct
{
	int position_x;
	int position_y;
	int condition;
} BULLET;

draw_stat(int* stat_array)
{
	int position_x = 17;

	gotoxy(12, 29);
	printf("LIFE");
	for (int i = 0; i < stat_array[0]; i++)
	{
		gotoxy(position_x, 29);
		printf("♥");
		position_x += 2;
	}
	gotoxy(30, 29);
	printf("BOMB");
	position_x = 35;
	for (int i = 0; i < stat_array[1]; i++)
	{
		gotoxy(position_x, 29);
		printf("◎");
		position_x += 2;
	}
	gotoxy(44, 29);
	printf("HP");
	position_x = 47;
	for (int i = 0; i < stat_array[2]; i++)
	{
		gotoxy(position_x, 29);
		printf("■");
		position_x += 2;
	}
	gotoxy(68, 29);
	printf("SCORE : %11d", stat_array[3]);
}

void game(void)
{
	/*
	* 1. 게임 시작전 아이템 불러오기 필요
	* 2. 게임 종료시 아이디, 비밀번호 정보로 DB연동해서 포인트, 점수, 랭킹 업데이트 필요
	*/

	// life, bomb, hp, score 순서
	int stat_array[STATSIZE] = {5, 3, 5, 0};
	int player_pos_x = 44, player_pos_y = 26;
	int key = 0;
	BULLET bullet[BULLETSIZE] = { 0, };
	int bullet_count = 0;
	
	system("cls");
	draw_content(1);
	draw_stat(stat_array);
	gotoxy(player_pos_x, player_pos_y);
	puts("<-*->");

	// 플레이어 움직임
	while (1)
	{
		gotoxy(10, 2);
		printf("%d", bullet_count);

		if (GetAsyncKeyState(VK_LEFT) && player_pos_x > 10) { //왼쪽
			gotoxy(player_pos_x, player_pos_y);
			printf("     ");
			player_pos_x--;
			gotoxy(player_pos_x, player_pos_y);
			puts("<-*->");
		}
		if (GetAsyncKeyState(VK_RIGHT) && player_pos_x < 84) { //오른쪽
			gotoxy(player_pos_x, player_pos_y);
			printf("     ");
			player_pos_x++;
			gotoxy(player_pos_x, player_pos_y);
			puts("<-*->");
		}
		if (GetAsyncKeyState(VK_UP) && player_pos_y > 20) { //위
			gotoxy(player_pos_x, player_pos_y);
			printf("     ");
			player_pos_y--;
			gotoxy(player_pos_x, player_pos_y);
			puts("<-*->");
		}
		if (GetAsyncKeyState(VK_DOWN) && player_pos_y < 26) { //아래
			gotoxy(player_pos_x, player_pos_y);
			printf("     ");
			player_pos_y++;
			gotoxy(player_pos_x, player_pos_y);
			puts("<-*->");
		}
		if ((GetAsyncKeyState(VK_SPACE)))
		{
			for (int i = 0; i < BULLETSIZE; i++)
			{
				if (bullet[i].condition == FALSE)
				{
					bullet[i].position_x = player_pos_x + 1;
					bullet[i].position_y = player_pos_y - 1;
					bullet[i].condition = TRUE;
					gotoxy(bullet[i].position_x, bullet[i].position_y);
					printf("%d", bullet_count);
					// puts("ⅰ");
					bullet_count++;
					break;
				}
			}

			gotoxy(10, 2);
			printf("%d", bullet_count);
			gotoxy(10, 3);
			printf("%d", bullet[0].condition);
			gotoxy(10, 4);
			printf("%d", bullet[1].condition);
			gotoxy(10, 5);
			printf("%d", bullet[2].condition);
			gotoxy(10, 6);
			printf("%d", bullet[3].condition);
			gotoxy(10, 7);
			printf("%d", bullet[4].condition);
		}

		// 총알 움직임 & 출력
		for (int i = 0; i < BULLETSIZE; i++)
		{
			if (bullet[i].condition == TRUE)
			{
				gotoxy(bullet[i].position_x, bullet[i].position_y);
				puts("  ");
				bullet[i].position_y--;
				gotoxy(bullet[i].position_x, bullet[i].position_y);
				printf("%d", i);
				// puts("ⅰ");
			}
		}

		// 총알이 천장에 닿으면 사라짐
		for (int i = 0; i < BULLETSIZE; i++)
		{
			if (bullet[i].condition == TRUE && bullet[i].position_y == 0)
			{
				gotoxy(bullet[i].position_x, bullet[i].position_y);
				puts("  ");
				bullet[i].condition = FALSE;
				bullet_count--;

				gotoxy(10, 2);
				printf("%d", bullet_count);
				gotoxy(10, 3);
				printf("%d", bullet[0].condition);
				gotoxy(10, 4);
				printf("%d", bullet[1].condition);
				gotoxy(10, 5);
				printf("%d", bullet[2].condition);
				gotoxy(10, 6);
				printf("%d", bullet[3].condition);
				gotoxy(10, 7);
				printf("%d", bullet[4].condition);

				
				break;
			}
		}

		/*
		* 1. 총알이 몇발 나갔는지 확인 v
			2. 5발 아래면 발사 v
			3. 이동 v
			4. 천장에 닿으면 총알 삭제
		*/

		Sleep(40);
		// Sleep(18);
	}
}
