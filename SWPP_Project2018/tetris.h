#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <mmsystem.h>
#include <time.h>
#include <stdlib.h>

#pragma comment(lib,"winmm.lib")
#define SOUND_FILE_NAME "TetrisBGM.mp3" // 사운드 파일

#define LEFT 75 // 키보드 입력 매크로
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32
#define ESC 27

#define SIZE_X 12 // 게임판 가로크기
#define SIZE_Y 24 // 게임판 세로크기
#define SIZE_X_ADJ  10
#define SIZE_Y_ADJ  2

#define TRUE 1
#define FALSE 0

int realboard[SIZE_Y][SIZE_X]; //실제 게임판
int copyboard[SIZE_Y][SIZE_X]; //카피 게임판

int block_typeNow; // 현재 블록의 타입
int block_typeNext_1; // 다음블록 1의 블록 타입
int block_typeNext_2; // 다음블록 2의 블록 타입
int block_typeNext_3; // 다음블록 3의 블록 타입
int block_typeHold; // 홀드블록의 블록타입

int block_X; // 현재 블록의 X 위치 값
int block_Y; // 현재 블록의 Y 위치 값
int block_rotation; // 블록 회전 값
int blockshuffle[7]; // 랜덤 선택된 블록 종류 값

int blocks[7][4][4][4];

int harddropOn; // 블록 하드드롭 체크
int crushOn; // 블록 충돌 체크
int neednewOn; // 새로운 블록이 필요한지 체크
int holdOn; // 홀드키 체크
int holdChanger;// 홀드 사용 체크

int gamespeed; //게임 스피드 조절값
int bestscore; //최고 점수
int yourscore; // 현재 점수
int deleteline_count; // 라인 파괴 총합
int deleteline_combo; // 라인 콤보 파괴
int game_level; // 레벨
int game_speed; // 스피드

int bestscoreFlag;

enum { EMPTY = 0, MBLOCK = 1, OVERLINE = 2, SBLOCK = 3, WALL = 4, FBLOCK = 5, EBLOCK = 6 };


int Tetris();

//ConsoleController의 함수
void ConsoleSize();// 콘솔창의 크기를 조절합니다.
void RemoveScrollbar(); // 콘솔창의 스크롤바를 삭제합니다.
void Gotoxy(int x, int y); // 좌표로 커서를 이동합니다.
void RemoveCurser(); //콘솔창에서 커서를 표시하지 않습니다.
void MusicPlay(); // 콘솔에서 음악을 반복재생합니다.
void SetConsole(); // 콘솔창 기본 세팅 함수 실행

//GameDrawer의 함수
void PrintGameBoard(); // 게임판을 출력합니다.
void UIDrawer(); // 게임 UI를 그립니다.
void HoldBlockDrawer(); // 홀드 블록을 그립니다.
void NextBlockDrawer();// 다음블록을 그립니다.
void PauseDrawer(); //   퍼즈창을 그립니다.
void IntroDrawer(); // 표지를 그립니다.
void HideDrawer(); // PAUSE, GameOVER 상황 때 화면을 잠시 지움
void GameOverDrawer(); // 게임 오버 화면을 그림
void WriteScore(); // Score 관련 표시 
void GameEndDrawer(); // 게임 종료 시 연출

//BlockMaker의 함수
void NewBlockMaker(); //새로운 블록을 맵에 생성합니다.
int BlockSelecter(); // 랜덤한 블록을 선택합니다.
void BlockShuffler();// 7종류의 블록을 섞어줍니다.
void ResetBlocks(); // 블록들을 초기화합니다.
void NextBlocksPush(); // 다음블록을 현재 블록으로 바꿉니다.
void ShadowBlockMaker(); //그림자 블록을 생성합니다.


//BlockControler의 함수
void KeyboardControl(); //블록을 키보드로 컨트롤합니다.
void BlockMove(int, int, int); // 블록을 이동 및 회전 시킵니다.
void BlockPrize(); // 블록을 픽스시킵니다.


//BlockDetect의 함수
int CrushCheak(int, int, int); // 블록 충돌을 체크합니다.
void BlockDrop(); // 블록을 하강시키고, 고정시킵니다.
void LineCheak(); // 라인을 체크하고, 줄을 지웁니다.
void MblockDeleter(); // 현재 이동중인 블록을 찾아서 지웁니다.
void ShadowBlockDeleter(); // 그림자 블록을 삭제합니다.

// GameManeger의 함수
void ReadBestScore(); // 베스트 스코어를 불러옵니다.
void GameoverCheak(); // 게임오버를 검사합니다.
void ResetRealBoard(); // 실제 게임판을 리셋시킵니다.
void ResetCopyBoard(); // 카피 게임판을 리셋시킵니다.
void ResetGame(); // 게임정보를 리셋시킵니다.
void EndPauseManeger(); // 버퍼를 줍니다.
void LevelManeger(); // 레벨 매니저
void DeleteScoreManeger(); // 라인삭제 스코어 매니저