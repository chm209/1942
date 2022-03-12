#include <stdio.h>
#include "common.h"
#define STATSIZE 4

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
	// life, bomb, hp, score 순서
	int stat_array[STATSIZE] = {5, 3, 5, 0};
	/*
	* 1. 게임 시작전 아이템 불러오기 필요
	* 2. 게임 종료시 아이디, 비밀번호 정보로 DB연동해서 포인트, 점수, 랭킹 업데이트 필요
	*/

	system("cls");
	while (1)
	{
		draw_content(1);
		draw_stat(stat_array);
		
	}
}