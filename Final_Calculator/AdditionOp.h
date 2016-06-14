#pragma once

//Header file for the derived class additionop

#include "BinaryOp.h"

class additionop : public binaryop                                      //Class definition
{
public:
	double calculate() const;
	void print(ostream& os) const;
	void prompt(istream& is);
};

double additionop::calculate() const                                    //Function definition
{
	return leftinput + rightinput;
}

void additionop::print(std::ostream& os) const                          //Function definition
{
	os << leftinput << " + " << rightinput << " = " << calculate();
}

void additionop::prompt(std::istream& is)
{
	cout << "Please enter two numbers to add" << endl;

	is >> leftinput >> rightinput;
}