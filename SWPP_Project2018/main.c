//Software Programing Pattern Class's term project
//Writed in 2018.DEC
#include"Project_Header.h"

char fileID[81];
char fileID_sd[81];  //file ID for time table
char fileID_mm[81];  //file ID for memo
char fileID_pw[81]; //file ID for password
int sd_count = 0;  // count of SD structs
SD* sd_start = NULL;  // start address of SD
SD* sd_next = NULL;
SD* sd_current = NULL;
SD* sd_prev = NULL;
SD* sd_end = NULL;  // end address of SD

int mm_count = 0;
MM* mm_start = NULL;
MM* mm_next = NULL;
MM* mm_current = NULL;
MM* mm_prev = NULL;
MM* mm_end = NULL;

CONSOLE_CURSOR_INFO cursorInfo = { 0, };  //cursor setting

void first_title();

int main() {
	char check = NULL, garbage;
	int num = 1;
	
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);  //hide cursor

	first_title();

	system("cls");

	cursorInfo.bVisible = TRUE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);  //show cursor for entering ID
	while (readFile()) {
		printf("\n\nDo you want to continue with new ID?(y/n) : ");  //존재하지 않는 아이디일 경우 그대로 계속할지 묻는다.
		fscanf(stdin, "%c", &check);
		fscanf(stdin, "%c", &garbage);
		if (check == 'y') {
			break;
		}
	}
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);  //hide cursor

	int i = 1;
	while (num != 0) { //work until return value 0
		num = printFirstMenu();
		i = 1;
		if (num == 1) {
			while (i != 0) {
				i = printTable();
			}
		}
		else if (num == 2) {
			while (i != 0) {
				i = printMemoList();
			}
		}
	}
	saveFile();

    return 0;
}

void first_title() {
	char c;
	printf("\n\n\n\n\n\t\t\t [WELCOME SCHEDULE]\n\n\n");
	printf("\t>This program is schedule management program.\n");
	printf("\t>Please report the bug to chromato99@outlook.com.\n\n\n");
	printf("\t Program is written by KIM BEOMGI, HWANG SUJEONG, SEO JIWON, KWON UHYEOK\n");
	printf("\t Made for SWPP Term Project\n\n");
	printf("\t Last update in 2018.DEC\n");
	printf("\n\n\n\t\t\t >Press ENTER to continue");
	while (1) {
		if (kbhit()) { // 키보드가 눌렸나 체크 
			c = getch(); // 눌린 값 대입
		if (c == 13)  //check ENTER
				break;
		}
	}
}