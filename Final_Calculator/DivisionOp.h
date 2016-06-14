#pragma once

//Header file for the derived class divisionop

#include "BinaryOp.h"
#include <string>

class divisionop : public binaryop                                      //Class definition
{
public:
	double calculate() const;
	void print(ostream& os) const;
	void prompt(istream& is);
};

double divisionop::calculate() const                                    //Function definition
{
	if (rightinput == 0)
		throw string("Denominator cannot be zero!");
	return leftinput / rightinput;
}

void divisionop::print(std::ostream& os) const                          //Function definition
{
	os << leftinput << " / " << rightinput << " = " << calculate();
}

void divisionop::prompt(std::istream& is)
{
	cout << "Please enter two numbers to divide." << endl;

	is >> leftinput >> rightinput;
}