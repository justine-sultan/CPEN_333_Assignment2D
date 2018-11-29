//Justine Sultan
//Student Number: 35880146

#ifndef   __Garbage__
#define   __Garbage__

class Garbage
{

public:
	Garbage();								//Constructor
	~Garbage();								//Destructor

	void disposeFilter(int* filter);		//Input: filter to dispose of. Disposes of filter (deletes filter object)
};

#endif 