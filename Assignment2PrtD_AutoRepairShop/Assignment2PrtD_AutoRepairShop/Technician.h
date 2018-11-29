//Justine Sultan
//Student Number: 35880146

#ifndef   __Technician__
#define   __Technician__

#include "Jobsheet.h"
#include "Car.h"
#include "Garbage.h"
#include "Recycling.h"
#include "Stores.h"
#include "..\DataStructures.h"
#include "..\rt.h"

class Technician : public ActiveClass
{
private:
	//associations:
	Car * custCar;								//Customer's car: unidirectional association
	Jobsheet* custJobsheet;						//Jobsheet: Created during service routine, and passed to customer at end (not deleted). Unidirectional association
	Garbage* garbage;							//Garbage disposal: unidirectional association
	Recycling* recycling;						//Recycler: unidirectional association
	Stores* stores;								//Stores: unidirectional association

	int main(void);

public:
	Technician();								//Constructor
	~Technician();								//Destructor

	//For the following add and swap associations functions, Input the new objects to add/swap and (for swap) the old object.
	//If you do not want to change the association for a certain object, enter nullptr for that corresponding argument.
	void addAsociations(Garbage* garbageP = nullptr, Recycling* recyclingP = nullptr, Stores* storesP = nullptr);
	void swapAssociations(Garbage* garbageP = nullptr, Recycling* recyclingP = nullptr, Stores* storesP = nullptr, 
		                 Garbage* newgarbageP = nullptr, Recycling* newrecyclingP = nullptr, Stores* newstoresP = nullptr);
	Jobsheet* addJobSheet(void);				//Creates jobsheet (during car service routine)
	void deleteJobsheet(Jobsheet* jobsheetP);	//Deletes jobsheet (not used during normal service routine)
				
	void serviceCar(Car* custCarP);				//Input: customer car. Function gets customer car from the receptionist and sends it to the technicians "main" thread to initiate the car servicing routine. 
	Car* getCar(void);							//Output: customer's car. Returns car (for receptionist's use)
	Jobsheet* getJobSheet(void);				//Output: jobsheet. Returns jobsheet (for receptionist's use)
};

#endif 

