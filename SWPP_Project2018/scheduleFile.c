#include"Project_Header.h"

extern char fileID[81];
extern int sd_count;
extern SD* start;  // start address of SD
extern SD* next;
extern SD* current;
extern SD* prev;
extern SD* end;  // end address of SD

int readFile() {                                                   //파일을 열고 데이터를 읽기

	fprintf(stdout, "\nEnter your ID : ");
	gets(fileID);
	strcat(fileID, ".bin");

	FILE* fPtr;
	fPtr = fopen(fileID, "rb");

	if (fPtr == NULL) {
		fprintf(stdout, "\nFile opening error.\nNo such file ID\n");
		return 1;
	}

	SD* newnode;
	newnode = (SD*)malloc(sizeof(SD));
	memset(newnode, 0, sizeof(SD));                              // 구조체 변수의 내용을 0으로 초기화
	fread(newnode, sizeof(SD), 1, fPtr);
	start = newnode;
	start->next = NULL;
	start->prev = NULL;
	end = start;                //처음 한개를 받았을 때는 시작과 끝이 같음

	sd_count = 0;
	while(!feof(fPtr)) {
		newnode = (SD*)malloc(sizeof(SD));
		memset(newnode, 0, sizeof(SD));     // 구조체 변수의 내용을 0으로 초기화
		fread(newnode, sizeof(SD), 1, fPtr);
		newnode->next = start;
		start->prev = newnode;
		start = newnode;
		sd_count++;
	}
	start->prev = NULL;

	fclose(fileID);
	if (start == NULL) {
		Tetris();
	}
	return 0;
}

int saveFile() {                                                //파일에 데이터를 저장하고 닫기

	FILE* fPtr;
	fPtr = fopen(fileID, "wb");                              //바이너리파일로 수정

	if (fPtr == NULL) {
		printf("\nFile writing error.\nFail to save data.\n");
		return 0;
	}
	
	current = start;
	while(current == NULL) {                           //구조체 저장
		fwrite(current, sizeof(SD), 1, fPtr);
		current = current->next;
	}

	fclose(fPtr);

	return 1;
}