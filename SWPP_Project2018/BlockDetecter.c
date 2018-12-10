#include "tetris.h"

int CrushCheak(int blockX_ODJ, int blockY_ODJ, int blockR_ODJ)
{
	int temp_blockrotation;
	temp_blockrotation = block_rotation + blockR_ODJ; // �ӽ� �����̼� �׽�Ʈ ��

	if (temp_blockrotation > 3) // ���� 3���� Ŀ���� 0���� �ٲ۴�.
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

void ShadowBlockDeleter() // �׸��� ��� ����
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

void LineCheak() // ������ üũ�ϰ�, ���� ����ϴ�.
{
	int k;
	deleteline_combo = 0; // ���� �ı� �޺� �ʱ�ȭ

	int block_linecheak;
	for (int y = SIZE_Y - 2; y > 2;) // Y�̵� ��
	{
		block_linecheak = 0; // 0���� �ʱ�ȭ
		for (int x = 1; x < SIZE_X - 1; x++) // X�̵� ��
			if (copyboard[y][x] == FBLOCK) // �ش� ��ġ�� fix�� ����� ������ �� ����
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
			deleteline_count++; // ������ ���� ����
			deleteline_combo++; // ���� �ı� �޺� ����
		}
		else
			y--;
	}
	DeleteScoreManeger(); // ���� �ı��� ���� ���� ȹ��
}

void MblockDeleter() // ���� �̵����� ����� ã�Ƽ� ����ϴ�.
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