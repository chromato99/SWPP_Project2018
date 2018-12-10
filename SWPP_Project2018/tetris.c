//Tetris is made by ����ҳ� https://blog.naver.com/workend1998/221413762657 

#include "tetris.h"

int Tetris()
{
	system("cls");
	SetConsole(); // �ܼ�â�� �����մϴ�.
	srand((unsigned)time(NULL)); // �õ尪 ����

	IntroDrawer(); // ����ǥ��
	system("cls"); // ����ȭ

	ResetGame(); // ���������� �ʱ�ȭ
	NewBlockMaker(); //���ο� ����� �����մϴ�.

	LevelManeger();

	if (holdChanger == 1)
		holdChanger = 0; // Ȧ�� ü���� ����

	for (int i = 0; i < 6; i++)
	{
		KeyboardControl(); // ���� Ű���� ��Ʈ��

		if (holdChanger == 1) // Ȧ�� ü������ 1�̸� ������ �������ɴϴ�.
			break;

		ShadowBlockMaker(); // �׸��� ��� ����
		PrintGameBoard(); //�������� ����մϴ�.
		Sleep(game_speed); // ���� ���̵� ����

		if (harddropOn == 1)
		{
			harddropOn = 0;
			break;
		}

		ShadowBlockDeleter(); // �׸��� ��� ����
		if (crushOn == 1 && CrushCheak(0, 1, FALSE) == FALSE) // �浹��Ȳ�̾ ���� �� �ִ� ��ȸ�� ��
			Sleep(50);
	}
	if (holdChanger == 0)
		BlockDrop(); // ����ϰ�

	LineCheak();
	GameoverCheak();

	if (neednewOn == 1)
		NewBlockMaker(); // ��ϻ���

	return 0;
}