//Justine Sultan
//Student Number: 35880146

#include "Garbage.h"
#include <stdio.h>

Garbage::Garbage()
{
	printf("Creating garbage object \n");
	return; 
}


Garbage::~Garbage()
{
	printf("Destroying garbage object \n");
	getchar();
	return;
}

void Garbage::disposeFilter(int* filter)
{
	printf("Disposing of filter \n"); 
	getchar();
	delete filter;
	return;
}