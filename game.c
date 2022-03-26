#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // GetAsyncKeyState 사용을 위함
#include <time.h>
#include "common.h"
#include "game.h"

void game(void)
{
	system("mode con: cols=80 lines=32");
	system("cls");
	srand(time(NULL));

	// 플레이어 - 폭탄, 스킬 포함
	Player player = { 28, 28, 1, 3, 0 }; // X값, Y값, 생명, 체력, 점수
	Bullet bullet[BULLET_SIZE] = { 0, }; // X값, Y값, 확인
	Skill skill = { 3, 3, 0, 0 };
	Item item[ITEM_SIZE] = { 0, };
	Bomb bomb[BOMB_SIZE] = { 29, 24, 1, 5, FALSE, 6, 24, 0, 5, FALSE }; // // X값, Y값, 잔량, 속도, 확인
	Bomb_blt bomb_bul[BOMB_BUL_SIZE] = { 0, };
	Bomb_blt bomb_bul2[BOMB_BUL_SIZE] = { 0, };
	
	// 적군
	int frame_cnt = 0; // 스테이지 생성용
	Enemy enemy[ENEMY_SIZE] = { 0, };

	while (1)
	{
		drawContent(1);
		drawStat(player, bomb);
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
		if ((GetAsyncKeyState(0x58) && frame_cnt > 1) && (skill.life_count == 0 && skill.life_plus > 0))
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
		enemyGen(enemy, frame_cnt);

		// 아이템 생성
		itemGen(item, frame_cnt);

		// 적군 이동
		enemyMove(enemy);

		// 폭탄 이동
		if (bomb[0].con == TRUE || bomb[1].con == TRUE)
			bombMove(bomb);

		// 총알 이동
		bulletMove(bullet);

		// 적군 총알 발사
		enemyBul(enemy, 0);

		// 적 총알 이동
		enemyBul(enemy, 1);
		
		// 아이템 이동
		itemMove(item);
		
		// 아이템 유저 충돌
		itemStatus(item, player, bullet, 0);

		// 아이템 바닥 충돌
		itemStatus(item, player, bullet, 1);
		
		// 적 총알 플레이어 충돌
		player = enmBulStatus(enemy, player, bomb, bullet, 0);

		// 적 총알 바닥 도달
		player = enmBulStatus(enemy, player, bomb, bullet, 1);
		
		// 적 총알 플레이어 총알 충돌
		player = enmBulStatus(enemy, player, bomb, bullet, 2);
		
		// 폭탄 발사시 적 총알 폭탄 앞에서 삭제
		player = enmBulStatus(enemy, player, bomb, bullet, 3);
		
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
						if (enemy[i].health > 0)
						{
							gotoxy(bullet[i].pos_x, bullet[i].pos_y);
							switch (rand() % 5 + 1)
							{
							case 1:
								puts("0");
								break;
							case 2:
								puts("o");
								break;
							case 3:
								puts("☆");
								break;
							case 4:
								puts("★");
								break;
							case 5:
								puts("♧");
								break;
							}
							enemy[i].health--;
						}
						else
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
		}

		// 폭탄 총알 발사
		bombBul(bomb, bomb_bul, bomb_bul2, 0);

		// 폭탄 총알 이동
		bombBul(bomb, bomb_bul, bomb_bul2, 1);

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

		// 스킬 재사용 대기
		if (skill.life_count > 0)
			skill.life_count--;

		frame_cnt++;
		Sleep(22);
	}
}