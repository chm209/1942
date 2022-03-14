#define TRUE 1
#define FALSE 0
#define STAT_SIZE 4
#define BULLET_SIZE 6
#define BOMB_SIZE 2
#define BOMB_BUL_SIZE 5
#define LEFT_LIMIT 
#define RIGHT_LIMIT 
#define UP_LIMIT 
#define DOWN_LIMIT 

void drawStat(int*);

typedef struct _PLAYER
{
	int pos_x;
	int pos_y;
} PLAYER;

typedef struct _BULLET
{
	int pos_x;
	int pos_y;
	int con;
} BULLET;

typedef struct _BOMB
{
	int count;
	int pos_x;
	int pos_y;
	int con;
	int speed;
} BOMB;

typedef struct _BOMB_BULLET
{
	int pos_x;
	int pos_y;
	int con;
} BOMB_BULLET;