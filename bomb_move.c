#include <stdio.h>
#include "common.h"
#include "game.h"

void bomb_move(BOMB* bomb)
{
	int POS_X = bomb->pos_x[0];
	int POS_Y = bomb->pos_y[0];

	// ��ź 0���� TRUE �������� �ѹ� �� �˻��ϴ� ������
	// ��ź 1���� 0������ ������ ������ ������
	// �ѹ� �� �˻����� ������ ��ź 1���� ������ ��������
	// �ϴܿ� ��ź 0���� ���������� ����
	if (bomb->condition[0] == TRUE)
	{
		// ��ź 0�� ������ �����϶�
		if ((POS_Y >= 13 && POS_Y <= 18) && bomb->move_interval[0] < 1)
		{
			draw_bomb(0, POS_X, POS_Y);
			bomb->pos_y[0]--;
			POS_Y = bomb->pos_y[0];
			draw_bomb(1, POS_X, POS_Y);
			bomb->move_interval[0] = 20;
		}

		// ��ź 0�� ������ �����϶�
		if (POS_Y > 18 || POS_Y < 13)
		{
			draw_bomb(0, POS_X, POS_Y);
			bomb->pos_y[0]--;
			POS_Y = bomb->pos_y[0];
			draw_bomb(1, POS_X, POS_Y);
		}
	}

	// ��ź 0���� Ư�� ��ġ���� ������ ��ź 1�� �̵�
	if (POS_Y < 18 || (bomb->condition[0] == FALSE && bomb->condition[1] == TRUE))
	{
		POS_X = bomb->pos_x[1];
		POS_Y = bomb->pos_y[1];

		// õõ��
		if ((POS_Y >= 14 && POS_Y <= 19) && bomb->move_interval[1] < 1)
		{
			draw_bomb(0, POS_X, POS_Y);
			bomb->pos_y[1]--;
			POS_Y = bomb->pos_y[1];
			draw_bomb(1, POS_X, POS_Y);
			bomb->move_interval[1] = 20;
		}
		//����
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