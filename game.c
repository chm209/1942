#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // GetAsyncKeyState 사용을 위함
#include "common.h"
#include "game.h"

void game(void)
{
	system("mode con: cols=80 lines=30");
	system("cls");

	// 플레이어 관련 구조체 변수
	// Player: 좌표 X값, 좌표 Y값, 생명, 체력, 점수, 전투기 모양, 전투기 색상
	// Bullet[]: 좌표 X값, 좌표 Y값, 상태 확인용, 총알 타입, 총알 모양, 총알 색상
	// Item[]: 좌표 X값, 좌표 Y값, 상태 확인용, 아이템 타입, 아이템 움직임 속도
	// Bomb[]: 좌표 X값, 좌표 Y값, 폭탄 수량, 폭탄 움직임 속도, 폭탄 상태 확인용 * 2
	// bomb_bul[]: 좌표 X값, 좌표 Y값, 폭탄 총알 상태 확인용
	// bomb_bul2[]: 좌표 X값, 좌표 Y값, 폭탄 총알 상태 확인용
	// Shop: 생명 추가 수량, 체력 회복 수량, 추가 점수 수량, 스킬 쿨타임, 전투기 색상, 총알 색상
	// ㄴ▷ DB 연동후 손봐야 하는 구조체 변수, 치장 아이템은 0이 Default 색상을 의미
	Player player = { 28, 28, 1, 3, 2, 0, NULL, 0 };
	Bullet bullet[BULLET_SIZE] = { 0, 0, 0, 0, NULL, 0 };
	Item item[ITEM_SIZE] = { 0, };
	Bomb bomb[BOMB_SIZE] = { 29, 24, 1, 5, FALSE, 6, 24, 0, 5, FALSE };
	Bomb_blt bomb_bul[BOMB_BUL_SIZE] = { 0, };
	Bomb_blt bomb_bul2[BOMB_BUL_SIZE] = { 0, };
	Shop shop = { 0, 0, 0, 0, 0, 0};

	// 적군 관련 변수
	// Enemy[]: 좌표 X값, 좌표 Y값, 적 비행기 타입, 움직임 패턴, 움직임 횟수, 움직임 속도, 체력, 상태 확인용
	// 총알 X값, 총알 Y값, 상태확인, 속도
	int frame_count = 0; // 스테이지 생성용
	Enemy enemy[ENEMY_SIZE] = { 0, };
	Enemy_bul enemy_bul[ENEMY_SIZE] = { 0, };

	// 게임 시작전 초기 설정
	// 1. 플레이어 전투기 디자인, 전투기 색상, 총알 디자인, 총알 색상 설정
	// 2. 최초 실행시 전투기를 한번은 출력해줘야한다.
	// -▷ DB 연동후 초기설정은 여기서 처리
	player = set_player(player, bullet, shop);

	while (1)
	{
		// UI 그리기
		// 1. 프레임 출력
		// 2. 플레이어 스탯 출력
		// 3. 플레이어 전투기 출력
		draw_game(0);
		draw_status(player, bomb, shop);
		{
			gotoxy(player.pos_x, player.pos_y);
			set_color(player.color);
			printf(player.shape);
			set_color(15);
		}

		// 키보드 입력 감지
		// 함수화, getch()로 감지 등등 전부 반응속도가 떨어지거나 툭툭 끊김
		{
			// 왼쪽 이동
			if (GetAsyncKeyState(VK_LEFT) && player.pos_x > LEFT_LIMIT)
			{
				gotoxy(player.pos_x, player.pos_y);
				puts("     ");
				player.pos_x--;
				gotoxy(player.pos_x, player.pos_y);
				set_color(player.color);
				printf(player.shape);
				set_color(15);
			}

			// 오른쪽 이동
			if (GetAsyncKeyState(VK_RIGHT) && player.pos_x < RIGHT_LIMIT)
			{
				gotoxy(player.pos_x, player.pos_y);
				puts("     ");
				player.pos_x++;
				gotoxy(player.pos_x, player.pos_y);
				set_color(player.color);
				printf(player.shape);
				set_color(15);
			}

			// 위로 이동
			if (GetAsyncKeyState(VK_UP) && player.pos_y > UP_LIMIT)
			{
				gotoxy(player.pos_x, player.pos_y);
				puts("     ");
				player.pos_y--;
				gotoxy(player.pos_x, player.pos_y);
				set_color(player.color);
				printf(player.shape);
				set_color(15);
			}

			// 아래로 이동
			if (GetAsyncKeyState(VK_DOWN) && player.pos_y < DOWN_LIMIT)
			{
				gotoxy(player.pos_x, player.pos_y);
				puts("     ");
				player.pos_y++;
				gotoxy(player.pos_x, player.pos_y);
				set_color(player.color);
				printf(player.shape);
				set_color(15);
			}
		}

		// 게임 일시 정지
		// 게임 시작전 눌린 키를 가려내기 위해 frame_count를 검사
		if (GetAsyncKeyState(VK_ESCAPE) && frame_count > 0)
		{
			int key = 0, do_exit = 23;

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
				// 게임 스코어, 포인트, 사용한 아이템 등등 DB에 저장
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
		if (GetAsyncKeyState(VK_SPACE) && frame_count > 0)
		{
			for (int i = 0; i < player.quantity; i++)
			{
				if (bullet[i].con == FALSE)
				{
					bullet[i].pos_x = player.pos_x + 1;
					bullet[i].pos_y = player.pos_y - 1;
					bullet[i].con = TRUE;
					break;
				}
			}
		}

		// 폭탄 공격 - Z키
		if (GetAsyncKeyState(0x5A) && frame_count > 0)
		{
			if (bomb[0].count > 0 && (bomb[0].con == FALSE && bomb[1].con == FALSE))
			{
				bomb[0].count--;
				bomb[0].con = TRUE;
				bomb[1].con = TRUE;
			}
		}

		// 생명 추가 - X키
		if ((GetAsyncKeyState(0x58) && frame_count > 1) && (shop.cool_time == 0 && shop.life_plus > 0))
		{
			player.life++;
			player.score -= 50;
			shop.life_plus--;
			shop.cool_time = 1000;

			if (bomb[0].count > 0 && (bomb[0].con == FALSE && bomb[1].con == FALSE))
			{
				bomb[0].con = TRUE;
				bomb[1].con = TRUE;
			}
			else
			{
				bomb[0].count++;
			}
		}

		// 체력 회복 - C키
		if ((GetAsyncKeyState(0x43) && frame_count > 1) && (shop.hp_plus > 0 && player.health < 3))
		{
			shop.hp_plus--;
			player.health++;
			player.score -= 10;
		}

		// 적군 생성
		enemy_gen(enemy, frame_count);

		// 아이템 생성
		item_gen(item, frame_count);

		// 적군 이동
		enemy_move(enemy);

		// 폭탄 이동
		if (bomb[0].con == TRUE || bomb[1].con == TRUE)
		{
			bomb_move(bomb);
		}

		// 총알 이동
		bullet_move(bullet);

		// 적군 총알 발사
		player = enm_bull_status(enemy, player, bomb, bullet, 0);

		// 적 총알 이동
		enm_bull_move(enemy);
		
		// 아이템 이동
		item_move(item);
		
		// 아이템 유저 충돌
		player = item_status(item, player, bullet, shop, 0);

		// 아이템 바닥 충돌
		player = item_status(item, player, bullet, shop, 1);
		
		// 적 총알 플레이어 충돌
		player = enm_bull_status(enemy, player, bomb, bullet, 1);

		// 적 총알 바닥 도달
		player = enm_bull_status(enemy, player, bomb, bullet, 2);
		
		// 적 총알 플레이어 총알 충돌
		player = enm_bull_status(enemy, player, bomb, bullet, 3);
		
		// 폭탄 발사시 적 총알 폭탄 앞에서 삭제
		player = enm_bull_status(enemy, player, bomb, bullet, 4);
		
		// 폭탄 - 적 충돌
		bomb_status(bomb, enemy, player, 0);

		// 폭탄이 천장에 도달하면 삭제
		bomb_status(bomb, enemy, player, 1);

		// 적군이 바닥에 도달하면 삭제
		player = enm_status(enemy, bomb, bomb_bul, bomb_bul2, player, bullet, 0);

		// 플레이어 - 적 충돌
		player = enm_status(enemy, bomb, bomb_bul, bomb_bul2, player, bullet, 1);
		
		// 총알 - 적 충돌
		player = enm_status(enemy, bomb, bomb_bul, bomb_bul2, player, bullet, 2);
		
		// 폭탄 총알 - 적 충돌
		player = enm_status(enemy, bomb, bomb_bul, bomb_bul2, player, bullet, 3);
		
		// 총알이 천장에 도달하면 삭제
		bullet_status(bullet);
		
		// 폭탄 총알 발사
		bomb_bull_status(bomb, bomb_bul, bomb_bul2, 0);

		// 폭탄 총알 이동
		bomb_bull_move(bomb, bomb_bul, bomb_bul2);

		// 폭탄 총알이 천장에 도달하면 삭제
		bomb_bull_status(bomb, bomb_bul, bomb_bul2, 1);
		
		// 스킬 재사용 대기
		if (shop.cool_time > 0)
		{
			shop.cool_time--;
		}

		// 게임 종료 검사
		if (player.life == 0 && player.health == 0)
		{
			break;
		}

		frame_count++;
		Sleep(22);
	}
}