#include "DashBoard.h"
#include <iostream>

using namespace std;

// the content seen by the user , just made into a different file to keep a better form for the main file

void DashBoard::dashLine(bool up)
{
	// upper and lower frames
	if (up == true) {
		cout << "                               _____________________________________________________\n";
	}
	else {
		cout << "                               ||_________________________________________________||\n";
	}
}

void DashBoard::welcome()
{
	// basic bitch welcome
	cout << "                               || Welcome To ........................ Parking Lot ||\n"
		 << "                               ||             CHOOSE FROM THE FOLLOWING           ||\n";
}

void DashBoard::uncoop()
{
	// in case user doesnt cooperate
	cout << "                               ||      Please choose from the selections:";
}

void DashBoard::custOpt()
{
	// when Customer service in admin entry is chosen
	cout << "                               || 1- Ticket options                               ||\n"
		 << "                               || 2- ...............                              ||\n";
}

void DashBoard::adminEntry()
{
	cout << "                               ||             Choose of the following             ||\n"
		 << "                               || 1- Set parking slot                             ||\n"
 		 << "                               || 2- check parking slots                          ||\n"
		 << "                               || 3- Customer options                             ||\n"
		 << "                               || 4- Save and Exit                                ||\n";
}

void DashBoard::customerServ()
{
	cout << "                               ||             Choose of the following             ||\n"
		 << "                               || 1- Ticket checkin                               ||\n"
		 << "                               || 2- Ticket checkout                              ||\n"
		 << "                               || 3- Return                                       ||\n";

}

void DashBoard::endThanks()
{
	cout << "                               ||           Thanks For using Our service          ||\n";
}

void DashBoard::tickOpt()
{
	cout << "                               || 1- Day or less ticket                           ||\n"
		 << "                               || 2- (1-7)Days ticket                             ||\n"
		 << "                               || 3- Week ticket                                  ||\n";
}

void DashBoard::PSOpt()
{
	cout << "                               || 1- specify for handicapped                      ||\n"
		 << "                               || 2- specify for account                          ||\n";
}
