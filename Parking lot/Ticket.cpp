#include "Ticket.h"
#include <time.h>
/*
Ticket entry timer
*/

void Ticket::setEnT(time_t t)
{
	enTime = t;
}

/*
Ticket exit timer
*/

void Ticket::setstat(bool s)
{
	stat = s;
}

/*
checks if ticket is available or busy
*/

bool Ticket::getstat()
{
	return stat;
}

/*
Swaps between free and busy tickets
*/

void Ticket::flipstat()
{
	stat = !stat;
}

void Ticket::getEnT()
{
	time(&enTime);
}


void Ticket::getExT()
{
	time(&exTime);
}

// calculates the time spent to deside on the cost

double Ticket::totalTime()
{
	double tt = difftime(exTime, enTime);
	tt /= 3600;
	return tt;
}
