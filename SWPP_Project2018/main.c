//Software Programing Pattern Class's term project
//Writed in 2018.DEC
#include"Project_Header.h"

char fileID[81];
int sd_count;  // count of SD structs
SD* start = NULL;  // start address of SD
SD* next = NULL;
SD* current = NULL;
SD* prev = NULL;
SD* end = NULL;  // end address of SD

void first_title();

int main() {
	char check = NULL, garbage;
	int num = 1;
	first_title();

	system("cls");

	while (readFile()) {
		printf("\n\nDo you want to continue with new ID?(y/n) : ");  //존재하지 않는 아이디일 경우 그대로 계속할지 묻는다.
		fscanf(stdin, "%c", &check);
		fscanf(stdin, "%c", &garbage);
		if (check == 'y') {
			break;
		}
	}

	while (num != -1) {  //work until return value is -1
		num = startASD();
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
	printf("\n\n\n\t\t\t >Press 'q' to continue");
	while (1) {
		if (_kbhit()) { // 키보드가 눌렸나 체크 
			c = _getch(); // 눌린 값 대입
		if (c == 'q')
				break;
		}
	}
}