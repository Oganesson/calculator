//Implementation file for the base class operation

#include "Operation.h"
#include <iostream>
using namespace std;

ostream& operator<< (ostream& os,
	const operation& op)
{
	op.print(os);
	return os;
}

istream& operator>>(istream& is,
	operation& op)
{
	op.prompt(is);
	return is;
}