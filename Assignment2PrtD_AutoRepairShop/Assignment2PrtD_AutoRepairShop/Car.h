//Justine Sultan
//Student Number: 35880146

#ifndef   __Car__
#define   __Car__

#include "Tire.h"
#include "../DataStructures.h"

class Car
{
private:
	struct oil* Oil; 
	int* oilFilter;
	int* airFilter;

	Tire* tireArray[4]; 

public:
	Car();
	~Car();

	void addTires(char* make, int size);		//will add 4 tires
	Tire* swapTire(int tireNum, Tire* newTire);	//will swap out 1 tire
	Tire* removeTire(int tireNum);				//will remove 1 tire
	
	struct oil* swapOil(struct oil* newOil);
	int* swapOilFilter(int* newOilFilter);
	int* swapAirFilter(int* newAirFilter); 
	int checkTire(int tireNum);
	void rotateTire(int tireNum);

};

#endif 