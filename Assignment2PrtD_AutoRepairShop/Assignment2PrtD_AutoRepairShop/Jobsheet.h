//Justine Sultan
//Student Number: 35880146

#ifndef   __Jobsheet__
#define   __Jobsheet__

class Jobsheet
{
private:
	float totalCost;											//Variable store the current total cost of all job items/job labour items

public:
	Jobsheet();													//Constructor
	~Jobsheet();												//Destructor

	void addItem(int partNumber, int quantity, float cost);		//Input: part number, quantity of parts, and cost of parts. 
																//Adds the paramaters to the job sheet as an job item, and increments total cost
	void addLabourItem(char name[4], float cost);				//Input: labour item (4 character code, e.g, SWTI for SWap TIres), and cost of labour. 
																//Adds labour item to job sheet and increments total cost
	float getTotalCost(void);									//Ouput: total cost. Returns the current total cost recorded on the job sheet
};

#endif 