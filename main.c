#include <stdio.h>
#include <stdlib.h>
#include "common.h"

char user_id[20] = { 0 ,};
int user_point = 0;
int user_score = 0;

int main(void)
{
	// cmd ����
	system("mode con: cols=100 lines=30");
	system("title 1942 ������Ʈ - 1705095 ��â��");
	cursor(0); // 0: Ŀ�� ����, 1: Ŀ�� ���̱�
	
	// main������ ����ϴ� ����
	int is_logined = FALSE;
	int choose_menu = 19;
	User *user = { 0, };

	// ������ �������Ḧ �����Ҷ����� ���ѹݺ�
	while (choose_menu != 24)
	{
		system("cls");
		draw_content(0); // ��Ʈ ���
		draw_content(1); // 1942 �׸� ���
		draw_content(2); // ����Ű ���� ������, �ؽ�Ʈ ���

		// draw_content(3) = ��α��� / draw_content(4) = �α���
		is_logined % 2 == 1 ? draw_content(4) : draw_content(3);
		choose_menu = menu(choose_menu);

		if (choose_menu == 19)
		{
			is_logined % 2 == 0 ? is_logined = login(1) : game();
			system("mode con: cols=100 lines=30");
		}
		else if (choose_menu == 21)
		{
			is_logined % 2 == 0 ? is_logined = login(0) : shop();
		}
		else if (choose_menu == 23)
		{
			is_logined % 2 == 0 ? ranking(0) : ranking(1);
		}
		else
		{
			break;
		}
		choose_menu = 19;
	}
	return 0;
}