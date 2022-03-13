#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h> // GetAsyncKeyState ����� ����
#include <time.h>
#include "common.h"
#define STATSIZE 4
#define BULLETSIZE 5
#define TRUE 1
#define FALSE 0

typedef struct
{
	int position_x;
	int position_y;
	int condition;
} BULLET;

draw_stat(int* stat_array)
{
	int position_x = 17;

	gotoxy(12, 29);
	printf("LIFE");
	for (int i = 0; i < stat_array[0]; i++)
	{
		gotoxy(position_x, 29);
		printf("��");
		position_x += 2;
	}
	gotoxy(30, 29);
	printf("BOMB");
	position_x = 35;
	for (int i = 0; i < stat_array[1]; i++)
	{
		gotoxy(position_x, 29);
		printf("��");
		position_x += 2;
	}
	gotoxy(44, 29);
	printf("HP");
	position_x = 47;
	for (int i = 0; i < stat_array[2]; i++)
	{
		gotoxy(position_x, 29);
		printf("��");
		position_x += 2;
	}
	gotoxy(68, 29);
	printf("SCORE : %11d", stat_array[3]);
}

void game(void)
{
	/*
	* 1. ���� ������ ������ �ҷ����� �ʿ�
	* 2. ���� ����� ���̵�, ��й�ȣ ������ DB�����ؼ� ����Ʈ, ����, ��ŷ ������Ʈ �ʿ�
	*/

	// life, bomb, hp, score ����
	int stat_array[STATSIZE] = {5, 3, 5, 0};
	int player_pos_x = 44, player_pos_y = 26;
	int key = 0;
	BULLET bullet[BULLETSIZE] = { 0, };
	int bullet_count = 0;
	
	system("cls");
	draw_content(1);
	draw_stat(stat_array);
	gotoxy(player_pos_x, player_pos_y);
	puts("<-*->");

	// �÷��̾� ������
	while (1)
	{
		gotoxy(10, 2);
		printf("%d", bullet_count);

		if (GetAsyncKeyState(VK_LEFT) && player_pos_x > 10) { //����
			gotoxy(player_pos_x, player_pos_y);
			printf("     ");
			player_pos_x--;
			gotoxy(player_pos_x, player_pos_y);
			puts("<-*->");
		}
		if (GetAsyncKeyState(VK_RIGHT) && player_pos_x < 84) { //������
			gotoxy(player_pos_x, player_pos_y);
			printf("     ");
			player_pos_x++;
			gotoxy(player_pos_x, player_pos_y);
			puts("<-*->");
		}
		if (GetAsyncKeyState(VK_UP) && player_pos_y > 20) { //��
			gotoxy(player_pos_x, player_pos_y);
			printf("     ");
			player_pos_y--;
			gotoxy(player_pos_x, player_pos_y);
			puts("<-*->");
		}
		if (GetAsyncKeyState(VK_DOWN) && player_pos_y < 26) { //�Ʒ�
			gotoxy(player_pos_x, player_pos_y);
			printf("     ");
			player_pos_y++;
			gotoxy(player_pos_x, player_pos_y);
			puts("<-*->");
		}
		if ((GetAsyncKeyState(VK_SPACE)))
		{
			for (int i = 0; i < BULLETSIZE; i++)
			{
				if (bullet[i].condition == FALSE)
				{
					bullet[i].position_x = player_pos_x + 1;
					bullet[i].position_y = player_pos_y - 1;
					bullet[i].condition = TRUE;
					gotoxy(bullet[i].position_x, bullet[i].position_y);
					printf("%d", bullet_count);
					// puts("��");
					bullet_count++;
					break;
				}
			}

			gotoxy(10, 2);
			printf("%d", bullet_count);
			gotoxy(10, 3);
			printf("%d", bullet[0].condition);
			gotoxy(10, 4);
			printf("%d", bullet[1].condition);
			gotoxy(10, 5);
			printf("%d", bullet[2].condition);
			gotoxy(10, 6);
			printf("%d", bullet[3].condition);
			gotoxy(10, 7);
			printf("%d", bullet[4].condition);
		}

		// �Ѿ� ������ & ���
		for (int i = 0; i < BULLETSIZE; i++)
		{
			if (bullet[i].condition == TRUE)
			{
				gotoxy(bullet[i].position_x, bullet[i].position_y);
				puts("  ");
				bullet[i].position_y--;
				gotoxy(bullet[i].position_x, bullet[i].position_y);
				printf("%d", i);
				// puts("��");
			}
		}

		// �Ѿ��� õ�忡 ������ �����
		for (int i = 0; i < BULLETSIZE; i++)
		{
			if (bullet[i].condition == TRUE && bullet[i].position_y == 0)
			{
				gotoxy(bullet[i].position_x, bullet[i].position_y);
				puts("  ");
				bullet[i].condition = FALSE;
				bullet_count--;

				gotoxy(10, 2);
				printf("%d", bullet_count);
				gotoxy(10, 3);
				printf("%d", bullet[0].condition);
				gotoxy(10, 4);
				printf("%d", bullet[1].condition);
				gotoxy(10, 5);
				printf("%d", bullet[2].condition);
				gotoxy(10, 6);
				printf("%d", bullet[3].condition);
				gotoxy(10, 7);
				printf("%d", bullet[4].condition);

				
				break;
			}
		}

		/*
		* 1. �Ѿ��� ��� �������� Ȯ�� v
			2. 5�� �Ʒ��� �߻� v
			3. �̵� v
			4. õ�忡 ������ �Ѿ� ����
		*/

		Sleep(40);
		// Sleep(18);
	}
}
