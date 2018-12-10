#include "tetris.h"
void GameoverCheak() // 게임오버를 검사합니다.
{
	for (int y = 0; y < 3; y++) // 오버라인을 넘은 블록이 있는지 체크
	{
		for (int x = 1; x < SIZE_X - 2; x++)
		{
			if (copyboard[y][x] == FBLOCK) // 오버라인을 넘은 블록이 있음?
			{
				if (bestscore < yourscore) // 현재 스코어가 베스트 스코어를 이김?
				{
					bestscoreFlag = 1;
					FILE *data = fopen("score.txt", "wt");

					if (data == 0) // 파일에 에러가 뜨면
					{
						Gotoxy(0, 0);
						printf("데이터 저장에 실패했습니다");
					}
					else
					{
						fprintf(data, "%d", yourscore);
						fclose(data);
					}

				}
				GameEndDrawer();
				GameOverDrawer(); // 게임 오버 화면을 그림
				ResetGame(); // 게임초기화
			}
		}
	}
	return;
}

void ReadBestScore() // 베스트 스코어 읽어오기
{
	FILE *data = fopen("score.txt", "rt");
	if (data == 0)
		bestscore = 0;
	else
	{
		fscanf(data, "%d", &bestscore);
		fclose(data);
	}
}

void ResetGame() // 게임 리셋시키기
{
	ReadBestScore(); // 베스트 스코어를 불러옵니다.
	ResetBlocks(); // 블록을 초기화시킵니다.
	ResetRealBoard(); // 실제게임판을 초기화시킵니다.
	ResetCopyBoard();
	UIDrawer(); // UI를 그립니다.

	holdOn = 0;
	yourscore = 0;
	deleteline_count = 0;
	game_level = 1;
	game_speed = 0;

	WriteScore(); // 게임 점수를 표시

}

void ResetRealBoard() // 실제 게임판을 초기화합니다.
{
	for (int y = 0; y < SIZE_Y; y++)
		for (int x = 0; x < SIZE_X; x++)
			realboard[y][x] = 10000;
}

void ResetCopyBoard() //카피 게임판을 초기화합니다.
{
	for (int y = 0; y < SIZE_Y; y++) // 빈 공간
		for (int x = 0; x < SIZE_X; x++)
			copyboard[y][x] = EMPTY;

	for (int y = 0; y < SIZE_Y; y++)
	{
		for (int x = 0; x < SIZE_X; x++)
		{
			if (x == 0 || x == SIZE_X - 1) // 좌-우 벽 그리기
				copyboard[y][x] = WALL;

			if (y == SIZE_Y - 1) // 하단 벽 그리기
				copyboard[y][x] = WALL;

			if (y == 2 && x != 0 && x != SIZE_X - 1) // 게임 오버라인 그리기
				copyboard[y][x] = OVERLINE;
		}
	}
}

void EndPauseManeger() // 버퍼주는용도
{
	int garbagy;

	Sleep(500);
	while (_kbhit())
		_getch();
	garbagy = _getch();
} // 퍼즈/종료 버퍼비우기

void LevelManeger() // 
{
	if (deleteline_count < 10)
	{
		game_level = 1;
		game_speed = 75;
		return;
	}

	else if (deleteline_count < 20)
	{
		game_level = 2;
		game_speed = 45;
		return;
	}

	else if (deleteline_count < 30)
	{
		game_level = 3;
		game_speed = 35;
		return;
	}

	else if (deleteline_count < 40)
	{
		game_level = 4;
		game_speed = 30;
		return;
	}

	else if (deleteline_count < 50)
	{
		game_level = 5;
		game_speed = 25;
		return;
	}

	else if (deleteline_count < 60)
	{
		game_level = 15;
		game_speed = 20;
		return;
	}

	else if (deleteline_count < 70)
	{
		game_level = 10;
		game_speed = 15;
		return;
	}

	else
	{
		game_level = 5;
		game_speed = 10;
		return;
	}

} // 레벨(게임스피드) 매니저
void DeleteScoreManeger()
{
	if (deleteline_combo == 1)
		yourscore += 50;

	if (deleteline_combo == 2)
	{
		yourscore += 150;
		Gotoxy(13, 26); printf("%d c o m bo!", deleteline_combo); Sleep(200);
		Gotoxy(13, 26); printf("            ");
	}

	if (deleteline_combo == 3)
	{
		yourscore += 300;
		Gotoxy(13, 26); printf("%d c o m b o!", deleteline_combo); Sleep(200);
		Gotoxy(13, 26); printf("             ");
	}

	if (deleteline_combo == 4)
	{
		yourscore += 1000;
		Gotoxy(13, 26); printf("%d c o m b o!", deleteline_combo); Sleep(200);
		Gotoxy(13, 26); printf("             ");
	}
} // 라인 파괴 점수 획득