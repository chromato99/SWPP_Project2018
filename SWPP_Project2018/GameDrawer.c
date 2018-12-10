#include"tetris.h"
void IntroDrawer()
{
	int x = 5;
	int y = 2;

	Gotoxy(x + 1, y + 0); printf("☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★");
	Gotoxy(x + 1, y + 2); printf("  ■■■  ■■■  ■■■  ■■■    ■■■  ■■■ \n"); Sleep(20);
	Gotoxy(x + 1, y + 3); printf("    ■    ■        ■    ■  ■      ■    ■      \n"); Sleep(20);
	Gotoxy(x + 1, y + 4); printf("    ■    ■■■    ■    ■■■      ■    ■■■  \n"); Sleep(20);
	Gotoxy(x + 1, y + 5); printf("    ■    ■        ■    ■  ■      ■        ■  \n"); Sleep(20);
	Gotoxy(x + 1, y + 6); printf("    ■    ■■■    ■    ■    ■  ■■■  ■■■  \n"); Sleep(20);
	Gotoxy(x + 1, y + 8); printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆");

	Gotoxy(x + 1, y + 18); printf("---------------------- HOWTOPLAY ---------------------");
	Gotoxy(x + 1, y + 20); printf("[◀] LEFT MOVE  [▶] RIGHT MOVE  [SPC] HARD DROP");
	Gotoxy(x + 1, y + 22); printf("[▼] DOWN MOVE  [▲] ROTATE      [A] HOLD");
	Gotoxy(x + 1, y + 24); printf("------------------------------------------------------");

	Gotoxy(x + 2, 26 + y); printf("https://blog.naver.com/workend1998 // Make by 여장소년(DragBoy) ");

	while (1)
	{
		if (_kbhit()) // 입력이 있을때까지
			break;
		Gotoxy(x + 9, y + 13); printf("  >> PRESS ANY BUTTON <<  "); Sleep(200);
		Gotoxy(x + 9, y + 13); printf("                          "); Sleep(200);
	}

	while (_kbhit()) // 버퍼 지우기
		_getch();

	system("cls"); // 화면 지우기
}


void PrintGameBoard() // 게임판 출력
{
	for (int y = 0; y < SIZE_Y; y++)
	{
		for (int x = 0; x < SIZE_X; x++)
		{
			if (copyboard[y][x] != realboard[y][x]) // 리얼보드와 카피를 비교, 값이 다르면 수정해서 출력
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
					printf("■");
					break;

				case OVERLINE:
					Gotoxy(x + SIZE_X_ADJ, y + SIZE_Y_ADJ);
					printf(". ");
					break;

				case SBLOCK:
					Gotoxy(x + SIZE_X_ADJ, y + SIZE_Y_ADJ);
					printf("◎");
					break;

				case WALL:
					Gotoxy(x + SIZE_X_ADJ, y + SIZE_Y_ADJ);
					printf("▩");
					break;

				case FBLOCK:
					Gotoxy(x + SIZE_X_ADJ, y + SIZE_Y_ADJ);
					printf("□");
					break;

				case EBLOCK:
					Gotoxy(x + SIZE_X_ADJ, y + SIZE_Y_ADJ);
					printf("■");
					break;
				}
				if (y == 2 && x != 0 && x != SIZE_X - 1 && copyboard[y][x] == EMPTY)
					copyboard[y][x] = OVERLINE; //오버라인이 지워지면 다시 그리기

			}
		}
	}
}

void UIDrawer() // UI를 그립니다.
{

	int x = 2, y = 2;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	Gotoxy(2 + x, y); printf("[HOLD]"); // Hold 블록칸
	Gotoxy(x, 1 + y); printf("┌");
	Gotoxy(6 + x, 1 + y); printf("┐");
	Gotoxy(x, 6 + y); printf("└");
	Gotoxy(6 + x, 6 + y); printf("┘");

	Gotoxy(23 + x, y); printf("[NEXT]"); // 1번 블록칸
	Gotoxy(21 + x, 1 + y); printf("┌");
	Gotoxy(27 + x, 1 + y); printf("┐");
	Gotoxy(21 + x, 6 + y); printf("└");
	Gotoxy(27 + x, 6 + y); printf("┘");

	Gotoxy(21 + x, 7 + y); printf("┌"); // 2번 블록칸
	Gotoxy(27 + x, 7 + y); printf("┐");
	Gotoxy(21 + x, 11 + y); printf("└");
	Gotoxy(27 + x, 11 + y); printf("┘");


	Gotoxy(21 + x, 12 + y); printf("┌"); // 3번 블록칸
	Gotoxy(27 + x, 12 + y); printf("┐");
	Gotoxy(21 + x, 15 + y); printf("└");
	Gotoxy(27 + x, 15 + y); printf("┘");


	Gotoxy(21 + x, 17 + y); printf(" [ BESTSCORE ]: ");
	Gotoxy(21 + x, 19 + y); printf(" [ YOURSCORE ]: ");
	Gotoxy(21 + x, 21 + y); printf(" [   LEVEL   ]: ");
	Gotoxy(21 + x, 23 + y); printf(" [  DESTROY  ]: ");

	Gotoxy(x + 5, 26 + y); printf("https://blog.naver.com/workend1998 // Make by 여장소년(DragBoy) ");


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	Gotoxy(x - 1, 8 + y); printf(" - How TO PLAY -  ");
	Gotoxy(x - 1, 10 + y); printf("[◀▶] :    MOVE  ");
	Gotoxy(x - 1, 14 + y); printf("[▲] :    ROTATE");
	Gotoxy(x - 1, 12 + y); printf("[▼] : SOFT DROP ");
	Gotoxy(x - 1, 16 + y); printf("[SPC] :HARD DROP");
	Gotoxy(x - 1, 18 + y); printf("[A] :       HOLD");
	Gotoxy(x - 1, 20 + y); printf("[P] :      PAUSE");
	Gotoxy(x - 1, 22 + y); printf("[ESC] :     EXIT");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

}
void NextBlockDrawer()// 다음블록을 그립니다.
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (blocks[block_typeNext_1][0][y][x] == 1) // Next Block_1 그리기
			{

				Gotoxy(24 + x, 4 + y);
				printf("■");
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				Gotoxy(24 + x, 4 + y);
				printf(" ");
			}

			if (blocks[block_typeNext_2][0][y][x] == 1) // Next Block_2 그리기
			{

				Gotoxy(24 + x, 9 + y);
				printf("■");
			}
			else
			{

				Gotoxy(24 + x, 9 + y);
				printf(" ");
			}

			if (blocks[block_typeNext_3][0][y][x] == 1) // Next Block_3 그리기
			{
				Gotoxy(24 + x, 14 + y);
				printf("■");
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
	if (holdOn == 0) // 홀드를 사용한적이 없으면 빠져나가기
		return;

	for (int y = 0; y < 4; y++) // 홀드 블록 그리기
	{
		for (int x = 0; x < 4; x++)
		{
			if (blocks[block_typeHold][0][y][x] == 1)
			{
				Gotoxy(3 + x, 4 + y);
				printf("■");
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
	for (int y = 0; y < SIZE_Y - 1; y++) // 게임 영역 가리기
	{
		for (int x = 1; x < SIZE_X - 1; x++)
		{
			Gotoxy(x + SIZE_X_ADJ, y + SIZE_Y_ADJ);
			printf(" ");
		}
	}

	for (int y = 0; y < 4; y++) // 홀드 블록 영역 가리기
	{
		for (int x = 0; x < 6; x++)
		{
			Gotoxy(3 + x, 4 + y);
			printf(" ");
		}
	}

	for (int y = 0; y < 4; y++) // 1번 블록 영역 가리기
	{
		for (int x = 0; x < 6; x++)
		{
			Gotoxy(24 + x, 4 + y);
			printf(" ");
		}
	}

	for (int y = 0; y < 3; y++) // 2번 블록 영역 가리기
	{
		for (int x = 0; x < 6; x++)
		{
			Gotoxy(24 + x, 10 + y);
			printf(" ");
		}
	}

	for (int y = 0; y < 2; y++) // 3번 블록 영역 가리기
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
	HideDrawer(); // 게임 내 블록 모두 지우기
	Gotoxy(13, 14); printf("  [ PAUSE ] ");
	Gotoxy(11, 16); printf("  PRESS ANY BUTTON ");

	EndPauseManeger(); // 버퍼 비우기
	NextBlockDrawer(); // 다음블록 다시표시
	HoldBlockDrawer(); // 홀드블록 다시표시

	Gotoxy(13, 14); printf("                   ");
	Gotoxy(11, 16); printf("                   ");

	ResetRealBoard(); // 실제 게임판 초기화
}

void GameOverDrawer() // 게임 오버화면을 그림
{
	HideDrawer(); // 게임 내 블록 모두 지우기

	if (bestscoreFlag == 1)
	{
		Gotoxy(11, 12); printf(" ☆★BestScore★☆");
		bestscoreFlag = 0;
	}

	Gotoxy(11, 14); printf("  [ ★GameOver★ ] ");
	Gotoxy(11, 16); printf("  PRESS ANY BUTTON ");

	EndPauseManeger(); // 버퍼 비우기
	Gotoxy(12, 12); printf("                     ");

	NextBlockDrawer(); // 다음블록 다시표시
	HoldBlockDrawer(); // 홀드블록 다시표시

	Gotoxy(11, 14); printf("                   ");
	Gotoxy(11, 16); printf("                   ");
}

void WriteScore() // 스코어 표시
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
		PrintGameBoard(); // 게임판 출력
		Sleep(20);
	}
	Sleep(200);
}