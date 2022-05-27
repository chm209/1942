#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // GetAsyncKeyState 사용을 위함
#include "common.h"
#include "game.h"

void game(void)
{
	system("mode con: cols=80 lines=30");
	system("cls");

	// 게임 시간 변수
	int frame_time = 750;
	int pause_flag = FALSE;

	// 구조체 변수
	PLAYER* player = malloc(sizeof(PLAYER));
	CANNON* cannon = malloc(sizeof(CANNON));
	BOMB* bomb = malloc(sizeof(BOMB));
	bomb->bomb_cannon[0] = malloc(sizeof(BOMB_CANNON));
	bomb->bomb_cannon[1] = malloc(sizeof(BOMB_CANNON));
	DROP_ITEM* drop_item = malloc(sizeof(DROP_ITEM));
	SHOP_ITEM* shop_item = malloc(sizeof(SHOP_ITEM));
	ENEMY* enemy = malloc(sizeof(ENEMY));
	for (int i = 0; i < ENEMY_SIZE; i++)
	{
		enemy->enemy_cannon[i] = malloc(sizeof(ENEMY));
	}

	// 구조체 변수 초기화
	init_variables(player, cannon, bomb, drop_item, shop_item, enemy);

	// DB에서 데이터를 읽어 초기 정보 세팅
	load_data(shop_item);

	// 자동적용
	if (shop_item->score_buff > 0)
	{
		shop_item->score_buff--;
		shop_item->buff_on = TRUE;
	}

	while (1)
	{
		gotoxy(0, 0);
		printf("%d", frame_time);

		draw_game(0); // 게임 UI 출력
		draw_status(player, shop_item); // 스탯 출력
		// 전투기 출력
		{
			gotoxy(player->pos_x, player->pos_y);
			set_color(shop_item->combat_color);
			printf(shop_item->combat_design);
			set_color(WHITE);
		}

		// 키보드 입력 감지
		// 함수화, getch()로 감지 등등 전부 반응속도가 떨어지고 툭툭 끊김
		{
			// 왼쪽 이동
			if ((GetAsyncKeyState(VK_LEFT) & 0x8000) && player->pos_x > LEFT_LIMIT)
			{
				gotoxy(player->pos_x, player->pos_y);
				printf("     ");
				player->pos_x--;
				gotoxy(player->pos_x, player->pos_y);
				set_color(shop_item->combat_color);
				printf(shop_item->combat_design);
				set_color(WHITE);
			}

			// 오른쪽 이동
			if ((GetAsyncKeyState(VK_RIGHT) & 0x8000) && player->pos_x < RIGHT_LIMIT)
			{
				gotoxy(player->pos_x, player->pos_y);
				printf("     ");
				player->pos_x++;
				gotoxy(player->pos_x, player->pos_y);
				set_color(shop_item->combat_color);
				printf(shop_item->combat_design);
				set_color(WHITE);
			}

			// 위로 이동
			if ((GetAsyncKeyState(VK_UP) & 0x8000) && player->pos_y > UP_LIMIT)
			{
				gotoxy(player->pos_x, player->pos_y);
				printf("     ");
				player->pos_y--;
				gotoxy(player->pos_x, player->pos_y);
				set_color(shop_item->combat_color);
				printf(shop_item->combat_design);
				set_color(WHITE);
			}

			// 아래로 이동
			if ((GetAsyncKeyState(VK_DOWN) & 0x8000) && player->pos_y < DOWN_LIMIT)
			{
				gotoxy(player->pos_x, player->pos_y);
				printf("     ");
				player->pos_y++;
				gotoxy(player->pos_x, player->pos_y);
				set_color(shop_item->combat_color);
				printf(shop_item->combat_design);
				set_color(WHITE);
			}
		}

		// 게임 일시 정지
		// 게임 시작전 눌린 키를 가려내기 위해 frame_time을 검사
		// https://genesis8.tistory.com/138 관련글
		if ((GetAsyncKeyState(VK_ESCAPE) & 0x0001) && frame_time > 0)
		{
			int key = 0;
			int do_exit = 23;

			while (key != ENTER)
			{
				// PAUSE 화면 출력
				draw_game(1);
				gotoxy(do_exit, 14);
				printf("◎");
				key = getch();
				gotoxy(do_exit, 14);
				printf("  ");
				do_exit = move(1, key, do_exit, 14);
			}
			// 네 선택
			if (do_exit == 23) // 네
			{
				system("cls");
				draw_end_game(player, shop_item);
				save_data(player, shop_item);
				free(player);
				free(cannon);
				free(bomb->bomb_cannon[0]);
				free(bomb->bomb_cannon[1]);
				free(bomb);
				free(drop_item);
				free(shop_item);
				for (int i = 0; i < ENEMY_SIZE; i++)
				{
					free(enemy->enemy_cannon[i]);
				}
				free(enemy);
				break;
			}
			// 아니요 선택
			else
			{
				system("cls");
				continue;
			}
		}

		// 플레이어 공격 - 스페이스바
		if ((GetAsyncKeyState(VK_SPACE) & 0x8000) && frame_time > 0)
		{
			for (int i = 0; i < player->cannon_limit; i++)
			{
				if (cannon->condition[i] == FALSE)
				{
					cannon->pos_x[i] = player->pos_x + 1;
					cannon->pos_y[i] = player->pos_y - 1;
					cannon->condition[i] = TRUE;
					break;
				}
			}
		}

		// 폭탄 공격 - Z키
		if ((GetAsyncKeyState(0x5A) & 0x0001) && frame_time > 0)
		{
			if (player->bomb_quantity > 0 && (bomb->condition[0] == FALSE && bomb->condition[1] == FALSE))
			{
				player->bomb_quantity--;
				bomb->condition[0] = TRUE;
				bomb->condition[1] = TRUE;
			}
		}

		// 생명 추가 - X키
		if (((GetAsyncKeyState(0x58) & 0x0001) && frame_time > 1) && (shop_item->cooldown_time == 0 && shop_item->life_plus > 0))
		{
			player->life++;
			player->score -= 50;
			shop_item->life_plus--;
			shop_item->cooldown_time = 1000;

			if (player->bomb_quantity > 0)
			{
				bomb->condition[0] = TRUE;
				bomb->condition[1] = TRUE; 
			}
			else
			{
				player->bomb_quantity++;
			}
		}

		// 체력 회복 - C키
		if (((GetAsyncKeyState(0x43) & 0x0001) && frame_time > 1) && (shop_item->hp_recover > 0 && player->hp < 3))
		{
			shop_item->hp_recover--;
			player->hp++;
			player->score -= 10;
		}

		// 적군 생성
		enemy_gen(enemy, frame_time);

		// 아이템 생성
		item_gen(drop_item, frame_time);

		// 적군 이동
		enemy_move(enemy);

		// 폭탄 이동
		if (bomb->condition[0] == TRUE || bomb->condition[1] == TRUE)
		{
			bomb_move(bomb);
		}

		// 총알 이동
		cannon_move(cannon, shop_item);

		// 적군 총알 발사
		eCannon_status(enemy, player, bomb, cannon, 0);

		// 적 총알 이동
		eCannon_move(enemy);
		
		// 아이템 이동
		item_move(drop_item);
		
		// 아이템 유저 충돌
		item_status(drop_item, player, cannon, shop_item, 0);

		// 아이템 바닥 충돌
		item_status(drop_item, player, cannon, shop_item, 1);
		
		// 적 총알 플레이어 충돌
		eCannon_status(enemy, player, bomb, cannon, 1);

		// 적 총알 바닥 도달
		eCannon_status(enemy, player, bomb, cannon, 2);
		
		// 적 총알 플레이어 총알 충돌
		eCannon_status(enemy, player, bomb, cannon, 3);
		
		// 폭탄 발사시 적 총알 폭탄 앞에서 삭제
		eCannon_status(enemy, player, bomb, cannon, 4);
		
		// 폭탄 - 적 충돌
		bomb_status(bomb, enemy, player, shop_item, 0);

		// 폭탄이 천장에 도달하면 삭제
		bomb_status(bomb, enemy, player, shop_item, 1);

		// 적군이 바닥에 도달하면 삭제
		enemy_status(enemy, bomb, player, cannon, shop_item, 0);

		// 플레이어 - 적 충돌
		enemy_status(enemy, bomb, player, cannon, shop_item, 1);
		
		// 총알 - 적 충돌
		enemy_status(enemy, bomb, player, cannon, shop_item, 2);
		
		// 폭탄 총알 - 적 충돌
		enemy_status(enemy, bomb, player, cannon, shop_item, 3);
		
		// 총알이 천장에 도달하면 삭제
		cannon_status(cannon);
		
		// 폭탄 총알 발사
		bCannon_status(bomb, 0);

		// 폭탄 총알 이동
		bCannon_move(bomb);

		// 폭탄 총알이 천장에 도달하면 삭제
		bCannon_status(bomb, 1);
		
		// 스킬 재사용 대기
		if (shop_item->cooldown_time > 0)
		{
			shop_item->cooldown_time--;
		}

		// 게임 종료 검사
		if (player->life == 0 && player->hp == 0)
		{
			draw_end_game(player, shop_item);
			save_data(player, shop_item);
			free(player);
			free(cannon);
			free(bomb->bomb_cannon[0]);
			free(bomb->bomb_cannon[1]);
			free(bomb);
			free(drop_item);
			free(shop_item);
			for (int i = 0; i < ENEMY_SIZE; i++)
			{
				free(enemy->enemy_cannon[i]);
			}
			free(enemy);
			break;
		}

		frame_time++;
		Sleep(22);
	}
}