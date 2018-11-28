//Justine Sultan
//Student Number: 35880146

#include "Receptionist.h"
#include <stdio.h>
#include <string.h>
//#include <Windows.h>
#include "..\DataStructures.h"

Receptionist::Receptionist()
{
	custServiceRecord = nullptr;	//not in charge of memory - passes through
	custCar = nullptr;	//not in charge of memory - passes through
	custInvoice = nullptr;			//in charge of memory - must delete at end of customer transaction
	custJobSheet = nullptr;			//in charge of memory - must delete at end of customer transaction
}


Receptionist::~Receptionist()
{
	//deleting/freeing memory will be dealt 
	//with in processPayment function (Receptionist unlinks with customer)
}

void Receptionist::makeCoffee(void) {
	printf("Receptionist making coffee \n");
	getchar(); 
	return;
}

void Receptionist::addTechnician(Technician* techP) {
	//associations
	technician = techP;		//unidirectional
	return;
}

Technician* Receptionist::swapTechnician(Technician* techP) {
	Technician* temp = technician;
	technician = techP;
	return temp;
}

void Receptionist::generateInvoice(void) {
	custInvoice = new struct invoice;
	
	printf("Receptionist making Invoice...\n");
	//char myName[10] = "John_Blah";
	strcpy_s(custInvoice->ownerName, 18, custServiceRecord->ownerName);
	char myShop[10] = "Auto_Shop";
	strcpy_s(custInvoice->shopName, 18, myShop);
	custInvoice->totalCost = custJobSheet->getTotalCost();

	printf("Invoice Onwner name: %s,  Shop name: %s,  Total cost: %f", custInvoice->ownerName, custInvoice->shopName, custInvoice->totalCost);
	getchar();

	return; 
}

void Receptionist::stampServiceRecord(void) {
	printf("Receptionist stamping Invoice...previous number of services = %d \n", custServiceRecord->numberOfStamps);
	custServiceRecord->numberOfStamps++;
	printf("Current number of stamps/number of services: %d \n", custServiceRecord->numberOfStamps);
	getchar();
	return; 
}

void Receptionist::getCarServiced(Car* custCarP, struct serviceRecord* custServiceRecordP) {
	printf("Receptionist getting car and service record \n");
	getchar();
	custServiceRecord = custServiceRecordP; 
	custCar = custCarP; 
	printf("Receptionist sending car to technician\n");
	getchar();
	technician->serviceCar(custCar); 
	makeCoffee();
	printf("Receptionist retrieving car and jobsheet from technician\n");
	getchar();
	custCar = technician->getCar();
	custJobSheet = technician->getJobSheet(); 
	generateInvoice();
	stampServiceRecord();
	printf("Receptionist ready to hand off to customer\n");
	getchar();

	return; 
}

struct invoice* Receptionist::getInvoice(void) {
	return custInvoice; 
}

Jobsheet* Receptionist::getJobsheet(void) {
	return custJobSheet;
}

struct serviceRecord* Receptionist::getServiceRecord(void) {
	return custServiceRecord;
}

Car* Receptionist::processPayment(float payment) {
	if (payment != custInvoice->totalCost) {
		printf("Error: Insufficient Payment");
		getchar();
		return nullptr; 
	}
	else {
		printf("Receptionist returning car\n");
		getchar(); 
		delete custInvoice;
		delete custJobSheet;
		custServiceRecord = nullptr;	//assume that customer has taken service record back	
		Car* temp = custCar;
		custCar = nullptr;				//assume that customer has taken car back
		return temp; 
	}
}
