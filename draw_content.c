#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void draw_content(int screen_num)
{
	switch (screen_num)
	{
	// 詭檣�飛� - 紫お 轎溘
	case 0:
		system("cls");
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 100; j += 2)
			{
				gotoxy(j, i);
				printf("王");
			}
		}
		break;
	// 詭檣�飛� - 1942 璋濠 轎溘
	case 1:
	{
		// 1
		gotoxy(24, 3);
		printf("≒≒");
		gotoxy(22, 4);
		printf("≒≒≒");
		gotoxy(20, 5);
		printf("≒≒≒≒");
		gotoxy(24, 6);
		printf("≒≒");
		gotoxy(24, 7);
		printf("≒≒");
		gotoxy(24, 8);
		printf("≒≒");
		gotoxy(24, 9);
		printf("≒≒");
		gotoxy(20, 10);
		printf("≒≒≒≒≒≒");
		gotoxy(20, 11);
		printf("≒≒≒≒≒≒");
		// 9
		gotoxy(38, 3);
		printf("≒≒≒");
		gotoxy(36, 4);
		printf("≒");
		gotoxy(44, 4);
		printf("≒");
		gotoxy(36, 5);
		printf("≒");
		gotoxy(44, 5);
		printf("≒");
		gotoxy(36, 6);
		printf("≒");
		gotoxy(44, 6);
		printf("≒");
		gotoxy(38, 7);
		printf("≒≒≒≒");
		gotoxy(42, 8);
		printf("≒≒");
		gotoxy(42, 9);
		printf("≒≒");
		gotoxy(42, 10);
		printf("≒≒");
		gotoxy(42, 11);
		printf("≒≒");
		// 4
		gotoxy(60, 3);
		printf("≒");
		gotoxy(58, 4);
		printf("≒≒");
		gotoxy(56, 5);
		printf("≒");
		gotoxy(60, 5);
		printf("≒");
		gotoxy(54, 6);
		printf("≒");
		gotoxy(60, 6);
		printf("≒");
		gotoxy(52, 7);
		printf("≒");
		gotoxy(60, 7);
		printf("≒");
		gotoxy(50, 8);
		printf("≒≒≒≒≒≒≒");
		gotoxy(60, 9);
		printf("≒");
		gotoxy(60, 10);
		printf("≒");
		gotoxy(60, 11);
		printf("≒");
		// 2
		gotoxy(70, 3);
		printf("≒≒≒≒");
		gotoxy(68, 4);
		printf("≒");
		gotoxy(78, 4);
		printf("≒");
		gotoxy(68, 5);
		printf("≒");
		gotoxy(78, 5);
		printf("≒");
		gotoxy(76, 6);
		printf("≒");
		gotoxy(74, 7);
		printf("≒");
		gotoxy(72, 8);
		printf("≒");
		gotoxy(70, 9);
		printf("≒");
		gotoxy(68, 10);
		printf("≒");
		gotoxy(68, 11);
		printf("≒≒≒≒≒≒");
		}
		break;
	// 詭檣�飛� - 褻濛酈 Щ溯歜, 臢蝶お 轎溘
	case 2:
	{
		gotoxy(18, 17);
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
		gotoxy(18, 18);
		printf("早                          早");
		gotoxy(18, 19);
		printf("早                          早");
		gotoxy(18, 20);
		printf("早                          早");
		gotoxy(18, 21);
		printf("早                          早");
		gotoxy(18, 22);
		printf("早                          早");
		gotoxy(18, 23);
		printf("早                          早");
		gotoxy(18, 24);
		printf("早                          早");
		gotoxy(18, 25);
		printf("早                          早");
		gotoxy(18, 26);
		printf("早                          早");
		gotoxy(18, 27);
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收旭");
		gotoxy(21, 18);
		printf("詭檣�飛� 褻濛酈");
		gotoxy(18, 19);
		printf("曳收收收收收收收收收收收收收收收收收收收收收收收收收收朽");
		gotoxy(21, 21);
		printf("嬪   | 酈爾萄 寞щ酈 ∟");
		gotoxy(21, 23);
		printf("嬴楚 | 酈爾萄 寞щ酈 ⊿");
		gotoxy(21, 25);
		printf("�挫� | 酈爾萄 縛攪酈");
	}
		break;
	// 詭檣�飛� - 煎斜檣瞪 臢蝶お 轎溘
	case 3:
	{
		gotoxy(56, 19);
		printf("煎斜檣");
		gotoxy(56, 21);
		printf("�蛾灠㊣�");
		gotoxy(56, 23);
		printf("楨韁�飛�");
		gotoxy(56, 25);
		printf("啪歜謙猿");
	}
		break;
	// 詭檣�飛� - 煎斜檣�� 臢蝶お 轎溘
	case 4:
	{
		gotoxy(56, 19);
		printf("啪歜衛濛");
		gotoxy(56, 21);
		printf("鼻薄");
		gotoxy(56, 23);
		printf("楨韁�挫�");
		gotoxy(56, 25);
		printf("啪歜謙猿");
		gotoxy(0, 29);
		printf("煎斜檣 嶸盪: %s", user.id);
	}
		break;
	// 煎斜檣 �飛� - �飛� 雖辦晦蒂 嬪и 奢寥 轎溘
	case 5:
	{
		gotoxy(34, 18);
		printf("                                 ");
		gotoxy(34, 20);
		printf("                                 ");
		gotoxy(34, 22);
		printf("                                 ");
		gotoxy(34, 24);
		printf("                                 ");
		cursor(1);
	}
		break;
	// 楨韁�飛� - 綠煎斜檣 鼻鷓 Щ溯歜 轎溘
	case 6:
	{
		gotoxy(2, 1);
		printf("旨收收收收收有收收收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
		for (int i = 2; i < 27; i++)
		{
			gotoxy(2, i);
			printf("早");
			gotoxy(8, i);
			printf("早");
			gotoxy(30, i);
			printf("早");
			gotoxy(50, i);
			printf("早");
			gotoxy(96, i);
			printf("早");
		}
		for (int i = 3; i < 27; i += 2)
		{
			gotoxy(3, i);
			printf("收收收收收朱");
			gotoxy(9, i);
			printf("收收收收收收收收收收收收收收收收收收收收收朱");
			gotoxy(31, i);
			printf("收收收收收收收收收收收收收收收收收收收朱收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收");
		}
		gotoxy(2, 27);
		printf("曲收收收收收朴收收收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");
	}
		break;
	// 楨韁�飛� - 綠煎斜檣 鼻鷓 臢蝶お 轎溘
	case 7:
	{
		gotoxy(4, 2);
		printf("牖嬪");
		int colum = 4;
		for (int i = 1; i < 13; i++)
		{
			gotoxy(5, colum);
			printf("%2d", i);
			colum += 2;
		}
		gotoxy(18, 2);
		printf("檜葷");
		gotoxy(39, 2);
		printf("薄熱");
		gotoxy(68, 2);
		printf("餌辨 嬴檜蠱");
		gotoxy(74, 28);
		printf("楨韁�飛� 釭陛晦: ESC 酈");
	}
		break;
	// 楨韁�飛� - 煎斜檣 鼻鷓 Щ溯歜 轎溘
	case 8:
	{
		gotoxy(2, 1);
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
		for (int i = 2; i < 9; i++)
		{
			gotoxy(2, i);
			printf("早");
			gotoxy(96, i);
			printf("早");
		}
		for (int i = 2; i < 9; i++)
		{
			gotoxy(30, i);
			printf("早");
		}
		for (int i = 9; i < 27; i++)
		{
			gotoxy(2, i);
			printf("早");
			gotoxy(8, i);
			printf("早");
			gotoxy(30, i);
			printf("早");
			gotoxy(50, i);
			printf("早");
			gotoxy(96, i);
			printf("早");
		}
		gotoxy(2, 9);
		printf("曳收收收收收有收收收收收收收收收收收收收收收收收收收收收朱收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽");
		for (int i = 11; i < 27; i += 2)
		{
			gotoxy(3, i);
			printf("收收收收收朱");
			gotoxy(9, i);
			printf("收收收收收收收收收收收收收收收收收收收收收朱");
			gotoxy(31, i);
			printf("收收收收收收收收收收收收收收收收收收收朱收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收");
		}
		gotoxy(2, 27);
		printf("曲收收收收收朴收收收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");
	}
		break;
	// 楨韁�飛� - 煎斜檣 鼻鷓 臢蝶お 轎溘
	case 9:
	{
		// 嶸盪 薑爾
		gotoxy(5, 3);
		printf("≒ 瞪癱晦: ");
		gotoxy(5, 5);
		printf("議喱 賅曄: ");
		gotoxy(5, 7);
		printf("堅嶸 儀鼻: ");
		gotoxy(33, 3);
		printf("檜葷: ");
		gotoxy(33, 5);
		printf("ん檣お");
		gotoxy(64, 3);
		printf("譆堅薄熱");
		gotoxy(33, 7);
		printf("餌辨и 嬴檜蠱");
		// 牖嬪 葬蝶お
		gotoxy(4, 10);
		printf("牖嬪");
		int colum = 12;
		for (int i = 1; i < 9; i++)
		{
			gotoxy(5, colum);
			printf("%d", i);
			colum += 2;
		}
		gotoxy(18, 10);
		printf("檜葷");
		gotoxy(39, 10);
		printf("薄熱");
		gotoxy(68, 10);
		printf("餌辨 嬴檜蠱");
		gotoxy(74, 28);
		printf("楨韁�飛� 釭陛晦: ESC 酈");
	}
		break;
	// 鼻薄�飛� - Щ溯歜 轎溘
	case 10:
	{
		gotoxy(2, 1);
		printf("旨收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收收收有收收收收收收收收收有收收收收收收收有收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
		for (int i = 2; i < 24; i++)
		{
			gotoxy(2, i);
			printf("早");
			gotoxy(22, i);
			printf("早");
			gotoxy(36, i);
			printf("早");
			gotoxy(46, i);
			printf("早");
			gotoxy(54, i);
			printf("早");
			gotoxy(96, i);
			printf("早");
		}
		for (int i = 3; i < 24; i += 2)
		{
			gotoxy(2, i);
			printf("曳收收收收收收收收收收收收收收收收收收收");
			gotoxy(22, i);
			printf("朱收收收收收收收收收收收收收");
			gotoxy(36, i);
			printf("朱收收收收收收收收收");
			gotoxy(46, i);
			printf("朱收收收收收收收");
			gotoxy(54, i);
			printf("朽");
		}
		gotoxy(36, 23);
		printf("朴收收收收收收收收收");
		gotoxy(46, 23);
		printf("朴收收收收收收收");
		gotoxy(2, 24);
		printf("早");
		gotoxy(22, 24);
		printf("早");
		gotoxy(54, 24);
		printf("早");
		gotoxy(96, 24);
		printf("早");
		gotoxy(2, 25);
		printf("曲收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");
	}
		break;
	// 鼻薄�飛� - 臢蝶お 轎溘
	case 11:
	{
		gotoxy(3, 26);
		printf("纂濰 嬴檜蠱擎 ж釭噶虜 模雖 陛棟 м棲棻. / 晦襄 纂濰 嬴檜蠱擎 60%% 陛問縑 濠翕 っ衙 腌棲棻.");
		gotoxy(3, 28);
		printf("跡煙 檜翕: 寞щ酈 ∟ ⊿  ||  掘衙: 縛攪酈                                  鼻薄 釭陛晦: ESC 酈");
		gotoxy(11, 2);
		printf("о跡");
		gotoxy(28, 2);
		printf("陛問");
		gotoxy(39, 2);
		printf("爾嶸熱");
		gotoxy(49, 2);
		printf("摹鷗");
		gotoxy(5, 4);
		printf("儅貲 蹺陛");
		gotoxy(5, 6);
		printf("HP �蛹�");
		gotoxy(5, 8);
		printf("蹺陛 薄熱");
		gotoxy(5, 10);
		printf("說鬼 む檣お");
		gotoxy(5, 12);
		printf("だ嫌 む檣お");
		gotoxy(5, 14);
		printf("喻嫌 む檣お");
		gotoxy(5, 16);
		printf("說除 議喱");
		gotoxy(5, 18);
		printf("だ塢 議喱");
		gotoxy(5, 20);
		printf("喻塢 議喱");
		gotoxy(5, 22);
		printf("楨韁璽 紱嘐晦");
		gotoxy(5, 24);
		printf("爾嶸 ん檣お");
	}
		break;
	case 12:
	{
		gotoxy(29, 4);
		printf("1000 pt");
		gotoxy(30, 6);
		printf("500 pt");
		gotoxy(29, 8);
		printf("2000 pt");
		gotoxy(29, 10);
		printf("3500 pt");
		gotoxy(29, 12);
		printf("4500 pt");
		gotoxy(29, 14);
		printf("5500 pt");
		gotoxy(29, 16);
		printf("3500 pt");
		gotoxy(29, 18);
		printf("4500 pt");
		gotoxy(29, 20);
		printf("5500 pt");
		gotoxy(27, 22);
		printf("100000 pt");
	}
		break;
	case 13:
	{
		for (int i = 4; i < 24; i++)
		{
			gotoxy(59, i);
			printf("                                     ");
		}
		gotoxy(59, 5);
		printf("掘衙 碳陛");
		set_color(12);
		gotoxy(59, 8);
		printf("ん檣お陛 睡褶м棲棻.");
		set_color(15);
	}
		break;
	}
}