#pragma once
#include <iostream>

class ParkSlot{
	bool free = true;      // 0 used   1 free
	bool account = false;  // 0 ticket 1 account
	bool handycap = false; // 0 normal 1 handycapped
public:
	void setFree(bool x);
	void setHandycap(bool x);
	void setAccount(bool x);
	bool isFree();
	void flipFree();
	bool isAccount();
	bool isHandycap();
	friend std::ostream& operator <<(std::ostream& out, const ParkSlot a) {
		out << a.free << '\n' << a.handycap << '\n';
		return out;
	}
	/*
	friend std::istream& operator >>(std::istream& in, ParkSlot a) {
		in >> a.free >> a.handycap;
		return in;
	}
	*/
};

