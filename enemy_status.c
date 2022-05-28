#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "common.h"

void enemy_status(ENEMY* enemy, BOMB* bomb, PLAYER* player, CANNON* cannon, SHOP_ITEM*  shop_item, int state)
{
	switch (state)
	{
	// 적군이 바닥에 도달하면 삭제
	case 0:
		for (int i = 0; i < ENEMY_SIZE; i++)
		{
			if (enemy->condition[i] == TRUE && enemy->pos_y[i] == 29)
			{
				gotoxy(enemy->pos_x[i], enemy->pos_y[i]);
				printf("     ");
				enemy->pos_x[i] = 0;
				enemy->pos_y[i] = 0;
				enemy->condition[i] = FALSE;
			}
		}
		break;
	// 플레이어 - 적 충돌
	case 1:
		for (int i = 0; i < ENEMY_SIZE; i++)
		{
			if (player->pos_y == enemy->pos_y[i])
			{
				if ((enemy->pos_x[i] <= player->pos_x && enemy->pos_x[i] + 5 >= player->pos_x) && enemy->pos_x[i] - 4 <= player->pos_x)
				{
					// game.c -> while(1) 마지막에 게임 오버를 체크하며 속도가 빠르기 때문에 게임 오버 처리는 따로 하지 않음
					if (player->life > 0)
					{
						player->life--;
						player->pos_x = 26;
						player->pos_y = 26;
						player->score -= 100;
						gotoxy(enemy->pos_x[i], enemy->pos_y[i]);
						printf("      ");
						enemy->pos_x[i] = 0;
						enemy->pos_y[i] = 0;
						enemy->condition[i] = FALSE;
						bomb->condition[0] = TRUE;
						bomb->condition[1] = TRUE;
						break;
					}
					break;
				}
			}
		}
		break;
	// 총알 - 적 충돌
	case 2:
		srand(time(NULL));
		for (int i = 0; i < CANNON_SIZE; i++)
		{
			for (int j = 0; j < ENEMY_SIZE; j++)
			{
				if ((cannon->condition[i] == TRUE && enemy->condition[j] == TRUE) && cannon->pos_y[i] == enemy->pos_y[j])
				{
					if ((enemy->pos_x[j] <= cannon->pos_x[i] - 1) && (enemy->pos_x[j] + 5) >= cannon->pos_x[i] + 1)
					{
						if (enemy->hp[j] > 0)
						{
							gotoxy(cannon->pos_x[i], cannon->pos_y[i]);
							switch (rand() % 5 + 1)
							{
							case 1:
								printf("A");
								break;
							case 2:
								printf("K");
								break;
							case 3:
								printf("♨");
								break;
							case 4:
								printf("★");
								break;
							case 5:
								printf("※");
								break;
							}
							switch (cannon->upgrade)
							{
							case LEVEL0:
								break;
							case LEVEL1:
								break;
							case LEVEL2:
								break;
							}

							gotoxy(cannon->pos_x[i], cannon->pos_y[i]);
							printf("  ");
							cannon->condition[i] = FALSE;
							enemy->hp[j]--;
						}
						else
						{
							gotoxy(enemy->pos_x[j], enemy->pos_y[j]);
							printf("      ");

							enemy->pos_x[j] = 0;
							enemy->pos_y[j] = 0;
							enemy->condition[j] = FALSE;
							switch (enemy->design[j])
							{
							case 0:
								if (shop_item->buff_on == TRUE)
								{
									player->score += 300;
								}
								else
								{
									player->score += 100;
								}
								break;
							case 1:
								if (shop_item->buff_on == TRUE)
								{
									player->score += 500;
								}
								else
								{
									player->score += 200;
								}
								break;
							case 2:
								if (shop_item->buff_on == TRUE)
								{
									player->score += 500;
								}
								else
								{
									player->score += 200;
								}
								break;
							}

							gotoxy(cannon->pos_x[i], cannon->pos_y[i]);
							printf("  ");
							cannon->condition[i] = FALSE;
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
			for (int j = 0; j < ENEMY_CANNON_SIZE; j++)
			{
				if ((bomb->bomb_cannon[0]->condition[j] == TRUE && enemy->condition[i] == TRUE) && bomb->bomb_cannon[0]->pos_y[j] == enemy->pos_y[i])
				{
					gotoxy(enemy->pos_x[i], enemy->pos_y[i]);
					printf("      ");
					enemy->pos_x[i] = 0;
					enemy->pos_y[i] = 0;
					enemy->condition[i] = FALSE;
					switch (enemy->design[i])
					{
					case 0:
						if (shop_item->buff_on == TRUE)
						{
							player->score += 150;
						}
						else
						{
							player->score += 50;
						}
						break;
					case 1:
						if (shop_item->buff_on == TRUE)
						{
							player->score += 200;
						}
						else
						{
							player->score += 60;
						}
						break;
					case 2:
						if (shop_item->buff_on == TRUE)
						{
							player->score += 170;
						}
						else
						{
							player->score += 53;
						}
						break;
					}
				}

				if ((bomb->bomb_cannon[1]->condition[j] == TRUE && enemy->condition[i] == TRUE) && bomb->bomb_cannon[1]->pos_y[j] == enemy->pos_y[i])
				{
					gotoxy(enemy->pos_x[i], enemy->pos_y[i]);
					printf("      ");
					enemy->pos_x[i] = 0;
					enemy->pos_y[i] = 0;
					enemy->condition[i] = FALSE;
					switch (enemy->design[i])
					{
					case 0:
						if (shop_item->buff_on == TRUE)
						{
							player->score += 150;
						}
						else
						{
							player->score += 50;
						}
						break;
					case 1:
						if (shop_item->buff_on == TRUE)
						{
							player->score += 200;
						}
						else
						{
							player->score += 60;
						}
						break;
					case 2:
						if (shop_item->buff_on == TRUE)
						{
							player->score += 170;
						}
						else
						{
							player->score += 53;
						}
						break;
					}
				}
			}
		}
		break;
	}
}