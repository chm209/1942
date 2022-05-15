#pragma once
#define TRUE 1
#define FALSE 0
#define FAIL 0
#define SUCCESS 1
#define RED 12
#define WHITE 15
#define YWLLOW 14
#define BLUE 9

// юс╫ц
typedef struct _User
{
	char id[20];
	int point;
	int score;
}User;

typedef struct _Item_list
{
	int item1;
	int item2;
	int item3;
	int item4;
	int item5;
	int item6;
	int item7;
	int item8;
	int item9;
	int item10;
}Item_list;

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
void possession_item(void);
void shop_db(void);

// db
void error(int);
int login_db(int);

enum ControlKey
{
	UP = 72, DOWN = 80, ENTER = 13, LEFT = 75, RIGHT = 77, BACKSPACE = 8, ESC = 27
};

extern Item_list item_list;
extern User user;