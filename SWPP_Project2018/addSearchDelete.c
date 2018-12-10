#include"addSearchDelete.h"

extern int sd_count;  // count of SD structs
extern SD* start;  // start address of SD
extern SD* end;  // end address of SD

void startASD() {
	int input;
	while (1) {
		printf("------------------------------------------------------------------------------------------");
		printf("\n\n1. add schedule\n2. delete scedule\n3. search schedule\n4. show\n-1. end program\nInput : ");
		scanf("%d", &input);
		if (input == 1) {
			add();
		}
		else if (input == 2) {
			del();
		}
		else if (input == 3) {
			search();
		}
		else if (input == 4) {
			show();
		}
		else if (input == -1)
			break;
	}
}

void add() {
	SD *newnode;
	newnode = (SD*)malloc(sizeof(SD));
	printf("Enter Title : ");
	gets(newnode->title);
	printf("Enter Subject : ");
	gets(newnode->subject);
	printf("Enter place : ");
	gets(newnode->place);
	printf("Enter People : ");
	gets(newnode->people);
	printf("Enter year(ex 2018) : ");
	scanf("%d", &newnode->year);
	printf("Enter month(ex 05) : ");
	scanf("%d", &newnode->month);
	printf("Enter date(ex 05) : ");
	scanf("%d", &newnode->date);
	printf("Enter Start Time : ");
	scanf("%d", &newnode->start_time);
	printf("Enter End Time : ");
	scanf("%d", &newnode->end_time);
	printf("Enter the details\n");
	gets(newnode->etc);
	newnode->next = start;
	start = newnode;
	sd_count++;
}

void del() {
	SD *ptr, *oldptr = NULL;
	ptr = start;
	char del[81];
	printf("enter title of the schedule you would delete\n");
	scanf("%s", del);
	while (ptr) {
		if (strcmp(ptr->title, del) == 0) {
			oldptr->next = ptr->next;
			break;
		}
		oldptr = ptr;
		ptr = ptr->next;

	}
	sd_count--;
}

void search() {
	char search[81];
	SD *pt;
	pt = start;
	printf("enter title of the schedule you want to search\n");
	scanf("%s", search);
	while (pt) {
		if (strcmp(pt->title, search) == 0) {
			printf("title: %s ,subject: %s, place: %s, start time: %d, end time: %d detals: %s\n", pt->title, pt->subject, pt->place, pt->start_time, pt->end_time, pt->etc);
			break;
		}
		pt = pt->next;
	}
}

void show() {
	SD *t;
	t = start->next;
	while (t != NULL) {
		printf("%s %s %s %d %d %s\n", t->title, t->subject, t->place, t->start_time, t->end_time, t->etc);
		t = t->next;
	}
}