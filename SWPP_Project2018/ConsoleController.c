#include "tetris.h"

void ConsoleSize()// �ܼ�â�� ũ�⸦ �����մϴ�.
{
	system("mode con cols=79 lines=30"); // ���� 79, ���� 30���� ����
}

void RemoveScrollbar() // �ܼ�â�� ��ũ�ѹٸ� �����մϴ�.
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

void Gotoxy(int x, int y) // ��ǥ�� Ŀ���� �̵��մϴ�.
{
	COORD pos = { 2 * x,y }; // ���δ� �� ĭ�� �̵��մϴ�.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void RemoveCurser() // Ŀ���� ǥ������ �ʽ��ϴ�.
{
	CONSOLE_CURSOR_INFO curinfo = { 0, };
	curinfo.dwSize = 1;
	curinfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);
}


void MusicPlay() // ������ �ݺ�����մϴ�.
{
	PlaySound(TEXT(SOUND_FILE_NAME), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void SetConsole() // �ܼ�â ����
{
	ConsoleSize();
	RemoveScrollbar();
	RemoveCurser();
	MusicPlay();
}