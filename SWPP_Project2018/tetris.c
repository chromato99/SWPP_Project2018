//Tetris is made by 여장소년 https://blog.naver.com/workend1998/221413762657 

#include "tetris.h"

int Tetris()
{
	system("cls");
	SetConsole(); // 콘솔창을 세팅합니다.
	srand((unsigned)time(NULL)); // 시드값 지정

	IntroDrawer(); // 게임표지
	system("cls"); // 게임화

	ResetGame(); // 게임정보를 초기화
	NewBlockMaker(); //새로운 블록을 생성합니다.

	LevelManeger();

	if (holdChanger == 1)
		holdChanger = 0; // 홀드 체인저 변경

	for (int i = 0; i < 6; i++)
	{
		KeyboardControl(); // 게임 키보드 컨트롤

		if (holdChanger == 1) // 홀드 체인저가 1이면 루프를 빠져나옵니다.
			break;

		ShadowBlockMaker(); // 그림자 블록 생성
		PrintGameBoard(); //게임판을 출력합니다.
		Sleep(game_speed); // 게임 난이도 조절

		if (harddropOn == 1)
		{
			harddropOn = 0;
			break;
		}

		ShadowBlockDeleter(); // 그림자 블록 삭제
		if (crushOn == 1 && CrushCheak(0, 1, FALSE) == FALSE) // 충돌상황이어도 돌릴 수 있는 기회를 줌
			Sleep(50);
	}
	if (holdChanger == 0)
		BlockDrop(); // 블록하강

	LineCheak();
	GameoverCheak();

	if (neednewOn == 1)
		NewBlockMaker(); // 블록생성

	return 0;
}