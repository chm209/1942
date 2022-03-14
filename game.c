#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h> // GetAsyncKeyState »ç¿ëÀ» À§ÇÔ
#include <time.h>
#include "common.h"
#define STATSIZE 4
#define BULLETSIZE 6
#define BOMBBULLETSIZE 5
#define TRUE 1
#define FALSE 0

typedef struct
{
	int position_x;
	int position_y;
	int condition;
} BULLET;

typedef struct
{
	int position_x;
	int position_y;
	int condition;
} BOMB_BULLET;

draw_stat(int* stat_array)
{
	int position_x = 17;

	gotoxy(12, 29);
	printf("LIFE");
	for (int i = 0; i < stat_array[0]; i++)
	{
		gotoxy(position_x, 29);
		printf("¢¾");
		position_x += 2;
	}
	gotoxy(30, 29);
	printf("BOMB");
	position_x = 35;
	for (int i = 0; i < stat_array[1]; i++)
	{
		gotoxy(position_x, 29);
		printf("¡Ý");
		position_x += 2;
	}
	gotoxy(44, 29);
	printf("HP");
	position_x = 47;
	for (int i = 0; i < stat_array[2]; i++)
	{
		gotoxy(position_x, 29);
		printf("¡á");
		position_x += 2;
	}
	gotoxy(68, 29);
	printf("SCORE : %11d", stat_array[3]);
}

void game(void)
{
	/*
	* 1. °ÔÀÓ ½ÃÀÛÀü ¾ÆÀÌÅÛ ºÒ·¯¿À±â ÇÊ¿ä
	* 2. °ÔÀÓ Á¾·á½Ã ¾ÆÀÌµð, ºñ¹Ð¹øÈ£ Á¤º¸·Î DB¿¬µ¿ÇØ¼­ Æ÷ÀÎÆ®, Á¡¼ö, ·©Å· ¾÷µ¥ÀÌÆ® ÇÊ¿ä
	*/

	// life, bomb, hp, score ¼ø¼­
	int stat_array[STATSIZE] = {5, 3, 5, 0};
	int player_pos_x = 44, player_pos_y = 26;
	int key = 0;
	BULLET bullet[BULLETSIZE] = { 0, };
	BOMB_BULLET bomb_bullet[BOMBBULLETSIZE] = { 0, };
	BOMB_BULLET bomb_bullet2[BOMBBULLETSIZE] = { 0, };
	// ÀÜ·®, ¹ß»ç È®ÀÎ¿ë, X, Y
	int bomb[4] = { 3, 0, 51, 24 };
	// x, y, È®ÀÎ¿ë
	int bomb2[3] = { 19, 24, 0 };
	int bomb_speed = 5;
	int bomb_speed2 = 5;

	system("cls");
	drawContent(1);
	draw_stat(stat_array);
	
	// ÇÃ·¹ÀÌ¾î ¿òÁ÷ÀÓ
	while (1)
	{
		gotoxy(player_pos_x, player_pos_y);
		puts("[-*-]");

		if (GetAsyncKeyState(VK_LEFT) && player_pos_x > 10) { //¿ÞÂÊ
			gotoxy(player_pos_x, player_pos_y);
			printf("     ");
			player_pos_x--;
			gotoxy(player_pos_x, player_pos_y);
			puts("[-*-]");
		}
		if (GetAsyncKeyState(VK_RIGHT) && player_pos_x < 84) { //¿À¸¥ÂÊ
			gotoxy(player_pos_x, player_pos_y);
			printf("     ");
			player_pos_x++;
			gotoxy(player_pos_x, player_pos_y);
			puts("[-*-]");
		}
		if (GetAsyncKeyState(VK_UP) && player_pos_y > 10) { //À§
			gotoxy(player_pos_x, player_pos_y);
			printf("     ");
			player_pos_y--;
			gotoxy(player_pos_x, player_pos_y);
			puts("[-*-]");
		}
		if (GetAsyncKeyState(VK_DOWN) && player_pos_y < 26) { //¾Æ·¡
			gotoxy(player_pos_x, player_pos_y);
			printf("     ");
			player_pos_y++;
			gotoxy(player_pos_x, player_pos_y);
			puts("[-*-]");
		}
		// °ø°Ý
		if ((GetAsyncKeyState(VK_SPACE)))
		{
			for (int i = 0; i < BULLETSIZE; i++)
			{
				if (bullet[i].condition == FALSE)
				{
					bullet[i].position_x = player_pos_x + 1;
					bullet[i].position_y = player_pos_y - 1;
					bullet[i].condition = TRUE;
					break; // ¾øÀ¸¸é ³ªÁß¿¡ ´«¹°ÀÌ ³ª´Â »óÈ²ÀÌ »ý±è
				}
			}
		}

		// ÆøÅº
		if ((GetAsyncKeyState(0x5A)))
		{
			if (bomb[0] > 0 && (bomb[1] == FALSE && bomb2[2] == FALSE))
			{
				bomb[0]--;
				stat_array[1]--;
				bomb[1] = TRUE;
				bomb2[2] = TRUE;
			}
		}

		// ÆøÅº ÃÑ¾Ë ¹ß»ç
		for (int i = 0; i < BOMBBULLETSIZE; i++)
		{
			if ((bomb[3] >= 10 && bomb[3] <= 18) && bomb_bullet[i].condition == FALSE)
			{
				bomb_bullet[i].position_x = bomb[2];
				bomb_bullet[i].position_y = bomb[3] - 2;
				bomb_bullet[i].condition = TRUE;
			}
		}

		// ÆøÅº ÃÑ¾Ë ¹ß»ç2
		for (int i = 0; i < BOMBBULLETSIZE; i++)
		{
			if ((bomb2[1] >= 12 && bomb2[1] <= 20) && bomb_bullet2[i].condition == FALSE)
			{
				bomb_bullet2[i].position_x = bomb2[0];
				bomb_bullet2[i].position_y = bomb2[1] - 2;
				bomb_bullet2[i].condition = TRUE;
			}
		}

		// ÃÑ¾Ë ¿òÁ÷ÀÓ & Ãâ·Â
		for (int i = 0; i < BULLETSIZE; i++)
		{
			if (bullet[i].condition == TRUE)
			{
				gotoxy(bullet[i].position_x, bullet[i].position_y);
				puts("  ");
				bullet[i].position_y--;
				gotoxy(bullet[i].position_x, bullet[i].position_y);
				puts("¥¡");
			}
		}

		// ÆøÅº ¿òÁ÷ÀÓ & Ãâ·Â
		if (bomb[1] == TRUE)
		{
			if ((bomb[3] >= 10 && bomb[3] <= 18) && bomb_speed < 1)
			{
				gotoxy(bomb[2], bomb[3]);
				puts("                             ");
				gotoxy(bomb[2], bomb[3] + 1);
				puts("                             ");
				gotoxy(bomb[2], bomb[3] + 2);
				puts("                             ");
				gotoxy(bomb[2], bomb[3] + 3);
				puts("                             ");
				gotoxy(bomb[2], bomb[3] + 4);
				puts("                             ");
				bomb[3]--;
				gotoxy(bomb[2], bomb[3]);
				puts("<<[[*]]::=::{-*-}::=::[[*]]>>");
				gotoxy(bomb[2], bomb[3] + 1);
				puts("             | |             ");
				gotoxy(bomb[2], bomb[3] + 2);
				puts("             | |             ");
				gotoxy(bomb[2], bomb[3] + 3);
				puts("             | |             ");
				gotoxy(bomb[2], bomb[3] + 4);
				puts("         <[[::=::]]>         ");
				bomb_speed = 20;
			}
			if (bomb[3] > 18 || bomb[3] < 10)
			{
				gotoxy(bomb[2], bomb[3]);
				puts("                             ");
				gotoxy(bomb[2], bomb[3] + 1);
				puts("                             ");
				gotoxy(bomb[2], bomb[3] + 2);
				puts("                             ");
				gotoxy(bomb[2], bomb[3] + 3);
				puts("                             ");
				gotoxy(bomb[2], bomb[3] + 4);
				puts("                             ");
				bomb[3]--;
				gotoxy(bomb[2], bomb[3]);
				puts("<<[[*]]::=::{-*-}::=::[[*]]>>");
				gotoxy(bomb[2], bomb[3] + 1);
				puts("             | |             ");
				gotoxy(bomb[2], bomb[3] + 2);
				puts("             | |             ");
				gotoxy(bomb[2], bomb[3] + 3);
				puts("             | |             ");
				gotoxy(bomb[2], bomb[3] + 4);
				puts("         <[[::=::]]>         ");
			}
			bomb_speed--;
		}

		// ÆøÅº2
		if (bomb2[2] == TRUE)
		{
			if (bomb[3] < 25)
			{
				if ((bomb2[1] >= 12 && bomb2[1] <= 20) && bomb_speed2 < 1)
				{
					gotoxy(bomb2[0], bomb2[1]);
					puts("                             ");
					gotoxy(bomb2[0], bomb2[1] + 1);
					puts("                             ");
					gotoxy(bomb2[0], bomb2[1] + 2);
					puts("                             ");
					gotoxy(bomb2[0], bomb2[1] + 3);
					puts("                             ");
					gotoxy(bomb2[0], bomb2[1] + 4);
					puts("                             ");
					bomb2[1]--;
					gotoxy(bomb2[0], bomb2[1]);
					puts("<<[[*]]::=::{-*-}::=::[[*]]>>");
					gotoxy(bomb2[0], bomb2[1] + 1);
					puts("             | |             ");
					gotoxy(bomb2[0], bomb2[1] + 2);
					puts("             | |             ");
					gotoxy(bomb2[0], bomb2[1] + 3);
					puts("             | |             ");
					gotoxy(bomb2[0], bomb2[1] + 4);
					puts("         <[[::=::]]>         ");
					bomb_speed2 = 20;
				}
				if (bomb2[1] > 20 || bomb2[1] < 12)
				{
					gotoxy(bomb2[0], bomb2[1]);
					puts("                             ");
					gotoxy(bomb2[0], bomb2[1] + 1);
					puts("                             ");
					gotoxy(bomb2[0], bomb2[1] + 2);
					puts("                             ");
					gotoxy(bomb2[0], bomb2[1] + 3);
					puts("                             ");
					gotoxy(bomb2[0], bomb2[1] + 4);
					puts("                             ");
					bomb2[1]--;
					gotoxy(bomb2[0], bomb2[1]);
					puts("<<[[*]]::=::{-*-}::=::[[*]]>>");
					gotoxy(bomb2[0], bomb2[1] + 1);
					puts("             | |             ");
					gotoxy(bomb2[0], bomb2[1] + 2);
					puts("             | |             ");
					gotoxy(bomb2[0], bomb2[1] + 3);
					puts("             | |             ");
					gotoxy(bomb2[0], bomb2[1] + 4);
					puts("         <[[::=::]]>         ");
				}
				bomb_speed2--;
			}
		}

		// ÆøÅº ÃÑ¾Ë ¿òÁ÷ÀÓ & Ãâ·Â
		for (int i = 0; i < BOMBBULLETSIZE; i++)
		{
			if (bomb_bullet[i].condition == TRUE)
			{
				gotoxy(bomb_bullet[i].position_x, bomb_bullet[i].position_y);
				puts("                          ");
				bomb_bullet[i].position_y--;
				gotoxy(bomb_bullet[i].position_x, bomb_bullet[i].position_y);
				puts("   ¤¶                   ¤¶");
			}
		}

		// ÆøÅº ÃÑ¾Ë ¿òÁ÷ÀÓ & Ãâ·Â2
		for (int i = 0; i < BOMBBULLETSIZE; i++)
		{
			if (bomb_bullet2[i].condition == TRUE)
			{
				gotoxy(bomb_bullet2[i].position_x, bomb_bullet2[i].position_y);
				puts("                          ");
				bomb_bullet2[i].position_y--;
				gotoxy(bomb_bullet2[i].position_x, bomb_bullet2[i].position_y);
				puts("   ¤¶                   ¤¶");
			}
		}

		// ÃÑ¾ËÀÌ ÃµÀå¿¡ ´êÀ¸¸é »ç¶óÁü
		for (int i = 0; i < BULLETSIZE; i++)
		{
			if (bullet[i].condition == TRUE && bullet[i].position_y == 0)
			{
				gotoxy(bullet[i].position_x, bullet[i].position_y);
				puts("  ");
				bullet[i].condition = FALSE;
			}
		}
		
		// ÆøÅºÀÌ ÃµÀå¿¡ ´êÀ¸¸é »ç¶óÁü
		if (bomb[1] == TRUE && bomb[3] == 0)
		{
			gotoxy(bomb[2], bomb[3]);
			puts("                             ");
			gotoxy(bomb[2], bomb[3] + 1);
			puts("                             ");
			gotoxy(bomb[2], bomb[3] + 2);
			puts("                             ");
			gotoxy(bomb[2], bomb[3] + 3);
			puts("                             ");
			gotoxy(bomb[2], bomb[3] + 4);
			puts("                             ");
			bomb[3] = 24;
			bomb[1] = FALSE;
		}

		// ÆøÅº2ÀÌ ÃµÀå¿¡ ´êÀ¸¸é »ç¶óÁü
		if (bomb2[2] == TRUE && bomb2[1] == 0)
		{
			gotoxy(bomb2[0], bomb2[1]);
			puts("                             ");
			gotoxy(bomb2[0], bomb2[1] + 1);
			puts("                             ");
			gotoxy(bomb2[0], bomb2[1] + 2);
			puts("                             ");
			gotoxy(bomb2[0], bomb2[1] + 3);
			puts("                             ");
			gotoxy(bomb2[0], bomb2[1] + 4);
			puts("                             ");
			bomb2[1] = 24;
			bomb2[2] = FALSE;
		}

		// ÆøÅº ÃÑ¾ËÀÌ ÃµÀå¿¡ ´êÀ¸¸é »ç¶óÁü
		for (int i = 0; i < BOMBBULLETSIZE; i++)
		{
			if (bomb_bullet[i].condition == TRUE && bomb_bullet[i].position_y == 0)
			{
				gotoxy(bomb_bullet[i].position_x, bomb_bullet[i].position_y);
				puts("                          ");
				bomb_bullet[i].condition = FALSE;
			}
		}

		// ÆøÅº ÃÑ¾ËÀÌ ÃµÀå¿¡ ´êÀ¸¸é »ç¶óÁü2
		for (int i = 0; i < BOMBBULLETSIZE; i++)
		{
			if (bomb_bullet2[i].condition == TRUE && bomb_bullet2[i].position_y == 0)
			{
				gotoxy(bomb_bullet2[i].position_x, bomb_bullet2[i].position_y);
				puts("                          ");
				bomb_bullet2[i].condition = FALSE;
			}
		}

		Sleep(20);
		// Sleep(18);
	}
}
