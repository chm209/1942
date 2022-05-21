#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int login(int is_logined)
{
	system("cls");
	draw_content(0); // 도트 출력
	draw_content(1); // 1942 그림 출력
	
	// 로그인 성공 여부를 검사하기 위한 변수
	int is_checked = FALSE;

	// 성공할때까지 반복
	while (is_checked == FALSE)
	{
		switch (is_logined)
		{
		// 회원가입
		case FALSE:
			is_checked = login_db(0);
			if (is_checked != TRUE)
			{
				break;
			}
			// 로그인을 할때 게임에 필요한 유저 정보를 동기화 하기 때문에
			// 회원가입후 로그인하는 절차가 필요함
			is_logined = TRUE;
		case TRUE:
			is_checked = FALSE;
			is_checked = login_db(1);
			break;
		}
	}
	return 1;
}