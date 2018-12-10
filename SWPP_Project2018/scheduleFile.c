#include"Project_Header.h"

extern char fileID[81];
extern int sd_count;
extern SD* start;  // start address of SD
extern SD* next;
extern SD* current;
extern SD* prev;
extern SD* end;  // end address of SD

int readFile() {                                                   //������ ���� �����͸� �б�

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
	memset(newnode, 0, sizeof(SD));                              // ����ü ������ ������ 0���� �ʱ�ȭ
	fread(newnode, sizeof(SD), 1, fPtr);
	start = newnode;
	start->next = NULL;
	start->prev = NULL;
	end = start;                //ó�� �Ѱ��� �޾��� ���� ���۰� ���� ����

	sd_count = 0;
	while(!feof(fPtr)) {
		newnode = (SD*)malloc(sizeof(SD));
		memset(newnode, 0, sizeof(SD));     // ����ü ������ ������ 0���� �ʱ�ȭ
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

int saveFile() {                                                //���Ͽ� �����͸� �����ϰ� �ݱ�

	FILE* fPtr;
	fPtr = fopen(fileID, "wb");                              //���̳ʸ����Ϸ� ����

	if (fPtr == NULL) {
		printf("\nFile writing error.\nFail to save data.\n");
		return 0;
	}
	
	current = start;
	while(current == NULL) {                           //����ü ����
		fwrite(current, sizeof(SD), 1, fPtr);
		current = current->next;
	}

	fclose(fPtr);

	return 1;
}