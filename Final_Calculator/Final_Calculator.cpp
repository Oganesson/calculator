// Name:    Eva Schwesig
// Date:    17 May 2016
// Program: Calculator 4.0
// Purpose: Program to calculate various functions, including
//          addition, subtraction, multiplication, division,
//          mod, e^x, sine, cosine, factorials, and powers.
//			The program stores a history of all performed operations
//			in a linked list. The user can search this list to display
//			previously performed calculations.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include "AdditionOp.h"
#include "SubtractionOp.h"
#include "MultiplicationOp.h"
#include "DivisionOp.h"
#include "ModOp.h"
#include "PowerOp.h"
#include "FactorialOp.h"
#include "EOp.h"
#include "SinOp.h"
#include "CosOp.h"
#include "orderedLinkedList.h"

using namespace std;

void showSelection();                                                   //Function prototypes
void searchHistory(orderedLinkedList<operation*> &history);	

int main()
{
	operation* op = nullptr;											//New pointer variables

	char choice;

	orderedLinkedList<operation*> history;								//Create new linked list of operation pointers

	cout << "This program calculates values of your choice." << endl;   //Instruction

	showSelection();                                                    //Call function to display menu
	cin >> choice;                                                      //Assign input to variable
	cout << endl;

	choice = tolower(choice);

	while (choice != 'z')												//While loop
	{
		switch (choice)                                                 //Begin switch
		{
		case 'a':
			op = new additionop();
			break;
		case 'b':
			op = new subtractionop();
			break;
		case 'c':
			op = new multiplicationop();
			break;
		case 'd':
			op = new divisionop();
			break;
		case 'e':
			op = new modop();
			break;
		case 'f':
			op = new powerop();
			break;
		case 'g':
			op = new factorialop();
			break;
		case 'h':
			op = new eop();
			break;
		case 'i':
			op = new sinop();
			break;
		case 'j':
			op = new cosop();
			break;
		case 'k':														//Access function to search history
			searchHistory(history);
			break;
		default:
			cout << "Invalid selection." << endl << endl;               //Output for invalid input
		}//end switch

		if (op != nullptr)												//Input parameters
		{
			cin >> *op;
			try
			{
				if (!cin)
					throw string("Invalid input!");                     //Exception handling
				cout << *op;
				cout << endl;

				history.insert(op);										//Insert pointer in list
			}
			catch (string message)
			{
				cout << message;
				cout << endl;
				cin.clear();
				cin.ignore(100, '\n');
				delete op;
			}
			op = nullptr;
		}

		cout << endl;

		showSelection();                                                //Repeat show selection for next entry
		cin >> choice;

	}//end while

	cin.ignore();
	cin.get();

	return 0;
}//end main

void showSelection()                                                    //Function to display selection
{
	cout << "Menu:" << endl;                                            //Menu choices
	cout << "Enter 'A' to calculate a sum." << endl;
	cout << "Enter 'B' to calculate a difference." << endl;
	cout << "Enter 'C' to calculate a product." << endl;
	cout << "Enter 'D' to calculate a quotient." << endl;
	cout << "Enter 'E' to calculate a mod." << endl;
	cout << "Enter 'F' to calculate a power." << endl;
	cout << "Enter 'G' to calculate a factorial." << endl;
	cout << "Enter 'H' to calculate e^x." << endl;
	cout << "Enter 'I' to calculate sin(x)." << endl;
	cout << "Enter 'J' to calculate cos(x)." << endl;
	cout << "Enter 'K' to perform a search." << endl;
	cout << "Enter 'Z' to stop the program." << endl;
}//end showSelection

void searchHistory(orderedLinkedList<operation*> &history)				//Function to perform a search of the history
{
	cout << "Search menu:" << endl;										//Search menu choices
	cout << "Enter 'A' to search for a sum." << endl;
	cout << "Enter 'B' to search for a difference." << endl;
	cout << "Enter 'C' to search for a product." << endl;
	cout << "Enter 'D' to search for a quotient." << endl;
	cout << "Enter 'E' to search for a mod." << endl;
	cout << "Enter 'F' to search for a power." << endl;
	cout << "Enter 'G' to search for a factorial." << endl;
	cout << "Enter 'H' to search for e^x." << endl;
	cout << "Enter 'I' to search for sin(x)." << endl;
	cout << "Enter 'J' to search for cos(x)." << endl;
	cout << "Enter 'Z' to return to the previous menu." << endl << endl;

	char choice;
	cin >> choice;

	choice = tolower(choice);

	if (choice == 'z')
		return;
	if (choice < 'a' || choice > 'j')
	{
		cout << "Invalid input." << endl;
		return;
	}
	
	linkedListIterator<operation*> iter = history.begin();				//Get the beginning iterator of the linked list
	linkedListIterator<operation*> last = history.end();				//Get the last iterator of the linked list
	while (iter != last)
	{
		switch (choice)
		{
		case 'a':
			if (dynamic_cast<additionop*>(iter.current->info) != nullptr)	//Try to dynamically cast chosen operation
																			//If operation is not found, return nullptr
				cout << *iter.current->info << endl;						//If matching operation is found, display info
			break;
		case 'b':
			if (dynamic_cast<subtractionop*>(iter.current->info) != nullptr)
				cout << *iter.current->info << endl;
			break;
		case 'c':
			if (dynamic_cast<multiplicationop*>(iter.current->info) != nullptr)
				cout << *iter.current->info << endl;
			break;
		case 'd':
			if (dynamic_cast<divisionop*>(iter.current->info) != nullptr)
				cout << *iter.current->info << endl;
			break;
		case 'e':
			if (dynamic_cast<modop*>(iter.current->info) != nullptr)
				cout << *iter.current->info << endl;
			break;
		case 'f':
			if (dynamic_cast<powerop*>(iter.current->info) != nullptr)
				cout << *iter.current->info << endl;
			break;
		case 'g':
			if (dynamic_cast<factorialop*>(iter.current->info) != nullptr)
				cout << *iter.current->info << endl;
			break;
		case 'h':
			if (dynamic_cast<eop*>(iter.current->info) != nullptr)
				cout << *iter.current->info << endl;
			break;
		case 'i':
			if (dynamic_cast<sinop*>(iter.current->info) != nullptr)
				cout << *iter.current->info << endl;
			break;
		case 'j':
			if (dynamic_cast<cosop*>(iter.current->info) != nullptr)
				cout << *iter.current->info << endl;
			break;
		}

		++iter;			//Increment iterator
	}
}