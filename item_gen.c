#include <stdio.h>
#include "common.h"
#include "game.h"

// +---------------+------+
// | item gen time | time |
// +---------------+------+
// | cannon up     | 700  |
// | cannon qty+   | 900  |
// | life+         | 1300 |
// | hp+           | 1400 |
// | cannon qty+   | 2000 |
// | hp+           | 2050 |
// | cannon up     | 2300 |
// | cannon qty+   | 2600 |
// | hp+           | 2900 |
// +---------------+------+

void item_gen(DROP_ITEM* drop_item, int frame_time)
{
	int isCreated = FALSE;

	for (int i = 0; i < ITEM_SIZE; i++)
	{
		// 캐논 업그레이드
		if (frame_time == 700 && drop_item->condition[i] == FALSE)
		{
			drop_item->pos_x[i] = 10;
			drop_item->pos_y[i] = 0;
			drop_item->condition[i] = TRUE;
			drop_item->type[i] = 0;
			isCreated = TRUE;
		}

		// 캐논 수량 추가
		if (frame_time == 900 && drop_item->condition[i] == FALSE)
		{
			drop_item->pos_x[i] = 30;
			drop_item->pos_y[i] = 0;
			drop_item->condition[i] = TRUE;
			drop_item->type[i] = 1;
			isCreated = TRUE;
		}

		// 생명 추가
		if (frame_time == 1300 && drop_item->condition[i] == FALSE)
		{
			drop_item->pos_x[i] = 49;
			drop_item->pos_y[i] = 0;
			drop_item->condition[i] = TRUE;
			drop_item->type[i] = 2;
			isCreated = TRUE;
		}

		// 체력 회복
		if (frame_time == 1400 && drop_item->condition[i] == FALSE)
		{
			drop_item->pos_x[i] = 21;
			drop_item->pos_y[i] = 0;
			drop_item->condition[i] = TRUE;
			drop_item->type[i] = 3;
			isCreated = TRUE;
		}

		// 캐논 수량 추가
		if (frame_time == 2000 && drop_item->condition[i] == FALSE)
		{
			drop_item->pos_x[i] = 30;
			drop_item->pos_y[i] = 0;
			drop_item->condition[i] = TRUE;
			drop_item->type[i] = 1;
			isCreated = TRUE;
		}

		// 체력 회복 추가
		if (frame_time == 2050 && drop_item->condition[i] == FALSE)
		{
			drop_item->pos_x[i] = 11;
			drop_item->pos_y[i] = 0;
			drop_item->condition[i] = TRUE;
			drop_item->type[i] = 3;
			isCreated = TRUE;
		}

		// 캐논 업그레이드
		if (frame_time == 2300 && drop_item->condition[i] == FALSE)
		{
			drop_item->pos_x[i] = 41;
			drop_item->pos_y[i] = 0;
			drop_item->condition[i] = TRUE;
			drop_item->type[i] = 0;
			isCreated = TRUE;
		}

		// 캐논 수량 추가
		if (frame_time == 2600 && drop_item->condition[i] == FALSE)
		{
			drop_item->pos_x[i] = 28;
			drop_item->pos_y[i] = 0;
			drop_item->condition[i] = TRUE;
			drop_item->type[i] = 1;
			isCreated = TRUE;
		}

		// 체력 회복 추가
		if (frame_time == 2900 && drop_item->condition[i] == FALSE)
		{
			drop_item->pos_x[i] = 51;
			drop_item->pos_y[i] = 0;
			drop_item->condition[i] = TRUE;
			drop_item->type[i] = 3;
			isCreated = TRUE;
		}

		if (isCreated == TRUE)
		{
			gotoxy(drop_item->pos_x[i], drop_item->pos_y[i]);
			switch (drop_item->type[i])
			{
			case 0:
				printf("[P]");
				break;
			case 1:
				printf("[ⅲ]");
				break;
			case 2:
				printf("[♥]");
				break;
			case 3:
				printf("[★]");
				break;
			}
			break;
		}
	}
}	