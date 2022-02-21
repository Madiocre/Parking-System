#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Ticket.h"

using namespace std;

enum vType {car, motorbike, jeep, van};


class Account{
	string uName; //users name
	vType type;
public:
	void getName(string name);


	
};

