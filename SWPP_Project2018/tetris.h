#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <mmsystem.h>
#include <time.h>
#include <stdlib.h>

#pragma comment(lib,"winmm.lib")
#define SOUND_FILE_NAME "TetrisBGM.mp3" // ���� ����

#define LEFT 75 // Ű���� �Է� ��ũ��
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32
#define ESC 27

#define SIZE_X 12 // ������ ����ũ��
#define SIZE_Y 24 // ������ ����ũ��
#define SIZE_X_ADJ  10
#define SIZE_Y_ADJ  2

#define TRUE 1
#define FALSE 0

int realboard[SIZE_Y][SIZE_X]; //���� ������
int copyboard[SIZE_Y][SIZE_X]; //ī�� ������

int block_typeNow; // ���� ����� Ÿ��
int block_typeNext_1; // ������� 1�� ��� Ÿ��
int block_typeNext_2; // ������� 2�� ��� Ÿ��
int block_typeNext_3; // ������� 3�� ��� Ÿ��
int block_typeHold; // Ȧ������ ���Ÿ��

int block_X; // ���� ����� X ��ġ ��
int block_Y; // ���� ����� Y ��ġ ��
int block_rotation; // ��� ȸ�� ��
int blockshuffle[7]; // ���� ���õ� ��� ���� ��

int blocks[7][4][4][4];

int harddropOn; // ��� �ϵ��� üũ
int crushOn; // ��� �浹 üũ
int neednewOn; // ���ο� ����� �ʿ����� üũ
int holdOn; // Ȧ��Ű üũ
int holdChanger;// Ȧ�� ��� üũ

int gamespeed; //���� ���ǵ� ������
int bestscore; //�ְ� ����
int yourscore; // ���� ����
int deleteline_count; // ���� �ı� ����
int deleteline_combo; // ���� �޺� �ı�
int game_level; // ����
int game_speed; // ���ǵ�

int bestscoreFlag;

enum { EMPTY = 0, MBLOCK = 1, OVERLINE = 2, SBLOCK = 3, WALL = 4, FBLOCK = 5, EBLOCK = 6 };


int Tetris();

//ConsoleController�� �Լ�
void ConsoleSize();// �ܼ�â�� ũ�⸦ �����մϴ�.
void RemoveScrollbar(); // �ܼ�â�� ��ũ�ѹٸ� �����մϴ�.
void Gotoxy(int x, int y); // ��ǥ�� Ŀ���� �̵��մϴ�.
void RemoveCurser(); //�ܼ�â���� Ŀ���� ǥ������ �ʽ��ϴ�.
void MusicPlay(); // �ֿܼ��� ������ �ݺ�����մϴ�.
void SetConsole(); // �ܼ�â �⺻ ���� �Լ� ����

//GameDrawer�� �Լ�
void PrintGameBoard(); // �������� ����մϴ�.
void UIDrawer(); // ���� UI�� �׸��ϴ�.
void HoldBlockDrawer(); // Ȧ�� ����� �׸��ϴ�.
void NextBlockDrawer();// ��������� �׸��ϴ�.
void PauseDrawer(); //   ����â�� �׸��ϴ�.
void IntroDrawer(); // ǥ���� �׸��ϴ�.
void HideDrawer(); // PAUSE, GameOVER ��Ȳ �� ȭ���� ��� ����
void GameOverDrawer(); // ���� ���� ȭ���� �׸�
void WriteScore(); // Score ���� ǥ�� 
void GameEndDrawer(); // ���� ���� �� ����

//BlockMaker�� �Լ�
void NewBlockMaker(); //���ο� ����� �ʿ� �����մϴ�.
int BlockSelecter(); // ������ ����� �����մϴ�.
void BlockShuffler();// 7������ ����� �����ݴϴ�.
void ResetBlocks(); // ��ϵ��� �ʱ�ȭ�մϴ�.
void NextBlocksPush(); // ��������� ���� ������� �ٲߴϴ�.
void ShadowBlockMaker(); //�׸��� ����� �����մϴ�.


//BlockControler�� �Լ�
void KeyboardControl(); //����� Ű����� ��Ʈ���մϴ�.
void BlockMove(int, int, int); // ����� �̵� �� ȸ�� ��ŵ�ϴ�.
void BlockPrize(); // ����� �Ƚ���ŵ�ϴ�.


//BlockDetect�� �Լ�
int CrushCheak(int, int, int); // ��� �浹�� üũ�մϴ�.
void BlockDrop(); // ����� �ϰ���Ű��, ������ŵ�ϴ�.
void LineCheak(); // ������ üũ�ϰ�, ���� ����ϴ�.
void MblockDeleter(); // ���� �̵����� ����� ã�Ƽ� ����ϴ�.
void ShadowBlockDeleter(); // �׸��� ����� �����մϴ�.

// GameManeger�� �Լ�
void ReadBestScore(); // ����Ʈ ���ھ �ҷ��ɴϴ�.
void GameoverCheak(); // ���ӿ����� �˻��մϴ�.
void ResetRealBoard(); // ���� �������� ���½�ŵ�ϴ�.
void ResetCopyBoard(); // ī�� �������� ���½�ŵ�ϴ�.
void ResetGame(); // ���������� ���½�ŵ�ϴ�.
void EndPauseManeger(); // ���۸� �ݴϴ�.
void LevelManeger(); // ���� �Ŵ���
void DeleteScoreManeger(); // ���λ��� ���ھ� �Ŵ���