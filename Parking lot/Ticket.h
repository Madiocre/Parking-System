#pragma once
#include <time.h>
#include <iostream>

enum class tickType{dayOrL , days, weeks};

class Ticket{
	tickType cause = tickType::dayOrL;
	bool stat = true; // 1 free 0 used
	time_t enTime = 0; //enterance time for temporary user
	time_t exTime = 0; //exit time for user
public:
	// void getType();
	void setEnT(time_t t);
	void setstat(bool s);
	bool getstat();
	void flipstat();
	void getEnT(); //getting entry time
	void getExT(); // getting exit time
	double totalTime();
	friend std::ostream& operator <<(std::ostream& out, const Ticket a) {
		out << a.enTime << '\n' << a.stat << '\n';
		return out;
	}
	/*
	friend std::istream& operator >>(std::istream& in, Ticket a) {
		in >> a.enTime >> a.stat;
		return in;
	}
	*/
};

