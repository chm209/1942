#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> // GetAsyncKeyState 사용을 위함
#include "common.h"
#include "game.h"

void game(void)
{
	system("mode con: cols=80 lines=32");
	system("cls");
	
	// 플레이어 - 폭탄, 스킬 포함
	Player player = { 28, 28, 1, 3, 0 }; // X값, Y값, 생명, 체력, 점수
	Bullet bullet[BULLET_SIZE] = { 0, }; // X값, Y값, 확인
	Skill skill = { 3, 0 };
	Item item[ITEM_SIZE] = { 0, };
	Bomb bomb[BOMB_SIZE] = { 29, 24, 1, 5, FALSE, 6, 24, 0, 5, FALSE }; // X값, Y값, 잔량, 속도, 확인
	Bomb_blt bomb_bul[BOMB_BUL_SIZE] = { 0, };
	Bomb_blt bomb_bul2[BOMB_BUL_SIZE] = { 0, };
	
	// 적군
	int frame_count = 0; // 스테이지 생성용
	Enemy enemy[ENEMY_SIZE] = { 0, };

	while (1)
	{
		draw_content(1);
		draw_stat(player, bomb);
		set_color(14);
		gotoxy(player.pos_x, player.pos_y);
		puts("[-*-]");
		set_color(15);

		// 유저 키보드 감지
		// GetAsyncKeyState()로 상시 감지하기 위해 함수화 X
		// 함수화 하거나 getch()로 돌리면 반응속도가 떨어짐
		{
			if (GetAsyncKeyState(VK_LEFT) && player.pos_x > 5) { //왼쪽
				gotoxy(player.pos_x, player.pos_y);
				puts("     ");
				player.pos_x--;
				gotoxy(player.pos_x, player.pos_y);
				puts("[-*-]");
			}
			if (GetAsyncKeyState(VK_RIGHT) && player.pos_x < 51) { //오른쪽
				gotoxy(player.pos_x, player.pos_y);
				puts("     ");
				player.pos_x++;
				gotoxy(player.pos_x, player.pos_y);
				puts("[-*-]");
			}
			if (GetAsyncKeyState(VK_UP) && player.pos_y > 4) { //위
				gotoxy(player.pos_x, player.pos_y);
				puts("     ");
				player.pos_y--;
				set_color(14);
				gotoxy(player.pos_x, player.pos_y);
				puts("[-*-]");
				set_color(15);
			}
			if (GetAsyncKeyState(VK_DOWN) && player.pos_y < 29) { //아래
				gotoxy(player.pos_x, player.pos_y);
				puts("     ");
				player.pos_y++;
				gotoxy(player.pos_x, player.pos_y);
				puts("[-*-]");
			}
		}

		// 게임 일시 정지
		if ((GetAsyncKeyState(VK_ESCAPE)))
		{
			int menu_num = 23;
			int key = 0;

			while (key != ENTER)
			{
				draw_content(2);
				gotoxy(menu_num, 14);
				puts("◎");
				key = getch();
				gotoxy(menu_num, 14);
				puts("  ");
				menu_num = move(1, key, menu_num, 14);
			}

			if (menu_num == 23) // 네
			{
				// 게임 스코어 저장
				break;
			}
			else // menu_num == 39 : 아니요
			{
				system("cls");
				continue;
			}
		}

		// 플레이어 총알 공격 스페이스바
		if ((GetAsyncKeyState(VK_SPACE)))
		{
			for (int i = 0; i < BULLET_SIZE; i++)
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

		// 폭탄 발사 Z키, frame_count > 1은 게임 시작하기전 Z키가 눌렸을대 스킬이 써지는걸 방지하기위함
		if (GetAsyncKeyState(0x5A) && frame_count > 0)
		{
			if (bomb[0].count > 0 && (bomb[0].con == FALSE && bomb[1].con == FALSE))
			{
				bomb[0].count--;
				bomb[0].con = TRUE;
				bomb[1].con = TRUE;
			}
		}

		// 스킬 X키 - 생명 추가, 추후 상점에서 구매하는 방식으로 변경할 예정
		// 추후 STAT UI에 스킬 개수를 표시해줘야함
		if ((GetAsyncKeyState(0x58) && frame_count > 1) && (skill.life_count == 0 && skill.life_plus > 0))
		{
			player.life++;
			skill.life_plus--;
			skill.life_count = 1000;

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

		// 적군 생성
		enemy_gen(enemy, frame_count);

		// 아이템 생성
		item_gen(item, frame_count);

		// 적군 이동
		enemy_move(enemy);

		// 폭탄 이동
		if (bomb[0].con == TRUE || bomb[1].con == TRUE)
			bomb_move(bomb);

		// 총알 이동
		bullet_move(bullet);

		// 적군 총알 발사
		player = enm_bull_status(enemy, player, bomb, bullet, 0);

		// 적 총알 이동
		enm_bull_move(enemy);
		
		// 아이템 이동
		item_move(item);
		
		// 아이템 유저 충돌
		item_status(item, player, bullet, 0);

		// 아이템 바닥 충돌
		item_status(item, player, bullet, 1);
		
		// 적 총알 플레이어 충돌
		player = enm_bull_status(enemy, player, bomb, bullet, 1);

		// 적 총알 바닥 도달
		player = enm_bull_status(enemy, player, bomb, bullet, 2);
		
		// 적 총알 플레이어 총알 충돌
		player = enm_bull_status(enemy, player, bomb, bullet, 3);
		
		// 폭탄 발사시 적 총알 폭탄 앞에서 삭제
		player = enm_bull_status(enemy, player, bomb, bullet, 4);
		
		// 폭탄 - 적 충돌
		bomb_status(bomb, enemy, 0);

		// 폭탄이 천장에 도달하면 삭제
		bomb_status(bomb, enemy, 1);

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
		if (skill.life_count > 0)
			skill.life_count--;

		// 게임 종료 검사
		if (player.life == 0 && player.health == 0)
		{
			break;
		}

		frame_count++;
		Sleep(22);
	}
}