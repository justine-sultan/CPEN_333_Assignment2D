//Justine Sultan
//Student Number: 35880146

#include "Car.h"
#include <stdio.h>
#include <string.h>
#include "../DataStructures.h"

Car::Car()
{
	printf("Creating car object....\n");
	Oil = new struct oil;
	oilFilter = new int;
	airFilter = new int; 
	Oil->amount = 1;
	Oil->type = 5; 
	*oilFilter = 2;
	*airFilter = 3;
	printf("Oil type:%d, Oil amount:%d,Oil Filter Type: %d, Oil Filter Amount: %d \n", Oil->amount, Oil->type, *oilFilter, *airFilter);
	printf("Car currently does not have tires. Please add tires...\n"); 
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
	tireArray[3] = new Tire(0, make, 5);		//create tire 4 as worn for demo
}

Tire* Car::swapTire(int tireNum, Tire* newTire)
{
	printf("Swapping Tire %d \n", tireNum);
	getchar();
	Tire* temp = tireArray[tireNum];
	tireArray[tireNum] = newTire; 
	return temp; 

}

struct oil* Car::swapOil(struct oil* newOil)
{
	printf("Swapping Oil. \n");
	getchar();
	struct oil* temp;
	temp = Oil;
	Oil = newOil;
	printf("New oil put in car.\n");
	return temp; 
}

int* Car::swapOilFilter(int* newOilFilter) {
	printf("Swapping oil filter \n");
	getchar();
	int* temp = oilFilter;
	oilFilter = newOilFilter;
	printf("New oil filter put in car.\n");
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
	printf("Checking Tire %d....", tireNum);
	getchar();
	int retVal = tireArray[tireNum]->getTireStatus();
	printf("Tire %d status is %d  (0=worn, 1=good) \n", tireNum, retVal);
	getchar(); 
	return retVal; 
}

void Car::rotateTire(int tireNum) {
	printf("Rotating tire %d...", tireNum);
	getchar();
	return; 
}