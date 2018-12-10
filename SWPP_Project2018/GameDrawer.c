#include"tetris.h"
void IntroDrawer()
{
	int x = 5;
	int y = 2;

	Gotoxy(x + 1, y + 0); printf("�١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١�");
	Gotoxy(x + 1, y + 2); printf("  ����  ����  ����  ����    ����  ���� \n"); Sleep(20);
	Gotoxy(x + 1, y + 3); printf("    ��    ��        ��    ��  ��      ��    ��      \n"); Sleep(20);
	Gotoxy(x + 1, y + 4); printf("    ��    ����    ��    ����      ��    ����  \n"); Sleep(20);
	Gotoxy(x + 1, y + 5); printf("    ��    ��        ��    ��  ��      ��        ��  \n"); Sleep(20);
	Gotoxy(x + 1, y + 6); printf("    ��    ����    ��    ��    ��  ����  ����  \n"); Sleep(20);
	Gotoxy(x + 1, y + 8); printf("�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�");

	Gotoxy(x + 1, y + 18); printf("---------------------- HOWTOPLAY ---------------------");
	Gotoxy(x + 1, y + 20); printf("[��] LEFT MOVE  [��] RIGHT MOVE  [SPC] HARD DROP");
	Gotoxy(x + 1, y + 22); printf("[��] DOWN MOVE  [��] ROTATE      [A] HOLD");
	Gotoxy(x + 1, y + 24); printf("------------------------------------------------------");

	Gotoxy(x + 2, 26 + y); printf("https://blog.naver.com/workend1998 // Make by ����ҳ�(DragBoy) ");

	while (1)
	{
		if (_kbhit()) // �Է��� ����������
			break;
		Gotoxy(x + 9, y + 13); printf("  >> PRESS ANY BUTTON <<  "); Sleep(200);
		Gotoxy(x + 9, y + 13); printf("                          "); Sleep(200);
	}

	while (_kbhit()) // ���� �����
		_getch();

	system("cls"); // ȭ�� �����
}


void PrintGameBoard() // ������ ���
{
	for (int y = 0; y < SIZE_Y; y++)
	{
		for (int x = 0; x < SIZE_X; x++)
		{
			if (copyboard[y][x] != realboard[y][x]) // ���󺸵�� ī�Ǹ� ��, ���� �ٸ��� �����ؼ� ���
			{
				realboard[y][x] = copyboard[y][x];
				switch (realboard[y][x])
				{
				case EMPTY:
					Gotoxy(x + SIZE_X_ADJ, y + SIZE_Y_ADJ);
					printf(" ");
					break;

				case MBLOCK:
					Gotoxy(x + SIZE_X_ADJ, y + SIZE_Y_ADJ);
					printf("��");
					break;

				case OVERLINE:
					Gotoxy(x + SIZE_X_ADJ, y + SIZE_Y_ADJ);
					printf(". ");
					break;

				case SBLOCK:
					Gotoxy(x + SIZE_X_ADJ, y + SIZE_Y_ADJ);
					printf("��");
					break;

				case WALL:
					Gotoxy(x + SIZE_X_ADJ, y + SIZE_Y_ADJ);
					printf("��");
					break;

				case FBLOCK:
					Gotoxy(x + SIZE_X_ADJ, y + SIZE_Y_ADJ);
					printf("��");
					break;

				case EBLOCK:
					Gotoxy(x + SIZE_X_ADJ, y + SIZE_Y_ADJ);
					printf("��");
					break;
				}
				if (y == 2 && x != 0 && x != SIZE_X - 1 && copyboard[y][x] == EMPTY)
					copyboard[y][x] = OVERLINE; //���������� �������� �ٽ� �׸���

			}
		}
	}
}

void UIDrawer() // UI�� �׸��ϴ�.
{

	int x = 2, y = 2;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	Gotoxy(2 + x, y); printf("[HOLD]"); // Hold ���ĭ
	Gotoxy(x, 1 + y); printf("��");
	Gotoxy(6 + x, 1 + y); printf("��");
	Gotoxy(x, 6 + y); printf("��");
	Gotoxy(6 + x, 6 + y); printf("��");

	Gotoxy(23 + x, y); printf("[NEXT]"); // 1�� ���ĭ
	Gotoxy(21 + x, 1 + y); printf("��");
	Gotoxy(27 + x, 1 + y); printf("��");
	Gotoxy(21 + x, 6 + y); printf("��");
	Gotoxy(27 + x, 6 + y); printf("��");

	Gotoxy(21 + x, 7 + y); printf("��"); // 2�� ���ĭ
	Gotoxy(27 + x, 7 + y); printf("��");
	Gotoxy(21 + x, 11 + y); printf("��");
	Gotoxy(27 + x, 11 + y); printf("��");


	Gotoxy(21 + x, 12 + y); printf("��"); // 3�� ���ĭ
	Gotoxy(27 + x, 12 + y); printf("��");
	Gotoxy(21 + x, 15 + y); printf("��");
	Gotoxy(27 + x, 15 + y); printf("��");


	Gotoxy(21 + x, 17 + y); printf(" [ BESTSCORE ]: ");
	Gotoxy(21 + x, 19 + y); printf(" [ YOURSCORE ]: ");
	Gotoxy(21 + x, 21 + y); printf(" [   LEVEL   ]: ");
	Gotoxy(21 + x, 23 + y); printf(" [  DESTROY  ]: ");

	Gotoxy(x + 5, 26 + y); printf("https://blog.naver.com/workend1998 // Make by ����ҳ�(DragBoy) ");


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	Gotoxy(x - 1, 8 + y); printf(" - How TO PLAY -  ");
	Gotoxy(x - 1, 10 + y); printf("[����] :    MOVE  ");
	Gotoxy(x - 1, 14 + y); printf("[��] :    ROTATE");
	Gotoxy(x - 1, 12 + y); printf("[��] : SOFT DROP ");
	Gotoxy(x - 1, 16 + y); printf("[SPC] :HARD DROP");
	Gotoxy(x - 1, 18 + y); printf("[A] :       HOLD");
	Gotoxy(x - 1, 20 + y); printf("[P] :      PAUSE");
	Gotoxy(x - 1, 22 + y); printf("[ESC] :     EXIT");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

}
void NextBlockDrawer()// ��������� �׸��ϴ�.
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (blocks[block_typeNext_1][0][y][x] == 1) // Next Block_1 �׸���
			{

				Gotoxy(24 + x, 4 + y);
				printf("��");
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				Gotoxy(24 + x, 4 + y);
				printf(" ");
			}

			if (blocks[block_typeNext_2][0][y][x] == 1) // Next Block_2 �׸���
			{

				Gotoxy(24 + x, 9 + y);
				printf("��");
			}
			else
			{

				Gotoxy(24 + x, 9 + y);
				printf(" ");
			}

			if (blocks[block_typeNext_3][0][y][x] == 1) // Next Block_3 �׸���
			{
				Gotoxy(24 + x, 14 + y);
				printf("��");
			}
			else
			{
				Gotoxy(24 + x, 14 + y);
				printf(" ");
			}
		}
	}

}

void HoldBlockDrawer()
{
	if (holdOn == 0) // Ȧ�带 ��������� ������ ����������
		return;

	for (int y = 0; y < 4; y++) // Ȧ�� ��� �׸���
	{
		for (int x = 0; x < 4; x++)
		{
			if (blocks[block_typeHold][0][y][x] == 1)
			{
				Gotoxy(3 + x, 4 + y);
				printf("��");
			}
			else
			{
				Gotoxy(3 + x, 4 + y);
				printf(" ");
			}
		}
	}
}

void HideDrawer()
{
	for (int y = 0; y < SIZE_Y - 1; y++) // ���� ���� ������
	{
		for (int x = 1; x < SIZE_X - 1; x++)
		{
			Gotoxy(x + SIZE_X_ADJ, y + SIZE_Y_ADJ);
			printf(" ");
		}
	}

	for (int y = 0; y < 4; y++) // Ȧ�� ��� ���� ������
	{
		for (int x = 0; x < 6; x++)
		{
			Gotoxy(3 + x, 4 + y);
			printf(" ");
		}
	}

	for (int y = 0; y < 4; y++) // 1�� ��� ���� ������
	{
		for (int x = 0; x < 6; x++)
		{
			Gotoxy(24 + x, 4 + y);
			printf(" ");
		}
	}

	for (int y = 0; y < 3; y++) // 2�� ��� ���� ������
	{
		for (int x = 0; x < 6; x++)
		{
			Gotoxy(24 + x, 10 + y);
			printf(" ");
		}
	}

	for (int y = 0; y < 2; y++) // 3�� ��� ���� ������
	{
		for (int x = 0; x < 6; x++)
		{
			Gotoxy(24 + x, 15 + y);
			printf(" ");
		}
	}

}

void PauseDrawer()
{
	HideDrawer(); // ���� �� ��� ��� �����
	Gotoxy(13, 14); printf("  [ PAUSE ] ");
	Gotoxy(11, 16); printf("  PRESS ANY BUTTON ");

	EndPauseManeger(); // ���� ����
	NextBlockDrawer(); // ������� �ٽ�ǥ��
	HoldBlockDrawer(); // Ȧ���� �ٽ�ǥ��

	Gotoxy(13, 14); printf("                   ");
	Gotoxy(11, 16); printf("                   ");

	ResetRealBoard(); // ���� ������ �ʱ�ȭ
}

void GameOverDrawer() // ���� ����ȭ���� �׸�
{
	HideDrawer(); // ���� �� ��� ��� �����

	if (bestscoreFlag == 1)
	{
		Gotoxy(11, 12); printf(" �١�BestScore�ڡ�");
		bestscoreFlag = 0;
	}

	Gotoxy(11, 14); printf("  [ ��GameOver�� ] ");
	Gotoxy(11, 16); printf("  PRESS ANY BUTTON ");

	EndPauseManeger(); // ���� ����
	Gotoxy(12, 12); printf("                     ");

	NextBlockDrawer(); // ������� �ٽ�ǥ��
	HoldBlockDrawer(); // Ȧ���� �ٽ�ǥ��

	Gotoxy(11, 14); printf("                   ");
	Gotoxy(11, 16); printf("                   ");
}

void WriteScore() // ���ھ� ǥ��
{
	Gotoxy(31, 19); printf("                   ");
	Gotoxy(31, 21); printf("                   ");
	Gotoxy(31, 23); printf("                   ");
	Gotoxy(31, 25); printf("                   ");

	Gotoxy(31, 19); printf("%d", bestscore);
	Gotoxy(31, 21); printf("%d", yourscore);
	Gotoxy(31, 23); printf("%d", game_level);
	Gotoxy(31, 25); printf("%d", deleteline_count);
}

void GameEndDrawer()
{
	for (int y = SIZE_Y; y > 0; y--)
	{
		Sleep(60);
		for (int x = 0; x < SIZE_X; x++)
		{
			if (copyboard[y][x] == FBLOCK)
				copyboard[y][x] = EBLOCK;
		}
		PrintGameBoard(); // ������ ���
		Sleep(20);
	}
	Sleep(200);
}