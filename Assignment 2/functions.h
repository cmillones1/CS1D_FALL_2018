/*
 * functions.h
 *
 *  Created on: Sep 12, 2018
 *      Author: Chris
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "header.h"
#include "Stack.h"

stack<string> StringStack(fstream &inFile) {
	string name;
	stack<string> stringStack;

	while (!inFile.eof()) {
		getline(inFile, name);
		stringStack.push(name);
	}
	return stringStack;
}

stack<double> DoubleStack(fstream &inFile) {
	double number;
	stack<double> doubleStack;

	while (!inFile.eof()) {
		inFile >> number;
		doubleStack.push(number);
	}

	return doubleStack;
}

template<class E>
void printStack(stack<E> myStack) {
	int size = 0;
	size = myStack.size();

	for (int i = 0; i < size; i++) {
		cout << "Element[" << i + 1 << "] " << myStack.top() << "\n";
		myStack.pop();
	}
}

bool validEquation(string x) {
	Stack<char> *list = new Stack<char>;
	for(int i=0; i < x.size(); i++)
	{
		if(x.at(i)== '[' || x.at(i) == '{' || x.at(i)== '(')
		{
			list->push(x.at(i));
		}
		if(x.at(i)== ']' || x.at(i) == '}' || x.at(i)== ')')
		{
			if(list->empty())
			{
				return false;
			}
			if(x.at(i) == ']' && list->top() == '[')
			{
				list->pop();
			}else if(x.at(i) == '}' && list->top() == '{')
			{
				list->pop();
			}else if(x.at(i) == ')' && list->top() == '(')
			{
				list->pop();
			}else
			{
				return false;
			}
		}
	}
	if(!list->empty())
	{
		return false;
	}
	else
	{
		return true;
	}

}


#endif /* FUNCTIONS_H_ */
