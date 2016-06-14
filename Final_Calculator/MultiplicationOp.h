#pragma once

//Header file for the derived class multiplicationop

#include "BinaryOp.h"

class multiplicationop : public binaryop                                //Class definition
{
public:
	double calculate() const;
	void print(ostream& os) const;
	void prompt(istream& is);
};

double multiplicationop::calculate() const                              //Function definition
{
	return leftinput * rightinput;
}

void multiplicationop::print(std::ostream& os) const                    //Function definition
{
	os << leftinput << " * " << rightinput << " = " << calculate();
}

void multiplicationop::prompt(std::istream& is)
{
	cout << "Please enter two numbers to multiply." << endl;

	is >> leftinput >> rightinput;
}