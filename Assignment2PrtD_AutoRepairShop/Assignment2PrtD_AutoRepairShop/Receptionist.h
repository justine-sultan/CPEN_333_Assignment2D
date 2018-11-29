//Justine Sultan
//Student Number: 35880146

#ifndef   __Receptionist__
#define   __Receptionist__

#include "Jobsheet.h"
#include "Car.h"
#include "Technician.h"
#include <string.h>
#include "..\DataStructures.h"
#include "..\rt.h"

class Receptionist : public ActiveClass
{
private:
	//associations:
	Technician* technician;								//Technician object (uni-directional association)

	struct serviceRecord *custServiceRecord;			//Data structure to record service record
	struct invoice *custInvoice;						//Data structure for customers invoice (records total cost for customer)
	Jobsheet* custJobSheet;								//Data structure for job sheet (list of job items and services)
	Car* custCar;										//Car object - passed through from customer to technician

	void makeCoffee(void);								//Print statement for receptionist to "make coffee"
	void generateInvoice(void);							//Receptionist generates invoice from jobsheet
	void stampServiceRecord(void);						//Receptionist adds a stamp to the service record

	int main(void);

public:
	Receptionist();										//Constructor
	~Receptionist();									//Destructor
	void addTechnician(Technician* techP);				//Input: technician object. Adds technician association
	Technician* swapTechnician(Technician* techP);		//Input: technician object. Output: old technicain obejct. Swaps technician association

	void getCarServiced(Car* custCarP, struct serviceRecord* custServiceRecordP);		//Input: car object and service record struct pointer. 
																						//Function passes information from customer to receptionist "main" thread to initiate service car routine
																						//Once called, the car service routine will run concurrently from the thread that called this function
	struct invoice* getInvoice(void);					//Output: invoice. Returns invoice (for customer)
	Jobsheet* getJobsheet(void);						//Output: jobsheet. Returns jobsheet (for customer)
	struct serviceRecord* getServiceRecord(void);		//Output: pointer to service record. Returns service record (for customer)
	Car* processPayment(float payment);					//Input: payment amount, Output: customer's car. Returns customer's (serviced) car IF the payment matches the total cost on the invoice 

};

#endif 