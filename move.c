#include <stdio.h>
#include "common.h"

// ȭ�� ��ȣ, ����ڰ� �Է��� ��, X��ǥ, Y��ǥ
int move(int screen_num, int key, int POS_X, int POS_Y)
{
	switch (screen_num)
	{
	// ����ȭ��, �� �Ʒ� ���۸� ����
	case 0:
		switch (key)
		{
		case UP:
			POS_Y = (POS_Y <= 19) ? 19 : POS_Y - 2;
			break;
		case DOWN:
			POS_Y = (POS_Y >= 25) ? 25 : POS_Y + 2;
			break;
		}
		return POS_Y;
	// PAUSE â, �� �� ���۸� ����
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
	// ���� ȭ��, �� �Ʒ� ���۸� ����
	case 2:
		switch (key)
		{
		case UP:
			POS_Y = (POS_Y <= 4) ? 4 : POS_Y - 2;
			break;
		case DOWN:
			POS_Y = (POS_Y >= 22) ? 22 : POS_Y + 2;
			break;
		}
		return POS_Y;
	}
}