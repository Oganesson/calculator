#pragma once

//Header file for the derived class sinop

#include "UnaryOp.h"
#include <string>
#include <cmath>

class sinop : public unaryop                                            //Class definition
{
public:
	double calculate() const;
	void print(ostream& os) const;
	void prompt(istream& is);
};

double sinop::calculate() const                                         //Function definition
{
	return sin(input);
}

void sinop::print(std::ostream& os) const                               //Function definition
{
	os << "sin(" << input << ") = " << calculate();
}

void sinop::prompt(std::istream& is)
{
	cout << "Please enter a number in radians"
		<< " to calculate its sine." << endl;

	is >> input;
}