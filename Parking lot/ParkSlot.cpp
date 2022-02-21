#include "ParkSlot.h"

// includes the data related to the parking slot (whether used or empty or for handicapped people)

void ParkSlot::setFree(bool x)
{
	free = x;
}

void ParkSlot::setHandycap(bool x)
{
	handycap = x;
}

void ParkSlot::setAccount(bool x)
{
	account = x;
}

bool ParkSlot::isFree()
{
	return free;
}

void ParkSlot::flipFree()
{
	free = !free;
}

bool ParkSlot::isAccount()
{
	return account;
}

bool ParkSlot::isHandycap()
{
	return handycap;
}


