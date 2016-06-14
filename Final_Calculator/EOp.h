#pragma once

//Header file for the derived class eop

#include "UnaryOp.h"
#include <string>
#include <cmath>

class eop : public unaryop                                              //Class definition
{
public:
	double calculate() const;
	void print(ostream& os) const;
	void prompt(istream& is);
};

double eop::calculate() const                                           //Function definition
{
	return exp(input);
}

void eop::print(std::ostream& os) const                                 //Function definition
{
	os << "e ^ " << input << " = " << calculate();
}

void eop::prompt(std::istream& is)
{
	cout << "Please enter an exponent to calculate e^x." << endl;

	is >> input;
}