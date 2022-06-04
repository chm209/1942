#pragma once
// 키보드 입력 관련
#define LEFT_LIMIT 5
#define RIGHT_LIMIT 51
#define UP_LIMIT 14 // 기본 14, 시연 4
#define DOWN_LIMIT 29

// 공통
#define LEVEL0 0
#define LEVEL1 1
#define LEVEL2 2

// 플레이어 전투기 관련
#define COMBAT1 "[-*-]"
#define COMBAT2 "<-*->"
#define COMBAT3 "{:*:}"
#define COMBAT4 "H:*:H"

// 플레이어 캐논 관련
#define CANNON1 "ⅰ"
#define CANNON2 "γ"
#define CANNON3 "＋"
#define CANNON4 "★"
#define CANNON5 "ⅱ"
#define CANNON6 "ψ"
#define CANNON7 "±"
#define CANNON8 "♠"
#define CANNON9 "ⅲ"
#define CANNON10 "Ψ"
#define CANNON11 "÷"
#define CANNON12 "♣"

// 구조체 변수 관련
#define CANNON_SIZE 4
#define BOMB_SIZE 2
#define BOMB_CANNON_SIZE 5
#define ITEM_SIZE 5
#define ENEMY_SIZE 30
#define ENEMY_CANNON_SIZE 10

// 플레이어 관련 구조체
typedef struct Player
{
	int pos_x;
	int pos_y;
	int life;
	int hp;
	int bomb_quantity;
	int cannon_limit;
	int score;
} PLAYER;

typedef struct Cannon
{
	int pos_x[CANNON_SIZE];
	int pos_y[CANNON_SIZE];
	int condition[CANNON_SIZE];
	int upgrade;
} CANNON;

typedef struct Bomb
{
	int pos_x[BOMB_SIZE];
	int pos_y[BOMB_SIZE];
	int condition[BOMB_SIZE];
	int move_interval[BOMB_SIZE];
	struct BombCannon* bomb_cannon[BOMB_SIZE];
} BOMB;

typedef struct BombCannon
{
	int pos_x[BOMB_CANNON_SIZE];
	int pos_y[BOMB_CANNON_SIZE];
	int condition[BOMB_CANNON_SIZE];
} BOMB_CANNON;

typedef struct DropItem
{
	int pos_x[ITEM_SIZE];
	int pos_y[ITEM_SIZE];
	int condition[ITEM_SIZE];
	int type[ITEM_SIZE];
	int move_interval[ITEM_SIZE];
} DROP_ITEM;

typedef struct ShopItem
{
	int life_plus;
	int hp_recover;
	int score_buff;
	int buff_on;
	int cooldown_time;
	int combat_color;
	char* combat_design;
	int cannon_color;
	char* cannon_design;
} SHOP_ITEM;

// 적군 관련 구조체
typedef struct Enemy
{
	int pos_x[ENEMY_SIZE];
	int pos_y[ENEMY_SIZE];
	int condition[ENEMY_SIZE];
	int design[ENEMY_SIZE];
	int pattern[ENEMY_SIZE];
	int move_count[ENEMY_SIZE];
	int move_interval[ENEMY_SIZE];
	int hp[ENEMY_SIZE];
	struct EnemyCannon* enemy_cannon[ENEMY_SIZE];
} ENEMY;

typedef struct EnemyCannon
{
	int pos_x[ENEMY_CANNON_SIZE];
	int pos_y[ENEMY_CANNON_SIZE];
	int condition[ENEMY_CANNON_SIZE];
	int move_interval;
	int move_pattern[ENEMY_CANNON_SIZE];
} ENEMY_CANNON;

// 초기설정, DB 불러오기 저장하기
void init_variables(PLAYER*, CANNON*, BOMB*, DROP_ITEM*, SHOP_ITEM*, ENEMY*);
void load_data(SHOP_ITEM*);
void save_data(PLAYER*, SHOP_ITEM*);

// UI 출력
void draw_status(PLAYER*, SHOP_ITEM*);
void draw_game(int);
void draw_symbol(int, int, int);
void draw_bomb(int, int, int);
void draw_end_game(PLAYER*, SHOP_ITEM*);
void draw_help(void);

// 캐논 관련
void cannon_move(CANNON*, SHOP_ITEM*);
void cannon_status(CANNON*);

// 폭탄 관련
void bomb_move(BOMB*);
void bomb_status(BOMB*, ENEMY*, PLAYER*, SHOP_ITEM* , int);
void bCannon_status(BOMB*, int);
void bCannon_move(BOMB*);

// 드랍 아이템 관련
void item_gen(DROP_ITEM*, int);
void item_move(DROP_ITEM*);
void item_status(DROP_ITEM*, PLAYER*, CANNON*, SHOP_ITEM*, int);

// 적군 관련
void enemy_gen(ENEMY*, int);
void enemy_move(ENEMY*);
void enemy_status(ENEMY*, BOMB*, PLAYER*, CANNON*, SHOP_ITEM*, int);
void eCannon_status(ENEMY*, PLAYER*, BOMB*, CANNON*, int);
void eCannon_move(ENEMY*);