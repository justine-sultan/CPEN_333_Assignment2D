//Justine Sultan
//Student Number: 35880146

#include "Tire.h"
#include <stdio.h>
#include <string.h>

Tire::Tire(int status, char* makeP, int sizeP)
{
	printf("Creating tire object with status=%d, make=%s, size=%d \n", status, makeP, sizeP);
	tireStatus = status; 
	make = makeP; 
	size = sizeP; 

	return;
}


Tire::~Tire()
{
	printf("Tire destructer being entered...destroying tire object \n");
	getchar();
	return; 
}

int Tire::getTireStatus(void) {
	return tireStatus; 
}
