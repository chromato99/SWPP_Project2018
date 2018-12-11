#include"Project_Header.h"

extern int sd_count;  // count of SD structs
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

extern CONSOLE_CURSOR_INFO cursorInfo;

void add_sd() {
	SD *newnode_sd;
	newnode_sd = (SD*)malloc(sizeof(SD));
	cursorInfo.bVisible = TRUE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);  //show cursor for entering dats
	fprintf(stdout, "Enter Title : ");
	fgets(newnode_sd->title, 81, stdin);
	fprintf(stdout, "Enter Subject : ");
	fgets(newnode_sd->subject, 81, stdin);
	fprintf(stdout, "Enter Place : ");
	fgets(newnode_sd->place, 81, stdin);
	fprintf(stdout, "Enter People : ");
	fgets(newnode_sd->people, 81, stdin);
	
	fprintf(stdout, "Enter Start Time (8:00 ~ 24:00) : ");
	fscanf(stdin, "%d", &newnode_sd->start_time);
	if (newnode_sd->start_time < 8 || newnode_sd->start_time > 24) {
		fprintf(stdout, "Enter Start Time (8:00 ~ 24:00) : ");
		fscanf(stdin, "%d", &newnode_sd->start_time);
	}
	fprintf(stdout, "Enter End Time (8:00 ~ 24:00) : ");
	fscanf(stdin, "%d", &newnode_sd->end_time);
	if (newnode_sd->end_time < 8 || newnode_sd->end_time > 24) {
		fprintf(stdout, "Enter End Time (8:00 ~ 24:00) : ");
		fscanf(stdin, "%d", &newnode_sd->end_time);
	}
	fprintf(stdout, "Enter other details\n");
	fgets(newnode_sd->etc, 400, stdin);
	newnode_sd->next = sd_start;
	sd_start = newnode_sd;
	sd_count++;

	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);  //hide cursor
	system("pause");
}

void del_sd() {

	sd_current = sd_start;
	char del[81];
	cursorInfo.bVisible = TRUE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);  //show cursor for entering title
	fprintf(stdout, "\n\nEnter title of the schedule you want to delete\n");
	fgets(del, 81, stdin);
	while (sd_current) {
		sd_prev = sd_current->prev;
		sd_next = sd_current->next;

		if (strcmp(sd_current->title, del) == 0) {
			sd_prev->next = sd_next;
			sd_next->prev = sd_prev;
			free(sd_current);
			sd_count--;
			fprintf(stdout, "\n*Deleted Success!*\n");
			cursorInfo.bVisible = FALSE;
			SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);  //hide cursor
			system("pause");
			return;
		}
		
		sd_current = sd_current->next;
	}
	fprintf(stdout, "\nFail to delete data\nNo such file name\n");

	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);  //hide cursor
	system("pause");
}

void search_sd() {
	char search[81];
	sd_current = sd_start;
	cursorInfo.bVisible = TRUE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);  //show cursor for entering data
	printf(stdout, "\n\nEnter title of the schedule you want to search\n");
	fgets(search, 81, stdin);
	while (sd_current) {
		if (strcmp(sd_current->title, search) == 0) {
			fprintf(stdout, "Title : ");
			fputs(sd_current->title, stdout);
			fprintf(stdout, "Subject : ");
			fputs(sd_current->subject, stdout);
			fprintf(stdout, "Place : ");
			fputs(sd_current->place, stdout);
			fprintf(stdout, "People : ");
			fputs(sd_current->people, stdout);
			if (sd_current->dow == 0) {
				fprintf(stdout, "Day of the week : Sunday\n");
			}
			else if (sd_current->dow == 1) {
				fprintf(stdout, "Day of the week : Monday\n");
			}
			else if (sd_current->dow == 2) {
				fprintf(stdout, "Day of the week : Tuesday\n");
			}
			else if (sd_current->dow == 3) {
				fprintf(stdout, "Day of the week : Wednesday\n");
			}
			else if (sd_current->dow == 4) {
				fprintf(stdout, "Day of the week : Turthday\n");
			}
			else if (sd_current->dow == 5) {
				fprintf(stdout, "Day of the week : Friday\n");
			}
			else if (sd_current->dow == 6) {
				fprintf(stdout, "Day of the week : Saturday\n");
			}
			fprintf(stdout, "Start Time : %d", sd_current->start_time);
			fprintf(stdout, "End Time : ", sd_current->end_time);
			fprintf(stdout, "Other details\n");
			fputs(sd_current->etc, stdout);
			system("pause");
			return;
		}
		sd_current = sd_current->next;
	}
	if (sd_current == NULL) {
		fprintf(stdout, "\nFail to find the schedule\n");
	}
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);  //hide cursor
	system("pause");
}

void add_mm() {
	system("cls");
	MM* newnode_mm;
	newnode_mm = (MM*)malloc(sizeof(MM));
	
	cursorInfo.bVisible = TRUE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);  //show cursor for entering title
	fprintf(stdout, "Enter Title : ");
	fgets(newnode_mm->title, 81, stdin);
	fprintf(stdout, "Enter year:month:date (yyyy mm dd) : ");
	fscanf(stdin, "%d %d %d", mm_current->year, mm_current->month, mm_current->date);
	fprintf(stdout, "Enter memo\n");
	fgets(newnode_mm->memo, 1000, stdin);

	newnode_mm->next = mm_start;
	mm_start->prev = newnode_mm;
	mm_start = newnode_mm;

	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);  //hide cursor
}

void del_mm(int num) {
	mm_current = mm_start;
	char del[81];
	for (int i = 0; i < num; i++) {
		mm_current = mm_current->next;
	}

	mm_prev = mm_current->prev;
	mm_next = mm_current->next;

	mm_prev->next = mm_next;
	mm_next->prev = mm_prev;
	free(mm_current);
	mm_count--;
	
	fprintf(stdout, "\nDelete Success!\n");
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);  //hide cursor
}