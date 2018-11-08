/*
 * Stack.h
 *
 *  Created on: Aug 3, 2018
 *      Author: Chris
 */

#ifndef STACK_H_
#define STACK_H_

#include "header.h"

template <class E>
	struct node
	{
		E data;
		node<E>* next;
	};

template <class E>
class Stack {
public:
	Stack();
	 ~Stack();

	bool empty();
	int size();
	E top();
	void push(E data);
	void  pop();
	void print();

private:

	node<E> *head;
	node<E> *tail;
	int count;


};

template <class E>
Stack<E>::Stack() {
	head = NULL;
	tail = NULL;
	count = 0;

}

template <class E>
Stack<E>::~Stack() {
	head = NULL;
	tail = NULL;
	count = 0;
}

template <class E>
bool Stack<E>::empty()
{
	return count == 0? true:false;
}

template <class E>
int Stack<E>::size()
{
	return count;
}

template <class E>
E Stack<E>::top()
{
	return tail->data;
}

template <class E>
void Stack<E>::push(E data)
{
	node<E>* temp = new node<E>;


	if(size() == 0)
	{
		temp->data = data;
		temp->next = NULL;
		head = tail = temp;
	}
	else
	{
		temp->data = data;
		temp->next = NULL;
		tail->next = temp;
		tail = temp;
	}

	count ++;
}

template <class E>
void Stack<E>::pop()
{
	node<E>* temp = new node<E>;
	temp = head;
	if (count == 0)
	{
		cout << "STACK IS EMPTY!\n";
	}else
	{
	while(temp->next != tail)
	{
		temp = temp->next;
	}
	tail = temp;
	tail->next = NULL;
	}
}

template <class E>
void Stack<E>::print()
{
	node<E>* temp = new node<E>;
	temp = head;
	vector<E> temp2;
	int counter = 1;

	while(temp != NULL){temp2.push_back(temp->data);temp = temp->next;}

	for(int i = temp2.size()-1; i >= 0; i--)
	{
		cout << "Element [" << counter << "] " << temp2.at(i) << endl;
		counter++;
	}

}

#endif /* STACK_H_ */













