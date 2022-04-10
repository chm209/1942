#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "common.h"

Player enm_status(Enemy* enemy, Bomb* bomb, Bomb_blt* bomb_bul, Bomb_blt* bomb_bul2, Player player, Bullet* bullet, int num)
{
	switch (num)
	{
	// 적군이 바닥에 도달하면 삭제
	case 0:
		for (int i = 0; i < ENEMY_SIZE; i++)
		{
			if (enemy[i].con == TRUE && enemy[i].pos_y == 29)
			{
				gotoxy(enemy[i].pos_x, enemy[i].pos_y);
				puts("     ");
				enemy[i].pos_x = 0;
				enemy[i].pos_y = 0;
				enemy[i].con = FALSE;
			}
		}
		break;
	// 플레이어 - 적 충돌
	case 1:
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
		break;
	// 총알 - 적 충돌
	case 2:
		srand(time(NULL));
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
		break;
	// 폭탄 총알 - 적 충돌
	case 3:
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
		break;
	}

	return player;
}