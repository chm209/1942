#pragma once
// 키보드 입력 관련
#define LEFT_LIMIT 5
#define RIGHT_LIMIT 51
#define UP_LIMIT 4
#define DOWN_LIMIT 29

// 게임 동작 관련
#define STAT 4
#define BULLET_SIZE 4
#define BOMB_SIZE 2
#define BOMB_BUL_SIZE 5
#define ITEM_SIZE 5
#define ENEMY_SIZE 30
#define ENEMY_BUL_SIZE 10

// 플레이어 관련
typedef struct _Player
{
	int pos_x;
	int pos_y;
	int life;
	int health;
	int quantity;
	int score;
	char* shape;
	int color;
} Player;

typedef struct _Bullet
{
	int pos_x;
	int pos_y;
	int con;
	int type;
	char* shape;
	int color;
} Bullet;

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

typedef struct _SHOP
{
	int life_plus;
	int hp_plus;
	int add_point;
	int cool_time;
	int paint_color;
	int bullet_color;
} Shop;

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
	int bul_pos_x[10];
	int bul_pos_y[10];
	int bul_con[10];
	int bul_speed;
} Enemy;

typedef struct _ENEMY_BULLET
{
	int pos_x[10];
	int pos_y[10];
	int con[10];
	int speed;
} Enemy_bul;


void draw_game(int);
void draw_symbol(int, int, int);
void draw_status(Player, Bomb*, Shop);
void item_gen(Item*, int);
void item_move(Item*);
Player item_status(Item*, Player, Bullet*, Shop, int);
void enemy_gen(Enemy*, int);
void enemy_move(Enemy*);
Player enm_status(Enemy*, Bomb*, Bomb_blt*, Bomb_blt*, Player, Bullet*, int);
void enm_bull_move(Enemy*);
Player enm_bull_status(Enemy*, Player, Bomb*, Bullet*, int);
void bomb_move(Bomb*);
void bullet_status(Bullet*);
void bullet_move(Bullet*);
void bomb_bull_move(Bomb*, Bomb_blt*, Bomb_blt*);
void bomb_status(Bomb*, Enemy*, Player, int);
void bomb_bull_status(Bomb*, Bomb_blt*, Bomb_blt*, int);
Player set_player(Player, Bullet*, Shop);