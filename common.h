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
	char* id;
	int point;
	int score;
}User;

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

// db
void error(int);
int login_db(int);

enum ControlKey
{
	UP = 72, DOWN = 80, ENTER = 13, LEFT = 75, RIGHT = 77, BACKSPACE = 8, ESC = 27
};

extern char user_id[20];
extern int user_point;
extern int user_score;