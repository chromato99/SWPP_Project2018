//Software Programing Pattern Clss's term project
//Writed in 2018.DEC

#include"Project_Header.h"
#include"addSearchDelete.h"

int sd_count;  // count of SD structs
SD* start;  // start address of SD
SD* next;
SD* current;
SD* prev;
SD* end;  // end address of SD

int main() {
	int num;
	encrypt();
	while (num) {
		num = mainWork();
	}
	decrypt();

    return 0;
}