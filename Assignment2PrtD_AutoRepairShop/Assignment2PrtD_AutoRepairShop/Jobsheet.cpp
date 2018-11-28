//Justine Sultan
//Student Number: 35880146

#include "Jobsheet.h"
#include <stdio.h>
#include <string.h>

Jobsheet::Jobsheet()
{
	printf("Jobsheet being created \n");
	totalCost = 0; 
	getchar();
	return; 
}


Jobsheet::~Jobsheet()
{
	printf("Jobsheet destructor being called \n");
	getchar(); 
	return;
}

void Jobsheet::addItem(int partNumber, int quantity, float cost) {
	printf("The following part line item added to jobsheet: \n");
	printf("Part Number: %d    Quantity:%d    Cost:%f \n", partNumber, quantity, cost);
	getchar();
	totalCost += cost; 
	return; 
}

void Jobsheet::addLabourItem(char name[4], float cost) {
	printf("The following labour line item added to jobsheet: \n");
	printf("Name: %s    Cost:%f \n", name, cost);
	getchar();
	totalCost += cost;
	return;
}

float Jobsheet::getTotalCost(void) {
	return totalCost;
}
