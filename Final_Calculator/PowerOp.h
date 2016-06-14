#pragma once

//Header file for the derived class powerop

#include "BinaryOp.h"
#include <cmath>

class powerop : public binaryop                                         //Class definition
{
public:
	double calculate() const;
	void print(ostream& os) const;
	void prompt(istream& is);
};

double powerop::calculate() const                                       //Function definition
{
	return pow(leftinput, rightinput);
}

void powerop::print(std::ostream& os) const                             //Function definition
{
	os << leftinput << " ^ " << rightinput << " = " << calculate();
}

void powerop::prompt(std::istream& is)
{
	cout << "Please enter two numbers."
		<< " The first one will be the base and"
		<< " the second one will be the exponent." << endl;

	is >> leftinput >> rightinput;
}