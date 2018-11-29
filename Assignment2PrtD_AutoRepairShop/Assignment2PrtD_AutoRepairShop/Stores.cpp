//Justine Sultan
//Student Number: 35880146

#include "Stores.h"
#include <stdio.h>
#include "Tire.h"
#include "../DataStructures.h"

Stores::Stores()
{
	printf("Creating store \n");
	return;
}


Stores::~Stores()
{
	printf("Destroying store \n");
	return;
}

struct oil* Stores::getOil(int type, int amount) {
	printf("New oil taken out of stores. Type = %d and amount = %d \n", type, amount);
	getchar(); 
	struct oil* temp = new oil;
	temp->amount = amount;
	temp->type = type; 
	return temp; 
}

int* Stores::getAirFilter(void) {
	printf("Air filter taken out of stores\n");
	getchar();
	int* temp = new int; 
	*temp = 1; 
	return temp; 
}

int* Stores::getOilFilter(void) {
	printf("Oil filter taken out of stores \n");
	getchar();
	int* temp = new int;
	*temp = 2;
	return temp;
}

Tire* Stores::getTire(char* make, int size, int status) {
	printf("New tire taken out of stores. Make = %s, size = %d, and status = %d \n", make, size, status);
	getchar();
	Tire* temp = new Tire(status, make, size);
	return temp; 
}
