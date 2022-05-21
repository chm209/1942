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
			}
		}
		break;
	// ¸ÞÀÎÈ­¸é - 1942 ¼ýÀÚ Ãâ·Â
	case 1:
	{
		// 1
		gotoxy(24, 3);
		printf("¡Ü¡Ü");
		gotoxy(22, 4);
		printf("¡Ü¡Ü¡Ü");
		gotoxy(20, 5);
		printf("¡Ü¡Ü¡Ü¡Ü");
		gotoxy(24, 6);
		printf("¡Ü¡Ü");
		gotoxy(24, 7);
		printf("¡Ü¡Ü");
		gotoxy(24, 8);
		printf("¡Ü¡Ü");
		gotoxy(24, 9);
		printf("¡Ü¡Ü");
		gotoxy(20, 10);
		printf("¡Ü¡Ü¡Ü¡Ü¡Ü¡Ü");
		gotoxy(20, 11);
		printf("¡Ü¡Ü¡Ü¡Ü¡Ü¡Ü");
		// 9
		gotoxy(38, 3);
		printf("¡Ü¡Ü¡Ü");
		gotoxy(36, 4);
		printf("¡Ü");
		gotoxy(44, 4);
		printf("¡Ü");
		gotoxy(36, 5);
		printf("¡Ü");
		gotoxy(44, 5);
		printf("¡Ü");
		gotoxy(36, 6);
		printf("¡Ü");
		gotoxy(44, 6);
		printf("¡Ü");
		gotoxy(38, 7);
		printf("¡Ü¡Ü¡Ü¡Ü");
		gotoxy(42, 8);
		printf("¡Ü¡Ü");
		gotoxy(42, 9);
		printf("¡Ü¡Ü");
		gotoxy(42, 10);
		printf("¡Ü¡Ü");
		gotoxy(42, 11);
		printf("¡Ü¡Ü");
		// 4
		gotoxy(60, 3);
		printf("¡Ü");
		gotoxy(58, 4);
		printf("¡Ü¡Ü");
		gotoxy(56, 5);
		printf("¡Ü");
		gotoxy(60, 5);
		printf("¡Ü");
		gotoxy(54, 6);
		printf("¡Ü");
		gotoxy(60, 6);
		printf("¡Ü");
		gotoxy(52, 7);
		printf("¡Ü");
		gotoxy(60, 7);
		printf("¡Ü");
		gotoxy(50, 8);
		printf("¡Ü¡Ü¡Ü¡Ü¡Ü¡Ü¡Ü");
		gotoxy(60, 9);
		printf("¡Ü");
		gotoxy(60, 10);
		printf("¡Ü");
		gotoxy(60, 11);
		printf("¡Ü");
		// 2
		gotoxy(70, 3);
		printf("¡Ü¡Ü¡Ü¡Ü");
		gotoxy(68, 4);
		printf("¡Ü");
		gotoxy(78, 4);
		printf("¡Ü");
		gotoxy(68, 5);
		printf("¡Ü");
		gotoxy(78, 5);
		printf("¡Ü");
		gotoxy(76, 6);
		printf("¡Ü");
		gotoxy(74, 7);
		printf("¡Ü");
		gotoxy(72, 8);
		printf("¡Ü");
		gotoxy(70, 9);
		printf("¡Ü");
		gotoxy(68, 10);
		printf("¡Ü");
		gotoxy(68, 11);
		printf("¡Ü¡Ü¡Ü¡Ü¡Ü¡Ü");
		}
		break;
	// ¸ÞÀÎÈ­¸é - Á¶ÀÛÅ° ÇÁ·¹ÀÓ, ÅØ½ºÆ® Ãâ·Â
	case 2:
	{
		gotoxy(18, 17);
		printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯");
		gotoxy(18, 18);
		printf("¦­                          ¦­");
		gotoxy(18, 19);
		printf("¦­                          ¦­");
		gotoxy(18, 20);
		printf("¦­                          ¦­");
		gotoxy(18, 21);
		printf("¦­                          ¦­");
		gotoxy(18, 22);
		printf("¦­                          ¦­");
		gotoxy(18, 23);
		printf("¦­                          ¦­");
		gotoxy(18, 24);
		printf("¦­                          ¦­");
		gotoxy(18, 25);
		printf("¦­                          ¦­");
		gotoxy(18, 26);
		printf("¦­                          ¦­");
		gotoxy(18, 27);
		printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");
		gotoxy(21, 18);
		printf("¸ÞÀÎÈ­¸é Á¶ÀÛÅ°");
		gotoxy(18, 19);
		printf("¦²¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦´");
		gotoxy(21, 21);
		printf("À§   | Å°º¸µå ¹æÇâÅ° ¡è");
		gotoxy(21, 23);
		printf("¾Æ·¡ | Å°º¸µå ¹æÇâÅ° ¡é");
		gotoxy(21, 25);
		printf("È®ÀÎ | Å°º¸µå ¿£ÅÍÅ°");
	}
		break;
	// ¸ÞÀÎÈ­¸é - ·Î±×ÀÎÀü ÅØ½ºÆ® Ãâ·Â
	case 3:
	{
		gotoxy(56, 19);
		printf("·Î±×ÀÎ");
		gotoxy(56, 21);
		printf("È¸¿ø°¡ÀÔ");
		gotoxy(56, 23);
		printf("·©Å·È­¸é");
		gotoxy(56, 25);
		printf("°ÔÀÓÁ¾·á");
	}
		break;
	// ¸ÞÀÎÈ­¸é - ·Î±×ÀÎÈÄ ÅØ½ºÆ® Ãâ·Â
	case 4:
	{
		gotoxy(56, 19);
		printf("°ÔÀÓ½ÃÀÛ");
		gotoxy(56, 21);
		printf("»óÁ¡");
		gotoxy(56, 23);
		printf("·©Å·È®ÀÎ");
		gotoxy(56, 25);
		printf("°ÔÀÓÁ¾·á");
		gotoxy(0, 29);
		printf("·Î±×ÀÎ À¯Àú: %s", user.id);
	}
		break;
	// ·Î±×ÀÎ È­¸é - È­¸é Áö¿ì±â¸¦ À§ÇÑ °ø¹é Ãâ·Â
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
	// ·©Å·È­¸é - ºñ·Î±×ÀÎ »óÅÂ ÇÁ·¹ÀÓ Ãâ·Â
	case 6:
	{
		gotoxy(2, 1);
		printf("¦®¦¬¦¬¦¬¦¬¦¬¦³¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦³¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦³¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯");
		for (int i = 2; i < 27; i++)
		{
			gotoxy(2, i);
			printf("¦­");
			gotoxy(8, i);
			printf("¦­");
			gotoxy(30, i);
			printf("¦­");
			gotoxy(50, i);
			printf("¦­");
			gotoxy(96, i);
			printf("¦­");
		}
		for (int i = 3; i < 27; i += 2)
		{
			gotoxy(3, i);
			printf("¦¬¦¬¦¬¦¬¦¬¦¶");
			gotoxy(9, i);
			printf("¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¶");
			gotoxy(31, i);
			printf("¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¶¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬");
		}
		gotoxy(2, 27);
		printf("¦±¦¬¦¬¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");
	}
		break;
	// ·©Å·È­¸é - ºñ·Î±×ÀÎ »óÅÂ ÅØ½ºÆ® Ãâ·Â
	case 7:
	{
		gotoxy(4, 2);
		printf("¼øÀ§");
		int colum = 4;
		for (int i = 1; i < 13; i++)
		{
			gotoxy(5, colum);
			printf("%2d", i);
			colum += 2;
		}
		gotoxy(18, 2);
		printf("ÀÌ¸§");
		gotoxy(39, 2);
		printf("Á¡¼ö");
		gotoxy(68, 2);
		printf("»ç¿ë ¾ÆÀÌÅÛ");
		gotoxy(74, 28);
		printf("·©Å·È­¸é ³ª°¡±â: ESC Å°");
	}
		break;
	// ·©Å·È­¸é - ·Î±×ÀÎ »óÅÂ ÇÁ·¹ÀÓ Ãâ·Â
	case 8:
	{
		gotoxy(2, 1);
		printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦³¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯");
		for (int i = 2; i < 9; i++)
		{
			gotoxy(2, i);
			printf("¦­");
			gotoxy(96, i);
			printf("¦­");
		}
		for (int i = 2; i < 9; i++)
		{
			gotoxy(30, i);
			printf("¦­");
		}
		for (int i = 9; i < 27; i++)
		{
			gotoxy(2, i);
			printf("¦­");
			gotoxy(8, i);
			printf("¦­");
			gotoxy(30, i);
			printf("¦­");
			gotoxy(50, i);
			printf("¦­");
			gotoxy(96, i);
			printf("¦­");
		}
		gotoxy(2, 9);
		printf("¦²¦¬¦¬¦¬¦¬¦¬¦³¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¶¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦³¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦´");
		for (int i = 11; i < 27; i += 2)
		{
			gotoxy(3, i);
			printf("¦¬¦¬¦¬¦¬¦¬¦¶");
			gotoxy(9, i);
			printf("¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¶");
			gotoxy(31, i);
			printf("¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¶¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬");
		}
		gotoxy(2, 27);
		printf("¦±¦¬¦¬¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");
	}
		break;
	// ·©Å·È­¸é - ·Î±×ÀÎ »óÅÂ ÅØ½ºÆ® Ãâ·Â
	case 9:
	{
		// À¯Àú Á¤º¸
		gotoxy(5, 3);
		printf("¡Ü ÀüÅõ±â: ");
		gotoxy(5, 5);
		printf("ÃÑ¾Ë ¸ð¾ç: ");
		gotoxy(5, 7);
		printf("°íÀ¯ »ö»ó: ");
		gotoxy(33, 3);
		printf("ÀÌ¸§");
		gotoxy(33, 5);
		printf("Æ÷ÀÎÆ®");
		gotoxy(64, 3);
		printf("ÃÖ°íÁ¡¼ö");
		gotoxy(33, 7);
		printf("»ç¿ëÇÑ ¾ÆÀÌÅÛ");
		// ¼øÀ§ ¸®½ºÆ®
		gotoxy(4, 10);
		printf("¼øÀ§");
		int colum = 12;
		for (int i = 1; i < 9; i++)
		{
			gotoxy(5, colum);
			printf("%d", i);
			colum += 2;
		}
		gotoxy(18, 10);
		printf("ÀÌ¸§");
		gotoxy(39, 10);
		printf("Á¡¼ö");
		gotoxy(68, 10);
		printf("»ç¿ë ¾ÆÀÌÅÛ");
		gotoxy(74, 28);
		printf("·©Å·È­¸é ³ª°¡±â: ESC Å°");
	}
		break;
	// »óÁ¡È­¸é - ÇÁ·¹ÀÓ Ãâ·Â
	case 10:
	{
		gotoxy(2, 1);
		printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦³¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦³¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦³¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦³¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯");
		for (int i = 2; i < 24; i++)
		{
			gotoxy(2, i);
			printf("¦­");
			gotoxy(22, i);
			printf("¦­");
			gotoxy(36, i);
			printf("¦­");
			gotoxy(46, i);
			printf("¦­");
			gotoxy(54, i);
			printf("¦­");
			gotoxy(96, i);
			printf("¦­");
		}
		for (int i = 3; i < 24; i += 2)
		{
			gotoxy(2, i);
			printf("¦²¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬");
			gotoxy(22, i);
			printf("¦¶¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬");
			gotoxy(36, i);
			printf("¦¶¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬");
			gotoxy(46, i);
			printf("¦¶¦¬¦¬¦¬¦¬¦¬¦¬¦¬");
			gotoxy(54, i);
			printf("¦´");
		}
		gotoxy(36, 23);
		printf("¦µ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬");
		gotoxy(46, 23);
		printf("¦µ¦¬¦¬¦¬¦¬¦¬¦¬¦¬");
		gotoxy(2, 24);
		printf("¦­");
		gotoxy(22, 24);
		printf("¦­");
		gotoxy(54, 24);
		printf("¦­");
		gotoxy(96, 24);
		printf("¦­");
		gotoxy(2, 25);
		printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");
	}
		break;
	// »óÁ¡È­¸é - ÅØ½ºÆ® Ãâ·Â
	case 11:
	{
		gotoxy(3, 26);
		printf("Ä¡Àå ¾ÆÀÌÅÛÀº ÇÏ³ª¾¿¸¸ ¼ÒÁö °¡´É ÇÕ´Ï´Ù. / ±âÁ¸ Ä¡Àå ¾ÆÀÌÅÛÀº 60%% °¡°Ý¿¡ ÀÚµ¿ ÆÇ¸Å µË´Ï´Ù.");
		gotoxy(3, 28);
		printf("¸ñ·Ï ÀÌµ¿: ¹æÇâÅ° ¡è ¡é  ||  ±¸¸Å: ¿£ÅÍÅ°                                  »óÁ¡ ³ª°¡±â: ESC Å°");
		gotoxy(11, 2);
		printf("Ç×¸ñ");
		gotoxy(28, 2);
		printf("°¡°Ý");
		gotoxy(39, 2);
		printf("º¸À¯¼ö");
		gotoxy(49, 2);
		printf("¼±ÅÃ");
		gotoxy(5, 4);
		printf("»ý¸í Ãß°¡");
		gotoxy(5, 6);
		printf("HP È¸º¹");
		gotoxy(5, 8);
		printf("Ãß°¡ Á¡¼ö");
		gotoxy(5, 10);
		printf("»¡°­ ÆäÀÎÆ®");
		gotoxy(5, 12);
		printf("ÆÄ¶û ÆäÀÎÆ®");
		gotoxy(5, 14);
		printf("³ë¶û ÆäÀÎÆ®");
		gotoxy(5, 16);
		printf("»¡°£ ÃÑ¾Ë");
		gotoxy(5, 18);
		printf("ÆÄ¶õ ÃÑ¾Ë");
		gotoxy(5, 20);
		printf("³ë¶õ ÃÑ¾Ë");
		gotoxy(5, 22);
		printf("·©Å·Ã¢ ²Ù¹Ì±â");
		gotoxy(5, 24);
		printf("º¸À¯ Æ÷ÀÎÆ®");
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
		printf("±¸¸Å ºÒ°¡");
		set_color(12);
		gotoxy(59, 8);
		printf("Æ÷ÀÎÆ®°¡ ºÎÁ·ÇÕ´Ï´Ù.");
		set_color(15);
	}
		break;
	}
}