//============================================================================
// Name        : Assignmet.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "header.h"
#include "functions.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"

int main() {

	fstream inFile;
	fstream inFile2;
	fstream inFile3;
	inFile.open("StringData.txt");
	inFile2.open("Double.txt");
	inFile3.open("Equations.txt");

	stack<string> stringStack;
	stack<double> doubleStack;


/*********************************************
*********************************************
*********************************************/

	stringStack = StringStack(inFile);
	doubleStack = DoubleStack(inFile2);

	cout << "------- PART A -----\n";
	cout << "\tStrings:\n";
	printStack(stringStack);
	cout << "\tDoubles:\n";
	printStack(doubleStack);

	cout << "\n------- PART B -----\n";

	stringStack.pop();
	stringStack.pop();
	stringStack.pop();
	stringStack.pop();
	stringStack.pop();
	doubleStack.pop();
	doubleStack.pop();
	doubleStack.pop();
	doubleStack.pop();

	cout << "\tStrings:\n";
	printStack(stringStack);
	cout << "\tDoubles:\n";
	printStack(doubleStack);

	inFile.close();
	inFile2.close();


/*********************************************
*********************************************
*********************************************/

	Stack<string> stack1;
	Stack<double> stack2;

	inFile.open("StringData.txt");
	inFile2.open("Double.txt");


	string name;
	double number;

	while(!inFile.eof())
	{

		getline(inFile, name);
		stack1.push(name);
	}
	while(!inFile2.eof())
	{
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
	stack1.pop();
	stack2.pop();
	stack2.pop();
	stack2.pop();
	stack2.pop();

	cout << "\n------- PART D -----\n";
	cout << "\tStrings:\n";
	stack1.print();
	cout << "\tDoubles:\n";
	stack2.print();

	inFile.close();
	inFile2.close();


/*********************************************
 *********************************************
 *********************************************/

	Queue<string> stack3;
	Queue<double> stack4;

	inFile.open("StringData.txt");
	inFile2.open("Double.txt");

	while(!inFile.eof())
	{

		getline(inFile, name);
		stack3.push(name);
	}
	while(!inFile2.eof())
	{
		inFile2 >> number;
		stack4.push(number);
	}

	cout << "\n------- PART E -----\n";
	cout << "\tStrings:\n";
	stack3.print();
	cout << "\tDoubles:\n";
	stack4.print();

	stack3.pop();
	stack3.pop();
	stack3.pop();
	stack4.pop();
	stack4.pop();
	stack4.pop();

	cout << "\n------- PART F -----\n";
	cout << "\tStrings:\n";
	stack3.print();
	cout << "\tDoubles:\n";
	stack4.print();


	inFile.close();
	inFile2.close();


/*********************************************
 *********************************************
 *********************************************/
	Deque<string> stack5;
	Deque<double> stack6;

	inFile.open("StringData.txt");
	inFile2.open("Double.txt");

	while(!inFile.eof())
	{

		getline(inFile, name);
		stack5.push_front(name);
	}
	while(!inFile2.eof())
	{
		inFile2 >> number;
		stack6.push_front(number);
	}


	cout << "\n------- PART G -----\n";
	cout << "\tStrings:\n";
	stack5.print();
	cout << "\tDoubles:\n";
	stack6.print();


	stack5.pop_front();
	stack5.pop_front();
	stack5.pop_front();
	stack5.pop_front();
	stack5.pop_front();
	stack6.pop_back();
	stack6.pop_back();
	stack6.pop_back();

	cout << "\n------- PART H -----\n";
	cout << "\tStrings:\n";
	stack5.print();
	cout << "\tDoubles:\n";
	stack6.print();

	inFile.close();
	inFile2.close();

/*********************************************
 *********************************************
 *********************************************/

	string condition;
	bool test;

	while(!inFile3.eof())
	{
		getline(inFile3, condition);
		test = validEquation(condition);
		if(test == true)
		{
			cout << condition << "  <----- Equation is VALID\n";
		}
		else
		{
			cout << condition << "  <----- Equation is NOT VALID\n";
		}
	}

	return 0;
}




























