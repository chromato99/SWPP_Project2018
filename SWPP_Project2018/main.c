//Software Programing Pattern Clss's term project
//Writed in 2018.DEC

#include<stdio.h>
#include<stdlib.h>

typedef struct schedule {
    char title[81];
    char subject[81];
    char place[81];
    char people[81];
    int year;
    int month;
    int date;
    int start_time;
    int end_time;
    char etc[400];
    struct schedule* next;
    struct schedule* prev;
}SD;

int sd_count;  // count of SD structs
SD* start;  // start address of SD
SD* end;  // end address of SD

int main() {
	printf("test");

    return 0;
}