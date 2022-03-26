#pragma once
#define TRUE 1
#define FALSE 0
#define STAT 4
#define BULLET_SIZE 4
#define BOMB_SIZE 2
#define BOMB_BUL_SIZE 5
#define ITEM_SIZE 5
#define ENEMY_SIZE 30
#define ENEMY_BUL_SIZE 10

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
	int type;
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

typedef struct _ITEM
{
	int pos_x;
	int pos_y;
	int con;
	int type;
	int speed;
} Item;

// 적군 관련

typedef struct _ENEMY
{
	int pos_x;
	int pos_y;
	int type;
	int move_pattern;
	int move_count;
	int speed;
	int health;
	int con;
	int bullet[10];
	int bul_pos_x[10];
	int bul_pos_y[10];
	int bul_con[10];
	int bul_speed;
} Enemy;

void drawSymbol(int, int, int);
void drawStat(Player, Bomb*);
void itemGen(Item*, int);
void itemMove(Item*);
void itemStatus(Item*, Player, Bullet*, int);
void enemyGen(Enemy*, int);
void enemyMove(Enemy*);
void enemyBul(Enemy*, int);
Player enmBulStatus(Enemy*, Player, Bomb*, Bullet*, int);
void bombMove(Bomb*);
void bulletMove(Bullet*);
void bombBul(Bomb*, Bomb_blt*, Bomb_blt*, int);