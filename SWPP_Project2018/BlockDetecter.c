#include "tetris.h"

int CrushCheak(int blockX_ODJ, int blockY_ODJ, int blockR_ODJ)
{
	int temp_blockrotation;
	temp_blockrotation = block_rotation + blockR_ODJ; // 임시 로테이션 테스트 값

	if (temp_blockrotation > 3) // 만약 3보다 커지면 0으로 바꾼다.
		temp_blockrotation = 0;

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (blocks[block_typeNow][temp_blockrotation][y][x] ==
				1 && copyboard[block_Y + blockY_ODJ + y][block_X + blockX_ODJ + x] > 3)
				return FALSE;
		}
	}
	return TRUE;
}

void ShadowBlockDeleter() // 그림자 블록 삭제
{
	for (int y = 0; y < SIZE_Y; y++)
	{
		for (int x = 0; x < SIZE_X; x++)
		{
			if (copyboard[y][x] == SBLOCK)
				copyboard[y][x] = EMPTY;
		}
	}
}

void LineCheak() // 라인을 체크하고, 줄을 지웁니다.
{
	int k;
	deleteline_combo = 0; // 라인 파괴 콤보 초기화

	int block_linecheak;
	for (int y = SIZE_Y - 2; y > 2;) // Y이동 ▲
	{
		block_linecheak = 0; // 0으로 초기화
		for (int x = 1; x < SIZE_X - 1; x++) // X이동 ▶
			if (copyboard[y][x] == FBLOCK) // 해당 위치에 fix된 블록이 있으면 값 증가
				block_linecheak++;

		if (block_linecheak == SIZE_X - 2)
		{
			for (k = y; k > 1; k--)
				for (int l = 1; l < SIZE_X - 1; l++)
				{
					if (copyboard[k - 1][l] != OVERLINE)
						copyboard[k][l] = copyboard[k - 1][l];

					if (copyboard[k - 1][l] == OVERLINE)
						copyboard[k][l] = EMPTY;
				}
			deleteline_count++; // 지운줄 총합 증가
			deleteline_combo++; // 라인 파괴 콤보 증가
		}
		else
			y--;
	}
	DeleteScoreManeger(); // 라인 파괴로 인한 점수 획득
}

void MblockDeleter() // 현재 이동중인 블록을 찾아서 지웁니다.
{
	for (int y = 0; y < SIZE_Y; y++)
	{
		for (int x = 0; x < SIZE_X; x++)
		{
			if (copyboard[y][x] == MBLOCK)
				copyboard[y][x] = EMPTY;
		}
	}
}