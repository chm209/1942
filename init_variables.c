#include <stdio.h>
#include "game.h"
#include "common.h"

void init_variables(PLAYER* player, CANNON* cannon, BOMB* bomb, DROP_ITEM* drop_item, SHOP_ITEM* shop_item, ENEMY* enemy)
{
	// player 구조체 초기화
	// 좌표 X, Y 값, 생명, 체력, 폭탄 잔량, 캐논 발사 가능 잔량, 점수
	player->pos_x = 28;
	player->pos_y = 28;
	player->life = 1;
	player->hp = 3;
	player->bomb_quantity = 1;
	player->cannon_limit = 2;
	player->score = 0;

	// cannon 구조체 초기화
	// 좌표 X, Y 값, 각각의 발사 확인용, 캐논 레벨 확인
	for (int i = 0; i < CANNON_SIZE; i++)
	{
		cannon->pos_x[i] = 0;
		cannon->pos_y[i] = 0;
		cannon->condition[i] = FALSE;
	}
	cannon->upgrade = LEVEL0;

	// bomb 구조체 초기화
	// 좌표 X, Y 값, 발사 확인용, 이동 속도 조절용
	bomb->pos_x[0] = 29;
	bomb->pos_y[0] = 24;
	bomb->condition[0] = FALSE;
	bomb->move_interval[0] = 5;
	bomb->pos_x[1] = 6;
	bomb->pos_y[1] = 24;
	bomb->condition[1] = FALSE;
	bomb->move_interval[1] = 5;

	// bomb -> bomb_cannon 구조체 초기화
	// 좌표 X, Y 값, 발사 확인용
	for (int i = 0; i < BOMB_CANNON_SIZE; i++)
	{
		bomb->bomb_cannon[0]->pos_x[i] = 0;
		bomb->bomb_cannon[0]->pos_y[i] = 0;
		bomb->bomb_cannon[0]->condition[i] = FALSE;
		bomb->bomb_cannon[1]->pos_x[i] = 0;
		bomb->bomb_cannon[1]->pos_y[i] = 0;
		bomb->bomb_cannon[1]->condition[i] = FALSE;
	}

	// drop_item 구조체 초기화
	// 좌표 X, Y 값, 발사 확인용, 아이템 종류, 움직임 속도 조절용
	for (int i = 0; i < ITEM_SIZE; i++)
	{
		drop_item->pos_x[i] = 0;
		drop_item->pos_y[i] = 0;
		drop_item->condition[i] = FALSE;
		drop_item->type[i] = 0;
		drop_item->move_interval[i] = 0;
	}

	// shop_item 구조체 초기화
	// 생명, 체력, 추가점수, 스킬 재사용 시간, 전투기 색상, 캐논 색상
	shop_item->life_plus = 0;
	shop_item->hp_recover = 0;
	shop_item->score_buff = 0;
	shop_item->score_buff = FALSE;
	shop_item->cooldown_time = 0;
	shop_item->combat_color = WHITE;
	shop_item->combat_design = COMBAT1;
	shop_item->cannon_color = WHITE;
	shop_item->cannon_design = CANNON1;

	// enemy 구조체 초기화
	// 좌표 X, Y 값, 발사 확인용, 움직임 & 공격 패턴, 움직임 방향 전환용, 움직임 속도 조절용, 적군 체력
	for (int i = 0; i < ENEMY_SIZE; i++)
	{
		enemy->pos_x[i] = 0;
		enemy->pos_y[i] = 0;
		enemy->condition[i] = FALSE;
		enemy->design[i] = 0;
		enemy->pattern[i] = 0;
		enemy->move_count[i] = 0;
		enemy->move_interval[i] = 0;
		enemy->hp[i] = 0;
		
		// enemy -> enemy_cannon 구조체 초기화
		// 좌표 X, Y 값, 발사 확인용, 움직임 속도 조절용
		for (int j = 0; j < ENEMY_CANNON_SIZE; j++)
		{
			enemy->enemy_cannon[i]->pos_x[i] = 0;
			enemy->enemy_cannon[i]->pos_y[i] = 0;
			enemy->enemy_cannon[i]->condition[i] = 0;
		}
		enemy->enemy_cannon[i]->move_interval = 0;
	}
}