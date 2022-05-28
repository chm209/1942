#include <stdio.h>
#include "game.h"
#include "common.h"

void eCannon_status(ENEMY* enemy, PLAYER* player, BOMB* bomb, CANNON* cannon, int state)
{
	switch (state)
	{
	// Àû±º ÃÑ¾Ë ¹ß»ç
	case 0:
		for (int i = 0; i < ENEMY_SIZE; i++)
		{
			if (enemy->condition[i] == TRUE)
			{
				if (enemy->pos_y[i] < 25)
				{
					for (int j = 0; j < ENEMY_CANNON_SIZE; j++)
					{
						if (enemy->enemy_cannon[i]->condition[j] == FALSE)
						{
							if (enemy->pattern[i] == 1 || enemy->pattern[i] == 0)
							{
								if (enemy->enemy_cannon[i]->move_interval > 60 && (enemy->move_count[i] == 1 || enemy->move_count[i] == 3))
								{
									enemy->enemy_cannon[i]->pos_x[j] = enemy->pos_x[i] + 2;
									enemy->enemy_cannon[i]->pos_y[j] = enemy->pos_y[i] + 1;
									enemy->enemy_cannon[i]->condition[j] = TRUE;
									enemy->enemy_cannon[i]->move_interval = 0;
									gotoxy(enemy->enemy_cannon[i]->pos_x[j], enemy->enemy_cannon[i]->pos_y[j]);
									printf("*");
								}
							}
							if (enemy->enemy_cannon[i]->move_interval > 60 && (enemy->pattern[i] == 2 || enemy->pattern[i] == 3))
							{
								if (enemy->move_count[i] == 3)
								{
									enemy->enemy_cannon[i]->pos_x[j] = enemy->pos_x[i] + 2;
									enemy->enemy_cannon[i]->pos_y[j] = enemy->pos_y[i] + 1;
									enemy->enemy_cannon[i]->condition[j] = TRUE;
									enemy->enemy_cannon[i]->move_interval = 0;
									gotoxy(enemy->enemy_cannon[i]->pos_x[j], enemy->enemy_cannon[i]->pos_y[j]);
									printf("¢´");
								}
							}
							if ((enemy->pattern[i] == 4 && enemy->move_count[i] == 1) && (enemy->move_interval[i] < 175))
							{
								enemy->enemy_cannon[i]->pos_x[j] = enemy->pos_x[i] + 2;
								enemy->enemy_cannon[i]->pos_y[j] = enemy->pos_y[i] + 1;
								enemy->enemy_cannon[i]->move_interval = 0;
								enemy->enemy_cannon[i]->condition[j] = TRUE;
								gotoxy(enemy->enemy_cannon[i]->pos_x[j], enemy->enemy_cannon[i]->pos_y[j]);
								printf("W");
							}
							if (enemy->enemy_cannon[i]->move_interval > 60 && (enemy->pattern[i] == 5 && (enemy->pos_y[i] > 1 && enemy->pos_y[i] < 18)))
							{
								enemy->enemy_cannon[i]->pos_x[j] = enemy->pos_x[i] + 2;
								enemy->enemy_cannon[i]->pos_y[j] = enemy->pos_y[i] + 1;
								enemy->enemy_cannon[i]->pos_x[j + 1] = enemy->pos_x[i] + 6;
								enemy->enemy_cannon[i]->pos_y[j + 1] = enemy->pos_y[i];
								enemy->enemy_cannon[i]->pos_x[j + 2] = enemy->pos_x[i] - 3;
								enemy->enemy_cannon[i]->pos_y[j + 2] = enemy->pos_y[i];
								enemy->enemy_cannon[i]->condition[j] = TRUE;
								enemy->enemy_cannon[i]->condition[j+1] = TRUE;
								enemy->enemy_cannon[i]->condition[j+2] = TRUE;
								enemy->enemy_cannon[i]->move_pattern[j + 1] = 1;
								enemy->enemy_cannon[i]->move_pattern[j + 2] = 2;
								gotoxy(enemy->enemy_cannon[i]->pos_x[j], enemy->enemy_cannon[i]->pos_y[j]);
								printf("*");
								gotoxy(enemy->enemy_cannon[i]->pos_x[j+1], enemy->enemy_cannon[i]->pos_y[j + 1]);
								printf("*");
								gotoxy(enemy->enemy_cannon[i]->pos_x[j + 2], enemy->enemy_cannon[i]->pos_y[j + 2]);
								printf("*");
								enemy->enemy_cannon[i]->move_interval = 0;
							}
						}
					}
					enemy->enemy_cannon[i]->move_interval++;
				}
			}
		}
		break;
	// Àû ÃÑ¾Ë ÇÃ·¹ÀÌ¾î Ãæµ¹
	case 1:
		for (int i = 0; i < ENEMY_SIZE; i++)
		{
			for (int j = 0; j < ENEMY_CANNON_SIZE; j++)
			{
				if (enemy->enemy_cannon[i]->condition[j] == TRUE && enemy->enemy_cannon[i]->pos_y[j] == player->pos_y)
				{
					if ((enemy->enemy_cannon[i]->pos_x[j] >= player->pos_x) && (enemy->enemy_cannon[i]->pos_x[j] <= player->pos_x + 5))
					{
						gotoxy(enemy->enemy_cannon[i]->pos_x[j], enemy->enemy_cannon[i]->pos_y[j]);
						printf("  ");
						enemy->enemy_cannon[i]->condition[j] = FALSE;

						if (player->hp > 0)
						{
							player->hp--;
						}
						else
						{
							if (player->life > 0)
							{
								player->life--;
								player->hp = 3;
								player->score -= 100;
								gotoxy(enemy->enemy_cannon[i]->pos_x[j], enemy->enemy_cannon[i]->pos_y[j]);
								printf("     ");
								player->pos_x = 26;
								player->pos_y = 26;
								bomb->condition[0] = TRUE;
								bomb->condition[1] = TRUE;
							}
						}

					}
				}
			}
		}
		break;
	// Àû ÃÑ¾Ë ¹Ù´Ú µµ´Þ
	case 2:
		for (int i = 0; i < ENEMY_SIZE; i++)
		{
			for (int j = 0; j < ENEMY_CANNON_SIZE; j++)
			{
				if (enemy->enemy_cannon[i]->condition[j] == TRUE && enemy->enemy_cannon[i]->pos_y[j] == 29)
				{
					gotoxy(enemy->enemy_cannon[i]->pos_x[j], enemy->enemy_cannon[i]->pos_y[j]);
					printf("    ");
					enemy->enemy_cannon[i]->condition[j] = FALSE;
				}

				if (enemy->enemy_cannon[i]->condition[j] == TRUE && enemy->enemy_cannon[i]->pos_x[j] == 5)
				{
					gotoxy(enemy->enemy_cannon[i]->pos_x[j], enemy->enemy_cannon[i]->pos_y[j]);
					printf("  ");
					enemy->enemy_cannon[i]->condition[j] = FALSE;
				}

				if (enemy->enemy_cannon[i]->condition[j] == TRUE && enemy->enemy_cannon[i]->pos_x[j] == 55)
				{
					gotoxy(enemy->enemy_cannon[i]->pos_x[j], enemy->enemy_cannon[i]->pos_y[j]);
					printf("  ");
					enemy->enemy_cannon[i]->condition[j] = FALSE;
				}
			}
		}
		break;
	// Àû ÃÑ¾Ë ÇÃ·¹ÀÌ¾î ÃÑ¾Ë Ãæµ¹
	case 3:
		for (int i = 0; i < ENEMY_SIZE; i++)
		{
			for (int j = 0; j < ENEMY_CANNON_SIZE; j++)
			{
				for (int k = 0; k < CANNON_SIZE; k++)
				{
					if (enemy->enemy_cannon[i]->condition[j] == TRUE && cannon->condition[k] == TRUE)
					{
						if (enemy->enemy_cannon[i]->pos_y[j] == cannon->pos_y[k])
						{
							if (enemy->enemy_cannon[i]->pos_x[j] == cannon->pos_x[k])
							{
								gotoxy(enemy->enemy_cannon[i]->pos_x[j], enemy->enemy_cannon[i]->pos_y[j]);
								printf("  ");
								enemy->enemy_cannon[i]->condition[j] = FALSE;
								cannon->condition[k] = FALSE;
							}
						}
					}
				}
			}
		}
		break;
	// ÆøÅº ¹ß»ç½Ã Àû ÃÑ¾Ë ÆøÅº ¾Õ¿¡¼­ »èÁ¦
	case 4:
		if (bomb->condition[0] == TRUE || bomb->condition[1] == TRUE)
		{
			for (int i = 0; i < ENEMY_SIZE; i++)
			{
				for (int j = 0; j < ENEMY_CANNON_SIZE; j++)
				{
					if (enemy->enemy_cannon[i]->condition[j] == TRUE && (enemy->enemy_cannon[i]->pos_y[j] >= bomb->pos_y[0] || enemy->enemy_cannon[i]->pos_y[j] >= bomb->pos_y[1]))
					{
						gotoxy(enemy->enemy_cannon[i]->pos_x[j], enemy->enemy_cannon[i]->pos_y[j]);
						puts("  ");
						enemy->enemy_cannon[i]->condition[j] = FALSE;
					}
				}
			}
		}
		break;
	}
}