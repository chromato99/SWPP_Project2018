#include "tetris.h"

void ConsoleSize()// 콘솔창의 크기를 조절합니다.
{
	system("mode con cols=79 lines=30"); // 가로 79, 세로 30으로 설정
}

void RemoveScrollbar() // 콘솔창의 스크롤바를 삭제합니다.
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);
}

void Gotoxy(int x, int y) // 좌표로 커서를 이동합니다.
{
	COORD pos = { 2 * x,y }; // 가로는 두 칸씩 이동합니다.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void RemoveCurser() // 커서를 표시하지 않습니다.
{
	CONSOLE_CURSOR_INFO curinfo = { 0, };
	curinfo.dwSize = 1;
	curinfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);
}


void MusicPlay() // 음악을 반복재생합니다.
{
	PlaySound(TEXT(SOUND_FILE_NAME), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void SetConsole() // 콘솔창 세팅
{
	ConsoleSize();
	RemoveScrollbar();
	RemoveCurser();
	MusicPlay();
}