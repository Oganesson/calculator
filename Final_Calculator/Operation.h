#pragma once

#include <iostream>

using namespace std;

class operation
{
	friend ostream& operator<<(ostream& os, const operation& op);		//Overloaded ostream as a non-member
	friend istream& operator>>(istream& is, operation& op);				//Overload istream as a non-member

public:
	virtual double calculate() const = 0;                               //Virtual functions
	virtual void print(std::ostream& os) const = 0;
	virtual void prompt(std::istream& is) = 0;
};
