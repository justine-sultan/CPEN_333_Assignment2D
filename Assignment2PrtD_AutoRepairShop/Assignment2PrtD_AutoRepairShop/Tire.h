//Justine Sultan
//Student Number: 35880146

#ifndef   __Tire__
#define   __Tire__

class Tire
{
private:
	int tireStatus;									//Status of tire: 0 = worn, 1 = good
	char* make;										//Make of tire (3 character code, e.g. "ABC")
	int size;										//Size of tire

public:
	Tire(int status, char* makeP, int sizeP);		//Constructor: must specify the status, make, and size of tire 
	~Tire();										//Destructor

	int getTireStatus(void);						//Output: status of tire. Returns the status of the tire object (see tireStatus member variable above)
};

#endif 

