#pragma once
#define TRUE 1
#define FALSE 0
#define STAT 4
#define BULLET_SIZE 4
#define BOMB_SIZE 2
#define BOMB_BUL_SIZE 5
#define ENEMY_SIZE 30
#define LEFT_LIMIT 
#define RIGHT_LIMIT 
#define UP_LIMIT 
#define DOWN_LIMIT 

// 플레이어 관련
typedef struct _PLAYER
{
	int pos_x;
	int pos_y;
	int life;
	int health;
	int score;
} Player;

typedef struct _BULLET
{
	int pos_x;
	int pos_y;
	int con;
} Bullet;

typedef struct _SKILL
{
	int life_plus;
	int invincible;
	int life_count;
	int invin_count;
} Skill;

typedef struct _BOMB
{
	int pos_x;
	int pos_y;
	int count;
	int speed;
	int con;
} Bomb;

typedef struct _BOMB_BULLET
{
	int pos_x;
	int pos_y;
	int con;
} Bomb_blt;

// 적군 관련

typedef struct _ENEMY
{
	int pos_x;
	int pos_y;
	int type;
	int move_pattern;
	int move_count;
	int speed;
	int con;
} Enemy;

void drawStat(int*);
void enemyGen(Enemy*, int);
void enemyMove(Enemy*);
void bombMove(Bomb*);
void bulletMove(Bullet*);
void bombBul(Bomb*, Bomb_blt*, Bomb_blt*, int);