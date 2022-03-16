#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // GetAsyncKeyState 사용을 위함
#include "common.h"
#include "game.h"

// 1. 게임 시작전 DB에 접속해서 상점 아이템 개수 불러오기 필요
// 2. 게임 종료시 사용한 상점 아이템 차감, 점수, 획득한 포인트, 랭킹 업데이트 필요

void game(void)
{
	system("mode con: cols=80 lines=40");

	// 생명, 폭탄, 체력, 점수
	int stat_list[STAT_SIZE] = { 5, 3, 5, 0 };

	// 플레이어 => 위치, 총알, 폭탄, 스킬
	PLAYER player;
	BULLET bullet[BULLET_SIZE] = { 0, };
	BOMB bomb[BOMB_SIZE] = { 0, };
	BOMB_BULLET bomb_bullet[BOMB_BUL_SIZE] = { 0, };
	BOMB_BULLET bomb_bullet2[BOMB_BUL_SIZE] = { 0, };

	player.pos_x = 28;
	player.pos_y = 34;
	bomb[0].pos_x = 29;
	bomb[0].pos_y = 34;
	bomb[0].count = 3;
	bomb[0].speed = 5;
	bomb[0].con = FALSE;
	bomb[1].pos_x = 6;
	bomb[1].pos_y = 34;
	bomb[1].speed = 5;
	bomb[1].con = FALSE;

	system("cls");
	drawContent(1);
	
	while (1)
	{
		// 반복할때마다 스탯과 플레이어 새로 그려줌
		drawStat(stat_list);
		gotoxy(player.pos_x, player.pos_y);
		puts("[-*-]");
		
		// ★ 키보드 입력 받는 기능들 함수로 분리하거나
		// ★ kbhit으로 묶어서 처리하면반응속도가 떨어짐
		
		// 플레이어 움직임
		{
			if (GetAsyncKeyState(VK_LEFT) && player.pos_x > 5) { //왼쪽
				gotoxy(player.pos_x, player.pos_y);
				printf("     ");
				player.pos_x--;
				gotoxy(player.pos_x, player.pos_y);
				puts("[-*-]");
			}
			if (GetAsyncKeyState(VK_RIGHT) && player.pos_x < 51) { //오른쪽
				gotoxy(player.pos_x, player.pos_y);
				printf("     ");
				player.pos_x++;
				gotoxy(player.pos_x, player.pos_y);
				puts("[-*-]");
			}
			if (GetAsyncKeyState(VK_UP) && player.pos_y > 10) { //위
				gotoxy(player.pos_x, player.pos_y);
				printf("     ");
				player.pos_y--;
				gotoxy(player.pos_x, player.pos_y);
				puts("[-*-]");
			}
			if (GetAsyncKeyState(VK_DOWN) && player.pos_y < 38) { //아래
				gotoxy(player.pos_x, player.pos_y);
				printf("     ");
				player.pos_y++;
				gotoxy(player.pos_x, player.pos_y);
				puts("[-*-]");
			}
		}

		// 플레이어 총알 공격
		if ((GetAsyncKeyState(VK_SPACE)))
		{
			for (int i = 0; i < BULLET_SIZE; i++)
			{
				if (bullet[i].con == FALSE)
				{
					bullet[i].pos_x = player.pos_x + 1;
					bullet[i].pos_y = player.pos_y - 1;
					bullet[i].con = TRUE;
					break; // 없으면 나중에 눈물이 나는 상황이 생김
				}
			}
		}

		// 폭탄 발사
		if ((GetAsyncKeyState(0x5A)))
		{
			if (bomb[0].count > 0 && (bomb[0].con == FALSE && bomb[1].con == FALSE))
			{
				bomb[0].count--;
				stat_list[1]--;
				bomb[0].con = TRUE;
				bomb[1].con = TRUE;
			}
		}

		// 폭탄 이동
		if (bomb[0].con == TRUE || bomb[1].con == TRUE)
		{
			int pos_x = 0;
			int pos_y = 0;

			pos_x = bomb[0].pos_x;
			pos_y = bomb[0].pos_y;

			// 폭탄 0번이 TRUE 상태인지 한번 더 검사하는 이유는
			// 폭탄 1번이 0번보다 느리게 끝나기 때문에
			// 한번 더 검사하지 않으면 폭탄 1번이 끝나는 시점에서
			// 하단에 폭탄 0번이 찍혀버리기 때문
			if (bomb[0].con == TRUE)
			{
				// 폭탄 0번 느리게 움직일때
				if ((pos_y >= 16 && pos_y <= 24) && bomb[0].speed < 1)
				{
					gotoxy(pos_x, pos_y);
					puts("                           ");
					gotoxy(pos_x + 11, pos_y + 1);
					puts("   ");
					gotoxy(pos_x + 11, pos_y + 2);
					puts("   ");
					gotoxy(pos_x +11, pos_y + 3);
					puts("   ");
					gotoxy(pos_x+7, pos_y + 4);
					puts("           ");
					bomb[0].pos_y--;
					pos_y = bomb[0].pos_y;
					gotoxy(pos_x, pos_y);
					puts("<<[[*]]:=:{-*-}:=:[[*]]>>");
					gotoxy(pos_x + 11, pos_y + 1);
					puts("| |");
					gotoxy(pos_x + 11, pos_y + 2);
					puts("| |");
					gotoxy(pos_x+11, pos_y + 3);
					puts("| |");
					gotoxy(pos_x+7, pos_y + 4);
					puts("<[[::=::]]>");
					bomb[0].speed = 20;
				}

				// 폭탄 0번 빠르게 움직일때
				if (pos_y > 24 || pos_y < 16)
				{
					gotoxy(pos_x, pos_y);
					puts("                           ");
					gotoxy(pos_x + 11, pos_y + 1);
					puts("   ");
					gotoxy(pos_x + 11, pos_y + 2);
					puts("   ");
					gotoxy(pos_x + 11, pos_y + 3);
					puts("   ");
					gotoxy(pos_x+7, pos_y + 4);
					puts("           ");
					bomb[0].pos_y--;
					pos_y = bomb[0].pos_y;
					gotoxy(pos_x, pos_y);
					puts("<<[[*]]:=:{-*-}:=:[[*]]>>");
					gotoxy(pos_x + 11, pos_y + 1);
					puts("| |");
					gotoxy(pos_x + 11, pos_y + 2);
					puts("| |");
					gotoxy(pos_x+11, pos_y + 3);
					puts("| |");
					gotoxy(pos_x+7, pos_y + 4);
					puts("<[[::=::]]>");
				}
			}

			// 폭탄 0번이 특정 위치까지 갔을때 폭탄 1번 이동
			if (pos_y < 30 || (bomb[0].con == FALSE && bomb[1].con == TRUE))
			{
				pos_x = bomb[1].pos_x;
				pos_y = bomb[1].pos_y;

				// 천천히
				if ((pos_y >= 18 && pos_y <= 26) && bomb[1].speed < 1)
				{
					gotoxy(pos_x, pos_y);
					puts("                         ");
					gotoxy(pos_x + 11, pos_y + 1);
					puts("   ");
					gotoxy(pos_x+11, pos_y + 2);
					puts("   ");
					gotoxy(pos_x+11, pos_y + 3);
					puts("   ");
					gotoxy(pos_x+7, pos_y + 4);
					puts("           ");
					bomb[1].pos_y--;
					pos_y = bomb[1].pos_y;
					gotoxy(pos_x, pos_y);
					puts("<<[[*]]:=:{-*-}:=:[[*]]>>");
					gotoxy(pos_x + 11, pos_y + 1);
					puts("| |");
					gotoxy(pos_x + 11, pos_y + 2);
					puts("| |");
					gotoxy(pos_x + 11, pos_y + 3);
					puts("| |");
					gotoxy(pos_x + 7, pos_y + 4);
					puts("<[[::=::]]>");
					bomb[1].speed = 20;
				}
				//빨리
				if (pos_y > 26 || pos_y < 18)
				{
					gotoxy(pos_x, pos_y);
					puts("                         ");
					gotoxy(pos_x+11, pos_y + 1);
					puts("   ");
					gotoxy(pos_x+11, pos_y + 2);
					puts("   ");
					gotoxy(pos_x+11, pos_y + 3);
					puts("   ");
					gotoxy(pos_x+7, pos_y + 4);
					puts("           ");
					bomb[1].pos_y--;
					pos_y = bomb[1].pos_y;
					gotoxy(pos_x, pos_y);
					puts("<<[[*]]:=:{-*-}:=:[[*]]>>");
					gotoxy(pos_x+11, pos_y + 1);
					puts("| |");
					gotoxy(pos_x + 11, pos_y + 2);
					puts("| |");
					gotoxy(pos_x + 11, pos_y + 3);
					puts("| |");
					gotoxy(pos_x+7, pos_y + 4);
					puts("<[[::=::]]>");
				}
				bomb[1].speed--;
			}
			bomb[0].speed--;
		}

		// 총알 이동
		for (int i = 0; i < BULLET_SIZE; i++)
		{
			if (bullet[i].con == TRUE)
			{
				gotoxy(bullet[i].pos_x, bullet[i].pos_y);
				puts("  ");
				bullet[i].pos_y--;
				gotoxy(bullet[i].pos_x, bullet[i].pos_y);
				puts("ⅰ");
			}
		}

		// 폭탄 총알 발사
		for (int i = 0; i < BOMB_BUL_SIZE; i++)
		{
			if ((bomb[0].pos_y >= 15 && bomb[0].pos_y <= 23) && bomb_bullet[i].con == FALSE)
			{
				bomb_bullet[i].pos_x = bomb[0].pos_x;
				bomb_bullet[i].pos_y = bomb[0].pos_y - 2;
				bomb_bullet[i].con = TRUE;
			}

			if ((bomb[1].pos_y >= 17 && bomb[1].pos_y <= 25) && bomb_bullet2[i].con == FALSE)
			{
				bomb_bullet2[i].pos_x = bomb[1].pos_x;
				bomb_bullet2[i].pos_y = bomb[1].pos_y - 2;
				bomb_bullet2[i].con = TRUE;
			}
		}

		// 폭탄 총알 이동
		for (int i = 0; i < BOMB_BUL_SIZE; i++)
		{
			if (bomb_bullet[i].con == TRUE)
			{
				gotoxy(bomb_bullet[i].pos_x, bomb_bullet[i].pos_y);
				puts("                      ");
				bomb_bullet[i].pos_y--;
				gotoxy(bomb_bullet[i].pos_x, bomb_bullet[i].pos_y);
				puts("    ㅆ              ㅆ");
			}

			if (bomb_bullet2[i].con == TRUE)
			{
				gotoxy(bomb_bullet2[i].pos_x, bomb_bullet2[i].pos_y);
				puts("                      ");
				bomb_bullet2[i].pos_y--;
				gotoxy(bomb_bullet2[i].pos_x, bomb_bullet2[i].pos_y);
				puts("    ㅆ              ㅆ");
			}
		}
		
		// 총알이 천장에 도달하면 삭제
		for (int i = 0; i < BULLET_SIZE; i++)
		{
			if (bullet[i].con == TRUE && bullet[i].pos_y == 0)
			{
				gotoxy(bullet[i].pos_x, bullet[i].pos_y);
				puts("  ");
				bullet[i].con = FALSE;
			}
		}
		
		// 폭탄이 천장에 도달하면 삭제
		{
			if (bomb[0].con == TRUE && bomb[0].pos_y == 0)
			{
				gotoxy(bomb[0].pos_x, bomb[0].pos_y);
				puts("                         ");
				gotoxy(bomb[0].pos_x + 11, bomb[0].pos_y + 1);
				puts("   ");
				gotoxy(bomb[0].pos_x + 11, bomb[0].pos_y + 2);
				puts("   ");
				gotoxy(bomb[0].pos_x+11, bomb[0].pos_y + 3);
				puts("   ");
				gotoxy(bomb[0].pos_x+7, bomb[0].pos_y + 4);
				puts("           ");
				bomb[0].pos_y = 34;
				bomb[0].con = FALSE;
			}

			if (bomb[1].con == TRUE && bomb[1].pos_y == 0)
			{
				gotoxy(bomb[1].pos_x, bomb[1].pos_y);
				puts("                         ");
				gotoxy(bomb[1].pos_x+11, bomb[1].pos_y + 1);
				puts("   ");
				gotoxy(bomb[1].pos_x + 11, bomb[1].pos_y + 2);
				puts("   ");
				gotoxy(bomb[1].pos_x + 11, bomb[1].pos_y + 3);
				puts("   ");
				gotoxy(bomb[1].pos_x+7, bomb[1].pos_y + 4);
				puts("           ");
				bomb[1].pos_y = 34;
				bomb[1].con = FALSE;
			}
		}

		// 폭탄 총알이 천장에 도달하면 삭제
		for (int i = 0; i < BOMB_BUL_SIZE; i++)
		{
			if (bomb_bullet[i].con == TRUE && bomb_bullet[i].pos_y == 0)
			{
				gotoxy(bomb_bullet[i].pos_x, bomb_bullet[i].pos_y);
				puts("                          ");
				bomb_bullet[i].con = FALSE;
			}

			if (bomb_bullet2[i].con == TRUE && bomb_bullet2[i].pos_y == 0)
			{
				gotoxy(bomb_bullet2[i].pos_x, bomb_bullet2[i].pos_y);
				puts("                          ");
				bomb_bullet2[i].con = FALSE;
			}
		}

		Sleep(20);
		// Sleep(18);
	}
}
