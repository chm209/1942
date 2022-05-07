#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int login(int is_logined)
{
	system("cls");
	draw_content(0); // 도트 출력
	draw_content(1); // 1942 그림 출력

	// 로그인 정보 저장을 위한 변수
	// * DB 연동 작업후 로그인을 위한 구조체에다가 저장하도록 구조 변경
	char* user_id = malloc(sizeof(char) * 20);
	char* user_password = malloc(sizeof(char) * 20);

	// 회원가입
	// 회원가입후 로그인 과정을 위해 if문 분리
	// 입력받은 값으로 DB에서 중복 확인 과정 필요함
	// 코드 대거 수정 & 로그인 과정을 위한 함수 분리 예상
	// 통과하면 DB에 저장
	if (is_logined == FALSE)
	{
		draw_content(5);
		gotoxy(39, 18);
		printf("회원가입");
		gotoxy(39, 20);
		printf("20자 이내에 입력하십시오");
		gotoxy(39, 22);
		printf("아이디: ");
		scanf("%s", user_id);
		gotoxy(39, 24);
		printf("비밀번호: ");
		scanf("%s", user_password);
		cursor(0);
		is_logined = TRUE;
	}

	// 로그인
	if (is_logined == TRUE)
	{
		draw_content(5);
		gotoxy(39, 18);
		printf("로그인");
		gotoxy(39, 20);
		printf("아이디: ");
		scanf("%s", user_id);
		gotoxy(39, 22);
		printf("비밀번호: ");
		scanf("%s", user_password);
		cursor(0);
		// DB에서 아이디, 비밀번호 조회 필요
	}

	free(user_id);
	free(user_password);
	return 1;
}