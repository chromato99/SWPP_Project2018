#include"Project_Header.h"

extern char fileID[81];
extern char fileID_sd[81];
extern char fileID_mm[81];

extern int sd_count;
extern SD* sd_start;  // start address of SD
extern SD* sd_next;
extern SD* sd_current;
extern SD* sd_prev;
extern SD* sd_end;  // end address of SD

extern int mm_count;
extern MM* mm_start;
extern MM* mm_next;
extern MM* mm_current;
extern MM* mm_prev;
extern MM* mm_end;

int readFile() {                                                   //������ ���� �����͸� �б�
	char c;
	fprintf(stdout, "\nEnter your ID : ");
	gets(fileID);
	strcpy(fileID_sd, fileID);
	strcpy(fileID_mm, fileID);
	strcat(fileID_sd, "_sd.dat");
	strcat(fileID_mm, "_mm.dat");

	FILE* fPtr_sd;  //���̳ʸ� �������� ���� ����
	FILE* fPtr_mm;
	fPtr_sd = fopen(fileID_sd, "rb");
	fPtr_mm = fopen(fileID_mm, "rb");

	if (fPtr_sd == NULL || fPtr_mm == NULL) {  //����ú� �ڵ�
		fprintf(stdout, "\nFile opening error.\nNo such file ID\n");
		return 1;
	}

	SD* newnode_sd;
	
	sd_count = 0;
	while(1) {
		newnode_sd = (SD*)malloc(sizeof(SD));
		//memset(newnode_sd, 0, sizeof(SD));     // ����ü ������ ������ 0���� �ʱ�ȭ
		fread(newnode_sd, sizeof(SD), 1, fPtr_sd);
		if (feof(fPtr_sd))
			break;

		newnode_sd->next = sd_start;
		if (sd_start) {
			sd_start->prev = newnode_sd;
		}
		sd_start = newnode_sd;
		if (sd_count == 0) {
			sd_end = sd_start;
		}
		sd_count++;
	}
	if (sd_start != NULL) {
		sd_start->prev = NULL;
	}

	fclose(fPtr_sd);

	MM* newnode_mm;

	mm_count = 0;
	while (1) {
		newnode_mm = (MM*)malloc(sizeof(MM));
		//memset(newnode_mm, 0, sizeof(MM));     // ����ü ������ ������ 0���� �ʱ�ȭ
		fread(newnode_mm, sizeof(MM), 1, fPtr_mm);
		if (feof(fPtr_mm))
			break;

		newnode_mm->next = mm_start;
		if (mm_start) {
			mm_start->prev = newnode_mm;
		}
		mm_start = newnode_mm;
		if (mm_count == 0) {
			mm_end = mm_start;
		}
		mm_count++;
	}

	if (mm_start != NULL) {
		mm_start->prev = NULL;
	}

	fclose(fPtr_mm);

	return 0;
}

int saveFile() {                                                //���Ͽ� �����͸� �����ϰ� �ݱ�

	FILE* fPtr_sd;
	FILE* fPtr_mm;
	fPtr_sd = fopen(fileID_sd, "wb");                              //���̳ʸ����Ϸ� ����
	fPtr_mm = fopen(fileID_mm, "wb");

	if (fPtr_sd == NULL || fPtr_mm == NULL) {
		printf("\nFile writing error.\nFail to save data.\n");
		return 0;
	}
	
	sd_current = sd_start;
	while(sd_current != NULL) {                           //����ü ����
		fwrite(sd_current, sizeof(SD), 1, fPtr_sd);
		sd_current = sd_current->next;
	}

	fclose(fPtr_sd);

	mm_current = mm_start;
	while (mm_current != NULL) {                           //����ü ����
		fwrite(mm_current, sizeof(MM), 1, fPtr_mm);
		mm_current = mm_current->next;
	}

	fclose(fPtr_mm);

	return 0;
}