#pragma once

#include <iostream>
#include <string>


class payT {
	double payment;
	bool method;		//cash (0) or credit (1)
public:
	double fullCost(double tTime); //calculates full cost based on time spent 
	void pMethod(bool pType); //checks if user wants to pay cash or credit

};
