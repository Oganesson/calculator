#pragma once

//Header file for the derived class factorialop

#include "UnaryOp.h"
#include <string>

class factorialop : public unaryop                                      //Class definition
{
public:
	double calculate() const;
	void print(ostream& os) const;
	void prompt(istream& is);

private:
	int factorial(int) const;
};

double factorialop::calculate() const                                   //Function definition
{
	if (input < 0 || input > 19)                                        //Exception handling
		throw string("Input out of bounds!");
	return static_cast<double>(factorial(static_cast<int>(input)));
}

void factorialop::print(std::ostream& os) const                         //Function definition
{
    os << input << "! = " << calculate();
}

int factorialop::factorial(int number) const                            //Function definition
{
	if (number == 0)
		return 1;
	
	return number * factorial(number - 1);				                //Recursive definition
}

void factorialop::prompt(std::istream& is)
{
	cout << "Please enter an integer to calculate "
		<< "its factorial." << endl;

	is >> input;
}