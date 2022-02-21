#include <iostream>
#include <stdio.h>
#include <utility>
#include <string>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include "Account.h"
#include "PayT.h"
#include "Ticket.h"
#include "DashBoard.h"
#include "ParkSlot.h"

using namespace std;

/*  application will be admin use only
	your parking has 10 slots (in test phase use only tickets and handycapped)
*/
int main() {
	int entr, slotn, popt; // first entry / slot number / opt. for parkslot
	bool popt1;
	DashBoard dsh;
	payT pay;
	Ticket ticket[10];
	ParkSlot slot[10];

	// loading data on launch

	fstream File;
	File.open("parking.txt", ios::in);

	if (!File) {
		cout << "No File Exists\n";
	}

	else {

		for (int i = 0; i < 10; i++) {
			bool sFree;	bool sHandycap;	time_t ttimer; bool tstat;
			File >> sFree >> sHandycap >> ttimer >> tstat;
			slot[i].setFree(sFree); slot[i].setHandycap(sHandycap);
			ticket[i].setEnT(ttimer); ticket[i].setstat(tstat);
		}
		File.close();
	}

	// a more organized way to write the console line 

reset:
	dsh.dashLine(true);
	dsh.welcome();
	dsh.adminEntry();
	dsh.dashLine(false);
	dsh.uncoop();
	cin >> entr;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000000, '\n');
	}
	// clears the screen
	system("CLS");

	dsh.dashLine(true);
	if (entr == 1) { // Setting up the Slots

		cout << "                               ||  Select slot number (1-10):";
		cin >> slotn;
		dsh.PSOpt();
	uncoop1:
		dsh.uncoop();
		cin >> popt;

		if (popt == 1) {
			cout << "                               ||  Select Handycap status (1 = true - 0 = false):";
			cin >> popt1;
			slot[slotn - 1].setHandycap(popt1);
		}

		else if (popt == 0) {
			cout << "                               ||  Select Account status (1 = true - 0 = false):";
			cin >> popt1;
			slot[slotn - 1].setAccount(popt1);
		}

		else {
			goto uncoop1;
		}

		system("pause");
		system("CLS");
		goto reset;
	}

	else if (entr == 2) { // option 2 : check if there are any non-handicapped free slots (complete)

		for (int i = 0; i < 10; i++) {

			if (slot[i].isFree() == true && slot[i].isHandycap() == false) {
				cout << "there is a free slot\n";

				system("pause");
				system("CLS");
				goto reset;
			}
		}

		cout << "there is no free slots\n";
		system("pause");
		system("CLS");
		goto reset;
	}

	else if (entr == 3) { // option 3 : goes to the customer service dashboard to get or end tickets
		dsh.dashLine(true);
		dsh.customerServ();
		dsh.dashLine(false);
	uncoop2:
		dsh.uncoop();

		int copts;
		cin >> copts;

		if (copts == 1) { // entry time and checking if there are no free slots

			for (int i = 0; i < 10; i++) {

				if (slot[i].isFree() == true && slot[i].isHandycap() == false) {

					for (int j = 0; j < 10; j++) {

						if (ticket[j].getstat()) {
							slot[i].flipFree();
							ticket[j].getEnT();
							cout << "                               |*            your ticket number is " << j + 1 << "              *|\n";
							ticket[j].flipstat();
							system("pause"); // screen clearing
							system("CLS");
							goto reset;
						}

					}

				}
			}
			cout << "there is no free slot\n";
			system("pause"); // screen clearing
			system("CLS");
			goto reset;

		}

		else if (copts == 2) { //exit time and calculating full cost
			int k;
			cout << "                               || Please enter your ticket number :";
			cin >> k;
			ticket[k - 1].flipstat();
			ticket[k - 1].getExT();

			double tt;
			tt = ticket[k - 1].totalTime();
			pay.fullCost(tt);
			cout << "                          |**   Total Cost is " << pay.fullCost(tt) << "pounds   **| \n";

			system("pause"); //screen clearing
			system("CLS");
			goto reset;
		}

		else if (copts == 3) {
			system("CLS"); //in case of misclick
			goto reset;
		}

		else {
			goto uncoop2;
		}

	}

	else if (entr == 4) { // option 4 : Save in a folder and exit
		dsh.dashLine(true);
		dsh.endThanks();
		dsh.dashLine(false);

		File.open("parking.txt", ios::in);
		if (!File) {
			cout << "File not found, Creating a new one . . .";
			File.open("parking.txt", ios::app);
			for (int i = 0; i < 10; i++) {
				File << slot[i] << ticket[i] << '\n';
			}
		}
		else {
			File.close();
			int status = remove("parking.txt");

			File.open("parking.txt", ios::app);
			for (int i = 0; i < 10; i++) {
				File << slot[i] << ticket[i] << '\n';
			}
			
		}
	}
	else {
		goto reset;
	}
	return 0;
}