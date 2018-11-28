//Justine Sultan
//Student Number: 35880146

#ifndef   __Tire__
#define   __Tire__

class Tire
{
private:
	int tireStatus;
	char* make; 
	int size; 

public:
	Tire(int status, char* makeP, int sizeP);
	~Tire();

	int getTireStatus(void);
};

#endif 

