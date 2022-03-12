#include <stdio.h>
#include "common.h"

int action(int screen_number, int key, int position_x, int position_y)
{
	switch (screen_number)
	{
	// 메인화면, 위 아래 동작만 있음
	case 0:
		switch (key)
		{
		case UP:
			position_y = (position_y <= 18) ? 18 : position_y - 2;
			break;
		case DOWN:
			position_y = (position_y >= 24) ? 24 : position_y + 2;
			break;
		}
		break;
	case 1:
		switch (key)
		{
		case UP:
			position_y = (position_y <= 12) ? 12 : position_y - 2;
			break;
		case DOWN:
			position_y = (position_y >= 16) ? 16 : position_y + 2;
			break;
		}
		break;
	case 2:
		switch (key)
		{
		case UP:
			position_y = (position_y <= 18) ? 18 : position_y - 2;
			break;
		case DOWN:
			position_y = (position_y >= 26) ? 26 : position_y + 2;
			break;
		}
		break;
	}
	return position_y;
}