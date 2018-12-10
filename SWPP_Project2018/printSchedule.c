#include"Project_Header.h"

void gotoxy(int x, int y)
{
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void main() {

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

	if (time == 8)
	{
		if (day == 0) {  // day==0==老
			gotoxy(5, 11);
			printf("%s", input);
		}
		else if (day == 1) {   // day==1==岿
			gotoxy(21, 11);
			printf("%s", input);
		}
		else if (day == 2) {   // day==2==拳
			gotoxy(37, 11);
			printf("%s", input);
		}
		else if (day == 3) {   // day==3==荐
			gotoxy(53, 11);
			printf("%s", input);
		}
		else if (day == 4) {   // day==4==格
			gotoxy(69, 11);
			printf("%s", input);
		}
		else if (day == 5) {   // day==5==陛
			gotoxy(85, 11);
			printf("%s", input);
		}
		else {
			gotoxy(101, 11);   // day==6==配
			printf("%s", input);
		}
	}
	else if (time == 9)
	{
		if (day == 0) {  // day==0==老
			gotoxy(5, 19);
			printf("%s", input);
		}
		else if (day == 1) {
			gotoxy(21, 19);
			printf("%s", input);
		}
		else if (day == 2) {
			gotoxy(37, 19);
			printf("%s", input);
		}
		else if (day == 3) {
			gotoxy(53, 19);
			printf("%s", input);
		}
		else if (day == 4) {
			gotoxy(69, 19);
			printf("%s", input);
		}
		else if (day == 5) {
			gotoxy(85, 19);
			printf("%s", input);
		}
		else {
			gotoxy(101, 19);
			printf("%s", input);
		}
	}
	else if (time == 10)
	{
		if (day == 0) {  // day==0==老
			gotoxy(5, 27);
			printf("%s", input);
		}
		else if (day == 1) {
			gotoxy(21, 27);
			printf("%s", input);
		}
		else if (day == 2) {
			gotoxy(37, 27);
			printf("%s", input);
		}
		else if (day == 3) {
			gotoxy(53, 27);
			printf("%s", input);
		}
		else if (day == 4) {
			gotoxy(69, 27);
			printf("%s", input);
		}
		else if (day == 5) {
			gotoxy(85, 27);
			printf("%s", input);
		}
		else {
			gotoxy(101, 27);
			printf("%s", input);
		}
	}
	else if (time == 11)
	{
		if (day == 0) {  // day==0==老
			gotoxy(5, 35);
			printf("%s", input);
		}
		else if (day == 1) {
			gotoxy(21, 35);
			printf("%s", input);
		}
		else if (day == 2) {
			gotoxy(37, 35);
			printf("%s", input);
		}
		else if (day == 3) {
			gotoxy(53, 35);
			printf("%s", input);
		}
		else if (day == 4) {
			gotoxy(69, 35);
			printf("%s", input);
		}
		else if (day == 5) {
			gotoxy(85, 35);
			printf("%s", input);
		}
		else {
			gotoxy(101, 35);
			printf("%s", input);
		}
	}
	else if (time == 12)
	{
		if (day == 0) {  // day==0==老
			gotoxy(5, 43);
			printf("%s", input);
		}
		else if (day == 1) {
			gotoxy(21, 43);
			printf("%s", input);
		}
		else if (day == 2) {
			gotoxy(37, 43);
			printf("%s", input);
		}
		else if (day == 3) {
			gotoxy(53, 43);
			printf("%s", input);
		}
		else if (day == 4) {
			gotoxy(69, 43);
			printf("%s", input);
		}
		else if (day == 5) {
			gotoxy(85, 43);
			printf("%s", input);
		}
		else {
			gotoxy(101, 43);
			printf("%s", input);
		}
	}
	else if (time == 13)
	{
		if (day == 0) {  // day==0==老
			gotoxy(5, 51);
			printf("%s", input);
		}
		else if (day == 1) {
			gotoxy(21, 51);
			printf("%s", input);
		}
		else if (day == 2) {
			gotoxy(37, 51);
			printf("%s", input);
		}
		else if (day == 3) {
			gotoxy(53, 51);
			printf("%s", input);
		}
		else if (day == 4) {
			gotoxy(69, 51);
			printf("%s", input);
		}
		else if (day == 5) {
			gotoxy(85, 51);
			printf("%s", input);
		}
		else {
			gotoxy(101, 51);
			printf("%s", input);
		}
	}
	else if (time == 14)
	{
		if (day == 0) {  // day==0==老
			gotoxy(5, 59);
			printf("%s", input);
		}
		else if (day == 1) {
			gotoxy(21, 59);
			printf("%s", input);
		}
		else if (day == 2) {
			gotoxy(37, 59);
			printf("%s", input);
		}
		else if (day == 3) {
			gotoxy(53, 59);
			printf("%s", input);
		}
		else if (day == 4) {
			gotoxy(69, 59);
			printf("%s", input);
		}
		else if (day == 5) {
			gotoxy(85, 59);
			printf("%s", input);
		}
		else {
			gotoxy(101, 59);
			printf("%s", input);
		}
	}
	else if (time == 15)
	{
		if (day == 0) {  // day==0==老
			gotoxy(5, 67);
			printf("%s", input);
		}
		else if (day == 1) {
			gotoxy(21, 67);
			printf("%s", input);
		}
		else if (day == 2) {
			gotoxy(37, 67);
			printf("%s", input);
		}
		else if (day == 3) {
			gotoxy(53, 67);
			printf("%s", input);
		}
		else if (day == 4) {
			gotoxy(69, 67);
			printf("%s", input);
		}
		else if (day == 5) {
			gotoxy(85, 67);
			printf("%s", input);
		}
		else {
			gotoxy(101, 67);
			printf("%s", input);
		}
	}
	else if (time == 16)
	{
		if (day == 0) {  // day==0==老
			gotoxy(5, 75);
			printf("%s", input);
		}
		else if (day == 1) {
			gotoxy(21, 75);
			printf("%s", input);
		}
		else if (day == 2) {
			gotoxy(37, 75);
			printf("%s", input);
		}
		else if (day == 3) {
			gotoxy(53, 75);
			printf("%s", input);
		}
		else if (day == 4) {
			gotoxy(69, 75);
			printf("%s", input);
		}
		else if (day == 5) {
			gotoxy(85, 75);
			printf("%s", input);
		}
		else {
			gotoxy(101, 75);
			printf("%s", input);
		}
	}
	else if (time == 17)
	{
		if (day == 0) {  // day==0==老
			gotoxy(5, 83);
			printf("%s", input);
		}
		else if (day == 1) {
			gotoxy(21, 83);
			printf("%s", input);
		}
		else if (day == 2) {
			gotoxy(37, 83);
			printf("%s", input);
		}
		else if (day == 3) {
			gotoxy(53, 83);
			printf("%s", input);
		}
		else if (day == 4) {
			gotoxy(69, 83);
			printf("%s", input);
		}
		else if (day == 5) {
			gotoxy(85, 83);
			printf("%s", input);
		}
		else {
			gotoxy(101, 83);
			printf("%s", input);
		}
	}
	else if (time == 18)
	{
		if (day == 0) {  // day==0==老
			gotoxy(5, 91);
			printf("%s", input);
		}
		else if (day == 1) {
			gotoxy(21, 91);
			printf("%s", input);
		}
		else if (day == 2) {
			gotoxy(37, 91);
			printf("%s", input);
		}
		else if (day == 3) {
			gotoxy(53, 91);
			printf("%s", input);
		}
		else if (day == 4) {
			gotoxy(69, 91);
			printf("%s", input);
		}
		else if (day == 5) {
			gotoxy(85, 91);
			printf("%s", input);
		}
		else {
			gotoxy(101, 91);
			printf("%s", input);
		}
	}
	else if (time == 19)
	{
		if (day == 0) {  // day==0==老
			gotoxy(5, 99);
			printf("%s", input);
		}
		else if (day == 1) {
			gotoxy(21, 99);
			printf("%s", input);
		}
		else if (day == 2) {
			gotoxy(37, 99);
			printf("%s", input);
		}
		else if (day == 3) {
			gotoxy(53, 99);
			printf("%s", input);
		}
		else if (day == 4) {
			gotoxy(69, 99);
			printf("%s", input);
		}
		else if (day == 5) {
			gotoxy(85, 99);
			printf("%s", input);
		}
		else {
			gotoxy(101, 99);
			printf("%s", input);
		}
	}

	else if (time == 20)
	{
		if (day == 0) {  // day==0==老
			gotoxy(5, 107);
			printf("%s", input);
		}
		else if (day == 1) {
			gotoxy(21, 107);
			printf("%s", input);
		}
		else if (day == 2) {
			gotoxy(37, 107);
			printf("%s", input);
		}
		else if (day == 3) {
			gotoxy(53, 107);
			printf("%s", input);
		}
		else if (day == 4) {
			gotoxy(69, 107);
			printf("%s", input);
		}
		else if (day == 5) {
			gotoxy(85, 107);
			printf("%s", input);
		}
		else {
			gotoxy(101, 107);
			printf("%s", input);
		}
	}
	else if (time == 21)
	{
		if (day == 0) {  // day==0==老
			gotoxy(5, 115);
			printf("%s", input);
		}
		else if (day == 1) {
			gotoxy(21, 115);
			printf("%s", input);
		}
		else if (day == 2) {
			gotoxy(37, 115);
			printf("%s", input);
		}
		else if (day == 3) {
			gotoxy(53, 115);
			printf("%s", input);
		}
		else if (day == 4) {
			gotoxy(69, 115);
			printf("%s", input);
		}
		else if (day == 5) {
			gotoxy(85, 115);
			printf("%s", input);
		}
		else {
			gotoxy(101, 115);
			printf("%s", input);
		}
	}
	else if (time == 22)
	{
		if (day == 0) {  // day==0==老
			gotoxy(5, 123);
			printf("%s", input);
		}
		else if (day == 1) {
			gotoxy(21, 123);
			printf("%s", input);
		}
		else if (day == 2) {
			gotoxy(37, 123);
			printf("%s", input);
		}
		else if (day == 3) {
			gotoxy(53, 123);
			printf("%s", input);
		}
		else if (day == 4) {
			gotoxy(69, 123);
			printf("%s", input);
		}
		else if (day == 5) {
			gotoxy(85, 123);
			printf("%s", input);
		}
		else {
			gotoxy(101, 123);
			printf("%s", input);
		}
	}
	else if (time == 23)
	{
		if (day == 0) {  // day==0==老
			gotoxy(5, 131);
			printf("%s", input);
		}
		else if (day == 1) {
			gotoxy(21, 131);
			printf("%s", input);
		}
		else if (day == 2) {
			gotoxy(37, 131);
			printf("%s", input);
		}
		else if (day == 3) {
			gotoxy(53, 131);
			printf("%s", input);
		}
		else if (day == 4) {
			gotoxy(69, 131);
			printf("%s", input);
		}
		else if (day == 5) {
			gotoxy(85, 131);
			printf("%s", input);
		}
		else {
			gotoxy(101, 131);
			printf("%s", input);
		}
	}


}