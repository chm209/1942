#include <stdio.h>
#include "common.h"

// ȭ�� ��ȣ, ����ڰ� �Է��� ��, X��ǥ, Y��ǥ
int move(int scr_num, int key, int pos_x, int pos_y)
{
	switch (scr_num)
	{
	// ����ȭ��, �� �Ʒ� ���۸� ����
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