void cursor(int);
void gotoxy(int, int);
int action(int, int, int, int);
void draw_content(int);
int login(int);
void ranking(void);
void shop(void);
void game(void);

enum ControlKey
{
	UP = 72, DOWN = 80, ENTER = 13, LEFT = 75, RIGHT = 77, BACKSPACE = 8
};