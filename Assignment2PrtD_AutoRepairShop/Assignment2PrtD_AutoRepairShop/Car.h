//Justine Sultan
//Student Number: 35880146

#ifndef   __Car__
#define   __Car__

#include "Tire.h"
#include "../DataStructures.h"

class Car
{
private:
	struct oil* Oil;								//Data structure representing oil (contains type and amount)
	int* oilFilter;									//Int represents oil filter
	int* airFilter;									//Int represents air filter

	Tire* tireArray[4];								//Array of tire objects: Agreggation, multiplicity of 4

public:
	Car();
	~Car();

	void addTires(char* make, int size);			//Input: make (3 character code), size. Will 4 tires to the car (create 4 associations with tire objects)
	Tire* swapTire(int tireNum, Tire* newTire);		//Input: Number (index) of tire to swap, new tire. Output: old tire. Will swap out selected tire and return the old tire. 
	Tire* removeTire(int tireNum);					//Output: old tire. Will remove the one selected tire and return the old tire
	
	struct oil* swapOil(struct oil* newOil);		//Input: new oil, Output: old oil. Will swap old oil for new oil, and return old oil struct for disposal
	int* swapOilFilter(int* newOilFilter);			//Input: new oil filter, Output: old oil filter. Will swap old and new oil filters and return old oil filter for disposal
	int* swapAirFilter(int* newAirFilter);			//Input: new air filter, Output: old air filter. Will swap old and new air filters and return old air filter for disposal
	int checkTire(int tireNum);						//Input: Number (index) of tire, Output: status of tire (1 = good, 0 = worn). Checks the status of selected tire and returns status
	void rotateTire(int tireNum);					//Input: Number (index) of tire. Rotates the selected tire. 

};

#endif 