#pragma once
#define TRUE 1
#define FALSE 0

void cursor(int);
void gotoxy(int, int);
int move(int, int, int, int);
void draw_content(int);
int menu(int);
int login(int);
void ranking(int);
void shop(void);
void game(void);
void set_color(unsigned short);
void shop_preview(int);

enum ControlKey
{
	UP = 72, DOWN = 80, ENTER = 13, LEFT = 75, RIGHT = 77, BACKSPACE = 8, ESC = 27
};