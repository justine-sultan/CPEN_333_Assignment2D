//Justine Sultan
//Student Number: 35880146

#ifndef   __Stores__
#define   __Stores__

#include "Tire.h"

class Stores
{
public:
	Stores();											//Constructor
	~Stores();											//Destructor

	struct oil* getOil(int type, int amount);			//Input: type and amount of oil, Output: new oil. Returns the specified oil
	int* getAirFilter(void);							//Output: new air filter struct. Returns a new air filter
	int* getOilFilter(void);							//Ouput: new oild fitler struct. Returns a new oil filter
	Tire* getTire(char* make, int size, int status);	//Input: tire make (3 character code), size, and status (1 = good, 0 = worn). Returns the requested tire object

};

#endif 
