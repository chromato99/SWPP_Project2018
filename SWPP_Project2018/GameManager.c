#include "tetris.h"
void GameoverCheak() // ���ӿ����� �˻��մϴ�.
{
	for (int y = 0; y < 3; y++) // ���������� ���� ����� �ִ��� üũ
	{
		for (int x = 1; x < SIZE_X - 2; x++)
		{
			if (copyboard[y][x] == FBLOCK) // ���������� ���� ����� ����?
			{
				if (bestscore < yourscore) // ���� ���ھ ����Ʈ ���ھ �̱�?
				{
					bestscoreFlag = 1;
					FILE *data = fopen("score.txt", "wt");

					if (data == 0) // ���Ͽ� ������ �߸�
					{
						Gotoxy(0, 0);
						printf("������ ���忡 �����߽��ϴ�");
					}
					else
					{
						fprintf(data, "%d", yourscore);
						fclose(data);
					}

				}
				GameEndDrawer();
				GameOverDrawer(); // ���� ���� ȭ���� �׸�
				ResetGame(); // �����ʱ�ȭ
			}
		}
	}
	return;
}

void ReadBestScore() // ����Ʈ ���ھ� �о����
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

void ResetGame() // ���� ���½�Ű��
{
	ReadBestScore(); // ����Ʈ ���ھ �ҷ��ɴϴ�.
	ResetBlocks(); // ����� �ʱ�ȭ��ŵ�ϴ�.
	ResetRealBoard(); // ������������ �ʱ�ȭ��ŵ�ϴ�.
	ResetCopyBoard();
	UIDrawer(); // UI�� �׸��ϴ�.

	holdOn = 0;
	yourscore = 0;
	deleteline_count = 0;
	game_level = 1;
	game_speed = 0;

	WriteScore(); // ���� ������ ǥ��

}

void ResetRealBoard() // ���� �������� �ʱ�ȭ�մϴ�.
{
	for (int y = 0; y < SIZE_Y; y++)
		for (int x = 0; x < SIZE_X; x++)
			realboard[y][x] = 10000;
}

void ResetCopyBoard() //ī�� �������� �ʱ�ȭ�մϴ�.
{
	for (int y = 0; y < SIZE_Y; y++) // �� ����
		for (int x = 0; x < SIZE_X; x++)
			copyboard[y][x] = EMPTY;

	for (int y = 0; y < SIZE_Y; y++)
	{
		for (int x = 0; x < SIZE_X; x++)
		{
			if (x == 0 || x == SIZE_X - 1) // ��-�� �� �׸���
				copyboard[y][x] = WALL;

			if (y == SIZE_Y - 1) // �ϴ� �� �׸���
				copyboard[y][x] = WALL;

			if (y == 2 && x != 0 && x != SIZE_X - 1) // ���� �������� �׸���
				copyboard[y][x] = OVERLINE;
		}
	}
}

void EndPauseManeger() // �����ִ¿뵵
{
	int garbagy;

	Sleep(500);
	while (_kbhit())
		_getch();
	garbagy = _getch();
} // ����/���� ���ۺ���

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

} // ����(���ӽ��ǵ�) �Ŵ���
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
} // ���� �ı� ���� ȹ��