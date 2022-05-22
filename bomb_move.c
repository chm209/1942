#include <stdio.h>
#include "common.h"
#include "game.h"

void bomb_move(BOMB* bomb)
{
	int POS_X = bomb->pos_x[0];
	int POS_Y = bomb->pos_y[0];

	// 폭탄 0번이 TRUE 상태인지 한번 더 검사하는 이유는
	// 폭탄 1번이 0번보다 느리게 끝나기 때문에
	// 한번 더 검사하지 않으면 폭탄 1번이 끝나는 시점에서
	// 하단에 폭탄 0번이 찍혀버리기 때문
	if (bomb->condition[0] == TRUE)
	{
		// 폭탄 0번 느리게 움직일때
		if ((POS_Y >= 13 && POS_Y <= 18) && bomb->move_interval[0] < 1)
		{
			draw_bomb(0, POS_X, POS_Y);
			bomb->pos_y[0]--;
			POS_Y = bomb->pos_y[0];
			draw_bomb(1, POS_X, POS_Y);
			bomb->move_interval[0] = 20;
		}

		// 폭탄 0번 빠르게 움직일때
		if (POS_Y > 18 || POS_Y < 13)
		{
			draw_bomb(0, POS_X, POS_Y);
			bomb->pos_y[0]--;
			POS_Y = bomb->pos_y[0];
			draw_bomb(1, POS_X, POS_Y);
		}
	}

	// 폭탄 0번이 특정 위치까지 갔을때 폭탄 1번 이동
	if (POS_Y < 18 || (bomb->condition[0] == FALSE && bomb->condition[1] == TRUE))
	{
		POS_X = bomb->pos_x[1];
		POS_Y = bomb->pos_y[1];

		// 천천히
		if ((POS_Y >= 14 && POS_Y <= 19) && bomb->move_interval[1] < 1)
		{
			draw_bomb(0, POS_X, POS_Y);
			bomb->pos_y[1]--;
			POS_Y = bomb->pos_y[1];
			draw_bomb(1, POS_X, POS_Y);
			bomb->move_interval[1] = 20;
		}
		//빨리
		if (POS_Y > 19 || POS_Y < 14)
		{
			draw_bomb(0, POS_X, POS_Y);
			bomb->pos_y[1]--;
			POS_Y = bomb->pos_y[1];
			draw_bomb(1, POS_X, POS_Y);
		}
		bomb->move_interval[1]--;
	}
	bomb->move_interval[0]--;
}