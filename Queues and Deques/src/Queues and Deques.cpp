//============================================================================
// Name        : Queues.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "header.h"
#include "Queue.h"
#include "Deque.h"
//#include "Deque.h"

int main() {

	fstream inFile;
	fstream inFile2;
	string name;
	double number;

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

		cout << "\n------- PART A -----\n";
		cout << "\tStrings:\n";
		stack3.print();
		cout << "\tDoubles:\n";
		stack4.print();

		stack3.pop();
		stack3.pop();
		stack3.pop();
		stack3.pop();
		stack4.pop();
		stack4.pop();
		stack4.pop();
		stack4.pop();
		stack4.pop();

		cout << "\n------- PART B -----\n";
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


		cout << "\n------- PART C -----\n";
		cout << "\tStrings:\n";
		stack5.print();
		cout << "\tDoubles:\n";
		stack6.print();

		stack5.pop_front();
		stack5.pop_front();
		stack5.pop_front();
		stack5.pop_front();
		stack6.pop_back();
		stack6.pop_back();
		stack6.pop_back();
		stack6.pop_back();
		stack6.pop_back();

		cout << "\n------- PART D -----\n";
		cout << "\tStrings:\n";
		stack5.print();
		cout << "\tDoubles:\n";
		stack6.print();

		inFile.close();
		inFile2.close();





	return 0;
}
