#define TRUE 1
#define FALSE 0
#define STAT_SIZE 4
#define BULLET_SIZE 6
#define BOMB_SIZE 2
#define BOMB_BUL_SIZE 5
#define ENEMY_SIZE 30
#define LEFT_LIMIT 
#define RIGHT_LIMIT 
#define UP_LIMIT 
#define DOWN_LIMIT 

void drawStat(int*);

typedef struct _ENEMY
{
	int pos_x;
	int pos_y;
	int type;
	int move_pattern;
	int move_count;
	int con;
	int speed;
} ENEMY;

typedef struct _SKILL
{
	int life_plus;
	int invincible;
	int life_count;
	int invin_count;
} SKILL;

typedef struct _PLAYER
{
	int pos_x;
	int pos_y;
	int life;
	int health;
	int score;
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