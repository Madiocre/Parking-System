#include "PayT.h"

#include <iostream>

double payT::fullCost(double tTime) 
{
	if (tTime <= 3) { return 20; } //short time cost
	else if (tTime > 3 && tTime < 11) { return 20 + (tTime - 3) * 10; } // less than half a day
	else if (tTime > 24) { // staying over time limit for day warents a penalty for each day spent
		std::cout << "*** You surpassed time limit for 1 day ticket, penalty being applied ***";
		
		return 100 +(tTime/24)*50;
	}
	else{return 100;} // half a day's cost is the same as one day
}
