#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // GetAsyncKeyState 사용을 위함
#include "common.h"
#include "game.h"

// 함수
void stage(int);

// 전역 변수
Enemy enemy[ENEMY_SIZE] = { 0, };

void game(void)
{
	system("mode con: cols=80 lines=31");
	system("cls");

	// 생명, 폭탄, 체력, 점수
	int stat_list[STAT] = { 5, 3, 5, 0 };

	// 플레이어
	// 위치, 총알, 폭탄, 스킬 관련
	Player player = { 28, 28, 1, 3, 0 }; // X값, Y값, 생명, 체력, 점수
	Bullet bullet[BULLET_SIZE] = { 0, }; // X값, Y값, 확인
	Skill skill = { 3, 3, 0, 0 };
	Bomb bomb[BOMB_SIZE] = { 29, 24, 3, 5, FALSE, 6, 24, 0, 5, FALSE }; // // X값, Y값, 잔량, 속도, 확인
	Bomb_blt bomb_bul[BOMB_BUL_SIZE] = { 0, };
	Bomb_blt bomb_bul2[BOMB_BUL_SIZE] = { 0, };
	
	// 적군
	int frame_cnt = 0;

	while (1)
	{
		// 반복할때마다 UI와 스탯을 새로 그려줌
		drawContent(1);
		drawStat(stat_list);
		gotoxy(player.pos_x, player.pos_y);
		puts("[-*-]");

		// 유저 키보드 감지
		// GetAsyncKeyState()로 상시 감지하기 위해 함수화 X
		// 함수화 하거나 getch()로 돌리면 반응속도가 떨어짐
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
			if (GetAsyncKeyState(VK_UP) && player.pos_y > 4) { //위
				gotoxy(player.pos_x, player.pos_y);
				printf("     ");
				player.pos_y--;
				gotoxy(player.pos_x, player.pos_y);
				puts("[-*-]");
			}
			if (GetAsyncKeyState(VK_DOWN) && player.pos_y < 29) { //아래
				gotoxy(player.pos_x, player.pos_y);
				printf("     ");
				player.pos_y++;
				gotoxy(player.pos_x, player.pos_y);
				puts("[-*-]");
			}
		}

		// 플레이어 총알 공격 스페이스바
		if ((GetAsyncKeyState(VK_SPACE)))
		{
			for (int i = 0; i < BULLET_SIZE; i++)
			{
				if (bullet[i].con == FALSE)
				{
					bullet[i].pos_x = player.pos_x + 1;
					bullet[i].pos_y = player.pos_y - 1;
					bullet[i].con = TRUE;
					break;
				}
			}
		}

		// 폭탄 발사 Z키, frame_cnt > 1은 게임 시작하기전 Z키가 눌렸을대 스킬이 써지는걸 방지하기위함
		if (GetAsyncKeyState(0x5A) && frame_cnt > 1)
		{
			if (bomb[0].count > 0 && (bomb[0].con == FALSE && bomb[1].con == FALSE))
			{
				bomb[0].count--;
				bomb[0].con = TRUE;
				bomb[1].con = TRUE;
			}
		}

		// 스킬 X키 - 생명 추가
		// STAT UI에 반영해야함
		if ((GetAsyncKeyState(0x58) && frame_cnt > 1 ) && (skill.life_count == 0 && skill.life_plus > 0 ))
		{
			player.life++;
			skill.life_plus--;

			if (bomb[0].count > 0 && (bomb[0].con == FALSE && bomb[1].con == FALSE))
			{
				bomb[0].con = TRUE;
				bomb[1].con = TRUE;
				// 스킬 재사용 시간 조정 필요
				skill.life_count = 1000;
			}
			else
			{
				bomb[0].count++;
				// 스킬 재사용 시간 조정 필요
				skill.life_count = 1000;
			}
		}

		// 스킬 C키 - 무적 기능
		if ((GetAsyncKeyState(0x43) && frame_cnt > 1))
		{
			// 적군 만들고 나서 만들어야함
			// 적군이나 총알이 유저한테 충돌해도 데미지 없음
		}

		// 적군 생성
		stage(frame_cnt);

		// 적군 이동
		for (int i = 0; i < ENEMY_SIZE; i++)
		{
			if (enemy[i].con == TRUE)
			{
				gotoxy(enemy[i].pos_x, enemy[i].pos_y);
				printf("     ");

				// 오른쪽 대각선 이동
				if (enemy[i].move_pattern == 0)
				{
					// 자기 턴이 오면 진행
					if (enemy[i].speed == 6)
					{
						// 아래로 내려갈 차례인지 옆으로 갈 차례인지 검사
						if (enemy[i].move_count == 3)
						{
							enemy[i].pos_y++;
							enemy[i].move_count = 0;
						}
						else
						{
							// 벽쪽으로 갔는지 검사, 벽쪽으로 갔으면 move_count 올릴 필요 없음
							if (enemy[i].pos_x > 48)
								enemy[i].pos_y++;
							else
							{
								enemy[i].pos_x++;
								enemy[i].move_count++;
							}
						}
						// 턴 초기화
						enemy[i].speed = 0;
					}
					else
					{
						enemy[i].speed++;
					}
				}

				// 왼쪽 대각선 이동
				if (enemy[i].move_pattern == 1)
				{
					// 자기 턴이 오면 진행
					if (enemy[i].speed == 9)
					{
						// 아래로 내려갈 차례인지 옆으로 갈 차례인지 검사
						if (enemy[i].move_count == 2)
						{
							enemy[i].pos_y++;
							enemy[i].move_count = 0;
						}
						else
						{
							// 벽쪽으로 갔는지 검사, 벽쪽으로 갔으면 move_count 올릴 필요 없음
							if (enemy[i].pos_x < 10)
								enemy[i].pos_y++;
							else
							{
								enemy[i].pos_x -= 2;
								enemy[i].move_count++;
							}
						}
						// 턴 초기화
						enemy[i].speed = 0;
					}
					else
					{
						enemy[i].speed++;
					}
				}

				gotoxy(enemy[i].pos_x, enemy[i].pos_y);
				switch (enemy[i].type)
				{
				case 0:
					printf("<WvW>");
					break;
				}
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
				if ((pos_y >= 13 && pos_y <= 18) && bomb[0].speed < 1)
				{
					gotoxy(pos_x, pos_y);
					puts("                           ");
					gotoxy(pos_x + 11, pos_y + 1);
					puts("   ");
					gotoxy(pos_x + 11, pos_y + 2);
					puts("   ");
					gotoxy(pos_x + 11, pos_y + 3);
					puts("   ");
					gotoxy(pos_x + 7, pos_y + 4);
					puts("           ");
					bomb[0].pos_y--;
					pos_y = bomb[0].pos_y;
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
					bomb[0].speed = 20;
				}

				// 폭탄 0번 빠르게 움직일때
				if (pos_y > 18 || pos_y < 13)
				{
					gotoxy(pos_x, pos_y);
					puts("                           ");
					gotoxy(pos_x + 11, pos_y + 1);
					puts("   ");
					gotoxy(pos_x + 11, pos_y + 2);
					puts("   ");
					gotoxy(pos_x + 11, pos_y + 3);
					puts("   ");
					gotoxy(pos_x + 7, pos_y + 4);
					puts("           ");
					bomb[0].pos_y--;
					pos_y = bomb[0].pos_y;
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
				}
			}

			// 폭탄 0번이 특정 위치까지 갔을때 폭탄 1번 이동
			if (pos_y < 18 || (bomb[0].con == FALSE && bomb[1].con == TRUE))
			{
				pos_x = bomb[1].pos_x;
				pos_y = bomb[1].pos_y;

				// 천천히
				if ((pos_y >= 14 && pos_y <= 19) && bomb[1].speed < 1)
				{
					gotoxy(pos_x, pos_y);
					puts("                         ");
					gotoxy(pos_x + 11, pos_y + 1);
					puts("   ");
					gotoxy(pos_x + 11, pos_y + 2);
					puts("   ");
					gotoxy(pos_x + 11, pos_y + 3);
					puts("   ");
					gotoxy(pos_x + 7, pos_y + 4);
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
				if (pos_y > 19 || pos_y < 14)
				{
					gotoxy(pos_x, pos_y);
					puts("                         ");
					gotoxy(pos_x + 11, pos_y + 1);
					puts("   ");
					gotoxy(pos_x + 11, pos_y + 2);
					puts("   ");
					gotoxy(pos_x + 11, pos_y + 3);
					puts("   ");
					gotoxy(pos_x + 7, pos_y + 4);
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

		// 플레이어 - 적 충돌
		for (int i = 0; i < ENEMY_SIZE; i++)
		{
			if (player.pos_y == enemy[i].pos_y)
			{
				if ((enemy[i].pos_x <= player.pos_x && enemy[i].pos_x + 5 >= player.pos_x) && enemy[i].pos_x - 4 <= player.pos_x)
				{
					if (player.life > 0)
					{
						player.life--;
						player.pos_x = 26;
						player.pos_y = 26;
						gotoxy(enemy[i].pos_x, enemy[i].pos_y);
						puts("      ");
						enemy[i].pos_x = 0;
						enemy[i].pos_y = 0;
						enemy[i].con = FALSE;
						bomb[0].con = TRUE;
						bomb[1].con = TRUE;
						break;
					}
					else
					{
						// 게임오버
					}
					break;
				}
			}
		}

		// 총알 - 적 충돌
		for (int i = 0; i < BULLET_SIZE; i++)
		{
			for (int j = 0; j < ENEMY_SIZE; j++)
			{
				if ((bullet[i].con == TRUE && enemy[j].con == TRUE) && bullet[i].pos_y == enemy[j].pos_y)
				{
					if ((enemy[j].pos_x <= bullet[i].pos_x - 1) && (enemy[j].pos_x + 5) >= bullet[i].pos_x + 1)
					{
						gotoxy(enemy[j].pos_x, enemy[j].pos_y);
						puts("      ");
						enemy[j].pos_x = 0;
						enemy[j].pos_y = 0;
						enemy[j].con = FALSE;

						gotoxy(bullet[i].pos_x, bullet[i].pos_y);
						puts("  ");
						bullet[i].con = FALSE;
					}
				}
			}
		}

		// 폭탄 총알 발사
		for (int i = 0; i < BOMB_BUL_SIZE; i++)
		{
			if ((bomb[0].pos_y >= 13 && bomb[0].pos_y <= 18) && bomb_bul[i].con == FALSE)
			{
				bomb_bul[i].pos_x = bomb[0].pos_x;
				bomb_bul[i].pos_y = bomb[0].pos_y - 2;
				bomb_bul[i].con = TRUE;
			}

			if ((bomb[1].pos_y >= 14 && bomb[1].pos_y <= 19) && bomb_bul2[i].con == FALSE)
			{
				bomb_bul2[i].pos_x = bomb[1].pos_x;
				bomb_bul2[i].pos_y = bomb[1].pos_y - 2;
				bomb_bul2[i].con = TRUE;
			}
		}

		// 폭탄 총알 이동
		for (int i = 0; i < BOMB_BUL_SIZE; i++)
		{
			if (bomb_bul[i].con == TRUE)
			{
				gotoxy(bomb_bul[i].pos_x, bomb_bul[i].pos_y);
				puts("                      ");
				bomb_bul[i].pos_y--;
				gotoxy(bomb_bul[i].pos_x, bomb_bul[i].pos_y);
				puts("    ㅆ              ㅆ");
			}

			if (bomb_bul2[i].con == TRUE)
			{
				gotoxy(bomb_bul2[i].pos_x, bomb_bul2[i].pos_y);
				puts("                      ");
				bomb_bul2[i].pos_y--;
				gotoxy(bomb_bul2[i].pos_x, bomb_bul2[i].pos_y);
				puts("    ㅆ              ㅆ");
			}
		}

		// 폭탄 - 적 충돌
		if (bomb[0].con == TRUE && bomb[1].con == TRUE)
		{
			for (int i = 0; i < BOMB_SIZE; i++)
			{
				for (int j = 0; j < ENEMY_SIZE; j++)
				{
					if (bomb[i].pos_y == enemy[j].pos_y || (enemy[j].pos_y - bomb[i].pos_y > 0))
					{
						gotoxy(enemy[j].pos_x, enemy[j].pos_y);
						puts("      ");
						enemy[j].pos_x = 0;
						enemy[j].pos_y = 0;
						enemy[j].con = FALSE;
					}
				}
			}
		}

		// 폭탄 총알 - 적 충돌
		for (int i = 0; i < ENEMY_SIZE; i++)
		{
			for (int j = 0; j < BOMB_BUL_SIZE; j++)
			{
				if ((bomb_bul[j].con == TRUE && enemy[i].con == TRUE) && bomb_bul[j].pos_y == enemy[i].pos_y)
				{
					gotoxy(enemy[i].pos_x, enemy[i].pos_y);
					puts("      ");
					enemy[i].pos_x = 0;
					enemy[i].pos_y = 0;
					enemy[i].con = FALSE;
				}

				if ((bomb_bul2[j].con == TRUE && enemy[i].con == TRUE) && bomb_bul2[j].pos_y == enemy[i].pos_y)
				{
					gotoxy(enemy[i].pos_x, enemy[i].pos_y);
					puts("      ");
					enemy[i].pos_x = 0;
					enemy[i].pos_y = 0;
					enemy[i].con = FALSE;
				}
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
				gotoxy(bomb[0].pos_x + 11, bomb[0].pos_y + 3);
				puts("   ");
				gotoxy(bomb[0].pos_x + 7, bomb[0].pos_y + 4);
				puts("           ");
				bomb[0].pos_y = 24;
				bomb[0].con = FALSE;
			}

			if (bomb[1].con == TRUE && bomb[1].pos_y == 0)
			{
				gotoxy(bomb[1].pos_x, bomb[1].pos_y);
				puts("                         ");
				gotoxy(bomb[1].pos_x + 11, bomb[1].pos_y + 1);
				puts("   ");
				gotoxy(bomb[1].pos_x + 11, bomb[1].pos_y + 2);
				puts("   ");
				gotoxy(bomb[1].pos_x + 11, bomb[1].pos_y + 3);
				puts("   ");
				gotoxy(bomb[1].pos_x + 7, bomb[1].pos_y + 4);
				puts("           ");
				bomb[1].pos_y = 24;
				bomb[1].con = FALSE;
			}
		}

		// 폭탄 총알이 천장에 도달하면 삭제
		for (int i = 0; i < BOMB_BUL_SIZE; i++)
		{
			if (bomb_bul[i].con == TRUE && bomb_bul[i].pos_y == 0)
			{
				gotoxy(bomb_bul[i].pos_x, bomb_bul[i].pos_y);
				puts("                          ");
				bomb_bul[i].con = FALSE;
			}

			if (bomb_bul2[i].con == TRUE && bomb_bul2[i].pos_y == 0)
			{
				gotoxy(bomb_bul2[i].pos_x, bomb_bul2[i].pos_y);
				puts("                          ");
				bomb_bul2[i].con = FALSE;
			}
		}

		// 적군이 바닥에 도달하면 삭제
		for (int i = 0; i < ENEMY_SIZE; i++)
		{
			if (enemy[i].con == TRUE && enemy[i].pos_y == 29)
			{
				gotoxy(enemy[i].pos_x, enemy[i].pos_y);
				printf("     ");
				enemy[i].pos_x = 0;
				enemy[i].pos_y = 0;
				enemy[i].con = FALSE;
			}
		}

		// 플레이어 스탯 동기화
		stat_list[0] = player.life; // 생명
		stat_list[1] = bomb[0].count; // 폭탄
		// stat_list[2] = ; // 체력
		// stat_list[3] = ; // 점수

		// 스킬 재사용 대기
		if (skill.life_count > 0)
			skill.life_count--;

		frame_cnt++;
		Sleep(15);
	}
}

void stage(int frame_cnt)
{
	for (int i = 0; i < ENEMY_SIZE; i++)
	{
		if ((enemy[i].con == FALSE && (frame_cnt >= 45 && frame_cnt <= 315) && (frame_cnt - 45) % 90 == 0))
		{
			enemy[i].pos_x = 6;
			enemy[i].pos_y = 0;
			enemy[i].type = 0; // <[W]> * * * * * * *
			enemy[i].move_pattern = 0; // 오른쪽 대각선 이동
			enemy[i].move_count = 0;
			enemy[i].speed = 0;
			enemy[i].con = TRUE;
			gotoxy(enemy[i].pos_x, enemy[i].pos_y);
			switch (enemy[i].type)
			{
			case 0:
				printf("<WvW>");
				break;
			}
			break;
		}
		if ((enemy[i].con == FALSE && (frame_cnt >= 90 && frame_cnt <= 360) && (frame_cnt - 90) % 90 == 0))
		{
			enemy[i].pos_x = 50;
			enemy[i].pos_y = 1;
			// <[W]> * * * * * * *
			enemy[i].type = 0;
			// 왼쪽 대각선으로 이동
			enemy[i].move_pattern = 1;
			enemy[i].con = TRUE;
			enemy[i].move_count = 0;
			enemy[i].speed = 0;
			gotoxy(enemy[i].pos_x, enemy[i].pos_y);
			switch (enemy[i].type)
			{
			case 0:
				printf("<WvW>");
				break;
			}
			break;
		}
	}

	// 스테이지별로 적군 생성
	// 메인하뭇에서 f_cnt가 증가하여 45~315동안 90으로 나누어 떨어질때 적군 생성
	// n_enemy(x좌표, y좌표, 타입, 이동패턴, 방향)으로 생성
	// 아이템 생성도 스테이지 함수에 맏겨야함 
	// 5 ~ 55 사이에 위치해야함
	// printf("<[W]>");
	// printf("<WvvW>");
	// printf("[-|-]");;
}
