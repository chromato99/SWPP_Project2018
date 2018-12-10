#include "tetris.h"

void KeyboardControl() // ����� Ű����� ����� �մϴ�.
{
	int key;
	if (_kbhit())
	{
		key = _getch();
		if (key == 224) //����Ű�̸�
		{
			key = _getch();
			switch (key)
			{
			case LEFT: //���� �̵�
				if (CrushCheak(-1, 0, FALSE) == TRUE)
					BlockMove(-1, 0, FALSE);
				break;

			case RIGHT: // ������ �̵�
				if (CrushCheak(1, 0, FALSE) == TRUE)
					BlockMove(1, 0, FALSE);
				break;

			case UP: // �⺻ ȸ��(����)
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

			case DOWN: // ����Ʈ ���
				if (CrushCheak(0, 1, FALSE) == TRUE)
					BlockMove(0, 1, FALSE);
				break;

			}
		}
		else
		{
			switch (key)
			{
			case SPACE: // �ϵ� ���
				harddropOn = 1;
				while (crushOn != 1)
					BlockDrop();
				break;


			case 'A': // Ȧ��
			case 'a':

				if (holdOn == 0) // ��Ȳ: �ش� �ǿ��� Ȧ�带 �ѹ��� ����� ���� ���ٸ�
				{
					block_typeHold = block_typeNow; // �������� Ȧ���Ͽ� �����մϴ�.
					NextBlocksPush(); // ��������� 1ĭ�� �о��ݴϴ�.
					neednewOn = 1;
					MblockDeleter(); // ���� �����ִ� ���� ����� �����ݴϴ�.
					holdOn = 2;
					holdChanger = 1;
					break;
				}
				if (holdOn == 1) // Ȧ�� ��� ���� ���¶��
				{
					int block_typeTemp;
					block_typeTemp = block_typeHold; // Ȧ�� ��ϰ� ������ ��ü
					block_typeHold = block_typeNow;
					block_typeNow = block_typeTemp;

					neednewOn = 1; // ��� �ʿ���·� ����
					MblockDeleter(); // ���� �����ִ� ���� ����� �����ݴϴ�.
					holdOn = 2; // Ȧ�� ��� �Ұ��� ���·� ����
					holdChanger = 1;
					break;
				}
				else
					break;// 0,1 �� �ƴ϶�� �ƹ��ϵ� �Ͼ�� �ʾƾ��� 
				break;

			case 'P': // ����
			case 'p':
				PauseDrawer();
				break;
			case ESC: //ESC Ŭ��
				system("cls");
				printf("������ ����Ǿ����ϴ�\n");
				exit(0); //�������� 
			}
		}
	}
}

void BlockMove(int inputX, int inputY, int rotateCheak) // ����� �̵� �� ȸ����ŵ�ϴ�.
{

	for (int y = 0; y < 4; y++) // ���� �ִ� �� �����
	{
		for (int x = 0; x < 4; x++)
		{
			if (blocks[block_typeNow][block_rotation][y][x] == 1)
				copyboard[block_Y + y][block_X + x] = EMPTY;
		}
	}

	if (rotateCheak == TRUE) // ȸ�� üũ
	{
		block_rotation++;
		if (block_rotation > 3) // 3�� �Ѿ��
			block_rotation = 0; // 0���� �ٽ� ������
	}

	for (int y = 0; y < 4; y++) // �ٽ� �� �ֱ�
	{
		for (int x = 0; x < 4; x++)
		{
			if (blocks[block_typeNow][block_rotation][y][x] == 1)
				copyboard[block_Y + y + inputY][block_X + x + inputX] = MBLOCK;
		}
	}

	block_X = block_X + inputX; //�Է¹��� �� ��ŭ X�� �̵�
	block_Y = block_Y + inputY; //�Է¹��� �� ��ŭ Y�� �̵�
}

void BlockDrop() // ����ڵ��ϰ�
{

	if (crushOn == 1 && CrushCheak(0, 1, FALSE) == TRUE) // �浹 ������ ���� ������ �浹���� ����
		crushOn = 0;

	if (crushOn == 1 && CrushCheak(0, 1, FALSE) == FALSE) // �浹 ������ �����ְ�, �̹����� �浹
		BlockPrize(); // ����� ������Ų��.

	if (CrushCheak(0, 1, FALSE) == TRUE)
		BlockMove(0, 1, FALSE);

	if (CrushCheak(0, 1, FALSE) == FALSE)
		crushOn = 1;
}

void BlockPrize() // ����� �Ƚ���ŵ�ϴ�.
{
	for (int y = 0; y < SIZE_Y; y++)
	{
		for (int x = 0; x < SIZE_X; x++)
		{
			if (copyboard[y][x] == MBLOCK)
				copyboard[y][x] = FBLOCK;
		}
	}
	crushOn = 0; // �浹 üũ ����
	neednewOn = 1; // ���ο� ��� �ʿ� �÷��� �ѱ�
	yourscore += 5; // ���� ȹ��
	WriteScore(); // ���� ������ ǥ��

	if (holdOn == 2) // Ȧ��Ű�� ��� �Ұ� ���¶��
		holdOn = 1; // ��밡�� ���·� ����
	return;
}