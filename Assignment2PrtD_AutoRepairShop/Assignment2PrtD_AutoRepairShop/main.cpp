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
	printf("Generating Auto shop...\n");
	Receptionist receptionist;				//create the auto shop
	receptionist.Resume(); 
	Technician technician;
	technician.Resume(); 
	Garbage garbage;
	Recycling recycling;
	Stores stores;
	receptionist.addTechnician(&technician); 
	technician.addAsociations(&garbage, &recycling, &stores);

	printf("Generating customer (your) paramaters...\n");
	Car* myCar = new Car;					//create customer objects
	char tireMake[4] = "ABC";
	myCar->addTires(tireMake, 8); 
	struct serviceRecord* myServiceRecord = new struct serviceRecord; 
	myServiceRecord->numberOfStamps = 3;
	char myName[10] = "John_Blah";
	strcpy_s(myServiceRecord->ownerName, 18, myName);
	printf("Created customer and car. Owner name is %s and service record has %d stamps \n", myServiceRecord->ownerName, myServiceRecord->numberOfStamps);
	printf("Car has tires with make: %s and size: 8 \n", tireMake); 
	getchar(); 
	printf("Press enter to go to the auto shop! \n"); 
	getchar(); 

	printf("Press enter to give car and service record to receptionist \n");
	getchar(); 
	receptionist.getCarServiced(myCar, myServiceRecord);			//car gets serviced
	printf("Customer is leaving shop (15 seconds) while waiting for car to be serviced \n");
	Sleep(15000); 
	printf("Customer has arrived back at the shop and will get transaction documents as soon as they are ready\n");

	struct invoice* myInvoice = receptionist.getInvoice();			//get transaction documents back 
	Jobsheet* myJobsheet = receptionist.getJobsheet(); 
	myServiceRecord = receptionist.getServiceRecord(); 
	printf("Customer recieved transaction papers....\n");
	printf("Invoice: Owner Name: %s, Shop Name: %s, Total Cost: %0.2f \n", myInvoice->ownerName, myInvoice->shopName, myInvoice->totalCost);
	printf("Job Sheet: Total Cost = %0.2f \n", myJobsheet->getTotalCost());
	printf("Service Record: Total Number of stamps now = %d \n", myServiceRecord->numberOfStamps); 

	printf("Press enter to pay the autoshop and get car back \n");
	getchar();
	myCar = receptionist.processPayment(myInvoice->totalCost);				//pay the autoshop and recieve car back

	printf("Press enter to see if all tires are good to go now...\n");
	for (int i = 0; i < 4; i++) {
		if (myCar->checkTire(i) == 0) {
			printf("Tire %d is still worn and needs to be replaced \n", (i+1));
		}
		else {
			printf("Tire %d is good to go \n", (i+1));
		}
	}

	printf("Hit enter to exit \n");
	getchar(); 

	return 0; 
}