#include <stdio.h>
#include "common.h"

// 화면 번호, 사용자가 입력한 값, X좌표, Y좌표
int move(int screen_num, int key, int POS_X, int POS_Y)
{
	switch (screen_num)
	{
	// 메인화면, 위 아래 동작만 있음
	case 0:
		switch (key)
		{
		case UP:
			POS_Y = (POS_Y <= 18) ? 18 : POS_Y - 2;
			break;
		case DOWN:
			POS_Y = (POS_Y >= 24) ? 24 : POS_Y + 2;
			break;
		}
		return POS_Y;
	// PAUSE 창
	case 1:
		switch (key)
		{
		case LEFT:
			POS_X = (POS_X > 23) ? 23 : POS_X;
			break;
		case RIGHT:
			POS_X = (POS_X < 39) ? 39 : POS_X;
			break;
		}
		return POS_X;
	}
}