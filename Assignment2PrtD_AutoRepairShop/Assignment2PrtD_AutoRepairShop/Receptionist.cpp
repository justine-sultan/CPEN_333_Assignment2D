//Justine Sultan
//Student Number: 35880146

#include "Receptionist.h"
#include <stdio.h>
#include <string.h>
//#include <Windows.h>
#include "..\DataStructures.h"
#include "..\rt.h"

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
	
	printf("Receptionist making invoice...\n");
	strcpy_s(custInvoice->ownerName, 18, custServiceRecord->ownerName);
	char myShop[10] = "Auto_Shop";
	strcpy_s(custInvoice->shopName, 18, myShop);
	custInvoice->totalCost = custJobSheet->getTotalCost();

	printf("Invoice: Owner name: %s,  Shop name: %s,  Total cost: %0.2f \n", custInvoice->ownerName, custInvoice->shopName, custInvoice->totalCost);
	getchar();

	return; 
}

void Receptionist::stampServiceRecord(void) {
	printf("Receptionist stamping invoice...previous number of services = %d \n", custServiceRecord->numberOfStamps);
	custServiceRecord->numberOfStamps++;
	printf("Current number of stamps/number of services: %d \n", custServiceRecord->numberOfStamps);
	getchar();
	return; 
}

void Receptionist::getCarServiced(Car* custCarP, struct serviceRecord* custServiceRecordP) {
	//todo: this will use a pipeline to send data to main() where everything else will be processed
	printf("Receptionist getting car and service record \n");
	getchar();
	CPipe custToRec("custToRec", 1024);
	custToRec.Write(&custCarP, sizeof(custCarP));
	custToRec.Write(&custServiceRecordP, sizeof(custServiceRecordP));
	/*
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
	getchar();*/

	return; 
}

struct invoice* Receptionist::getInvoice(void) {
	//Todo: this will just wait on the pipeline for the receptionist to send the below info, get the info, then return it
	//same with the other 3
	CPipe recToCust("recToCust", 1024);
	struct invoice* temp; 
	recToCust.Read(&temp, sizeof(temp));
	return temp;

	//return custInvoice; 
}

Jobsheet* Receptionist::getJobsheet(void) {
	CPipe recToCust("recToCust", 1024);
	Jobsheet* temp;
	recToCust.Read(&temp, sizeof(temp));
	return temp;

	//return custJobSheet;
}

struct serviceRecord* Receptionist::getServiceRecord(void) {
	CPipe recToCust("recToCust", 1024);
	struct serviceRecord* temp;
	recToCust.Read(&temp, sizeof(temp));
	return temp;

	//return custServiceRecord;
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

int Receptionist::main(void)
{
	CPipe custToRec("custToRec", 1024); 
	CPipe recToCust("recToCust", 1024);
	//CPipe techToRec("techToRec", 1024);
	//CPipe recToTech("recToTech", 1024);
	
	while (1) {
		custToRec.Read(&custCar, sizeof(custCar));
		custToRec.Read(&custServiceRecord, sizeof(custServiceRecord));

		printf("Receptionist sending car to technician\n");
		getchar();
		technician->serviceCar(custCar);
		for (int i = 0; i <3; i++) {
			makeCoffee();
			Sleep(8000);
		}
		
		printf("Receptionist done making coffee and will get car and jobsheet from technician as soon as they are ready\n");
		getchar();
		custCar = technician->getCar();
		custJobSheet = technician->getJobSheet();
		generateInvoice();
		stampServiceRecord();
		printf("Receptionist ready to hand off to customer\n");
		getchar();

		recToCust.Write(&custInvoice, sizeof(custInvoice));
		recToCust.Write(&custJobSheet, sizeof(custJobSheet));
		recToCust.Write(&custServiceRecord, sizeof(custServiceRecord));

	}

	return(0);
}
