/*
 * functions.h
 *
 *  Created on: Aug 2, 2018
 *      Author: Chris
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include "header.h"
#include "stack.h"

stack<string> StringStack(fstream &inFile)
{
	string name;
	stack<string> stringStack;


	while(!inFile.eof())
	{
			getline(inFile, name);
			stringStack.push(name);
	}
	return stringStack;
}

stack<double> DoubleStack(fstream &inFile)
{
	double number;
	stack<double> doubleStack;

	while(!inFile.eof())
	{
		inFile >> number;
		doubleStack.push(number);
	}

	return doubleStack;
}

template<class E>
void printStack(stack<E> myStack)
{
	int size = 0;
	size = myStack.size();

	for(int i=0; i< size; i++)
	{
		cout << "Element[" << i+1 << "] " << myStack.top() << "\n";
		myStack.pop();
	}
}


bool validEquation(string eqn)
{
	Stack<string> temp;
	string condition;
	cout << "EQUATION : " << eqn << endl;
	for(unsigned int i = 0; i<= eqn.size()-1; i++)
	{
		if(eqn.at(i) == '(' || eqn.at(i) ==  '{' || eqn.at(i) == '[')
		{
			condition = eqn.at(i);
			temp.push(condition);
		}
		else if (eqn.at(i) == ')' || eqn.at(i) ==  '}' || eqn.at(i) == ']')
		{
			if((eqn.at(i) == ')' && temp.top() == "(") || (eqn.at(i) == '}' && temp.top() == "{" )|| (eqn.at(i) == ']' && temp.top() == "["))
			{
				return true;
			}

		}

	}

	return false;

}


#endif /* FUNCTIONS_H_ */
