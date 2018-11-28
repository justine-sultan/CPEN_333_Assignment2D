//Justine Sultan
//Student Number: 35880146

#include "Technician.h"
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "..\DataStructures.h"

Technician::Technician()
{
	printf("Creating technician \n");
	Car * custCar = nullptr;
	Jobsheet* custJobsheet = nullptr;
	Garbage* garbage = nullptr;
	Recycling* recycling = nullptr;
	Stores* stores = nullptr;
}

Technician::~Technician()
{
	printf("Destroying technician \n");
}

void Technician::addAsociations(Garbage* garbageP , Recycling* recyclingP, Stores* storesP) 
{
	if (garbageP != nullptr) { garbage = garbageP; }
	if (recyclingP != nullptr) { recycling = recyclingP; }
	if (storesP != nullptr) { stores = storesP; }

	return; 
}

void Technician::swapAssociations(Garbage* garbageP, Recycling* recyclingP, Stores* storesP ,
	                   Garbage* newgarbageP, Recycling* newrecyclingP, Stores* newstoresP)
{
	if (newgarbageP != nullptr) { 
		garbageP = garbage; 
		garbage = newgarbageP;
	}
	if (newrecyclingP != nullptr) { 
		recyclingP = recycling; 
		recycling = newrecyclingP;
	}
	if (newstoresP != nullptr) { 
		storesP = stores; 
		stores = newstoresP;
	}

	return;
}


void Technician::serviceCar(Car* custCarP) {
	printf("Technician creating jobsheet \n");
	getchar();
	custJobsheet = new Jobsheet; 
	custCar = custCarP; 

	printf("Technician getting oil, airfilter, and oilfilter \n");
	getchar();
	struct oil* newOil = stores->getOil(8,10); 
	custJobsheet->addItem(newOil->type, newOil->amount = 5, 5.00);
	int* airFilter = stores->getAirFilter();
	custJobsheet->addItem(*airFilter, 1, 10.00);
	int* oilFilter = stores->getOilFilter();
	custJobsheet->addItem(*oilFilter, 1, 10.00);

	printf("Technician swapping oil, airfilter, and oilfilter \n");
	getchar();
	struct oil* oldOil = custCar->swapOil(newOil);
	recycling->recycleOil(oldOil);
	char job1[5] = "OILC"; 
	custJobsheet->addLabourItem(job1, 5.00);
	int* oldAirFilter = custCar->swapAirFilter(airFilter);
	garbage->disposeFilter(oldAirFilter);
	char job2[5] = "AIFC";
	custJobsheet->addLabourItem(job2, 5.00);
	int* oldOilFilter = custCar->swapOilFilter(oilFilter);
	garbage->disposeFilter(oldOilFilter);
	char job3[5] = "OIFC";
	custJobsheet->addLabourItem(job3, 5.00);

	printf("Technician checking Tires \n");
	getchar();
	for (int i = 0; i < 4; i++) {
		int tireStatus = custCar->checkTire(i);
		if (tireStatus == 0) {
			char tireName[4] = "ABC"; 
			Tire* newTire = stores->getTire(tireName, 6, 1);
			custJobsheet->addItem(001, 1, 7.00);
			Tire* oldTire = custCar->swapTire(i, newTire);
			recycling->recycleTire(oldTire); 
			char job4[5] = "SWTI";
			custJobsheet->addLabourItem(job4, 15.00);
		}
		else {
			custCar->rotateTire(i);
			char job4[5] = "RTTI";
			custJobsheet->addLabourItem(job4, 3.00);
		}
	}

	printf("Technician done servicing car \n");
	getchar();

}

Car* Technician::getCar(void) {
	Car* temp = custCar;
	custCar = nullptr; 
	return temp; 
}

Jobsheet* Technician::getJobSheet(void) {
	Jobsheet* temp = custJobsheet;
	custJobsheet = nullptr;
	return temp; 
}