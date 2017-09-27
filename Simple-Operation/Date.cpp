#include "Date.h"
#include <iostream>

using namespace std;

int Date::gunGetir()
{
	Gun = rand() % 31 + 1;
	return Gun;
}

int Date::AyGetir()
{
	Ay = rand() % 12 + 1;
	return Ay;
}

int Date::yilGetir()
{
	Yil = rand() % 12 + 2005;
	return Yil;
}
