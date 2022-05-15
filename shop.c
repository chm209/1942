#include <stdio.h>
#include <windows.h>
#include "common.h"
#define SHOP_POS_X 50

void shop()
{
	system("cls");
	draw_content(10); // ����ȭ�� ������ ���
	draw_content(11); // ����ȭ�� ������ ����Ʈ ���
	draw_content(12); // ������ ���� ���
	possession_item(); // ���� ���� (����Ʈ, ���� ������ ����ϴ� �Լ� �ʿ�)
	shop_preview(4); // ����ȭ�� ������ ����Ʈ ���� ���, ó������ 1�� �׸� ���

	// shop���� ����ϴ� ����
	int list_num = 4, choose_item = 0;
	int price = 0;

	// ESC Ű�� �Է��Ҷ����� ���� �ݺ�
	while (choose_item != ESC)
	{
		gotoxy(SHOP_POS_X, list_num);
		puts("��");
		possession_item();
		shop_preview(list_num);
		choose_item = getch();

		if (choose_item == ENTER)
		{
			// ���� ���μ���
			// ���� ���� ����Ʈ�� ������ ���� ��
			// ���� ���� ����Ʈ�� �� ũ�ٸ� ġ�� ���������� Ȯ��
			// ġ�� �������� �ƴ϶�� �ִ� ���� ���� �̸����� ������ �ִ��� Ȯ��
			// ���� ����ϸ� ����
			// �ϳ��� �ɸ��� ���� �Ұ�, ���� �Ұ� ���� ���

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
						if (item_list.item1 < 3)
						{
							user.point -= 1000;
							item_list.item1++;
						}
						else
						{
							// ���� �Ұ� �˸�
						}
						break;
					// HP ȸ��
					case 6:
						if (item_list.item2 < 5)
						{
							user.point -= 500;
							item_list.item2++;
						}
						else
						{
							// ���� �Ұ� �˸�
						}
						break;
					// �߰� ����
					case 8:
						user.point -= 2000;
						item_list.item3++;
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
						if (item_list.item4 == 0)
						{
							user.point -= 3500;
							item_list.item4++;

							if (item_list.item5 == 1)
							{
								item_list.item5 = 0;
								user.point += 2700;
							}
							else if (item_list.item6 == 1)
							{
								item_list.item6 = 0;
								user.point += 3300;
							}
						}
						break;
					// �Ķ� ����Ʈ
					case 12:
						if (item_list.item5 == 0)
						{
							user.point -= 4500;
							item_list.item5++;

							if (item_list.item4 == 1)
							{
								item_list.item4 = 0;
								user.point += 2100;
							}
							else if (item_list.item6 == 1)
							{
								item_list.item6 = 0;
								user.point += 3300;
							}
						}
						break;
					// ��� ����Ʈ
					case 14:
						if (item_list.item6 == 0)
						{
							user.point -= 5500;
							item_list.item6++;

							if (item_list.item4 == 1)
							{
								item_list.item4 = 0;
								user.point += 2100;
							}
							else if (item_list.item5 == 1)
							{
								item_list.item5 = 0;
								user.point += 2700;
							}
						}
						break;
					// ���� �Ѿ�
					case 16:
						if (item_list.item7 == 0)
						{
							user.point -= 3500;
							item_list.item7++;

							if (item_list.item8 == 1)
							{
								item_list.item8 = 0;
								user.point += 2700;
							}
							else if (item_list.item9 == 1)
							{
								item_list.item9 = 0;
								user.point += 3300;
							}
						}
						break;
					// �Ķ� �Ѿ�
					case 18:
						if (item_list.item8 == 0)
						{
							user.point -= 4500;
							item_list.item8++;

							if (item_list.item7 == 1)
							{
								item_list.item7 = 0;
								user.point += 2100;
							}
							else if (item_list.item9 == 1)
							{
								item_list.item9 = 0;
								user.point += 3300;
							}
						}
						break;
					// ��� �Ѿ�
					case 20:
						if (item_list.item9 == 0)
						{
							user.point -= 5500;
							item_list.item9++;

							if (item_list.item7 == 1)
							{
								item_list.item7 = 0;
								user.point += 2100;
							}
							else if (item_list.item8 == 1)
							{
								item_list.item8 = 0;
								user.point += 2700;
							}
						}
						break;
					case 22:
						if (item_list.item10 == 0)
						{
							user.point -= 100000;
							item_list.item10++;
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
	shop_db();
}