#pragma once
// bool Ÿ�� �䳻
#define TRUE 1
#define SUCCESS 1
#define FALSE 0
#define FAIL 0
// set_color() ����
#define WHITE 15
#define RED 12
#define YELLOW 14
#define BLUE 9
// Ű���� ó�� ����
#define UP 72
#define DOWN 80
#define ENTER 13
#define LEFT 75
#define RIGHT 77
#define BACKSPACE 8
#define ESC 27

// ����ü - �α��� �������� ���α׷��� �����Ҷ����� ������ ����ִ� ����ü
typedef struct User
{
	char id[20];
	int point;
	int score;
	int item[10];
}USER;

// �Լ� ����
// ���� ��� ����
void cursor(int);
void gotoxy(int, int);
void set_color(unsigned short);
int move(int, int, int, int);
// ������ ȭ��
void game(void);
void shop(void);
void ranking(int);
int menu(int);
int login(int);
// UI ���
void draw_content(int);
void shop_preview(int);
void draw_owned_item(void);
void draw_error(int);
// DB ����
void shop_db(void);
int login_db(int);
void ranking_db(int);

// ���� ����
extern USER user;