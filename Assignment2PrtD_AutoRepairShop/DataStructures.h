//Justine Sultan
//Student Number 35880146

//Data Types(excluding classes) :
//	struct serviceRecord
//	struct invoice
//	struct oil
//	int tireStatus[4];

#ifndef   __DataStructures__
#define   __DataStructures__

#include <stdio.h>

struct serviceRecord {
	char ownerName[20];
	int numberOfStamps; 
};

struct invoice{
	char ownerName[20];
	char shopName[20];
	float totalCost;
};

struct oil {
	int type;
	int amount;
};

#endif 