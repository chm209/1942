#include <stdio.h>
#include "common.h"

// 화면 번호, 사용자가 입력한 값, X좌표, Y좌표
int move(int scr_num, int key, int pos_x, int pos_y)
{
	switch (scr_num)
	{
	// 메인화면, 위 아래 동작만 있음
	case 0:
		switch (key)
		{
		case UP:
			pos_y = (pos_y <= 18) ? 18 : pos_y - 2;
			break;
		case DOWN:
			pos_y = (pos_y >= 24) ? 24 : pos_y + 2;
			break;
		}
		break;
	}
	return pos_y;
}