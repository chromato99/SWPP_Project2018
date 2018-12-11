#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include <conio.h>
#include"tetris.h"

typedef struct memo {
	char title[81];
	int year;
	int month;
	int date;
	char memo[1000];
	struct memo* next;
	struct memo* prev;
}MM;

typedef struct schedule {
	char title[81];
	char subject[81];
	char place[81];
	char people[81];
	int dow;  //day of the week
	int start_time;
	int end_time;
	char etc[400];
	struct schedule* next;
	struct schedule* prev;
}SD;

//addSearchDelete
void add_sd();
void search_sd();
void del_sd();
void add_mm();
void del_mm(int num);

//fileIO
int readFile();
int saveFile();

//printData
int printFirstMenu();
int printTable();
int printTableMenu();
void printSchedule();
int printMemoList();
void printMemo(int n);