//Justine Sultan
//Student Number: 35880146

#ifndef   __Stores__
#define   __Stores__

#include "Tire.h"

class Stores
{
public:
	Stores();
	~Stores();

	struct oil* getOil(int type, int amount);
	int* getAirFilter(void);
	int* getOilFilter(void);
	Tire* getTire(char* make, int size, int status); 
};

#endif 
