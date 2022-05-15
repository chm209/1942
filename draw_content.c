#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void draw_content(int screen_num)
{
	switch (screen_num)
	{
	// ¸ÞÀÎÈ­¸é - µµÆ® Ãâ·Â
	case 0:
		system("cls");
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 100; j += 2)
			{
				gotoxy(j, i);
				printf("¤ý");
				// puts ´ë½Å printf¸¦ »ç¿ëÇÑ ÀÌÀ¯
				// puts´Â ¹®ÀÚ¿­¸¸ Ã³¸®ÇÏ±â ¶§¹®¿¡ ¼Óµµ°¡ ºü¸¥ ´ë½Å °³Çàµµ ÇØ¹ö¸®±â ¶§¹®¿¡
				// for¹®À¸·Î ÇÁ·¹ÀÓÀ» ±×¸±¶§ È­¸éÀ» ¹þ¾î³ª¹ö¸®´Â ¹®Á¦°¡ ¹ß»ýÇÑ´Ù.
				// ³¹°³·Î Ãâ·ÂÇØ¼­ gotoxy·Î ÄÁÆ®·ÑÇÏ¸é »ó°ü¾øÁö¸¸
				// for¹®À¸·Î Ãâ·ÂÇÒ¶§´Â printf¾²´Â°Ô ÁÁ´Ù.
			}
		}
		break;
	// ¸ÞÀÎÈ­¸é - 1942 ¼ýÀÚ Ãâ·Â
	case 1:
	{
		// 1
		gotoxy(24, 3);
		puts("¡Ü¡Ü");
		gotoxy(22, 4);
		puts("¡Ü¡Ü¡Ü");
		gotoxy(20, 5);
		puts("¡Ü¡Ü¡Ü¡Ü");
		gotoxy(24, 6);
		puts("¡Ü¡Ü");
		gotoxy(24, 7);
		puts("¡Ü¡Ü");
		gotoxy(24, 8);
		puts("¡Ü¡Ü");
		gotoxy(24, 9);
		puts("¡Ü¡Ü");
		gotoxy(20, 10);
		puts("¡Ü¡Ü¡Ü¡Ü¡Ü¡Ü");
		gotoxy(20, 11);
		puts("¡Ü¡Ü¡Ü¡Ü¡Ü¡Ü");
		// 9
		gotoxy(38, 3);
		puts("¡Ü¡Ü¡Ü");
		gotoxy(36, 4);
		puts("¡Ü");
		gotoxy(44, 4);
		puts("¡Ü");
		gotoxy(36, 5);
		puts("¡Ü");
		gotoxy(44, 5);
		puts("¡Ü");
		gotoxy(36, 6);
		puts("¡Ü");
		gotoxy(44, 6);
		puts("¡Ü");
		gotoxy(38, 7);
		puts("¡Ü¡Ü¡Ü¡Ü");
		gotoxy(42, 8);
		puts("¡Ü¡Ü");
		gotoxy(42, 9);
		puts("¡Ü¡Ü");
		gotoxy(42, 10);
		puts("¡Ü¡Ü");
		gotoxy(42, 11);
		puts("¡Ü¡Ü");
		// 4
		gotoxy(60, 3);
		puts("¡Ü");
		gotoxy(58, 4);
		puts("¡Ü¡Ü");
		gotoxy(56, 5);
		puts("¡Ü");
		gotoxy(60, 5);
		puts("¡Ü");
		gotoxy(54, 6);
		puts("¡Ü");
		gotoxy(60, 6);
		puts("¡Ü");
		gotoxy(52, 7);
		puts("¡Ü");
		gotoxy(60, 7);
		puts("¡Ü");
		gotoxy(50, 8);
		puts("¡Ü¡Ü¡Ü¡Ü¡Ü¡Ü¡Ü");
		gotoxy(60, 9);
		puts("¡Ü");
		gotoxy(60, 10);
		puts("¡Ü");
		gotoxy(60, 11);
		puts("¡Ü");
		// 2
		gotoxy(70, 3);
		puts("¡Ü¡Ü¡Ü¡Ü");
		gotoxy(68, 4);
		puts("¡Ü");
		gotoxy(78, 4);
		puts("¡Ü");
		gotoxy(68, 5);
		puts("¡Ü");
		gotoxy(78, 5);
		puts("¡Ü");
		gotoxy(76, 6);
		puts("¡Ü");
		gotoxy(74, 7);
		puts("¡Ü");
		gotoxy(72, 8);
		puts("¡Ü");
		gotoxy(70, 9);
		puts("¡Ü");
		gotoxy(68, 10);
		puts("¡Ü");
		gotoxy(68, 11);
		puts("¡Ü¡Ü¡Ü¡Ü¡Ü¡Ü");
		}
		break;
	// ¸ÞÀÎÈ­¸é - Á¶ÀÛÅ° ÇÁ·¹ÀÓ, ÅØ½ºÆ® Ãâ·Â
	case 2:
	{
		gotoxy(18, 17);
		puts("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯");
		gotoxy(18, 18);
		puts("¦­                          ¦­");
		gotoxy(18, 19);
		puts("¦­                          ¦­");
		gotoxy(18, 20);
		puts("¦­                          ¦­");
		gotoxy(18, 21);
		puts("¦­                          ¦­");
		gotoxy(18, 22);
		puts("¦­                          ¦­");
		gotoxy(18, 23);
		puts("¦­                          ¦­");
		gotoxy(18, 24);
		puts("¦­                          ¦­");
		gotoxy(18, 25);
		puts("¦­                          ¦­");
		gotoxy(18, 26);
		puts("¦­                          ¦­");
		gotoxy(18, 27);
		puts("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");
		gotoxy(21, 18);
		puts("¸ÞÀÎÈ­¸é Á¶ÀÛÅ°");
		gotoxy(18, 19);
		puts("¦²¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦´");
		gotoxy(21, 21);
		puts("À§   | Å°º¸µå ¹æÇâÅ° ¡è");
		gotoxy(21, 23);
		puts("¾Æ·¡ | Å°º¸µå ¹æÇâÅ° ¡é");
		gotoxy(21, 25);
		puts("È®ÀÎ | Å°º¸µå ¿£ÅÍÅ°");
	}
		break;
	// ¸ÞÀÎÈ­¸é - ·Î±×ÀÎÀü ÅØ½ºÆ® Ãâ·Â
	case 3:
	{
		gotoxy(56, 19);
		puts("·Î±×ÀÎ");
		gotoxy(56, 21);
		puts("È¸¿ø°¡ÀÔ");
		gotoxy(56, 23);
		puts("·©Å·È­¸é");
		gotoxy(56, 25);
		puts("°ÔÀÓÁ¾·á");
	}
		break;
	// ¸ÞÀÎÈ­¸é - ·Î±×ÀÎÈÄ ÅØ½ºÆ® Ãâ·Â
	case 4:
	{
		gotoxy(56, 19);
		puts("°ÔÀÓ½ÃÀÛ");
		gotoxy(56, 21);
		puts("»óÁ¡");
		gotoxy(56, 23);
		puts("·©Å·È®ÀÎ");
		gotoxy(56, 25);
		puts("°ÔÀÓÁ¾·á");
		gotoxy(0, 29);
		printf("·Î±×ÀÎ À¯Àú: %s", user_id);
	}
		break;
	// ·Î±×ÀÎ È­¸é - È­¸é Áö¿ì±â¸¦ À§ÇÑ °ø¹é Ãâ·Â
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
	// ·©Å·È­¸é - ºñ·Î±×ÀÎ »óÅÂ ÇÁ·¹ÀÓ Ãâ·Â
	case 6:
	{
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
	}
		break;
	// ·©Å·È­¸é - ºñ·Î±×ÀÎ »óÅÂ ÅØ½ºÆ® Ãâ·Â
	case 7:
	{
		gotoxy(4, 2);
		puts("¼øÀ§");
		gotoxy(18, 2);
		puts("ÀÌ¸§");
		gotoxy(39, 2);
		puts("Á¡¼ö");
		gotoxy(68, 2);
		puts("»ç¿ë ¾ÆÀÌÅÛ");
		gotoxy(74, 28);
		puts("·©Å·È­¸é ³ª°¡±â: ESC Å°");
	}
		break;
	// ·©Å·È­¸é - ·Î±×ÀÎ »óÅÂ ÇÁ·¹ÀÓ Ãâ·Â
	case 8:
	{
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
	}
		break;
	// ·©Å·È­¸é - ·Î±×ÀÎ »óÅÂ ÅØ½ºÆ® Ãâ·Â
	case 9:
	{
		// À¯Àú Á¤º¸
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
		puts("³» ¼øÀ§");
		gotoxy(64, 5);
		puts("ÃÖ°íÁ¡¼ö");
		gotoxy(33, 7);
		puts("»ç¿ëÇÑ ¾ÆÀÌÅÛ");
		// ¼øÀ§ ¸®½ºÆ®
		gotoxy(4, 10);
		puts("¼øÀ§");
		gotoxy(18, 10);
		puts("ÀÌ¸§");
		gotoxy(39, 10);
		puts("Á¡¼ö");
		gotoxy(68, 10);
		puts("»ç¿ë ¾ÆÀÌÅÛ");
		gotoxy(74, 28);
		puts("·©Å·È­¸é ³ª°¡±â: ESC Å°");
	}
		break;
	// »óÁ¡È­¸é - ÇÁ·¹ÀÓ Ãâ·Â
	case 10:
	{
		gotoxy(2, 1);
		puts("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦³¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦³¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦³¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦³¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯");
		for (int i = 2; i < 24; i++)
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
	}
		break;
	// »óÁ¡È­¸é - ÅØ½ºÆ® Ãâ·Â
	case 11:
	{
		gotoxy(3, 26);
		puts("Ä¡Àå ¾ÆÀÌÅÛÀº ÇÏ³ª¾¿¸¸ ¼ÒÁö °¡´É ÇÕ´Ï´Ù. / ±¸¸Å½Ã ±âÁ¸ Ä¡Àå ¾ÆÀÌÅÛÀº ÀÚµ¿ ÆÇ¸Å µË´Ï´Ù.");
		gotoxy(3, 28);
		puts("¸ñ·Ï ÀÌµ¿: ¹æÇâÅ° ¡è ¡é  ||  ±¸¸Å: ¿£ÅÍÅ°                                  »óÁ¡ ³ª°¡±â: ESC Å°");
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
	}
		break;
	}
}