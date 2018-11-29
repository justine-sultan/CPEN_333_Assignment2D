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
	Car * custCar;
	Jobsheet* custJobsheet; 
	Garbage* garbage;
	Recycling* recycling;
	Stores* stores;

	int main(void);

public:
	Technician();
	~Technician();
	//for add and swap associations functions, if you do not want to change the association enter nullptr for that argument
	void addAsociations(Garbage* garbageP = nullptr, Recycling* recyclingP = nullptr, Stores* storesP = nullptr);
	void swapAssociations(Garbage* garbageP = nullptr, Recycling* recyclingP = nullptr, Stores* storesP = nullptr, 
		                 Garbage* newgarbageP = nullptr, Recycling* newrecyclingP = nullptr, Stores* newstoresP = nullptr);

	void serviceCar(Car* custCarP);
	Car* getCar(void); 
	Jobsheet* getJobSheet(void); 
};

#endif 

/*void addObject(void* object);
void swapObject(void* newObject, void* oldObject); */

/*void addCar(Car* carP);
void addJobsheet(Jobsheet* jobsheetP);
void addGarbage(Garbage* garbageP);
void addRecycling(Recycling* recyclingP);
void addStores(Stores* storesP);
Car* swapCar(Car* carP);
Jobsheet* swapJobsheet(Jobsheet* jobsheetP);
Garbage* swapGarbage(Garbage* garbageP);
Recycling* swapRecycling(Recycling* recyclingP);
Stores* swapStores(Stores* storesP);*/