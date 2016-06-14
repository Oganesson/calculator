#pragma once

//Header file for the derived class modop

#include "BinaryOp.h"
#include <string>

class modop : public binaryop                                           //Class definition
{
public:
	double calculate() const;
	void print(ostream& os) const;
	void prompt(istream& is);
};

double modop::calculate() const                                         //Function definition
{
	if (rightinput == 0)
		throw string("Denominator cannot be zero!");
	return static_cast<int>(leftinput) % static_cast<int>(rightinput);
}

void modop::print(std::ostream& os) const                               //Function definition
{
	os << leftinput << " % " << rightinput << " = " << calculate();
}

void modop::prompt(std::istream& is)
{
	cout << "Please enter a dividend followed"
		<< " by a divisor to calculate the modulus." << endl;

	is >> leftinput >> rightinput;
}