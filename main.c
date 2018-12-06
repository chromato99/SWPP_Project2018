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

int sd_count;
SD* start;
SD* end;

int main() {


    return 0;
}