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

void add_sd() {
	SD *newnode_sd;
	newnode_sd = (SD*)malloc(sizeof(SD));
	fprintf(stdout, "Enter Title : ");
	fgets(stdin, 81, newnode_sd->title);
	fprintf(stdout, "Enter Subject : ");
	fgets(stdin, 81, newnode_sd->subject);
	fprintf(stdout, "Enter Place : ");
	fgets(stdin, 81, newnode_sd->place);
	fprintf(stdout, "Enter People : ");
	fgets(stdin, 81, newnode_sd->people);
	
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
	fgets(stdin, 400, newnode_sd->etc);
	newnode_sd->next = sd_start;
	sd_start = newnode_sd;
	sd_count++;
	system("pause");
}

void del_sd() {

	sd_current = sd_start;
	char del[81];
	fprintf(stdout, "\n\nEnter title of the schedule you want to delete\n");
	fgets(stdin, 81, del);
	while (sd_current) {
		sd_prev = sd_current->prev;
		sd_next = sd_current->next;

		if (strcmp(sd_current->title, del) == 0) {
			sd_prev->next = sd_next;
			fprintf(stdout, "\n*Deleted Success!*\n");
			sd_count--;
			system("pause");
			return;
		}
		
		sd_current = sd_current->next;
	}
	fprintf(stdout, "\nFail to delete data\nNo such file name\n");
	system("pause");
}

void search_sd() {
	char search[81];
	sd_current = sd_start;
	printf(stdout, "\n\nEnter title of the schedule you want to search\n");
	fgets(stdin, 81, search);
	while (sd_current) {
		if (strcmp(sd_current->title, search) == 0) {
			fprintf(stdout, "Title : ");
			fputs(stdout, sd_current->title);
			fprintf(stdout, "Subject : ");
			fputs(stdout, sd_current->subject);
			fprintf(stdout, "Place : ");
			fputs(stdout, sd_current->place);
			fprintf(stdout, "People : ");
			fputs(stdin, sd_current->people);
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
			fputs(stdout, sd_current->etc);
			system("pause");
			return;
		}
		sd_current = sd_current->next;
	}
	if (sd_current == NULL) {
		fprintf(stdout, "\nFail to find the schedule\n");
	}
	system("pause");
}