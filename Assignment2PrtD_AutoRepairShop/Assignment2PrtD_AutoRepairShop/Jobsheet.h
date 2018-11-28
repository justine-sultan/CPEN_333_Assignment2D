//Justine Sultan
//Student Number: 35880146

#ifndef   __Jobsheet__
#define   __Jobsheet__

class Jobsheet
{
private:
	float totalCost;

public:
	Jobsheet();
	~Jobsheet();

	void addItem(int partNumber, int quantity, float cost);
	void addLabourItem(char name[4], float cost); 
	float getTotalCost(void); 
};

#endif 