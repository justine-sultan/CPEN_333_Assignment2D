//Justine Sultan
//Student Number: 35880146

#include "Car.h"
#include <stdio.h>
#include <string.h>
#include "../DataStructures.h"

Car::Car()
{
	printf("Creating car object with the following components....\n");
	Oil = new struct oil;
	oilFilter = new int;
	airFilter = new int; 
	Oil->amount = 1;
	Oil->type = 5; 
	*oilFilter = 2;
	*airFilter = 3;
	printf("Oil type: %d     Oil amount: %d \nOil Filter Type: %d     Oil Filter Amount: %d \n", Oil->amount, Oil->type, *oilFilter, *airFilter);
	printf("Car currently does not have tires. Please add tires....\n"); 
	for (int i = 0; i < 4; i++) {
		tireArray[i] = nullptr; 
	}

	return;
}


Car::~Car()
{
	printf("Destroying car object \n");
	delete Oil;
	delete oilFilter;
	delete airFilter; 
	return;
}

void Car::addTires(char* make, int size)
{
	printf("Adding Tires to car \n");
	getchar(); 
	for (int i = 0; i < 3; i++) {
		tireArray[i] = new Tire(1, make, 5); 
	}
	tireArray[3] = new Tire(0, make, 5);		//Note: creating tire 4 as "worn" for demo (so that technician can swap out tire)
}

Tire* Car::swapTire(int tireNum, Tire* newTire)
{
	printf("Swapping Tire %d \n", (tireNum+1));
	getchar();
	Tire* temp = tireArray[tireNum];
	tireArray[tireNum] = newTire; 
	return temp; 

}

Tire* Car::removeTire(int tireNum)
{
	printf("Removing Tire %d from car \n", (tireNum + 1));
	Tire* temp = tireArray[tireNum];
	tireArray[tireNum] = nullptr;
	return temp; 
}

struct oil* Car::swapOil(struct oil* newOil)
{
	printf("Swapping Oil. \n");
	struct oil* temp;
	temp = Oil;
	Oil = newOil;
	printf("New oil put in car.\n");
	getchar();
	return temp; 
}

int* Car::swapOilFilter(int* newOilFilter) {
	printf("Swapping oil filter \n");
	int* temp = oilFilter;
	oilFilter = newOilFilter;
	printf("New oil filter put in car.\n");
	getchar();
	return temp; 
}

int* Car::swapAirFilter(int* newAirFilter) {
	printf("Swapping air filter \n");
	getchar();
	int* temp = airFilter;
	airFilter = newAirFilter;
	printf("New air filter being put in car.\n");
	return temp;
}

int Car::checkTire(int tireNum) {
	printf("Checking Tire %d....", (tireNum+1));
	getchar();
	int retVal = tireArray[tireNum]->getTireStatus();
	printf("Tire %d status is %d  (0: worn, 1: good) \n", (tireNum+1), retVal);
	getchar(); 
	return retVal; 
}

void Car::rotateTire(int tireNum) {
	printf("Rotating tire %d...", (tireNum+1));
	getchar();
	return; 
}