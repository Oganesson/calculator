#pragma once

//Header file for the derived class subtractionop

#include "BinaryOp.h"

class subtractionop : public binaryop                                   //Class definition
{
public:
	double calculate() const;
	void print(ostream& os) const;
	void prompt(istream& is);
};

double subtractionop::calculate() const                                 //Function definition
{
	return leftinput - rightinput;
}

void subtractionop::print(std::ostream& os) const                       //Function definition
{
	os << leftinput << " - " << rightinput << " = " << calculate();
}

void subtractionop::prompt(std::istream& is)
{
	cout << "Please enter two numbers to subtract from "
		<< "each other." << endl;

	is >> leftinput >> rightinput;
}