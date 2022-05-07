#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void draw_content(int screen_num)
{
	switch (screen_num)
	{
	// ¸ÞÀÎ È­¸é
	case 0:
		system("cls");
		// 1
		gotoxy(25, 3);
		puts("¢È¢È");
		gotoxy(23, 4);
		puts("¢É¢È¢È");
		gotoxy(21, 5);
		puts("¢É¢É¢È¢È");
		gotoxy(25, 6);
		puts("¢È¢È");
		gotoxy(25, 7);
		puts("¢È¢È");
		gotoxy(25, 8);
		puts("¢È¢È");
		gotoxy(25, 9);
		puts("¢È¢È");
		gotoxy(21, 10);
		puts("¢Ç¢Ç¢È¢È¢Ç¢Ç");
		gotoxy(21, 11);
		puts("¢Ç¢Ç¢È¢È¢Ç¢Ç");
		// 9
		gotoxy(35, 3);
		puts("¢Ì¢Ç¢Ç¢È¢È");
		gotoxy(35, 4);
		puts("¢È    ¢È¢È");
		gotoxy(35, 5);
		puts("¢È    ¢È¢È");
		gotoxy(35, 6);
		puts("¢Ì¢Ç¢Ç¢È¢È");
		gotoxy(41, 7);
		puts("¢È¢È");
		gotoxy(41, 8);
		puts("¢È¢È");
		gotoxy(41, 9);
		puts("¢È¢È");
		gotoxy(41, 10);
		puts("¢È¢È");
		gotoxy(41, 11);
		puts("¢È¢È");
		// 4
		gotoxy(49, 3);
		puts("¢È    ¢È¢È");
		gotoxy(49, 4);
		puts("¢È    ¢È¢È");
		gotoxy(49, 5);
		puts("¢È    ¢È¢È");
		gotoxy(49, 6);
		puts("¢È    ¢È¢È");
		gotoxy(49, 7);
		puts("¢Ì¢Ç¢Ç¢È¢È¢Ç¢Ç");
		gotoxy(55, 8);
		puts("¢È¢È");
		gotoxy(55, 9);
		puts("¢È¢È");
		gotoxy(55, 10);
		puts("¢È¢È");
		gotoxy(55, 11);
		puts("¢È¢È");
		// 2
		gotoxy(65, 3);
		puts("¢Ç¢Ç¢Ç¢Ç¢Ç¢È¢Ì");
		gotoxy(65, 4);
		puts("¢Ç¢Ç¢Ç¢Ç¢Ç¢È¢È");
		gotoxy(75, 5);
		puts("¢È¢È");
		gotoxy(75, 6);
		puts("¢È¢È");
		gotoxy(65, 7);
		puts("¢Ì¢È¢Ç¢Ç¢Ç¢È¢È");
		gotoxy(65, 8);
		puts("¢È¢È¢Ç¢Ç¢Ç¢È¢Ì");
		gotoxy(65, 9);
		puts("¢È¢È");
		gotoxy(65, 10);
		puts("¢È¢È");
		gotoxy(65, 11);
		puts("¢Ì¢È¢Ç¢Ç¢Ç¢Ç¢Ç");
		gotoxy(51, 13);
		puts("1705095 ÀÌÃ¢¹Î ±â¸» ÇÁ·ÎÁ§Æ®");
		gotoxy(2, 29);
		puts("Á¶ÀÛ¹æ¹ý: ¹æÇâ ¡è ¡é ¡ç ¡æ ¼±ÅÃ ENTER ¾ÆÀÌÅÛ Z X");
		break;
	// °ÔÀÓ È­¸é
	case 1:
		for (int i = 0; i <= 30; i += 1)
		{
			gotoxy(4, i);
			puts(":");
			gotoxy(56, i);
			puts(":");
		}
		break;
	// pause È­¸é
	case 2:
		gotoxy(16, 10);
		puts("PAUSE");
		gotoxy(15, 11);
		puts("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");
		gotoxy(15, 12);
		puts("¦¢  °ÔÀÓÀ» Á¾·á ÇÏ½Ã°Ú½À´Ï±î?  ¦¢");
		gotoxy(15, 13);
		puts("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©");
		gotoxy(15, 14);
		puts("¦¢   ¿¹ (  )  ¦¢  ¾Æ´Ï¿ä (  )   ¦¢");
		gotoxy(15, 15);
		puts("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");
		break;
	// »óÁ¡ È­¸é
	case 3:
		gotoxy(2, 1);
		puts("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦³¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦³¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦³¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦³¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯");
		for (int i = 2; i < 24; i ++)
		{
			gotoxy(2, i);
			puts("¦­");
			gotoxy(22, i);
			puts("¦­");
			gotoxy(36, i);
			puts("¦­");
			gotoxy(46, i);
			puts("¦­");
			gotoxy(54, i);
			puts("¦­");
			gotoxy(96, i);
			puts("¦­");
		}
		for (int i = 3; i < 24; i += 2)
		{
			gotoxy(2, i);
			puts("¦²¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬");
			gotoxy(22, i);
			puts("¦¶¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬");
			gotoxy(36, i);
			puts("¦¶¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬");
			gotoxy(46, i);
			puts("¦¶¦¬¦¬¦¬¦¬¦¬¦¬¦¬");
			gotoxy(54, i);
			puts("¦´");
		}
		gotoxy(36, 23);
		puts("¦µ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬");
		gotoxy(46, 23);
		puts("¦µ¦¬¦¬¦¬¦¬¦¬¦¬¦¬");
		gotoxy(2, 24);
		puts("¦­");
		gotoxy(22, 24);
		puts("¦­");
		gotoxy(54, 24);
		puts("¦­");
		gotoxy(96, 24);
		puts("¦­");
		gotoxy(2, 25);
		puts("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");
		break;
	case 4:
		gotoxy(3, 26);
		puts("Ä¡Àå ¾ÆÀÌÅÛÀº ÇÏ³ª¾¿¸¸ ¼ÒÁö °¡´É ÇÕ´Ï´Ù. / ±¸¸Å½Ã ±âÁ¸ Ä¡Àå ¾ÆÀÌÅÛÀº ÀÚµ¿ ÆÇ¸Å µË´Ï´Ù.");
		gotoxy(3, 28);
		puts("¸ñ·Ï ÀÌµ¿: ¹æÇâÅ° ¡è ¡é  ||  ±¸¸Å: ENTER                                   »óÁ¡ ³ª°¡±â: ESC Å°");
		gotoxy(11, 2);
		puts("Ç×¸ñ");
		gotoxy(28, 2);
		puts("°¡°Ý");
		gotoxy(39, 2);
		puts("º¸À¯¼ö");
		gotoxy(49, 2);
		puts("¼±ÅÃ");
		gotoxy(5, 4);
		puts("»ý¸í Ãß°¡");
		gotoxy(5, 6);
		puts("HP È¸º¹");
		gotoxy(5, 8);
		puts("Ãß°¡ Á¡¼ö");
		gotoxy(5, 10);
		puts("»¡°­ ÆäÀÎÆ®");
		gotoxy(5, 12);
		puts("ÆÄ¶û ÆäÀÎÆ®");
		gotoxy(5, 14);
		puts("³ë¶û ÆäÀÎÆ®");
		gotoxy(5, 16);
		puts("»¡°£ ÃÑ¾Ë");
		gotoxy(5, 18);
		puts("ÆÄ¶õ ÃÑ¾Ë");
		gotoxy(5, 20);
		puts("³ë¶õ ÃÑ¾Ë");
		gotoxy(5, 22);
		puts("·©Å·Ã¢ ²Ù¹Ì±â");
		gotoxy(5, 24);
		puts("º¸À¯ Æ÷ÀÎÆ®");
		break;
	case 5:
		gotoxy(2, 1);
		puts("¦®¦¬¦¬¦¬¦¬¦¬¦³¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦³¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦³¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯");
		for (int i = 2; i < 27; i++)
		{
			gotoxy(2, i);
			puts("¦­");
			gotoxy(8, i);
			puts("¦­");
			gotoxy(30, i);
			puts("¦­");
			gotoxy(50, i);
			puts("¦­");
			gotoxy(96, i);
			puts("¦­");
		}
		for (int i = 3; i < 27; i += 2)
		{
			gotoxy(3, i);
			puts("¦¬¦¬¦¬¦¬¦¬¦¶");
			gotoxy(9, i);
			puts("¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¶");
			gotoxy(31, i);
			puts("¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¶¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬");
		}
		gotoxy(2, 27);
		puts("¦±¦¬¦¬¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");
		break;
	case 6:
		gotoxy(4, 2);
		puts("¼øÀ§");
		gotoxy(18, 2);
		puts("ÀÌ¸§");
		gotoxy(39, 2);
		puts("Á¡¼ö");
		gotoxy(68, 2);
		puts("»ç¿ë ¾ÆÀÌÅÛ");
		gotoxy(3, 28);
		puts("ÀüÃ¼·©Å· - ºñ·Î±×ÀÎ");
		gotoxy(76, 28);
		puts("·©Å·Ã¢ ³ª°¡±â: ESC Å°");
		break;
	case 7:
		gotoxy(2, 1);
		puts("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦³¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯");
		for (int i = 2; i < 9; i++)
		{
			gotoxy(2, i);
			puts("¦­");
			gotoxy(96, i);
			puts("¦­");
		}
		for (int i = 2; i < 9; i++)
		{
			gotoxy(30, i);
			puts("¦­");
		}
		for (int i = 9; i < 27; i++)
		{
			gotoxy(2, i);
			puts("¦­");
			gotoxy(8, i);
			puts("¦­");
			gotoxy(30, i);
			puts("¦­");
			gotoxy(50, i);
			puts("¦­");
			gotoxy(96, i);
			puts("¦­");
		}
		gotoxy(2, 9);
		puts("¦²¦¬¦¬¦¬¦¬¦¬¦³¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¶¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦³¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦´");
		for (int i = 11; i < 27; i += 2)
		{
			gotoxy(3, i);
			puts("¦¬¦¬¦¬¦¬¦¬¦¶");
			gotoxy(9, i);
			puts("¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¶");
			gotoxy(31, i);
			puts("¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¶¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬");
		}
		gotoxy(2, 27);
		puts("¦±¦¬¦¬¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");
		break;
	case 8:
		gotoxy(4, 3);
		puts("ÀüÅõ±â");
		gotoxy(4, 5);
		puts("ÃÑ¾Ë ¸ð¾ç");
		gotoxy(4, 7);
		puts("°íÀ¯ »ö»ó");
		gotoxy(33, 3);
		puts("ÀÌ¸§");
		gotoxy(33, 5);
		puts("Æ÷ÀÎÆ®");
		gotoxy(64, 3);
		puts("³» ·©Å·");
		gotoxy(64, 5);
		puts("ÃÖ°íÁ¡¼ö");
		gotoxy(33, 7);
		puts("»ç¿ëÇÑ ¾ÆÀÌÅÛ");

		gotoxy(4, 10);
		puts("¼øÀ§");
		gotoxy(18, 10);
		puts("ÀÌ¸§");
		gotoxy(39, 10);
		puts("Á¡¼ö");
		gotoxy(68, 10);
		puts("»ç¿ë ¾ÆÀÌÅÛ");
		gotoxy(3, 28);
		puts("ÀüÃ¼·©Å· - ·Î±×ÀÎ");
		gotoxy(76, 28);
		puts("·©Å·Ã¢ ³ª°¡±â: ESC Å°");
		break;
	}
}