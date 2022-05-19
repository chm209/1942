#include <stdio.h>
#include "common.h"
#include "game.h"

void set_player(Player* player, Bullet* bullet, Shop shop)
{
	// 플레이어 비행기 설정
	switch (shop.paint_color)
	{
	case 0:
		player->shape = "[-*-]";
		player->color = 15;
		break;
	case 1:
		player->shape = "<-*->";
		player->color = 12;
		break;
	case 2:
		player->shape = "{:*:}";
		player->color = 9;
		break;
	case 3:
		player->shape = "H:*:H";
		player->color = 14;
		break;
	}

	// 플레이어 총알 설정
	switch (shop.bullet_color)
	{
	case 0:
		bullet->shape = "ⅰ";
		bullet->color = 15;
		break;
	case 1:
		bullet->shape = "γ";
		bullet->color = 12;
		break;
	case 2:
		bullet->shape = "＋";
		bullet->color = 9;
		break;
	case 3:
		bullet->shape = "★";
		bullet->color = 14;
		break;
	}
}