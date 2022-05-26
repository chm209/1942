#pragma once
// bool 타입 흉내
#define TRUE 1
#define SUCCESS 1
#define FALSE 0
#define FAIL 0
// set_color() 관련
#define WHITE 15
#define RED 12
#define YELLOW 14
#define BLUE 9
// 키보드 처리 관련
#define UP 72
#define DOWN 80
#define ENTER 13
#define LEFT 75
#define RIGHT 77
#define BACKSPACE 8
#define ESC 27

// 구조체 - 로그인 시점부터 프로그램을 종료할때까지 끝까지 살아있는 구조체
typedef struct User
{
	char id[20];
	int point;
	int score;
	int item[10];
}USER;

// 함수 원형
// 공통 기능 관련
void cursor(int);
void gotoxy(int, int);
void set_color(unsigned short);
int move(int, int, int, int);
// 각각의 화면
void game(void);
void shop(void);
void ranking(int);
int menu(int);
int login(int);
// UI 출력
void draw_content(int);
void shop_preview(int);
void draw_owned_item(void);
void draw_error(int);
// DB 관련
void shop_db(void);
int login_db(int);
void ranking_db(int);

// 전역 변수
extern USER user;