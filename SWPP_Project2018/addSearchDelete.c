#include"Project_Header.h"

extern int sd_count;  // count of SD structs
extern SD* start;  // start address of SD
extern SD* next;
extern SD* current;
extern SD* prev;
extern SD* end;  // end address of SD

int startASD() {
	int input;
	fprintf(stdout, "------------------------------------------------------------------------------------------");
	fprintf(stdout, "\n\n0. Show Schedule\n1. Add schedule\n2. Delete scedule\n3. Search schedule\n-1. end program\n\nInput : ");
	fscanf(stdin, "%d", &input);
	if (input == 0) {

	}
	if (input == 1) {
		add();
	}
	else if (input == 2) {
		del();
	}
	else if (input == 3) {
		search();
	}
	else if (input == -1)
		return -1;
}

void add() {
	SD *newnode;
	newnode = (SD*)malloc(sizeof(SD));
	fprintf(stdout, "Enter Title : ");
	fgets(stdin, 81, newnode->title);
	fprintf(stdout, "Enter Subject : ");
	fgets(stdin, 81, newnode->subject);
	fprintf(stdout, "Enter Place : ");
	fgets(stdin, 81, newnode->place);
	fprintf(stdout, "Enter People : ");
	fgets(stdin, 81, newnode->people);
	fprintf(stdout, "Enter Year(ex 2018) : ");
	fscanf(stdin, "%d", &newnode->year);
	fprintf(stdout, "Enter Month(ex 05) : ");
	fscanf(stdin, "%d", &newnode->month);
	fprintf(stdout, "Enter Date(ex 05) : ");
	fscanf(stdin, "%d", &newnode->date);
	fprintf(stdout, "Enter Start Time (8:00 ~ 24:00) : ");
	fscanf(stdin, "%d", &newnode->start_time);
	if (newnode->start_time < 8 || newnode->start_time > 24) {
		fprintf(stdout, "Enter Start Time (8:00 ~ 24:00) : ");
		fscanf(stdin, "%d", &newnode->start_time);
	}
	fprintf(stdout, "Enter End Time (8:00 ~ 24:00) : ");
	fscanf(stdin, "%d", &newnode->end_time);
	if (newnode->end_time < 8 || newnode->end_time > 24) {
		fprintf(stdout, "Enter End Time (8:00 ~ 24:00) : ");
		fscanf(stdin, "%d", &newnode->end_time);
	}
	fprintf(stdout, "Enter other details\n");
	fgets(stdin, 400, newnode->etc);
	newnode->next = start;
	start = newnode;
	sd_count++;
}

void del() {

	current = start;
	char del[81];
	fprintf(stdout, "\n\nEnter title of the schedule you want to delete\n");
	fgets(stdin, 81, del);
	while (current) {
		prev = current->prev;
		next = current->next;

		if (strcmp(current->title, del) == 0) {
			prev->next = next;
			fprintf(stdout, "\n*Deleted Success!*\n");
			break;
		}
		
		current = current->next;
	}
	sd_count--;
}

void search() {
	char search[81];
	current = start;
	printf(stdout, "\n\nEnter title of the schedule you want to search\n");
	fgets(stdin, 81, search);
	while (current) {
		if (strcmp(current->title, search) == 0) {
			fprintf(stdout, "Title : ");
			fputs(stdout, current->title);
			fprintf(stdout, "Subject : ");
			fputs(stdout, current->subject);
			fprintf(stdout, "Place : ");
			fputs(stdout, current->place);
			fprintf(stdout, "People : ");
			fputs(stdin, current->people);
			fprintf(stdout, "Date(yyyy:mm:dd) : %d:%d:%d", current->year, current->month, current->date);
			fprintf(stdout, "Start Time : %d", current->start_time);
			fprintf(stdout, "End Time : ", current->end_time);
			fprintf(stdout, "Other details\n");
			fputs(stdout, current->etc);
			break;
		}
		current = current->next;
	}
	if (current == NULL) {
		fprintf(stdout, "\nFail to find the schedule\n");
	}
}