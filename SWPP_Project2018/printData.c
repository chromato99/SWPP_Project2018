#include"Project_Header.h"

extern int sd_count;  // count of SD structs
extern SD* sd_start;  // start address of SD
extern SD* sd_next;
extern SD* sd_current;
extern SD* sd_prev;
extern SD* sd_end;  // end address of SD

void gotoxy(int x, int y)
{
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int printFirstMenu() {
	char key;
	int y = 0;
	system("cls");
	printf(" > Show Time Table\n");
	printf("   Show Memo\n");
	printf("   Exit Program");
	while (1) {
		if (kbhit()) {  //keyboard input
			key = getch();
			if (key == 80) { //upper direction key
				if (y < 2) {
					gotoxy(1, y++);
					putc(' ', stdout);
					gotoxy(1, y);
					putc('>', stdout);
				}

			}
			else if (key == 72 && y > 0) { //lower direction key
				gotoxy(1, y--);
				putc(' ', stdout);
				gotoxy(1, y);
				putc('>', stdout);
			}
			else if (key == 13) {  //enter key
				if (y == 0) {
					return 1;
				}
				else if (y == 1) {
					return 2;
				}
				else if (y == 2) {
					return 0;
				}
			}
		}
	}
}

void printSchedule() {
	int i = 0;
	int y = 11 + (sd_current->start_time - 8) * 8;
	gotoxy((5 + (sd_current->dow * 16)), y);
	while (sd_current->title[i]) {
		putchar(sd_current->title[i]);
		if (i % 15 == 14) {
			y++;
			gotoxy((5 + (sd_current->dow * 16)), y);
		}
		i++;
	}

}

void printTable() {
	while (1) {
		system("cls");
		gotoxy(0, 0);
		int time = 9;
		int day = 0;
		int col = 0;
		char input = "";


		// tab : array
		// title
		printf("\n");
		printf("\t\t");
		printf("<<\t T\tI\tM\tE \tT\tA\tB\tL\tE \t>>");
		printf("\n\n\n");
		printf("Week ");
		for (int top = 0; top < 55; top++) { // table top
			printf("= ");
		}
		printf("\n\n");

		// table day of week_individual line
		printf("  ");
		printf("|");
		printf("\tSunday\t  |\tMonday\t  |    Tuesday\t  |   Wednesday   |    Thursday\t  |     Friday\t  |   Saturday  ");
		printf("  ");
		printf("|");
		printf("\n\n");


		printf("08 ");
		for (int row = 0; row < 56; row++) {
			printf("- ");
		}
		printf("\n");
		for (int tab = 0; tab < 2; tab++) {
			printf("\t");
		}
		printf("\n");
		for (int side = 0; side < 15; side++) {


			for (int i = 0; i < 3; i++) {
				printf("  ");
				for (int col = 0; col < 7; col++)
				{
					printf("|");
					for (int tab = 0; tab < 2; tab++) {
						printf("\t");
					}
					printf("  ");
				}
				printf("|");
				printf("\n\n");
			}

			printf("%d ", time);
			if (time >= 9) {
				time++;
			}
			for (int row = 0; row < 56; row++) {
				printf("- ");
			}
			printf("\n\n");
		}
		for (int i = 0; i < 3; i++) {   // individual line
			printf("  ");
			for (int col = 0; col < 7; col++)
			{

				printf("|");
				for (int tab = 0; tab < 2; tab++) {
					printf("\t");
				}
				printf("  ");
			}
			printf("|");
			printf("\n\n");
		}

		printf("%d ", time);
		for (int floor = 0; floor < 56; floor++) {
			printf("= ");
		}

		sd_current = sd_start;

		while (sd_current) {
			printSchedule();
			sd_current = sd_current->next;
		}
		int n = 0;
		n = printTableMenu();
		if (n == 1) {
			gotoxy(0, 144);
			add_sd();
		}
		else if (n == 2) {
			gotoxy(0, 144);
			del_sd();
		}
		else if (n == 3) {
			gotoxy(0, 144);
			search_sd();
		}
	}
}

int printTableMenu() {
	char key;
	int x = 1;
	int check = 1;

	printf(" > Add schedule    Delete Schedule    Search Detail    Back to first menu\n");

	while (1) {
		if (kbhit()) {  //keyboard input
			key = getch();
			if (key == 75) { //left direction key
				
				if (check == 2) {
					gotoxy(--x, 142);
					putc(' ', stdout);
					x = 1;
					gotoxy(x, 142);
					putc('>', stdout);
					check--;
				}
				else if (check == 3) {
					gotoxy(--x, 142);
					putc(' ', stdout);
					x = 17;
					gotoxy(x, 142);
					putc('>', stdout);
					check--;
				}
				else if (check == 4) {
					gotoxy(--x, 142);
					putc(' ', stdout);
					x = 36;
					gotoxy(x, 142);
					putc('>', stdout);
					check--;
				}

			}
			else if (key == 77) { //lower direction key
				if (check == 1) {
					gotoxy(--x, 142);
					putc(' ', stdout);
					x = 17;
					gotoxy(x, 142);
					putc('>', stdout);
					check++;
				}
				else if (check == 2) {
					gotoxy(--x, 142);
					putc(' ', stdout);
					x = 36;
					gotoxy(x, 142);
					putc('>', stdout);
					check++;
				}
				else if (check == 3) {
					gotoxy(--x, 142);
					putc(' ', stdout);
					x = 53;
					gotoxy(x, 142);
					putc('>', stdout);
					check++;
				}
			}
			else if (key == 13) {  //enter key
				if (x == 1) {
					return 1;
				}
				else if (x == 17) {
					return 2;
				}
				else if (x == 36) {
					return 3;
				}
				else if (x == 53) {
					return 0;
				}
			}
		}
	}
}

void printMemoList() {
	system("cls");

}