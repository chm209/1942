#include <stdio.h>
#include <windows.h>
#include "common.h"
#define SHOP_POS_X 50

void shop(void)
{
	system("cls");
	draw_content(10); // ����ȭ�� ������ ���
	draw_content(11); // ����ȭ�� ������ ����Ʈ ���
	draw_content(12); // ������ ���� ���
	draw_owned_item(); // ���� ���� (����Ʈ, ���� ������ ����ϴ� �Լ� �ʿ�)
	shop_preview(4); // ����ȭ�� ������ ����Ʈ ���� ���, ó������ 1�� �׸� ���

	// shop���� ����ϴ� ����
	int list_num = 4;
	int choose_item = 0;
	int price = 0;

	// ESC Ű�� �Է��Ҷ����� ���� �ݺ�
	while (choose_item != ESC)
	{
		gotoxy(SHOP_POS_X, list_num);
		puts("��");
		draw_owned_item(user);
		shop_preview(list_num);
		choose_item = getch();

		if (choose_item == ENTER)
		{
			switch (list_num)
			{
			case 4:
				price = 1000;
				break;
			case 6:
				price = 500;
				break;
			case 8:
				price = 2000;
				break;
			case 10:
				price = 3500;
				break;
			case 12:
				price = 4500;
				break;
			case 14:
				price = 5500;
				break;
			case 16:
				price = 3500;
				break;
			case 18:
				price = 4500;
				break;
			case 20:
				price = 5500;
				break;
			case 22:
				price = 100000;
				break;
			}
		
			if (user.point >= price)
			{
				// ��� ������
				if (list_num < 10)
				{
					switch (list_num)
					{
					// ���� �߰�
					case 4:
						if (user.item[0] < 3)
						{
							user.point -= 1000;
							user.item[0]++;
						}
						else
						{
							// ���� �Ұ� �˸�
						}
						break;
					// HP ȸ��
					case 6:
						if (user.item[1] < 5)
						{
							user.point -= 500;
							user.item[1]++;
						}
						else
						{
							// ���� �Ұ� �˸�
						}
						break;
					// �߰� ����
					case 8:
						user.point -= 2000;
						user.item[2]++;
						break;
					}
				}
				// ġ�� ������
				else
				{
					switch (list_num)
					{
					// ���� ����Ʈ
					case 10:
						if (user.item[3] == 0)
						{
							user.point -= 3500;
							user.item[3]++;

							if (user.item[4] == 1)
							{
								user.item[4] = 0;
								user.point += 2700;
							}
							else if (user.item[5] == 1)
							{
								user.item[5] = 0;
								user.point += 3300;
							}
						}
						break;
					// �Ķ� ����Ʈ
					case 12:
						if (user.item[4] == 0)
						{
							user.point -= 4500;
							user.item[4]++;

							if (user.item[3] == 1)
							{
								user.item[3] = 0;
								user.point += 2100;
							}
							else if (user.item[5] == 1)
							{
								user.item[5] = 0;
								user.point += 3300;
							}
						}
						break;
					// ��� ����Ʈ
					case 14:
						if (user.item[5] == 0)
						{
							user.point -= 5500;
							user.item[5]++;

							if (user.item[3] == 1)
							{
								user.item[3] = 0;
								user.point += 2100;
							}
							else if (user.item[4] == 1)
							{
								user.item[4] = 0;
								user.point += 2700;
							}
						}
						break;
					// ���� �Ѿ�
					case 16:
						if (user.item[6] == 0)
						{
							user.point -= 3500;
							user.item[6]++;

							if (user.item[7] == 1)
							{
								user.item[7] = 0;
								user.point += 2700;
							}
							else if (user.item[8] == 1)
							{
								user.item[8] = 0;
								user.point += 3300;
							}
						}
						break;
					// �Ķ� �Ѿ�
					case 18:
						if (user.item[7] == 0)
						{
							user.point -= 4500;
							user.item[7]++;

							if (user.item[6] == 1)
							{
								user.item[6] = 0;
								user.point += 2100;
							}
							else if (user.item[8] == 1)
							{
								user.item[8] = 0;
								user.point += 3300;
							}
						}
						break;
					// ��� �Ѿ�
					case 20:
						if (user.item[8] == 0)
						{
							user.point -= 5500;
							user.item[8]++;

							if (user.item[6] == 1)
							{
								user.item[6] = 0;
								user.point += 2100;
							}
							else if (user.item[7] == 1)
							{
								user.item[7] = 0;
								user.point += 2700;
							}
						}
						break;
					case 22:
						if (user.item[9] == 0)
						{
							user.point -= 100000;
							user.item[9]++;
						}
						break;
					}
				}
			}
			else
			{
				
				// �� �������� ���� �Ұ�
			}
			choose_item = 0;
		}
		else
		{
			gotoxy(SHOP_POS_X, list_num);
			puts("  ");
			// ȭ���ȣ, �Է¹��� Ű ��, X ��, Y ��
			list_num = move(2, choose_item, SHOP_POS_X, list_num);
		}
	}
	// db ����
	shop_db(user);
}