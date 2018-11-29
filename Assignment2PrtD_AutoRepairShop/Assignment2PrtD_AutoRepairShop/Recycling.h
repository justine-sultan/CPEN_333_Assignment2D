//Justine Sultan
//Student Number: 35880146

#ifndef   __Recycling__
#define   __Recycling__

#include "Tire.h"

class Recycling
{
public:
	Recycling();								//Constructor
	~Recycling();								//Destructor

	void recycleOil(struct oil* oldOil);		//Input: Oil oil. Recyles old oil (deletes the struct)
	void recycleTire(Tire* oldTire);			//Input: old tire. Recylces old tire (deletes the object)
};

#endif 