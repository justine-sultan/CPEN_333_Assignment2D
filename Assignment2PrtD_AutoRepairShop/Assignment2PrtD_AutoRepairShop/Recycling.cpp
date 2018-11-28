//Justine Sultan
//Student Number: 35880146

#include "Recycling.h"
#include <stdio.h>
#include "Tire.h"
#include "../DataStructures.h"

Recycling::Recycling()
{
	printf("Creating recycling object \n");
	return;
}


Recycling::~Recycling()
{
	printf("Destroying recycling object \n");
	return;
}

void Recycling::recycleOil(struct oil* oldOil)
{
	printf("Recycling %d liters of old Oil", oldOil->amount); 
	getchar(); 
	delete oldOil; 
}

void Recycling::recycleTire(Tire* oldTire) {
	printf("Recycling tire \n");
	getchar();
	delete oldTire; 
}