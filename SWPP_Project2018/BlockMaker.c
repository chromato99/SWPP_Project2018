#include "tetris.h"

blocks[7][4][4][4] = // [�������][ȸ��][����][����]
{
	// J�̳�(0�� ���)
	{
		0,0,0,0,
		0,1,0,0,
		0,1,1,1,
		0,0,0,0,

		0,0,0,0,
		0,0,1,1,
		0,0,1,0,
		0,0,1,0,

		0,0,0,0,
		0,0,0,0,
		0,1,1,1,
		0,0,0,1,

		0,0,0,0,
		0,0,1,0,
		0,0,1,0,
		0,1,1,0
	},
	// L�̳�(1�� ���)
	{
		0,0,0,0,
		0,0,0,1,
		0,1,1,1,
		0,0,0,0,

		0,0,0,0,
		0,0,1,0,
		0,0,1,0,
		0,0,1,1,

		0,0,0,0,
		0,0,0,0,
		0,1,1,1,
		0,1,0,0,

		0,0,0,0,
		0,1,1,0,
		0,0,1,0,
		0,0,1,0
	},
	// O�̳�(2�� ���)
	{
		0,0,0,0,
		0,1,1,0,
		0,1,1,0,
		0,0,0,0,

		0,0,0,0,
		0,1,1,0,
		0,1,1,0,
		0,0,0,0,

		0,0,0,0,
		0,1,1,0,
		0,1,1,0,
		0,0,0,0,

		0,0,0,0,
		0,1,1,0,
		0,1,1,0,
		0,0,0,0
	},
	// T�̳�(3�� ���)
	{
		0,0,0,0,
		0,0,1,0,
		0,1,1,1,
		0,0,0,0,

		0,0,0,0,
		0,0,1,0,
		0,0,1,1,
		0,0,1,0,

		0,0,0,0,
		0,0,0,0,
		0,1,1,1,
		0,0,1,0,

		0,0,0,0,
		0,0,1,0,
		0,1,1,0,
		0,0,1,0
	},
	// I�̳�(4�� ���)
	{
		0,0,0,0,
		0,0,0,0,
		1,1,1,1,
		0,0,0,0,

		0,0,1,0,
		0,0,1,0,
		0,0,1,0,
		0,0,1,0,

		0,0,0,0,
		1,1,1,1,
		0,0,0,0,
		0,0,0,0,

		0,1,0,0,
		0,1,0,0,
		0,1,0,0,
		0,1,0,0
	},
	// Z�̳�(5�� ���)
	{
		0,0,0,0,
		0,1,1,0,
		0,0,1,1,
		0,0,0,0,

		0,0,0,1,
		0,0,1,1,
		0,0,1,0,
		0,0,0,0,

		0,1,1,0,
		0,0,1,1,
		0,0,0,0,
		0,0,0,0,

		0,0,1,0,
		0,1,1,0,
		0,1,0,0,
		0,0,0,0
	},
	// S�̳�(6�� ���)
	{
		0,0,0,0,
		0,0,1,1,
		0,1,1,0,
		0,0,0,0,

		0,0,1,0,
		0,0,1,1,
		0,0,0,1,
		0,0,0,0,

		0,0,1,1,
		0,1,1,0,
		0,0,0,0,
		0,0,0,0,

		0,1,0,0,
		0,1,1,0,
		0,0,1,0,
		0,0,0,0
	}
};

void NewBlockMaker() // ���ο� ����� �ʿ� �����մϴ�.
{
	block_X = (SIZE_X / 2) - 2;
	block_Y = 0;
	block_rotation = 0;

	if (holdOn == 0 || holdOn == 1) // Ȧ�尡�ɻ����϶�����
		NextBlocksPush();
	NextBlockDrawer();

	if (holdOn == 2) // Ȧ�带 ������� ���� ������Ʈ
		HoldBlockDrawer(); // Ȧ�� ��� �׸���

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (blocks[block_typeNow][block_rotation][y][x] == 1)
				copyboard[block_Y + y][block_X + x] = MBLOCK;
		}
	}
	neednewOn = 0; // ����ʿ���¸� �ٽ� ��ȯ
}

int BlockSelecter() // ������ ����� �����մϴ�.
{
	static int count = 7;

	count++;
	if (count > 6)
	{
		BlockShuffler(); // ��� 7���� �ٽ� �����ϴ�.
		count = 0; //�ٽ� ī��Ʈ�� 0���� �ʱ�ȭ
	}
	return blockshuffle[count];
}

void BlockShuffler() // 7������ ����� �����ݴϴ�.
{
	int j, temp;

	for (int i = 0; i < 7; i++)
		blockshuffle[i] = i;

	for (int i = 0; i < 7; i++)
	{
		j = rand() % 7;

		temp = blockshuffle[i];
		blockshuffle[i] = blockshuffle[j];
		blockshuffle[j] = temp;
	}
}

void ResetBlocks() // ��ϵ��� �ʱ�ȭ�մϴ�.
{
	block_typeNext_1 = BlockSelecter();
	block_typeNext_2 = BlockSelecter();
	block_typeNext_3 = BlockSelecter();
}

void NextBlocksPush() // ��������� ���� ������� �ٲߴϴ�.
{
	block_typeNow = block_typeNext_1;
	block_typeNext_1 = block_typeNext_2;
	block_typeNext_2 = block_typeNext_3;
	block_typeNext_3 = BlockSelecter();
}

void ShadowBlockMaker() // �׸��ں���� �����մϴ�.
{

	int shadowblock_Y = 0;
	while (1)
	{
		if (CrushCheak(0, shadowblock_Y, FALSE) == TRUE) // �׸��� ����� �Ƚ���ϰ� �浹�Ҷ����� �����ϴ�.
			++shadowblock_Y;

		if (CrushCheak(0, shadowblock_Y, FALSE) == FALSE) // �浹�� �� ��ġ�� �׸��ϴ�.
		{
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					if (blocks[block_typeNow][block_rotation][y][x] == 1
						&& copyboard[(block_Y - 1) + shadowblock_Y + y][block_X + x] < 1) //�浹�� �Ͼ Y���� -1����
						copyboard[(block_Y - 1) + shadowblock_Y + y][block_X + x] = SBLOCK;
				}
			}
			shadowblock_Y = 0;
			return;
		}
	}
}