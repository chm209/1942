#include <stdio.h>
#include <stdlib.h>  
#include "common.h"

void ranking(int is_logined)
{
	system("cls");
	int key = 0;

	switch (is_logined)
	{
	// 비로그인
	case FALSE:
		draw_content(6);
		draw_content(7);
		ranking_db(0);
		while (key != ESC)
		{
			key = getch();
		}
		break;
	// 로그인
	case TRUE:
		draw_content(8);
		draw_content(9);
		ranking_db(1);
		while (key != ESC)
		{
			key = getch();
		}
		break;
	}
}