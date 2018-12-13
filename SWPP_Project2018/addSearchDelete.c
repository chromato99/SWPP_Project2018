#include"Project_Header.h"

extern int sd_count;  // count of SD structs
extern SD* sd_start;  // start address of SD
extern SD* sd_next;
extern SD* sd_current;
extern SD* sd_prev;
extern SD* sd_end;  // end address of SD

extern int mm_count;  //메모
extern MM* mm_start;
extern MM* mm_next;
extern MM* mm_current;
extern MM* mm_prev;
extern MM* mm_end;

extern CONSOLE_CURSOR_INFO cursorInfo;

char garbage;

void add_sd() {
	char dow[16];
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
	fprintf(stdout, "Enter day of the week : ");
	gets_s(dow, 16);
	strlwr(dow);  //change to lower character
	
	if (strcmp(dow, "sun") == 0 || strcmp(dow, "sunday") == 0) {  //요일에 따라 dow에 저장
		newnode_sd->dow = 0;
	}
	else if (strcmp(dow, "mon") == 0 || strcmp(dow, "monday") == 0) {
		newnode_sd->dow = 1;
	}
	else if (strcmp(dow, "tue") == 0 || strcmp(dow, "tuesday") == 0) {
		newnode_sd->dow = 2;
	}
	else if (strcmp(dow, "wed") == 0 || strcmp(dow, "wednesday") == 0) {
		newnode_sd->dow = 3;
	}
	else if (strcmp(dow, "thur") == 0 || strcmp(dow, "thursday") == 0) {
		newnode_sd->dow = 4;
	}
	else if (strcmp(dow, "fri") == 0 || strcmp(dow, "friday") == 0) {
		newnode_sd->dow = 5;
	}
	else if (strcmp(dow, "sat") == 0 || strcmp(dow, "saturday") == 0) {
		newnode_sd->dow = 6;
	}
	

	fprintf(stdout, "Enter Start Time (8:00 ~ 24:00) : ");  //시작시간
	fscanf(stdin, "%d", &newnode_sd->start_time);
	if (newnode_sd->start_time < 8 || newnode_sd->start_time > 24) {
		fprintf(stdout, "Enter Start Time (8:00 ~ 24:00) : ");
		fscanf(stdin, "%d", &newnode_sd->start_time);
	}
	fprintf(stdout, "Enter End Time (8:00 ~ 24:00) : ");  //끝나는 시간
	fscanf(stdin, "%d", &newnode_sd->end_time);
	if (newnode_sd->end_time < 8 || newnode_sd->end_time > 24) {
		fprintf(stdout, "Enter End Time (8:00 ~ 24:00) : ");
		fscanf(stdin, "%d", &newnode_sd->end_time);
	}
	fprintf(stdout, "Enter other details\n");
	fscanf(stdin, "%c", &garbage);
	fgets(newnode_sd->etc, 400, stdin);
	newnode_sd->next = sd_start;
	newnode_sd->prev = NULL;
	if (sd_start) {
		sd_start->prev = newnode_sd;
	}
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

			if (sd_current == sd_start) {
				sd_start = sd_start->next;
			}
			if (sd_current == sd_end) {
				sd_end = sd_end->prev;
			}

			if (sd_prev != NULL) {
				sd_prev->next = sd_next;
			}
			if (sd_next != NULL) {
				sd_next->prev = sd_prev;
			}
			
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
	fprintf(stdout, "\n\nEnter title of the schedule you want to search\n");
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
				fprintf(stdout, "Day of the week : Thursday\n");
			}
			else if (sd_current->dow == 5) {
				fprintf(stdout, "Day of the week : Friday\n");
			}
			else if (sd_current->dow == 6) {
				fprintf(stdout, "Day of the week : Saturday\n");
			}
			fprintf(stdout, "Start Time : %d\n", sd_current->start_time);
			fprintf(stdout, "End Time : %d\n", sd_current->end_time);
			fprintf(stdout, "\n[Other details]\n");
			puts(sd_current->etc);
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
	char c;

	system("cls");
	MM* newnode_mm;
	newnode_mm = (MM*)malloc(sizeof(MM));
	
	cursorInfo.bVisible = TRUE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);  //show cursor for entering title
	fprintf(stdout, "Enter Title : ");
	fgets(newnode_mm->title, 81, stdin);
	fprintf(stdout, "Enter year:month:date (yyyy mm dd) : ");
	scanf_s("%c", &c); //garbage
	scanf_s("%d %d %d", &newnode_mm->year, &newnode_mm->month, &newnode_mm->date);

	scanf_s("%c", &c); //garbage
	fprintf(stdout, "Enter memo\n");
	fgets(newnode_mm->memo, 1000, stdin);

	newnode_mm->next = mm_start;
	newnode_mm->prev = NULL;
	if (mm_start) {
		mm_start->prev = newnode_mm;
	}
	mm_start = newnode_mm;
	mm_count++;

	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);  //hide cursor
}

void del_mm(int num) {
	mm_current = mm_start;
	
	for (int i = 0; i < num; i++) {
		mm_current = mm_current->next;
	}

	mm_prev = mm_current->prev;
	mm_next = mm_current->next;

	if (mm_current == mm_start) {
		mm_start = mm_start->next;
	}
	if (mm_current == mm_end) {
		mm_end = mm_end->prev;
	}

	if (mm_prev != NULL) {
		mm_prev->next = mm_next;
	}
	if (mm_next != NULL) {
		mm_next->prev = mm_prev;
	}
	free(mm_current);
	mm_count--;
	
	fprintf(stdout, "\nDelete Success!\n");
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);  //hide cursor
}