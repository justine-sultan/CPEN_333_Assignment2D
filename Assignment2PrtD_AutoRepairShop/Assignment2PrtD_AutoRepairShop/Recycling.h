//Justine Sultan
//Student Number: 35880146

#ifndef   __Recycling__
#define   __Recycling__

#include "Tire.h"

class Recycling
{
public:
	Recycling();
	~Recycling();

	void recycleOil(struct oil* oldOil); 
	void recycleTire(Tire* oldTire); 
};

#endif 