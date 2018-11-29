//Justine Sultan
//Student Number 35880146

//first create car (and tires) and service record of customer
//then create all objects
//then link all objects with association fxns

#include <stdio.h>
#include "Car.h"
#include "Receptionist.h"
#include "..\DataStructures.h"
#include "..\rt.h"

int main() {
	Receptionist receptionist;				//create the auto shop
	receptionist.Resume(); 
	Technician technician;
	technician.Resume(); 
	Garbage garbage;
	Recycling recycling;
	Stores stores;
	receptionist.addTechnician(&technician); 
	technician.addAsociations(&garbage, &recycling, &stores);

	Car* myCar = new Car;					//create customer objects
	char tireMake[4] = "ABC";
	myCar->addTires(tireMake, 8); 
	struct serviceRecord* myServiceRecord = new struct serviceRecord; 
	myServiceRecord->numberOfStamps = 3;
	char myName[10] = "John_Blah";
	strcpy_s(myServiceRecord->ownerName, 18, myName);
	printf("Created customer and car. Owner name = %s and service record has %d stamps \n", myServiceRecord->ownerName, myServiceRecord->numberOfStamps);
	printf("Car has tires with: make %s and size 8 \n", tireMake); 
	printf("Press enter to go to the auto shop! \n"); 
	getchar(); 

	receptionist.getCarServiced(myCar, myServiceRecord);			//car gets serviced
	printf("Customer waiting for car to be serviced \n");

	struct invoice* myInvoice = receptionist.getInvoice();			//get transaction documents back 
	Jobsheet* myJobsheet = receptionist.getJobsheet(); 
	myServiceRecord = receptionist.getServiceRecord(); 
	printf("Customer recieved transaction papers....\n");
	printf("Invoice: Owner Name=%s, Shop Name=%s, Total Cost = %f \n", myInvoice->ownerName, myInvoice->shopName, myInvoice->totalCost);
	printf("Job Sheet: Total Cost = %f \n", myJobsheet->getTotalCost());
	printf("Service Record: Total Number of stamps now = %d \n", myServiceRecord->numberOfStamps); 

	myCar = receptionist.processPayment(myInvoice->totalCost);				//pay the autoshop and recieve car back

	printf("Customer checks to see if all tires are good now...\n");
	for (int i = 0; i < 4; i++) {
		if (myCar->checkTire(i) == 0) {
			printf("Tire %d is still worn \n", i);
		}
		else {
			printf("Tire %d is good \n", i);
		}
	}

	printf("Hit enter to exit \n");
	getchar(); 

	return 0; 
}