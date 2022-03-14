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
	BULLET bullet[BULLETSIZE];
	int bullet_count = 0;
	
	system("cls");
	drawContent(1);
	draw_stat(stat_array);
	gotoxy(player_pos_x, player_pos_y);
	puts("<-*->");

	// 플레이어 움직임
	while (1)
	{
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
		if (GetAsyncKeyState(VK_SPACE) & 0x8000 && bullet_count < BULLETSIZE)
		{
			bullet[bullet_count].position_x = player_pos_x + 1;
			bullet[bullet_count].position_y = player_pos_y - 1;
			gotoxy(bullet[bullet_count].position_x, bullet[bullet_count].position_y);
			puts("ⅰ");
			bullet[bullet_count].condition = TRUE;
			bullet_count++;
		}
		
		// 총알 움직임 & 출력
		for (int i = 0; i < bullet_count; i++)
		{
			if (bullet[i].condition)
			{
				gotoxy(bullet[i].position_x, bullet[i].position_y);
				puts("  ");
				bullet[i].position_y--;
				gotoxy(bullet[i].position_x, bullet[i].position_y);
				puts("ⅰ");
			}
		}

		// 총알이 천장에 닿으면 사라짐
		for (int i = 0; i < bullet_count; i++)
		{
			if (bullet[i].position_y == 0)
			{
				gotoxy(bullet[i].position_x, bullet[i].position_y);
				puts("  ");
				bullet[i].position_x = 0;
				bullet[i].position_y = 0;
				bullet[i].condition = FALSE;
				bullet_count--;
			}
		}

		Sleep(40);
		// Sleep(18);
	}
}
