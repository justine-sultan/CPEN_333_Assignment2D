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
	Technician* technician;

	struct serviceRecord *custServiceRecord;
	struct invoice *custInvoice;
	Jobsheet* custJobSheet; 
	Car* custCar; 

	void makeCoffee(void);
	void generateInvoice(void); 
	void stampServiceRecord(void); 

	int main(void);

public:
	Receptionist();
	~Receptionist();
	void addTechnician(Technician* techP);
	Technician* swapTechnician(Technician* techP);

	void getCarServiced(Car* custCarP, struct serviceRecord* custServiceRecordP);
	struct invoice* getInvoice(void);
	Jobsheet* getJobsheet(void);
	struct serviceRecord* getServiceRecord(void);
	Car* processPayment(float payment); 

};

#endif 