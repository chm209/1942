#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int login(int is_logined)
{
	system("cls");
	draw_content(0); // ��Ʈ ���
	draw_content(1); // 1942 �׸� ���
	
	// �α��� ���� ���θ� �˻��ϱ� ���� ����
	int is_checked = FALSE;

	// �����Ҷ����� �ݺ�
	while (is_checked == FALSE)
	{
		switch (is_logined)
		{
		// ȸ������
		case FALSE:
			is_checked = login_db(0);
			if (is_checked != TRUE)
			{
				break;
			}
			is_logined = TRUE;
		case TRUE:
			is_checked = FALSE;
			is_checked = login_db(1);
			break;
		}
	}
	return 1;
}