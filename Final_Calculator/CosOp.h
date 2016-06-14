#pragma once

//Header file for the derived class cosop

#include "UnaryOp.h"
#include <string>
#include <cmath>

class cosop : public unaryop                                            //Class definition
{
public:
	double calculate() const;
	void print(ostream& os) const;
	void prompt(istream& is);
};

double cosop::calculate() const                                         //Function definition
{
	return cos(input);
}

void cosop::print(std::ostream& os) const                               //Function definition
{
	os << "cos(" << input << ") = " << calculate();
}

void cosop::prompt(std::istream& is)
{
	cout << "Please enter a number in radians"
		<< " to calculate its cosine." << endl;

	is >> input;
}