#include "tetris.h"

void KeyboardControl() // 블록을 키보드로 컨드롤 합니다.
{
	int key;
	if (_kbhit())
	{
		key = _getch();
		if (key == 224) //방향키이면
		{
			key = _getch();
			switch (key)
			{
			case LEFT: //왼쪽 이동
				if (CrushCheak(-1, 0, FALSE) == TRUE)
					BlockMove(-1, 0, FALSE);
				break;

			case RIGHT: // 오른쪽 이동
				if (CrushCheak(1, 0, FALSE) == TRUE)
					BlockMove(1, 0, FALSE);
				break;

			case UP: // 기본 회전(왼쪽)
				for (int rotatemove_y = 0;; rotatemove_y--)
				{
					for (int rotatemove_x = 0; rotatemove_x < 3; rotatemove_x++)
					{
						for (int n = 0; n < 2; n++)
						{
							rotatemove_x *= -1;

							if (CrushCheak(rotatemove_x, rotatemove_y, TRUE) == TRUE)
							{
								BlockMove(rotatemove_x, rotatemove_y, TRUE);
								return;
							}
						}
					}
				}

			case DOWN: // 소프트 드롭
				if (CrushCheak(0, 1, FALSE) == TRUE)
					BlockMove(0, 1, FALSE);
				break;

			}
		}
		else
		{
			switch (key)
			{
			case SPACE: // 하드 드롭
				harddropOn = 1;
				while (crushOn != 1)
					BlockDrop();
				break;


			case 'A': // 홀드
			case 'a':

				if (holdOn == 0) // 상황: 해당 판에서 홀드를 한번도 사용한 적이 없다면
				{
					block_typeHold = block_typeNow; // 현재블록을 홀드블록에 저장합니다.
					NextBlocksPush(); // 다음블록을 1칸씩 밀어줍니다.
					neednewOn = 1;
					MblockDeleter(); // 현재 나와있는 무브 블록을 지워줍니다.
					holdOn = 2;
					holdChanger = 1;
					break;
				}
				if (holdOn == 1) // 홀드 사용 가능 상태라면
				{
					int block_typeTemp;
					block_typeTemp = block_typeHold; // 홀드 블록과 현재블록 교체
					block_typeHold = block_typeNow;
					block_typeNow = block_typeTemp;

					neednewOn = 1; // 블록 필요상태로 변경
					MblockDeleter(); // 현재 나와있는 무브 블록을 지워줍니다.
					holdOn = 2; // 홀드 사용 불가능 상태로 변경
					holdChanger = 1;
					break;
				}
				else
					break;// 0,1 이 아니라면 아무일도 일어나지 않아야함 
				break;

			case 'P': // 퍼즈
			case 'p':
				PauseDrawer();
				break;
			case ESC: //ESC 클릭
				system("cls");
				printf("게임이 종료되었습니다\n");
				exit(0); //게임종료 
			}
		}
	}
}

void BlockMove(int inputX, int inputY, int rotateCheak) // 블록을 이동 및 회전시킵니다.
{

	for (int y = 0; y < 4; y++) // 원래 있던 값 지우기
	{
		for (int x = 0; x < 4; x++)
		{
			if (blocks[block_typeNow][block_rotation][y][x] == 1)
				copyboard[block_Y + y][block_X + x] = EMPTY;
		}
	}

	if (rotateCheak == TRUE) // 회전 체크
	{
		block_rotation++;
		if (block_rotation > 3) // 3을 넘어가면
			block_rotation = 0; // 0으로 다시 돌리기
	}

	for (int y = 0; y < 4; y++) // 다시 값 넣기
	{
		for (int x = 0; x < 4; x++)
		{
			if (blocks[block_typeNow][block_rotation][y][x] == 1)
				copyboard[block_Y + y + inputY][block_X + x + inputX] = MBLOCK;
		}
	}

	block_X = block_X + inputX; //입력받은 값 만큼 X값 이동
	block_Y = block_Y + inputY; //입력받은 값 만큼 Y값 이동
}

void BlockDrop() // 블록자동하강
{

	if (crushOn == 1 && CrushCheak(0, 1, FALSE) == TRUE) // 충돌 판정이 켜져 있지만 충돌하지 않음
		crushOn = 0;

	if (crushOn == 1 && CrushCheak(0, 1, FALSE) == FALSE) // 충돌 판정이 켜져있고, 이번에도 충돌
		BlockPrize(); // 블록을 고정시킨다.

	if (CrushCheak(0, 1, FALSE) == TRUE)
		BlockMove(0, 1, FALSE);

	if (CrushCheak(0, 1, FALSE) == FALSE)
		crushOn = 1;
}

void BlockPrize() // 블록을 픽스시킵니다.
{
	for (int y = 0; y < SIZE_Y; y++)
	{
		for (int x = 0; x < SIZE_X; x++)
		{
			if (copyboard[y][x] == MBLOCK)
				copyboard[y][x] = FBLOCK;
		}
	}
	crushOn = 0; // 충돌 체크 끄기
	neednewOn = 1; // 새로운 블록 필요 플래그 켜기
	yourscore += 5; // 점수 획득
	WriteScore(); // 게임 점수를 표시

	if (holdOn == 2) // 홀드키가 사용 불가 상태라면
		holdOn = 1; // 사용가능 상태로 변경
	return;
}