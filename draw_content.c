#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void draw_content(int screen_num)
{
	switch (screen_num)
	{
	// 詭檣 �飛�
	case 0:
		system("cls");
		// 1
		gotoxy(25, 3);
		puts("〦〦");
		gotoxy(23, 4);
		puts("〧〦〦");
		gotoxy(21, 5);
		puts("〧〧〦〦");
		gotoxy(25, 6);
		puts("〦〦");
		gotoxy(25, 7);
		puts("〦〦");
		gotoxy(25, 8);
		puts("〦〦");
		gotoxy(25, 9);
		puts("〦〦");
		gotoxy(21, 10);
		puts("〥〥〦〦〥〥");
		gotoxy(21, 11);
		puts("〥〥〦〦〥〥");
		// 9
		gotoxy(35, 3);
		puts("十〥〥〦〦");
		gotoxy(35, 4);
		puts("〦    〦〦");
		gotoxy(35, 5);
		puts("〦    〦〦");
		gotoxy(35, 6);
		puts("十〥〥〦〦");
		gotoxy(41, 7);
		puts("〦〦");
		gotoxy(41, 8);
		puts("〦〦");
		gotoxy(41, 9);
		puts("〦〦");
		gotoxy(41, 10);
		puts("〦〦");
		gotoxy(41, 11);
		puts("〦〦");
		// 4
		gotoxy(49, 3);
		puts("〦    〦〦");
		gotoxy(49, 4);
		puts("〦    〦〦");
		gotoxy(49, 5);
		puts("〦    〦〦");
		gotoxy(49, 6);
		puts("〦    〦〦");
		gotoxy(49, 7);
		puts("十〥〥〦〦〥〥");
		gotoxy(55, 8);
		puts("〦〦");
		gotoxy(55, 9);
		puts("〦〦");
		gotoxy(55, 10);
		puts("〦〦");
		gotoxy(55, 11);
		puts("〦〦");
		// 2
		gotoxy(65, 3);
		puts("〥〥〥〥〥〦十");
		gotoxy(65, 4);
		puts("〥〥〥〥〥〦〦");
		gotoxy(75, 5);
		puts("〦〦");
		gotoxy(75, 6);
		puts("〦〦");
		gotoxy(65, 7);
		puts("十〦〥〥〥〦〦");
		gotoxy(65, 8);
		puts("〦〦〥〥〥〦十");
		gotoxy(65, 9);
		puts("〦〦");
		gotoxy(65, 10);
		puts("〦〦");
		gotoxy(65, 11);
		puts("十〦〥〥〥〥〥");
		gotoxy(51, 13);
		puts("1705095 檜璽團 晦蜓 Щ煎薛お");
		gotoxy(2, 29);
		puts("褻濛寞徹: 寞щ ∟ ⊿ ∠ ⊥ 摹鷗 ENTER 嬴檜蠱 Z X");
		break;
	// 啪歜 �飛�
	case 1:
		for (int i = 0; i <= 30; i += 1)
		{
			gotoxy(4, i);
			puts(":");
			gotoxy(56, i);
			puts(":");
		}
		break;
	// pause �飛�
	case 2:
		gotoxy(16, 10);
		puts("PAUSE");
		gotoxy(15, 11);
		puts("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖");
		gotoxy(15, 12);
		puts("弛  啪歜擊 謙猿 ж衛啊蝗棲梱?  弛");
		gotoxy(15, 13);
		puts("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣");
		gotoxy(15, 14);
		puts("弛   蕨 (  )  弛  嬴棲蹂 (  )   弛");
		gotoxy(15, 15);
		puts("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎");
		break;
	// 鼻薄 �飛�
	case 3:
		gotoxy(2, 1);
		puts("旨收收收收收收收收收收收收收收收收收收收有收收收收收收收收收收收收收有收收收收收收收收收有收收收收收收收有收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬");
		for (int i = 2; i < 24; i ++)
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
		break;
	case 4:
		gotoxy(3, 26);
		puts("纂濰 嬴檜蠱擎 ж釭噶虜 模雖 陛棟 м棲棻. / 掘衙衛 晦襄 纂濰 嬴檜蠱擎 濠翕 っ衙 腌棲棻.");
		gotoxy(3, 28);
		puts("跡煙 檜翕: 寞щ酈 ∟ ⊿  ||  掘衙: ENTER                                   鼻薄 釭陛晦: ESC 酈");
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
		break;
	case 5:
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
		break;
	case 6:
		gotoxy(4, 2);
		puts("牖嬪");
		gotoxy(18, 2);
		puts("檜葷");
		gotoxy(39, 2);
		puts("薄熱");
		gotoxy(68, 2);
		puts("餌辨 嬴檜蠱");
		gotoxy(3, 28);
		puts("瞪羹楨韁 - 綠煎斜檣");
		gotoxy(76, 28);
		puts("楨韁璽 釭陛晦: ESC 酈");
		break;
	case 7:
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
		break;
	case 8:
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
		puts("頂 楨韁");
		gotoxy(64, 5);
		puts("譆堅薄熱");
		gotoxy(33, 7);
		puts("餌辨и 嬴檜蠱");

		gotoxy(4, 10);
		puts("牖嬪");
		gotoxy(18, 10);
		puts("檜葷");
		gotoxy(39, 10);
		puts("薄熱");
		gotoxy(68, 10);
		puts("餌辨 嬴檜蠱");
		gotoxy(3, 28);
		puts("瞪羹楨韁 - 煎斜檣");
		gotoxy(76, 28);
		puts("楨韁璽 釭陛晦: ESC 酈");
		break;
	}
}