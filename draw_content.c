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
				// puts 渠褐 printf蒂 餌辨и 檜嶸
				// puts朝 僥濠翮虜 籀葬ж晦 陽僥縑 樓紫陛 緒艇 渠褐 偃ч紫 п幗葬晦 陽僥縑
				// for僥戲煎 Щ溯歜擊 斜萵陽 �飛橉� 慇橫釭幗葬朝 僥薯陛 嫦儅и棻.
				// 章偃煎 轎溘п憮 gotoxy煎 鐘お煤ж賊 鼻婦橈雖虜
				// for僥戲煎 轎溘й陽朝 printf噙朝啪 謠棻.
			}
		}
		break;
	// 詭檣�飛� - 1942 璋濠 轎溘
	case 1:
	{
		// 1
		gotoxy(24, 3);
		puts("≒≒");
		gotoxy(22, 4);
		puts("≒≒≒");
		gotoxy(20, 5);
		puts("≒≒≒≒");
		gotoxy(24, 6);
		puts("≒≒");
		gotoxy(24, 7);
		puts("≒≒");
		gotoxy(24, 8);
		puts("≒≒");
		gotoxy(24, 9);
		puts("≒≒");
		gotoxy(20, 10);
		puts("≒≒≒≒≒≒");
		gotoxy(20, 11);
		puts("≒≒≒≒≒≒");
		// 9
		gotoxy(38, 3);
		puts("≒≒≒");
		gotoxy(36, 4);
		puts("≒");
		gotoxy(44, 4);
		puts("≒");
		gotoxy(36, 5);
		puts("≒");
		gotoxy(44, 5);
		puts("≒");
		gotoxy(36, 6);
		puts("≒");
		gotoxy(44, 6);
		puts("≒");
		gotoxy(38, 7);
		puts("≒≒≒≒");
		gotoxy(42, 8);
		puts("≒≒");
		gotoxy(42, 9);
		puts("≒≒");
		gotoxy(42, 10);
		puts("≒≒");
		gotoxy(42, 11);
		puts("≒≒");
		// 4
		gotoxy(60, 3);
		puts("≒");
		gotoxy(58, 4);
		puts("≒≒");
		gotoxy(56, 5);
		puts("≒");
		gotoxy(60, 5);
		puts("≒");
		gotoxy(54, 6);
		puts("≒");
		gotoxy(60, 6);
		puts("≒");
		gotoxy(52, 7);
		puts("≒");
		gotoxy(60, 7);
		puts("≒");
		gotoxy(50, 8);
		puts("≒≒≒≒≒≒≒");
		gotoxy(60, 9);
		puts("≒");
		gotoxy(60, 10);
		puts("≒");
		gotoxy(60, 11);
		puts("≒");
		// 2
		gotoxy(70, 3);
		puts("≒≒≒≒");
		gotoxy(68, 4);
		puts("≒");
		gotoxy(78, 4);
		puts("≒");
		gotoxy(68, 5);
		puts("≒");
		gotoxy(78, 5);
		puts("≒");
		gotoxy(76, 6);
		puts("≒");
		gotoxy(74, 7);
		puts("≒");
		gotoxy(72, 8);
		puts("≒");
		gotoxy(70, 9);
		puts("≒");
		gotoxy(68, 10);
		puts("≒");
		gotoxy(68, 11);
		puts("≒≒≒≒≒≒");
		}
		break;
	// 詭檣�飛� - 褻濛酈 Щ溯歜, 臢蝶お 轎溘
	case 2:
	{
		gotoxy(18, 17);
		puts("旨收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
		gotoxy(18, 18);
		puts("早                          早");
		gotoxy(18, 19);
		puts("早                          早");
		gotoxy(18, 20);
		puts("早                          早");
		gotoxy(18, 21);
		puts("早                          早");
		gotoxy(18, 22);
		puts("早                          早");
		gotoxy(18, 23);
		puts("早                          早");
		gotoxy(18, 24);
		puts("早                          早");
		gotoxy(18, 25);
		puts("早                          早");
		gotoxy(18, 26);
		puts("早                          早");
		gotoxy(18, 27);
		puts("曲收收收收收收收收收收收收收收收收收收收收收收收收收收旭");
		gotoxy(21, 18);
		puts("詭檣�飛� 褻濛酈");
		gotoxy(18, 19);
		puts("曳收收收收收收收收收收收收收收收收收收收收收收收收收收朽");
		gotoxy(21, 21);
		puts("嬪   | 酈爾萄 寞щ酈 ∟");
		gotoxy(21, 23);
		puts("嬴楚 | 酈爾萄 寞щ酈 ⊿");
		gotoxy(21, 25);
		puts("�挫� | 酈爾萄 縛攪酈");
	}
		break;
	// 詭檣�飛� - 煎斜檣瞪 臢蝶お 轎溘
	case 3:
	{
		gotoxy(56, 19);
		puts("煎斜檣");
		gotoxy(56, 21);
		puts("�蛾灠㊣�");
		gotoxy(56, 23);
		puts("楨韁�飛�");
		gotoxy(56, 25);
		puts("啪歜謙猿");
	}
		break;
	// 詭檣�飛� - 煎斜檣�� 臢蝶お 轎溘
	case 4:
	{
		gotoxy(56, 19);
		puts("啪歜衛濛");
		gotoxy(56, 21);
		puts("鼻薄");
		gotoxy(56, 23);
		puts("楨韁�挫�");
		gotoxy(56, 25);
		puts("啪歜謙猿");
		gotoxy(0, 29);
		printf("煎斜檣 嶸盪: %s", user_id);
	}
		break;
	// 煎斜檣 �飛� - �飛� 雖辦晦蒂 嬪и 奢寥 轎溘
	case 5:
	{
		gotoxy(39, 18);
		printf("                            ");
		gotoxy(39, 20);
		printf("                            ");
		gotoxy(39, 22);
		printf("                            ");
		gotoxy(39, 24);
		printf("                            ");
		cursor(1);
	}
		break;
	// 楨韁�飛� - 綠煎斜檣 鼻鷓 Щ溯歜 轎溘
	case 6:
	{
		gotoxy(2, 1);
		puts("旨收收收收收有收收收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
		for (int i = 2; i < 27; i++)
		{
			gotoxy(2, i);
			puts("早");
			gotoxy(8, i);
			puts("早");
			gotoxy(30, i);
			puts("早");
			gotoxy(50, i);
			puts("早");
			gotoxy(96, i);
			puts("早");
		}
		for (int i = 3; i < 27; i += 2)
		{
			gotoxy(3, i);
			puts("收收收收收朱");
			gotoxy(9, i);
			puts("收收收收收收收收收收收收收收收收收收收收收朱");
			gotoxy(31, i);
			puts("收收收收收收收收收收收收收收收收收收收朱收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收");
		}
		gotoxy(2, 27);
		puts("曲收收收收收朴收收收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");
	}
		break;
	// 楨韁�飛� - 綠煎斜檣 鼻鷓 臢蝶お 轎溘
	case 7:
	{
		gotoxy(4, 2);
		puts("牖嬪");
		gotoxy(18, 2);
		puts("檜葷");
		gotoxy(39, 2);
		puts("薄熱");
		gotoxy(68, 2);
		puts("餌辨 嬴檜蠱");
		gotoxy(74, 28);
		puts("楨韁�飛� 釭陛晦: ESC 酈");
	}
		break;
	// 楨韁�飛� - 煎斜檣 鼻鷓 Щ溯歜 轎溘
	case 8:
	{
		gotoxy(2, 1);
		puts("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
		for (int i = 2; i < 9; i++)
		{
			gotoxy(2, i);
			puts("早");
			gotoxy(96, i);
			puts("早");
		}
		for (int i = 2; i < 9; i++)
		{
			gotoxy(30, i);
			puts("早");
		}
		for (int i = 9; i < 27; i++)
		{
			gotoxy(2, i);
			puts("早");
			gotoxy(8, i);
			puts("早");
			gotoxy(30, i);
			puts("早");
			gotoxy(50, i);
			puts("早");
			gotoxy(96, i);
			puts("早");
		}
		gotoxy(2, 9);
		puts("曳收收收收收有收收收收收收收收收收收收收收收收收收收收收朱收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朽");
		for (int i = 11; i < 27; i += 2)
		{
			gotoxy(3, i);
			puts("收收收收收朱");
			gotoxy(9, i);
			puts("收收收收收收收收收收收收收收收收收收收收收朱");
			gotoxy(31, i);
			puts("收收收收收收收收收收收收收收收收收收收朱收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收");
		}
		gotoxy(2, 27);
		puts("曲收收收收收朴收收收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");
	}
		break;
	// 楨韁�飛� - 煎斜檣 鼻鷓 臢蝶お 轎溘
	case 9:
	{
		// 嶸盪 薑爾
		gotoxy(4, 3);
		puts("瞪癱晦");
		gotoxy(4, 5);
		puts("識憲 賅曄");
		gotoxy(4, 7);
		puts("堅嶸 儀鼻");
		gotoxy(33, 3);
		puts("檜葷");
		gotoxy(33, 5);
		puts("ん檣お");
		gotoxy(64, 3);
		puts("頂 牖嬪");
		gotoxy(64, 5);
		puts("譆堅薄熱");
		gotoxy(33, 7);
		puts("餌辨и 嬴檜蠱");
		// 牖嬪 葬蝶お
		gotoxy(4, 10);
		puts("牖嬪");
		gotoxy(18, 10);
		puts("檜葷");
		gotoxy(39, 10);
		puts("薄熱");
		gotoxy(68, 10);
		puts("餌辨 嬴檜蠱");
		gotoxy(74, 28);
		puts("楨韁�飛� 釭陛晦: ESC 酈");
	}
		break;
	// 鼻薄�飛� - Щ溯歜 轎溘
	case 10:
	{
		gotoxy(2, 1);
		puts("旨收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收收收有收收收收收收收收收有收收收收收收收有收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
		for (int i = 2; i < 24; i++)
		{
			gotoxy(2, i);
			puts("早");
			gotoxy(22, i);
			puts("早");
			gotoxy(36, i);
			puts("早");
			gotoxy(46, i);
			puts("早");
			gotoxy(54, i);
			puts("早");
			gotoxy(96, i);
			puts("早");
		}
		for (int i = 3; i < 24; i += 2)
		{
			gotoxy(2, i);
			puts("曳收收收收收收收收收收收收收收收收收收收");
			gotoxy(22, i);
			puts("朱收收收收收收收收收收收收收");
			gotoxy(36, i);
			puts("朱收收收收收收收收收");
			gotoxy(46, i);
			puts("朱收收收收收收收");
			gotoxy(54, i);
			puts("朽");
		}
		gotoxy(36, 23);
		puts("朴收收收收收收收收收");
		gotoxy(46, 23);
		puts("朴收收收收收收收");
		gotoxy(2, 24);
		puts("早");
		gotoxy(22, 24);
		puts("早");
		gotoxy(54, 24);
		puts("早");
		gotoxy(96, 24);
		puts("早");
		gotoxy(2, 25);
		puts("曲收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收朴收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");
	}
		break;
	// 鼻薄�飛� - 臢蝶お 轎溘
	case 11:
	{
		gotoxy(3, 26);
		puts("纂濰 嬴檜蠱擎 ж釭噶虜 模雖 陛棟 м棲棻. / 掘衙衛 晦襄 纂濰 嬴檜蠱擎 濠翕 っ衙 腌棲棻.");
		gotoxy(3, 28);
		puts("跡煙 檜翕: 寞щ酈 ∟ ⊿  ||  掘衙: 縛攪酈                                  鼻薄 釭陛晦: ESC 酈");
		gotoxy(11, 2);
		puts("о跡");
		gotoxy(28, 2);
		puts("陛問");
		gotoxy(39, 2);
		puts("爾嶸熱");
		gotoxy(49, 2);
		puts("摹鷗");
		gotoxy(5, 4);
		puts("儅貲 蹺陛");
		gotoxy(5, 6);
		puts("HP �蛹�");
		gotoxy(5, 8);
		puts("蹺陛 薄熱");
		gotoxy(5, 10);
		puts("說鬼 む檣お");
		gotoxy(5, 12);
		puts("だ嫌 む檣お");
		gotoxy(5, 14);
		puts("喻嫌 む檣お");
		gotoxy(5, 16);
		puts("說除 識憲");
		gotoxy(5, 18);
		puts("だ塢 識憲");
		gotoxy(5, 20);
		puts("喻塢 識憲");
		gotoxy(5, 22);
		puts("楨韁璽 紱嘐晦");
		gotoxy(5, 24);
		puts("爾嶸 ん檣お");
	}
		break;
	}
}