/*************************************************************************
 * AUTHOR(S)	 : Chris Millones
 * STUDENT IDS   : 361396
 * Assignment #2 : Stacks
 * CLASS         : CS1D
 * SECTION       : Mondays & Wednesday: 5:00 - 7:20PM
 * DUE DATE    	 : 9/12
 ************************************************************************/

/*************************************************************************
 * Assignment 2: Stacks
 * _______________________________________________________________________
 *
 *Quick Description :
 *In this Assignment Ill be using the STL stack and test the functions of the
 *stack and after wards I'll be implementing my own stack using a singly
 *linked list. And test the functionality of my implemented stack.
 *
 ************************************************************************/

#include "header.h"
#include "functions.h"
#include "Stack"

const void PRINTAUTHOR() {

	cout << left;
	cout << "********************************************************\n";
	cout << setw(10) << "AUTHOR: " << "      Christopher Millones\n";
	cout << setw(10) << "ASSIGNMENT #:  2\n";
	cout << setw(10) << "CLASS: " << "      CS1D\n";
	cout << setw(10) << "TIME: "
			<< "      Mondays & Wednesday: 5:00 - 7:20PM\n";
	cout << setw(10) << "DUE DATE: " << "      9/12/18\n";
	cout << "********************************************************\n\n";
}

const void INSTRUCTIONS() {

	cout << left;
	cout
			<< "A. Implement and print (top of stack to bottom) the stacks\n"
					" using the STL <stack> with the above data.\n"
					"B. Delete Eric and 8.445 from the above stacks\n"
					" (you will need to delete others) using the STL <stack> \n"
					"and print (top of stack to bottom) the remaining elements in the stacks.\n"
					"C. Implement and print (top of stack to bottom)\n"
					" the stacks using a singly linked list using the above data.  \n"
					"Do not use the STL.\n"
					"D. Delete Eric and 8.445 from the above stacks \n"
					"(you will need to delete others) and print (top of stack to bottom) the \n"
					"remaining elements in the stacks. Do not use the STL.\n"
					"E. Implement the Parentheses Algorithm without \n"
					"using the STL).  Test your algorithm with the given mathematical statements\n";
}

int main() {
	PRINTAUTHOR();
	INSTRUCTIONS();

	fstream inFile1;
	fstream inFile2;
	inFile1.open("StringData.txt");
	inFile2.open("DoubleData.txt");

	stack<string> stringStack;
	stack<double> doubleStack;

	stringStack = StringStack(inFile1);
	doubleStack = DoubleStack(inFile2);

	cout << "\n\n------- PART A -----\n";
	cout << "\tStrings:\n";
	printStack(stringStack);
	cout << "\tDoubles:\n";
	printStack(doubleStack);

	cout << "\n------- PART B -----\n";

	stringStack.pop();
	stringStack.pop();
	stringStack.pop();
	stringStack.pop();
	doubleStack.pop();
	doubleStack.pop();
	doubleStack.pop();
	doubleStack.pop();
	doubleStack.pop();

	cout << "\tStrings:\n";
	printStack(stringStack);
	cout << "\tDoubles:\n";
	printStack(doubleStack);

	inFile1.close();
	inFile2.close();

	/*********************************************
	 *********************************************
	 *********************************************/


	Stack<string> stack1;
	Stack<double> stack2;

	inFile1.open("StringData.txt");
	inFile2.open("DoubleData.txt");

	string name;
	double number;

	while (!inFile1.eof()) {

		getline(inFile1, name);
		stack1.push(name);
	}
	while (!inFile2.eof()) {
		inFile2 >> number;
		stack2.push(number);
	}

	cout << "\n------- PART C -----\n";
	cout << "\tStrings:\n";
	stack1.print();
	cout << "\tDoubles:\n";
	stack2.print();

	stack1.pop();
	stack1.pop();
	stack1.pop();
	stack1.pop();
	stack2.pop();
	stack2.pop();
	stack2.pop();
	stack2.pop();
	stack2.pop();

	cout << "\n------- PART D -----\n";
	cout << "\tStrings:\n";
	stack1.print();
	cout << "\tDoubles:\n";
	stack2.print();

	inFile1.close();
	inFile2.close();

	cout << "\n------- PART E -----\n";

	ifstream Equations;
	string equation;
	bool temp;

	Equations.open("Equations.txt");

	while(!Equations.eof())
	{
		getline(Equations,equation);
		temp = validEquation(equation);
		if(temp == true)
		{
			cout << equation << " <- IS VALID\n";
		}
		else
		{
			cout << equation << " <- IS NOT VALID\n";
		}
	}
	Equations.close();



	return 0;
}
