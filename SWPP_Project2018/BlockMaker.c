#include "tetris.h"

blocks[7][4][4][4] = // [블록종류][회전][세로][가로]
{
	// J미노(0번 블록)
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
	// L미노(1번 블록)
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
	// O미노(2번 블록)
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
	// T미노(3번 블록)
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
	// I미노(4번 블록)
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
	// Z미노(5번 블록)
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
	// S미노(6번 블록)
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

void NewBlockMaker() // 새로운 블록을 맵에 생성합니다.
{
	block_X = (SIZE_X / 2) - 2;
	block_Y = 0;
	block_rotation = 0;

	if (holdOn == 0 || holdOn == 1) // 홀드가능상태일때에만
		NextBlocksPush();
	NextBlockDrawer();

	if (holdOn == 2) // 홀드를 사용했을 때만 업데이트
		HoldBlockDrawer(); // 홀드 블록 그리기

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (blocks[block_typeNow][block_rotation][y][x] == 1)
				copyboard[block_Y + y][block_X + x] = MBLOCK;
		}
	}
	neednewOn = 0; // 블록필요상태를 다시 변환
}

int BlockSelecter() // 랜덤한 블록을 선택합니다.
{
	static int count = 7;

	count++;
	if (count > 6)
	{
		BlockShuffler(); // 블록 7개를 다시 섞습니다.
		count = 0; //다시 카운트를 0으로 초기화
	}
	return blockshuffle[count];
}

void BlockShuffler() // 7종류의 블록을 섞어줍니다.
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

void ResetBlocks() // 블록들을 초기화합니다.
{
	block_typeNext_1 = BlockSelecter();
	block_typeNext_2 = BlockSelecter();
	block_typeNext_3 = BlockSelecter();
}

void NextBlocksPush() // 다음블록을 현재 블록으로 바꿉니다.
{
	block_typeNow = block_typeNext_1;
	block_typeNext_1 = block_typeNext_2;
	block_typeNext_2 = block_typeNext_3;
	block_typeNext_3 = BlockSelecter();
}

void ShadowBlockMaker() // 그림자블록을 생성합니다.
{

	int shadowblock_Y = 0;
	while (1)
	{
		if (CrushCheak(0, shadowblock_Y, FALSE) == TRUE) // 그림자 블록을 픽스블록과 충돌할때까지 내립니다.
			++shadowblock_Y;

		if (CrushCheak(0, shadowblock_Y, FALSE) == FALSE) // 충돌을 한 위치에 그립니다.
		{
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					if (blocks[block_typeNow][block_rotation][y][x] == 1
						&& copyboard[(block_Y - 1) + shadowblock_Y + y][block_X + x] < 1) //충돌이 일어난 Y에서 -1을뺌
						copyboard[(block_Y - 1) + shadowblock_Y + y][block_X + x] = SBLOCK;
				}
			}
			shadowblock_Y = 0;
			return;
		}
	}
}